//-------------------------------------------------------------------------------------------------
// File:    d_col_shape.cpp
// Authors: Alec Guarino
// Project: DMath - Deterministic Math
//
// © 2026 DigiPen (USA) Corporation
//-------------------------------------------------------------------------------------------------

#include "d_col_shape.h"
#include <cmath>

//#include <godot_cpp/core/class_db.hpp>

//void D_Col_Shape::_bind_methods() {
//	ClassDB::bind_method(D_METHOD("get_d_position"), &D_Col_Shape::get_d_position);
//	ClassDB::bind_method(D_METHOD("set_d_position", "value"), &D_Col_Shape::set_d_position);
//	ClassDB::bind_method(D_METHOD("d_position_to_render"), &D_Col_Shape::d_position_to_render);
//
//	ClassDB::bind_method(D_METHOD("get_d_rotation"), &D_Col_Shape::get_d_rotation);
//	ClassDB::bind_method(D_METHOD("set_d_rotation", "value"), &D_Col_Shape::set_d_rotation);
//	ClassDB::bind_method(D_METHOD("d_rotation_to_render"), &D_Col_Shape::d_rotation_to_render);
//
//	ClassDB::bind_method(D_METHOD("initialize_d_transforms"), &D_Col_Shape::initialize_d_transforms);
//
//	//ClassDB::bind_method( D_METHOD("get_my_shape_type"), &D_Col_Shape::get_my_shape_type );
//	//ClassDB::bind_method( D_METHOD("set_d_position", "value"), &D_Col_Shape::set_d_position );
//
//	ADD_PROPERTY(PropertyInfo(Variant::VECTOR3I, "Position in cm"), "set_d_position", "get_d_position");
//	ADD_PROPERTY(PropertyInfo(Variant::VECTOR3I, "Rotation in degrees"), "set_d_rotation", "get_d_rotation");
//}

#pragma region position rotation basics

DVector3Di32 D_Col_Shape::get_d_position() {
	return d_pos;
}
void D_Col_Shape::set_d_position(DVector3Di32 p_value) {
	d_pos = p_value;
	//set_global_position(d_position_to_render());
}
DVector3Df D_Col_Shape::d_position_to_render() {
	DVector3Df translated = DVector3Df();
	translated.x = (d_pos.x * .01);
	translated.y = (d_pos.y * .01);
	translated.z = (d_pos.z * .01);
	return translated;
}

DVector3Di32 D_Col_Shape::get_d_rotation() {
	return d_rot;
}
void D_Col_Shape::set_d_rotation(DVector3Di32 p_value) {
	d_rot = p_value;
	//set_global_rotation_degrees(d_rotation_to_render());
}
DVector3Df D_Col_Shape::d_rotation_to_render() {
	DVector3Df translated = DVector3Df();
	translated.x = d_rot.x;//(d_rot.x * .01);
	translated.y = d_rot.y;//(d_rot.y * .01);
	translated.z = d_rot.z;//(d_rot.z * .01);
	return translated;
}

void D_Col_Shape::initialize_d_transforms() {
	//d_pos = get_global_position() * 100;
	//d_rot = get_global_rotation_degrees() * 100;
}

#pragma endregion

//void D_Col_Shape::update_collisions() {
//	// Don't think I need to do anyhting here.
//}

//void D_Col_Shape::_ready() {
//	set_global_position(d_position_to_render());
//}

D_Col_Shape::D_Col_Shape() {
	//Set_D_Position();
	d_pos = DVector3Di32(0, 0, 0);
	//d_rot = DVector3Di32(0, 0, 0);
}

