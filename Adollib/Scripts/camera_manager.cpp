
#include "../Adollib/gameobject_manager.h"

#include "camera_manager.h"
#include <DirectXMath.h>

#include "../Adollib/Adollib.h"

#include "camera_FPS.h"
#include "camera_TPS.h"
#include "camera_Follow.h"
#include "camera_Surveillance.h"
#include "camera_Free.h"


namespace Adollib
{
	// 所属するシーンの初期化時に一度だけ呼ばれる
	void camera_manager_s::awake() {
		player = Gameobject_manager::find("player")->transform;
		now_type = camera_types::Free;
		set_camera(camera_types::Free, vector3(0, 0, -20), vector3(0, 0, 1));
		set_camera(camera_types::First_P, vector3(0, 0, -20), vector3(0, 0, 1));
		set_camera(camera_types::Follow, vector3(0, 0, -20), vector3(0, 0, 1));
		set_camera(camera_types::Surveillance, vector3(0, 0, -20), vector3(0, 0, 1));
		set_camera(camera_types::Third_P, vector3(0, 0, -20), vector3(0, 0, 1));
	}

	void camera_manager_s::start()
	{
		//	set_camera(vector3(0, 0, 20), vector3(0, 0, 1));
	}

	// 毎フレーム呼ばれる更新処理
	void camera_manager_s::update()
	{
		if (input->getKeyTrigger(Key::Q)) {
			int C = static_cast<int>(now_type);
			C++;
			now_type = static_cast<camera_types>(C % static_cast<int>(camera_types::camera_types_size));
		}
		for (int i = 0; i < cameras.size(); i++) {
			if (cameras[i]->camera_type != now_type) cameras[i]->gameobject->set_active(false);
			else cameras[i]->gameobject->set_active(true);
		}

		if (input->getKeyTrigger(Key::C)) {
			Al_Global::render_collider_flag = Al_Global::render_collider_flag == false ? true : false;
		}
	}

	// このスクリプトがアタッチされているGOのactiveSelfがtrueになった時呼ばれる
	void camera_manager_s::onEnable()
	{

	}

	// このスクリプトがアタッチされているGOのactiveSelfがfalseになった時呼ばれる
	void camera_manager_s::onDisable()
	{

	}

}


namespace Adollib {
	void camera_manager_s::set_camera(camera_types type, vector3 pos, vector3 look_pos) {
		Camera* camera = nullptr;
		camera = Gameobject_manager::create_camera("camera");

		camera->active = false;
		camera->transform->local_pos = pos;
		camera->transform->local_orient = quaternion_look_at(pos, look_pos);
		camera_base* C = nullptr;

		switch (type)
		{
		case Adollib::camera_types::Surveillance:
			C = camera->addComponent<camera_Surveillance>();
			C->camera_type = camera_types::Surveillance;
			break;
		case Adollib::camera_types::Follow:
			C = camera->addComponent<camera_Follow>();
			C->camera_type = camera_types::Follow;
			break;
		case Adollib::camera_types::Third_P:
			C = camera->addComponent<camera_TPS>();
			C->camera_type = camera_types::Third_P;
			break;
		case Adollib::camera_types::First_P:
			C = camera->addComponent<camera_FPS>();
			C->camera_type = camera_types::First_P;
			break;
		case Adollib::camera_types::Free:
			C = camera->addComponent<camera_Free>();
			C->camera_type = camera_types::Free;
			break;
		default:
			C = camera->addComponent<camera_Free>();
			C->camera_type = camera_types::Free;
			break;
		}
		C->player = player;
		cameras.push_back(C);

		//camera->transform->local_position = pos.get_XM3();
		//camera->transform->local_rotation = quaternion_look_at(pos, vector3(0, 0, 0)).euler().get_XM3();
		//camera->transform->position = pos.get_XM3();
		//camera->transform->position = DirectX::XMFLOAT3(0, 0, 0);

	}
}