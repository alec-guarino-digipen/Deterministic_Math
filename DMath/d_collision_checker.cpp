//-------------------------------------------------------------------------------------------------
// File:    d_collision_checker.cpp
// Authors: Alec Guarino
// Project: DMath - Deterministic Math
//
// © 2026 DigiPen (USA) Corporation
//-------------------------------------------------------------------------------------------------

#include "d_collision_checker.h"
#include "CollisionShapes/d_collision_AABB.h"
#include "CollisionShapes/d_collision_sphere.h"

//#include "d_trigonometry_helper.h"
#include "DeterministicMath.h"

#include <algorithm>

D_Collision_Check* D_Collision_Check::singleton = nullptr;

bool D_Collision_Check::d_sphere_on_sphere_collision(D_Col_Sphere* sphere1, D_Col_Sphere* sphere2) {//(Vector3i p1, int r1, Vector3i p2, int r2) {
	DVector3Di32 distance;
	distance.x = abs(sphere1->get_d_position().x - sphere2->get_d_position().x);
	distance.x *= distance.x;
	distance.y = abs(sphere1->get_d_position().y - sphere2->get_d_position().y);
	distance.y *= distance.y;
	distance.z = abs(sphere1->get_d_position().z - sphere2->get_d_position().z);
	distance.z *= distance.z;
	int idistance = distance.x + distance.y + distance.z;
	idistance = floorSqrt(idistance);//(int)std::sqrt(idistance);

	int minDistance = sphere1->get_d_radius() + sphere2->get_d_radius();
	if (minDistance > idistance) {
		return true;
	}
	//distance
	//Vector3 foobar;
	//foobar.direction_to

	return false;
}

//Maybe do if (box1.max < box2.min || box1.min > box2.max) for less calculations?
bool D_Collision_Check::d_aabb_on_aabb_collision(D_Col_AABB* box1, D_Col_AABB* box2) {


	// return (
	//     box1->get_x_min() <= box2->get_x_max() && box1->get_x_max() >= box2->get_x_min() &&
	//     box1->get_y_min() <= box2->get_y_max() && box1->get_y_max() >= box2->get_y_min() &&
	//     box1->get_z_min() <= box2->get_z_max() && box1->get_z_max() >= box2->get_z_min()
	// );

	//bool colliding = false;
	//Check if box1 collides with box2
	if (box1->get_x_max() >= box2->get_x_min() &&
		box1->get_x_max() <= box2->get_x_max() ||

		box1->get_x_min() >= box2->get_x_min() &&
		box1->get_x_min() <= box2->get_x_max() ||

		//Check if box2 collides with box1
		box2->get_x_max() >= box1->get_x_min() &&
		box2->get_x_max() <= box1->get_x_max() ||

		box2->get_x_min() >= box1->get_x_min() &&
		box2->get_x_min() <= box1->get_x_max()) {
		// X is colliding
			//colliding = true;
	}
	else {
		return false;
	}


	if (box1->get_y_max() >= box2->get_y_min() &&
		box1->get_y_max() <= box2->get_y_max() ||

		box1->get_y_min() >= box2->get_y_min() &&
		box1->get_y_min() <= box2->get_y_max() ||

		//Check if box2 collides with box1
		box2->get_y_max() >= box1->get_y_min() &&
		box2->get_y_max() <= box1->get_y_max() ||

		box2->get_y_min() >= box1->get_y_min() &&
		box2->get_y_min() <= box1->get_y_max()) {
		// X is colliding
			//colliding = true;
	}
	else {
		return false;
	}


	if (box1->get_z_max() >= box2->get_z_min() &&
		box1->get_z_max() <= box2->get_z_max() ||

		box1->get_z_min() >= box2->get_z_min() &&
		box1->get_z_min() <= box2->get_z_max() ||

		//Check if box2 collides with box1
		box2->get_z_max() >= box1->get_z_min() &&
		box2->get_z_max() <= box1->get_z_max() ||

		box2->get_z_min() >= box1->get_z_min() &&
		box2->get_z_min() <= box1->get_z_max()) {
		// X is colliding
			//colliding = true;
	}
	else {
		return false;
	}

	return true;
}

bool D_Collision_Check::d_sphere_on_aabb_collision(D_Col_Sphere* sphere1, D_Col_AABB* box2) {
	int closest_box_x = std::max(box2->get_x_min(), std::min(sphere1->get_d_position().x, box2->get_x_max()));
	int closest_box_y = std::max(box2->get_y_min(), std::min(sphere1->get_d_position().y, box2->get_y_max()));
	int closest_box_z = std::max(box2->get_z_min(), std::min(sphere1->get_d_position().z, box2->get_z_max()));

	int distance_x = closest_box_x - sphere1->get_d_position().x;
	int distance_y = closest_box_y - sphere1->get_d_position().y;
	int distance_z = closest_box_z - sphere1->get_d_position().z;

	int d_squared = distance_x * distance_x + distance_y * distance_y + distance_z * distance_z;
	int radius_squared = sphere1->get_d_radius() * sphere1->get_d_radius();

	return d_squared <= radius_squared;
}

std::int32_t D_Collision_Check::Distancei(DVector3Di32 p1, DVector3Di32 p2) {
	DVector3Di32 distance;
	distance.x = abs(p1.x - p2.x);
	distance.x *= distance.x;
	distance.y = abs(p1.y - p2.y);
	distance.y *= distance.y;
	distance.z = abs(p1.z - p2.z);
	distance.z *= distance.z;
	int idistance = distance.x + distance.y + distance.z;
	idistance = floorSqrt(idistance);
	return idistance;
}

D_Collision_Check::D_Collision_Check() {
	if (nullptr == singleton) {
		singleton = this;
	}
}

int D_Collision_Check::floorSqrt(int n) {
	// Base cases
	if (n == 0 || n == 1) {
		return n;
	}

	int i = 1, result = 1;
	while (result <= n) {
		i++;
		result = i * i;
	}
	return i - 1;
}

