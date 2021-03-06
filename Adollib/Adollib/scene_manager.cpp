#include "gameobject_manager.h"

#include "scene_manager.h"
#include "scene_game.h"
#include "scene_title.h"

namespace Adollib {

	Scenelist Scene::now_scene = Scenelist::scene_null;
	Scenelist Scene::next_scene = Scenelist::scene_null;

	//::: Sceneを変更する際はここを変更 ::::::::::::::::::::::::::::::::::::::::
	void Scene_manager::initialize() {
		Scene::now_scene = Scenelist::scene_null;
		Scene::next_scene = Scenelist::scene_game;

		scenes[Scenelist::scene_game] = std::make_unique<scene_game>();
		scenes[Scenelist::scene_title] = std::make_unique<scene_title>();
	}
	//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	void Scene_manager::update() {

		if (!(Scene::now_scene == Scene::next_scene)) {

			Gameobject_manager::destroy(Scene::now_scene); //前sceneのgameobjectを削除

			Scene::now_scene = Scene::next_scene;
			if(Scene::now_scene != Scenelist::scene_null)

				scenes[Scene::now_scene]->initialize(); //次sceneのcomponentを設定

			Gameobject_manager::initialize(Scene::now_scene); //次sceneのinitializeを呼ぶ
	
		}

	}


}