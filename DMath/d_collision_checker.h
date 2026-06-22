//-------------------------------------------------------------------------------------------------
// File:    d_collision_checker.h
// Authors: Alec Guarino
// Project: DMath - Deterministic Math
//
// © 2026 DigiPen (USA) Corporation
//-------------------------------------------------------------------------------------------------

#pragma once

#include <list>

#include "DeterministicMath.h"

#include "d_physics_body.h"

class D_Col_AABB;
class D_Col_OBB;
class D_Col_Sphere;

class D_Collision_Check {

	std::list<D_Physics_Body*> static_bodies;
	std::list<D_Physics_Body*> character_bodies;
	std::list<D_Physics_Body*> projectile_bodies;
	std::list<D_Physics_Body*> area_bodies;

	static D_Collision_Check* singleton;

protected:
	static void _bind_methods();

public:

	static D_Collision_Check* get_singleton() { return singleton; };

	bool d_sphere_on_sphere_collision(D_Col_Sphere* sphere1, D_Col_Sphere* sphere2);//bool d_sphere_on_sphere_collision(Vector3i p1, int r1, Vector3i p2, int r2);
	bool d_aabb_on_aabb_collision(D_Col_AABB* box1, D_Col_AABB* box2);//(const Ref<D_Col_AABB> &box1, const Ref<D_Col_AABB> &box2);//(D_Col_AABB &box1, D_Col_AABB &box2);
	bool d_obb_on_obb_collision(D_Col_OBB* box1, D_Col_OBB* box2);

	bool d_sphere_on_aabb_collision(D_Col_Sphere* sphere1, D_Col_AABB* box2);
	bool d_sphere_on_obb_collision(D_Col_Sphere* sphere1, D_Col_OBB* box2);
	bool d_obb_on_aabb_collision(D_Col_OBB* box1, D_Col_AABB* box2);


	int floorSqrt(int n);
	int Distancei(DVector3Di32 p1, DVector3Di32 p2);


	std::list<D_Physics_Body*> get_static_bodies_list() { return static_bodies; };
	std::list<D_Physics_Body*> get_character_bodies_list() { return character_bodies; };
	std::list<D_Physics_Body*> get_projectile_bodies_list() { return projectile_bodies; };
	std::list<D_Physics_Body*> get_area_bodies_list() { return area_bodies; };

	int get_character_bodies_count() { return character_bodies.size(); }

	void add_to_static_bodies(D_Physics_Body* new_body) { static_bodies.push_back(new_body); };
	void add_to_character_bodies(D_Physics_Body* new_body) { character_bodies.push_back(new_body); };
	void add_to_projectile_bodies(D_Physics_Body* new_body) { projectile_bodies.push_back(new_body); };
	void add_to_area_bodies(D_Physics_Body* new_body) { area_bodies.push_back(new_body); };

	D_Collision_Check();
};
