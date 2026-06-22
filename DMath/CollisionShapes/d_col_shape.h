//-------------------------------------------------------------------------------------------------
// File:    d_col_shape.h
// Authors: Alec Guarino
// Project: DMath - Deterministic Math
//
// © 2026 DigiPen (USA) Corporation
//-------------------------------------------------------------------------------------------------

#pragma once
#include "../DeterministicMath.h"

//#include <godot_cpp/classes/object.hpp>
//#include <godot_cpp/classes/node3d.hpp>
//#include <godot_cpp/classes/resource.hpp>

//using namespace godot;

enum col_shape_type {
	col_shape_none,
	col_shape_sphere,
	col_shape_AABB,
	//col_shape_OBB,
	//col_shape_mesh
};

//class D_Col_Shape : public Node3D {
class D_Col_Shape {
	//GDCLASS(D_Col_Shape, Node3D);

	DVector3Di32 d_pos;
	DVector3Di32 d_rot;

protected:
	//void d_initialize();

	col_shape_type my_collision_shape = col_shape_none;

public:
	DVector3Di32 get_d_position();
	void set_d_position(DVector3Di32 p_value);
	DVector3Df d_position_to_render();

	DVector3Di32 get_d_rotation();
	void set_d_rotation(DVector3Di32 p_value);
	DVector3Df d_rotation_to_render();

	void initialize_d_transforms();

	col_shape_type get_my_shape_type() { return my_collision_shape; };


	virtual void update_collisions() = 0;
	//virtual void _ready() override;
	D_Col_Shape();
};
