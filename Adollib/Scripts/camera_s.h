#pragma once

#include "../Adollib/component_camera.h"
#include "../Adollib/rigit_body.h"

namespace Adollib
{
	enum class camera_types {
		Surveillance,
		Follow,
		Third_P,
		First_P,
		Free,
		camera_types_size
	};

	class camera_base : public Component_camera
	{
	public:
		camera_types camera_type;
		Transfome* player;

		virtual void awake() {};

		// 所属するシーンの初期化時に一度だけ呼ばれる
		virtual void start() {};

		// 毎フレーム呼ばれる更新処理
		virtual void update() {};

		// このスクリプトがアタッチされているGOのactiveSelfがtrueになった時呼ばれる
		virtual void onEnable() {};

		// このスクリプトがアタッチされているGOのactiveSelfがfalseになった時呼ばれる
		virtual void onDisable() {};

	};

}