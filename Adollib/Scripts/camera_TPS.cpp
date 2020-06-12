
#include "../Adollib/systems.h"
#include "../Adollib/Adollib.h"
#include "../Adollib/transform.h"
#include "../Adollib/gameobject_manager.h"
#include "camera_global.h"
#include "camera_TPS.h"

namespace Adollib
{

	// ��������V�[���̏��������Ɉ�x�����Ă΂��
	void camera_TPS::awake()
	{

	}

	void camera_TPS::start()
	{

	}

	// ���t���[���Ă΂��X�V����
	void camera_TPS::update()
	{
		vector3 position = vector3(0, 0, 0);
		quaternion rotate = quaternion_identity();

		if (camera_Global::set_carsol_stop == false) input->setCursorPos(Al_Global::SCREEN_WIDTH / 2, Al_Global::SCREEN_HEIGHT / 2);

		{
			vector3 TPS = vector3(0, 20, -40);
			transform->local_pos = player->local_pos + vector3_be_rotated_by_quaternion(TPS, player->local_orient);
			transform->local_orient = quaternion_look_at(transform->local_pos, player->local_pos);
		}

		if (input->getKeyTrigger(Key::P))
			camera_Global::set_carsol_stop == true ?
			camera_Global::set_carsol_stop = false, input->setCursorPos(Al_Global::SCREEN_WIDTH / 2, Al_Global::SCREEN_HEIGHT / 2) :
			camera_Global::set_carsol_stop = true, input->setCursorPos(Al_Global::SCREEN_WIDTH / 2, Al_Global::SCREEN_HEIGHT / 2);

	}

	// ���̃X�N���v�g���A�^�b�`����Ă���GO��activeSelf��true�ɂȂ������Ă΂��
	void camera_TPS::onEnable()
	{

	}

	// ���̃X�N���v�g���A�^�b�`����Ă���GO��activeSelf��false�ɂȂ������Ă΂��
	void camera_TPS::onDisable()
	{

	}

}
