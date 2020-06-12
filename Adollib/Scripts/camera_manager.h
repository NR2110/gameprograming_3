#pragma once

#include "../Adollib/component.h"
#include "../Adollib/rigit_body.h"
#include "camera_s.h"

namespace Adollib
{
	class camera_manager_s : public Component
	{
	private:
		std::vector<camera_base*> cameras;
		Transfome* player;

	public:
		void set_camera(camera_types type, vector3 pos, vector3 look_pos);
		camera_types now_type;

	public:
		void awake();

		// 所属するシーンの初期化時に一度だけ呼ばれる
		void start();

		// 毎フレーム呼ばれる更新処理
		void update();

		// このスクリプトがアタッチされているGOのactiveSelfがtrueになった時呼ばれる
		void onEnable();

		// このスクリプトがアタッチされているGOのactiveSelfがfalseになった時呼ばれる
		void onDisable();

	};

}