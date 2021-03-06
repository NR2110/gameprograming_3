#pragma once

#include "../Adollib/component_camera.h"
#include "../Adollib/rigit_body.h"
#include "camera_s.h"


namespace Adollib
{
	class camera_Free : public camera_base
	{
	public:

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