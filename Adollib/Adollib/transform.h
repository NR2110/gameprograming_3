#pragma once

#include "vector.h"
#include "quaternion.h"

#include <list>
#include <memory>

namespace Adollib {

	//描画用transfome
	class Transfome {
	public:
		vector3 scale = vector3(1, 1, 1);

		//描画用の情報 
		vector3 position = vector3(0, 0, 0);
		quaternion orientation = quaternion(1, 0, 0, 0);
		//親からの相対情報
		vector3 local_pos = vector3(0, 0, 0);
		quaternion local_orient = quaternion(1, 0, 0, 0);
		vector3 local_scale = vector3(1, 1, 1);
	};

}