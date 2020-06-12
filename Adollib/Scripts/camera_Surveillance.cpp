
#include "../Adollib/systems.h"
#include "../Adollib/Adollib.h"
#include "../Adollib/transform.h"
#include "../Adollib/gameobject_manager.h"
#include "camera_global.h"
#include "camera_Surveillance.h"

namespace Adollib
{

	// ��������V�[���̏��������Ɉ�x�����Ă΂��
	void camera_Surveillance::awake()
	{

	}

	void camera_Surveillance::start()
	{

	}

	// ���t���[���Ă΂��X�V����
	void camera_Surveillance::update()
	{
		vector3 position = vector3(0, 0, 0);

		if (camera_Global::set_carsol_stop == false) input->setCursorPos(Al_Global::SCREEN_WIDTH / 2, Al_Global::SCREEN_HEIGHT / 2);
	
		
		//�J�����̈ړ�
		{
			vector3 move_vec = vector3(0, 0, 0);
			float   move_pow = 10 * Al_Global::elapsed_time;
			if (input->getKeyState(Key::W))move_vec += vector3(0, 0, +1);
			if (input->getKeyState(Key::S))move_vec += vector3(0, 0, -1);
			if (input->getKeyState(Key::D))move_vec += vector3(+1, 0, 0);
			if (input->getKeyState(Key::A))move_vec += vector3(-1, 0, 0);

			//����Ȃ���]������
			vector3 eu = transform->local_orient.euler();
			quaternion y_axis_rotate = quaternion_from_euler(0, eu.y, 0);
			position += vector3_be_rotated_by_quaternion(move_vec, y_axis_rotate).unit_vect() * move_pow;

			//y�������̈ړ�
			if (input->getKeyState(Key::Space))position += vector3(0, 1, 0) * move_pow;
			if (input->getKeyState(Key::LeftShift))position += vector3(0, -1, 0) * move_pow;
		}

		transform->local_pos += position;
		transform->local_orient = quaternion_look_at(transform->local_pos, player->local_pos);

		if (input->getKeyTrigger(Key::P))
			camera_Global::set_carsol_stop == true ?
			camera_Global::set_carsol_stop = false, input->setCursorPos(Al_Global::SCREEN_WIDTH / 2, Al_Global::SCREEN_HEIGHT / 2) :
			camera_Global::set_carsol_stop = true, input->setCursorPos(Al_Global::SCREEN_WIDTH / 2, Al_Global::SCREEN_HEIGHT / 2);

	}

	// ���̃X�N���v�g���A�^�b�`����Ă���GO��activeSelf��true�ɂȂ������Ă΂��
	void camera_Surveillance::onEnable()
	{

	}

	// ���̃X�N���v�g���A�^�b�`����Ă���GO��activeSelf��false�ɂȂ������Ă΂��
	void camera_Surveillance::onDisable()
	{

	}

}
