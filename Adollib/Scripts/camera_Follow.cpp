
#include "../Adollib/systems.h"
#include "../Adollib/Adollib.h"
#include "../Adollib/transform.h"
#include "../Adollib/gameobject_manager.h"
#include "camera_global.h"
#include "camera_Follow.h"

namespace Adollib
{

	// ��������V�[���̏��������Ɉ�x�����Ă΂��
	void camera_Follow::awake()
	{

	}

	void camera_Follow::start()
	{

	}

	// ���t���[���Ă΂��X�V����
	void camera_Follow::update()
	{

			//�J�����̉�]
			if (camera_Global::set_carsol_stop == false) 
				input->setCursorPos(Al_Global::SCREEN_WIDTH / 2, Al_Global::SCREEN_HEIGHT / 2);	
			
			//�J�����̈ړ�
			{
				transform->local_pos = player->local_pos + vector3(0, 50, -10);
			}
			transform->local_orient = quaternion_look_at(transform->position, player->local_pos);
		if (input->getKeyTrigger(Key::P))
			camera_Global::set_carsol_stop == true ?
			camera_Global::set_carsol_stop = false, input->setCursorPos(Al_Global::SCREEN_WIDTH / 2, Al_Global::SCREEN_HEIGHT / 2) :
			camera_Global::set_carsol_stop = true, input->setCursorPos(Al_Global::SCREEN_WIDTH / 2, Al_Global::SCREEN_HEIGHT / 2);

	}

	// ���̃X�N���v�g���A�^�b�`����Ă���GO��activeSelf��true�ɂȂ������Ă΂��
	void camera_Follow::onEnable()
	{

	}

	// ���̃X�N���v�g���A�^�b�`����Ă���GO��activeSelf��false�ɂȂ������Ă΂��
	void camera_Follow::onDisable()
	{

	}

}
