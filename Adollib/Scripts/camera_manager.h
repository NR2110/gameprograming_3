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

		// ��������V�[���̏��������Ɉ�x�����Ă΂��
		void start();

		// ���t���[���Ă΂��X�V����
		void update();

		// ���̃X�N���v�g���A�^�b�`����Ă���GO��activeSelf��true�ɂȂ������Ă΂��
		void onEnable();

		// ���̃X�N���v�g���A�^�b�`����Ă���GO��activeSelf��false�ɂȂ������Ă΂��
		void onDisable();

	};

}