
#include "../Adollib/systems.h"
#include "../Adollib/Adollib.h"
#include "../Adollib/transform.h"
#include "../Adollib/gameobject_manager.h"
#include "camera_global.h"
#include "camera_Follow.h"

namespace Adollib
{

	// 所属するシーンの初期化時に一度だけ呼ばれる
	void camera_Follow::awake()
	{

	}

	void camera_Follow::start()
	{

	}

	// 毎フレーム呼ばれる更新処理
	void camera_Follow::update()
	{

			//カメラの回転
			if (camera_Global::set_carsol_stop == false) 
				input->setCursorPos(Al_Global::SCREEN_WIDTH / 2, Al_Global::SCREEN_HEIGHT / 2);	
			
			//カメラの移動
			{
				transform->local_pos = player->local_pos + vector3(0, 50, -10);
			}
			transform->local_orient = quaternion_look_at(transform->position, player->local_pos);
		if (input->getKeyTrigger(Key::P))
			camera_Global::set_carsol_stop == true ?
			camera_Global::set_carsol_stop = false, input->setCursorPos(Al_Global::SCREEN_WIDTH / 2, Al_Global::SCREEN_HEIGHT / 2) :
			camera_Global::set_carsol_stop = true, input->setCursorPos(Al_Global::SCREEN_WIDTH / 2, Al_Global::SCREEN_HEIGHT / 2);

	}

	// このスクリプトがアタッチされているGOのactiveSelfがtrueになった時呼ばれる
	void camera_Follow::onEnable()
	{

	}

	// このスクリプトがアタッチされているGOのactiveSelfがfalseになった時呼ばれる
	void camera_Follow::onDisable()
	{

	}

}
