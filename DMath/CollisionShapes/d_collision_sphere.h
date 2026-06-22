//-------------------------------------------------------------------------------------------------
// File:    d_collision_sphere.h
// Authors: Alec Guarino
// Project: DMath - Deterministic Math
//
// © 2026 DigiPen (USA) Corporation
//-------------------------------------------------------------------------------------------------

#pragma once

#include "d_col_shape.h"


class D_Col_Sphere : public D_Col_Shape {

	int radius;

protected:
	//void d_initialize();

public:
	int get_d_radius();
	void set_d_radius(int new_radius);

	void update_collisions() override;
	D_Col_Sphere();
};


/*



#pragma once

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/node3d.hpp>

using namespace godot;

*/
