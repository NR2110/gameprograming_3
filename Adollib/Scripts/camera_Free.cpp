
#include "../Adollib/systems.h"
#include "../Adollib/Adollib.h"
#include "../Adollib/transform.h"
#include "../Adollib/gameobject_manager.h"
#include "camera_global.h"
#include "camera_Free.h"

namespace Adollib
{

	// 所属するシーンの初期化時に一度だけ呼ばれる
	void camera_Free::awake()
	{

	}

	void camera_Free::start()
	{

	}

	// 毎フレーム呼ばれる更新処理
	void camera_Free::update()
	{

		vector3 position = vector3(0, 0, 0);
		quaternion rotate = quaternion_identity();


		//カメラの回転
		if (camera_Global::set_carsol_stop == false) {
			float rotate_pow = 3 * Al_Global::elapsed_time;
			vector3 rotate_vec = vector3(0, 0, 0);
			rotate_vec.y = input->getCursorPosX() - Al_Global::SCREEN_WIDTH / 2;
			rotate_vec.x = input->getCursorPosY() - Al_Global::SCREEN_HEIGHT / 2;

			rotate *= quaternion_angle_axis(rotate_vec.y, vector3(0, 1, 0));
			rotate *= quaternion_angle_axis(rotate_vec.x, vector3_cross(vector3(0, 1, 0), vector3_be_rotated_by_quaternion(vector3(0, 0, 1), transform->local_orient)).unit_vect());

			input->setCursorPos(Al_Global::SCREEN_WIDTH / 2, Al_Global::SCREEN_HEIGHT / 2);
		}
		else {
			float rotate_pow = 100 * Al_Global::elapsed_time;
			vector3 rotate_vec = vector3(0, 0, 0);
			if (input->getKeyState(Key::I))rotate_vec += vector3(-1, 0, 0);
			if (input->getKeyState(Key::K))rotate_vec += vector3(+1, 0, 0);
			if (input->getKeyState(Key::J))rotate_vec += vector3(0, -1, 0);
			if (input->getKeyState(Key::L))rotate_vec += vector3(0, +1, 0);

			rotate *= quaternion_angle_axis(rotate_vec.y, vector3(0, 1, 0));
			rotate *= quaternion_angle_axis(rotate_vec.x, vector3_cross(vector3(0, 1, 0), vector3_be_rotated_by_quaternion(vector3(0, 0, 1), transform->local_orient)).unit_vect());

		}

		//カメラの移動
		{
			vector3 move_vec = vector3(0, 0, 0);
			float   move_pow = 10 * Al_Global::elapsed_time;
			if (input->getKeyState(Key::W))move_vec += vector3(0, 0, +1);
			if (input->getKeyState(Key::S))move_vec += vector3(0, 0, -1);
			if (input->getKeyState(Key::D))move_vec += vector3(+1, 0, 0);
			if (input->getKeyState(Key::A))move_vec += vector3(-1, 0, 0);

			//いらない回転を除く
			vector3 eu = transform->local_orient.euler();
			quaternion y_axis_rotate = quaternion_from_euler(0, eu.y, 0);
			position += vector3_be_rotated_by_quaternion(move_vec, y_axis_rotate).unit_vect() * move_pow;

			//y軸方向の移動
			if (input->getKeyState(Key::Space))position += vector3(0, 1, 0) * move_pow;
			if (input->getKeyState(Key::LeftShift))position += vector3(0, -1, 0) * move_pow;
		}

		transform->local_pos += position;
		transform->local_orient *= rotate;


		if (input->getKeyTrigger(Key::P))
			camera_Global::set_carsol_stop == true ?
			camera_Global::set_carsol_stop = false, input->setCursorPos(Al_Global::SCREEN_WIDTH / 2, Al_Global::SCREEN_HEIGHT / 2) :
			camera_Global::set_carsol_stop = true, input->setCursorPos(Al_Global::SCREEN_WIDTH / 2, Al_Global::SCREEN_HEIGHT / 2);

	}

	// このスクリプトがアタッチされているGOのactiveSelfがtrueになった時呼ばれる
	void camera_Free::onEnable()
	{

	}

	// このスクリプトがアタッチされているGOのactiveSelfがfalseになった時呼ばれる
	void camera_Free::onDisable()
	{

	}

}
