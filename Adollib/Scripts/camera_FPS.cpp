
#include "../Adollib/systems.h"
#include "../Adollib/Adollib.h"
#include "../Adollib/transform.h"
#include "../Adollib/gameobject_manager.h"
#include "camera_global.h"
#include "camera_FPS.h"

namespace Adollib
{

	// 所属するシーンの初期化時に一度だけ呼ばれる
	void camera_FPS::awake()
	{

	}

	void camera_FPS::start()
	{

	}

	// 毎フレーム呼ばれる更新処理
	void camera_FPS::update()
	{

		vector3 position = vector3(0, 0, 0);
		quaternion rotate = quaternion_identity();

		if (camera_Global::set_carsol_stop == false) input->setCursorPos(Al_Global::SCREEN_WIDTH / 2, Al_Global::SCREEN_HEIGHT / 2);
		
		{
			transform->local_orient = player->local_orient;
			transform->local_pos = player->local_pos + vector3(0, 4, 0);
		}

		if (input->getKeyTrigger(Key::P))
			camera_Global::set_carsol_stop == true ?
			camera_Global::set_carsol_stop = false, input->setCursorPos(Al_Global::SCREEN_WIDTH / 2, Al_Global::SCREEN_HEIGHT / 2) :
			camera_Global::set_carsol_stop = true, input->setCursorPos(Al_Global::SCREEN_WIDTH / 2, Al_Global::SCREEN_HEIGHT / 2);

	}

	// このスクリプトがアタッチされているGOのactiveSelfがtrueになった時呼ばれる
	void camera_FPS::onEnable()
	{

	}

	// このスクリプトがアタッチされているGOのactiveSelfがfalseになった時呼ばれる
	void camera_FPS::onDisable()
	{

	}

}
