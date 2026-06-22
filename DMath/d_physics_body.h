//-------------------------------------------------------------------------------------------------
// File:    d_physics_body.h
// Authors: Alec Guarino
// Project: DMath - Deterministic Math
//
// © 2026 DigiPen (USA) Corporation
//-------------------------------------------------------------------------------------------------

#pragma once

//#include <godot_cpp/classes/object.hpp>
//#include <godot_cpp/classes/node3d.hpp>
//#include <godot_cpp/classes/resource.hpp>

#include "CollisionShapes/d_col_shape.h"
#include <memory>

//using namespace godot;

enum class body_type {
	body_static = 0,		//Static for not moving
	body_kinematic = 1		//Kinematic for moving
};

enum class body_purpose {
	purpose_unimportant = 0,			//Don't do physics checks.
	purpose_scenery = 1,				//For walls and houses and shit
	purpose_character_or_tank = 2,		//For humans and vehicles that can be shot
	purpose_projectile = 3,				//For boolet
	purpose_area_detection = 4			//For if other is in place. IE King of the Hill Zone
};

class D_Physics_Body : public D_Col_Shape {
	//GDCLASS(D_Physics_Body, D_Col_Shape);

	D_Col_Shape* d_shape; // conver to unique_ptr?

	bool active = false;

protected:
	//static void _bind_methods();

	body_type my_body_type = body_type::body_static;
	body_purpose my_body_purpose = body_purpose::purpose_unimportant;

public:

	//void i_was_collided_with(D_Physics_Body* other) { emit_signal("collided_with", other); };

	body_type get_my_body_type();// { return my_body_type; };
	void set_my_body_type(body_type new_body_type);// { my_body_type = new_body_type; };

	body_purpose get_my_body_purpose();// { return my_body_purpose; };
	void set_my_body_purpose(body_purpose new_body_purpose);// { my_body_purpose = new_body_purpose; };

	D_Col_Shape* get_d_col_shape();// { return d_shape; };
	void set_d_col_shape(D_Col_Shape* new_shape);// { d_shape = new_shape; };

	bool get_active() { return active; };
	void set_active(bool new_state) { active = new_state; };

	//void translate_d_towards_local_axis(Vector3i direction);

	void update_collisions();

	//void d_initialize_mdcl();
	//virtual void _ready() override;
	D_Physics_Body();
};
