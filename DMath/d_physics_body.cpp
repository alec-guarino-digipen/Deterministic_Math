//-------------------------------------------------------------------------------------------------
// File:    d_physics_body.cpp
// Authors: Alec Guarino
// Project: DMath - Deterministic Math
//
// © 2026 DigiPen (USA) Corporation
//-------------------------------------------------------------------------------------------------

//#include <godot_cpp/classes/engine.hpp>

//#include "d_collision_shape.h"
#include "d_physics_body.h"
#include "d_collision_checker.h"
#include "CollisionShapes/d_collision_AABB.h"
#include "CollisionShapes/d_collision_sphere.h"

#include <cmath>

//#include <godot_cpp/core/class_db.hpp>



body_type D_Physics_Body::get_my_body_type() {
	return my_body_type;
}
void D_Physics_Body::set_my_body_type(body_type new_body_type) {
	my_body_type = (body_type)new_body_type;
}

body_purpose D_Physics_Body::get_my_body_purpose() {
	return my_body_purpose;
}
void D_Physics_Body::set_my_body_purpose(body_purpose new_body_purpose) {
	my_body_purpose = (body_purpose)new_body_purpose;
}

D_Col_Shape* D_Physics_Body::get_d_col_shape() {
	return d_shape;
}
void D_Physics_Body::set_d_col_shape(D_Col_Shape* new_shape) {
	d_shape = new_shape;
}


void D_Physics_Body::update_collisions() {
	if (false == active) {
		return;
	}
	switch (d_shape->get_my_shape_type())
	{
	//case col_shape_OBB:
	//	static_cast<D_Col_OBB*>(d_shape)->update_collisions();
	//	//d_shape->update_collisions(); //static_cast<D_Col_AABB*>( get_d_col_shape() )
	//	break;
	case col_shape_AABB:
		static_cast<D_Col_AABB*>(d_shape)->update_collisions();
		break;
	case col_shape_sphere:
		static_cast<D_Col_Sphere*>(d_shape)->update_collisions();
		break;
	default:
		break;
	}
}

// void D_Physics_Body::translate_d_towards_local_axis(Vector3i direction) {
// 	// get local direction relative... add...
// 	// math.... I should learn this proper haha


// }

//void D_Physics_Body::_ready() {
//	if (Engine::get_singleton()->is_editor_hint()) {
//		printf("Skipping ready because I am in editor.");
//		return;
//	}
//
//	get_d_col_shape()->set_d_position(get_d_position());
//	get_d_col_shape()->set_d_rotation(get_d_rotation());
//
//	String node_name = get_name();
//	printf("Node name: %s\n", node_name.utf8().get_data());
//
//	if (nullptr == D_Collision_Check::get_singleton()) {
//		printf("Null pointer to D col check");
//		return;
//	}
//	printf("VALID pointer to D col check");
//
//	switch (my_body_purpose) {
//	case purpose_scenery:
//		D_Collision_Check::get_singleton()->add_to_static_bodies(this);
//		break;
//	case purpose_character_or_tank:
//		D_Collision_Check::get_singleton()->add_to_character_bodies(this);
//		break;
//	case purpose_projectile:
//		D_Collision_Check::get_singleton()->add_to_projectile_bodies(this);
//		break;
//	case purpose_area_detection:
//		D_Collision_Check::get_singleton()->add_to_area_bodies(this);
//		break;
//	case purpose_unimportant:
//		// Do nothing. Not important.
//		active = false;
//	default:
//		break;
//
//	}
//}

D_Physics_Body::D_Physics_Body() {
	//Set_D_Position();
	// d_pos = Vector3i(0,0,0);
	// d_rot = Vector3i(0,0,0);

	get_d_col_shape()->set_d_position(get_d_position());
	get_d_col_shape()->set_d_rotation(get_d_rotation());

	//std::string node_name = get_name();
	//printf("Node name: %s\n", node_name.utf8().get_data());

	if (nullptr == D_Collision_Check::get_singleton()) {
		printf("Null pointer to D col check");
		return;
	}
	printf("VALID pointer to D col check");

	switch (my_body_purpose) {
	case body_purpose::purpose_scenery:
		D_Collision_Check::get_singleton()->add_to_static_bodies(this);
		break;
	case body_purpose::purpose_character_or_tank:
		D_Collision_Check::get_singleton()->add_to_character_bodies(this);
		break;
	case body_purpose::purpose_projectile:
		D_Collision_Check::get_singleton()->add_to_projectile_bodies(this);
		break;
	case body_purpose::purpose_area_detection:
		D_Collision_Check::get_singleton()->add_to_area_bodies(this);
		break;
	case body_purpose::purpose_unimportant:
		// Do nothing. Not important.
		active = false;
	default:
		break;

	}

}

