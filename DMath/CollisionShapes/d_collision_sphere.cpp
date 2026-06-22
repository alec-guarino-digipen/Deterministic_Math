//-------------------------------------------------------------------------------------------------
// File:    d_collision_sphere.cpp
// Authors: Alec Guarino
// Project: DMath - Deterministic Math
//
// © 2026 DigiPen (USA) Corporation
//-------------------------------------------------------------------------------------------------

#include "d_collision_sphere.h"
#include <cmath>

int D_Col_Sphere::get_d_radius() {
	return radius;
}

void D_Col_Sphere::set_d_radius(int new_radius) {
	radius = new_radius;
}

void D_Col_Sphere::update_collisions() {

}

D_Col_Sphere::D_Col_Sphere() : D_Col_Shape() {
	my_collision_shape = col_shape_sphere;
	radius = 0;
}
