//-------------------------------------------------------------------------------------------------
// File:    d_collision_AABB.cpp
// Authors: Alec Guarino
// Project: DMath - Deterministic Math
//
// © 2026 DigiPen (USA) Corporation
//-------------------------------------------------------------------------------------------------

#include "d_col_shape.h"
#include "d_collision_AABB.h"
//#include <cmath>



void D_Col_AABB::set_d_dimensions(DVector3Di32 newDimensions) {
	width_x = newDimensions.x; // new_width;
	height_y = newDimensions.y; // new_height;
	depth_z = newDimensions.z; // new_depth;
}

DVector3Di32 D_Col_AABB::get_d_dimensions() {
	return DVector3Di32(width_x, height_y, depth_z);
}

int D_Col_AABB::get_x_min() {
	return get_d_position().x - (width_x / 2);
}
int D_Col_AABB::get_x_max() {
	return get_d_position().x + (width_x / 2);
}
int D_Col_AABB::get_y_min() {
	return get_d_position().y - (height_y / 2);
}
int D_Col_AABB::get_y_max() {
	return get_d_position().y + (height_y / 2);
}
int D_Col_AABB::get_z_min() {
	return get_d_position().z - (depth_z / 2);
}
int D_Col_AABB::get_z_max() {
	return get_d_position().z + (depth_z / 2);
}

void D_Col_AABB::update_collisions() {
	//Unsure if I need to do anything here
}

D_Col_AABB::D_Col_AABB() : D_Col_Shape() {
	update_local_radius();
	my_collision_shape = col_shape_AABB;
}