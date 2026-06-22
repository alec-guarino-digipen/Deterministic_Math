//-------------------------------------------------------------------------------------------------
// File:    d_collision_AABB.h
// Authors: Alec Guarino
// Project: DMath - Deterministic Math
//
// © 2026 DigiPen (USA) Corporation
//-------------------------------------------------------------------------------------------------

#pragma once
#include "../DeterministicMath.h"
#include "d_col_shape.h"


class D_Col_AABB : public D_Col_Shape {
	

	int width_x;
	int height_y;
	int depth_z;

	int width_x_radius;
	int height_y_radius;
	int depth_z_radius;

protected:
	//void d_initialize();

public:
	//Vector3i get_d_dimensions() {};
	void set_d_dimensions(DVector3Di32 newDimensions);
	DVector3Di32 get_d_dimensions();

	int get_x_min();
	int get_x_max();
	int get_y_min();
	int get_y_max();
	int get_z_min();
	int get_z_max();

	int get_width_x() { return width_x; };
	int get_height_y() { return height_y; };
	int get_depth_z() { return depth_z; };

	int get_width_x_radius() { return width_x_radius; };
	int get_height_y_radius() { return height_y_radius; };
	int get_depth_z_radius() { return depth_z_radius; };
	int get_radius_along(int dimension) { switch (dimension) { case 0: return width_x_radius; case 1: return height_y_radius; case 2: return depth_z_radius; } return 0; };
	void update_local_radius() { width_x_radius = get_width_x() / 2; height_y_radius = get_height_y() / 2; depth_z_radius = get_depth_z() / 2; };
	
	void update_collisions() override;
	D_Col_AABB();

};
