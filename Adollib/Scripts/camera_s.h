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

		// ��������V�[���̏��������Ɉ�x�����Ă΂��
		virtual void start() {};

		// ���t���[���Ă΂��X�V����
		virtual void update() {};

		// ���̃X�N���v�g���A�^�b�`����Ă���GO��activeSelf��true�ɂȂ������Ă΂��
		virtual void onEnable() {};

		// ���̃X�N���v�g���A�^�b�`����Ă���GO��activeSelf��false�ɂȂ������Ă΂��
		virtual void onDisable() {};

	};

}