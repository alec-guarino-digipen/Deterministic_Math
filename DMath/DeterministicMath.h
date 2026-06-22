//-------------------------------------------------------------------------------------------------
// File:    DeterministicMath.h
// Authors: Alec Guarino
// Project: DMath - Deterministic Math
//
// © 2026 DigiPen (USA) Corporation
//-------------------------------------------------------------------------------------------------

#pragma once
#ifndef DeterministicMath
#define DeterministicMath



#include <cstdint>

#pragma region 2D

/// <summary>
/// NOT DETERMINISTIC!
/// </summary>
struct DVector2Df {
	float x = 0.0f;
	float y = 0.0f;
};

struct DVector2Dui8 {
	std::uint8_t x = 0;
	std::uint8_t y = 0;
};

struct DVector2Di8 {
	std::int8_t x = 0;
	std::int8_t y = 0;
};

struct DVector2Di {
	std::int32_t x = 0;
	std::int32_t y = 0;
};

struct DVector2Di16 {
	std::int16_t x = 0;
	std::int16_t y = 0;
};

#pragma endregion

#pragma region 3D

/// <summary>
/// NOT DETERMINISTIC!
/// </summary>
struct DVector3Df {
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

struct DVector3Di32 {
	std::int32_t x = 0;
	std::int32_t y = 0;
	std::int32_t z = 0;
};

struct DVector3Di16 {
	std::int16_t x = 0;
	std::int16_t y = 0;
	std::int16_t z = 0;
};

struct DVector3Di8 {
	std::int8_t x = 0;
	std::int8_t y = 0;
	std::int8_t z = 0;
};


#pragma endregion

#pragma region 4D

/// <summary>
/// NOT DETERMINISTIC!
/// </summary>
struct DVector4Df {
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	float w = 0.0f;
};

struct DMatrix4Df {
	DVector4Df columns[4];
};

#pragma endregion

#pragma region Trigonometry

inline constexpr std::int32_t RADIAN_NORMALIZER = 1000;
inline constexpr float FLOAT_RADIAN_NORMALIZER = 1000.0f;

inline constexpr std::int32_t SIN_TABLE[360] = {
	0,   17,  35,  52,  70,  87,  105, 122, 139, 156,
	174, 191, 208, 225, 242, 259, 276, 292, 309, 326,
	342, 358, 374, 390, 406, 422, 438, 453, 469, 484,
	499, 515, 529, 544, 559, 573, 587, 601, 615, 629,
	642, 656, 669, 682, 694, 707, 719, 731, 743, 755,
	766, 777, 788, 799, 809, 819, 829, 839, 848, 857,
	866, 874, 882, 890, 897, 904, 911, 918, 924, 930,
	936, 941, 946, 951, 955, 959, 963, 966, 969, 972,
	974, 976, 978, 979, 980, 981, 981, 981, 981, 980,
	979, 978, 976, 974, 972, 969, 966, 963, 959, 955,
	951, 946, 941, 936, 930, 924, 918, 911, 904, 897,
	890, 882, 874, 866, 857, 848, 839, 829, 819, 809,
	799, 788, 777, 766, 755, 743, 731, 719, 707, 694,
	682, 669, 656, 642, 629, 615, 601, 587, 573, 559,
	544, 529, 515, 499, 484, 469, 453, 438, 422, 406,
	390, 374, 358, 342, 326, 309, 292, 276, 259, 242,
	225, 208, 191, 174, 156, 139, 122, 105, 87,  70,
	52,  35,  17,

	0,  -17, -35, -52, -70, -87, -105, -122, -139, -156,
	-174, -191, -208, -225, -242, -259, -276, -292, -309, -326,
	-342, -358, -374, -390, -406, -422, -438, -453, -469, -484,
	-499, -515, -529, -544, -559, -573, -587, -601, -615, -629,
	-642, -656, -669, -682, -694, -707, -719, -731, -743, -755,
	-766, -777, -788, -799, -809, -819, -829, -839, -848, -857,
	-866, -874, -882, -890, -897, -904, -911, -918, -924, -930,
	-936, -941, -946, -951, -955, -959, -963, -966, -969, -972,
	-974, -976, -978, -979, -980, -981, -981, -981, -981, -980,
	-979, -978, -976, -974, -972, -969, -966, -963, -959, -955,
	-951, -946, -941, -936, -930, -924, -918, -911, -904, -897,
	-890, -882, -874, -866, -857, -848, -839, -829, -819, -809,
	-799, -788, -777, -766, -755, -743, -731, -719, -707, -694,
	-682, -669, -656, -642, -629, -615, -601, -587, -573, -559,
	-544, -529, -515, -499, -484, -469, -453, -438, -422, -406,
	-390, -374, -358, -342, -326, -309, -292, -276, -259, -242,
	-225, -208, -191, -174, -156, -139, -122, -105, -87,  -70,
	-52, -35, -17
};

inline int32_t get_d_sin(int32_t degrees) {
	return SIN_TABLE[degrees % 360];
}

inline std::int32_t get_d_cos(std::int32_t degrees) {
	return SIN_TABLE[(degrees + 90) % 360];
}

inline constexpr std::int32_t ARC_MINUTES_PER_DEGREE = 60;
inline constexpr std::int32_t ARC_MINUTES_PER_TURN = 21600;

inline constexpr std::int32_t degrees_to_arc_minutes(std::int32_t degrees) {
	return degrees * ARC_MINUTES_PER_DEGREE;
}

inline constexpr std::int32_t normalize_arc_minutes(std::int32_t arcMinutes) {
	const std::int32_t normalized = arcMinutes % ARC_MINUTES_PER_TURN;
	return normalized < 0 ? normalized + ARC_MINUTES_PER_TURN : normalized;
}

inline std::int32_t get_d_sin_arc_minutes(std::int32_t arcMinutes) {
	const std::int32_t normalized = normalize_arc_minutes(arcMinutes);
	const std::int32_t wholeDegrees = normalized / ARC_MINUTES_PER_DEGREE;
	const std::int32_t remainingMinutes = normalized % ARC_MINUTES_PER_DEGREE;
	const std::int32_t nextDegree = (wholeDegrees + 1) % 360;
	const std::int32_t currentValue = SIN_TABLE[wholeDegrees];
	const std::int32_t nextValue = SIN_TABLE[nextDegree];
	return currentValue +
		((nextValue - currentValue) * remainingMinutes) / ARC_MINUTES_PER_DEGREE;
}

inline std::int32_t get_d_cos_arc_minutes(std::int32_t arcMinutes) {
	return get_d_sin_arc_minutes(
		arcMinutes + degrees_to_arc_minutes(90));
}

#pragma endregion

#pragma region Linear Algebra

inline DVector3Di32 get_d_right_vector(DVector3Di32 rotation) {

	return {
	(get_d_cos(rotation.y) * get_d_cos(rotation.z)) / RADIAN_NORMALIZER,
	(get_d_cos(rotation.y) * get_d_sin(rotation.z)) / RADIAN_NORMALIZER,
	(-get_d_sin(rotation.y)) / RADIAN_NORMALIZER
	};
}

inline DVector3Di32 get_d_up_vector(DVector3Di32 rotation) {
	return {

		(get_d_sin(rotation.x) * get_d_sin(rotation.y) * get_d_cos(rotation.z) - get_d_cos(rotation.x) * get_d_sin(rotation.z)) / RADIAN_NORMALIZER,
		(get_d_sin(rotation.x) * get_d_sin(rotation.y) * get_d_sin(rotation.z) + get_d_cos(rotation.x) * get_d_cos(rotation.z)) / RADIAN_NORMALIZER,
		(get_d_sin(rotation.x) * get_d_cos(rotation.y)) / RADIAN_NORMALIZER

	};
}

inline DVector3Di32 get_d_forward_vector(DVector3Di32 rotation) {

	return {

		(get_d_cos(rotation.x) * get_d_sin(rotation.y) * get_d_cos(rotation.z) + get_d_sin(rotation.x) * get_d_sin(rotation.z)) / RADIAN_NORMALIZER,
		(get_d_cos(rotation.x) * get_d_sin(rotation.y) * get_d_sin(rotation.z) - get_d_sin(rotation.x) * get_d_cos(rotation.z)) / RADIAN_NORMALIZER,
		(get_d_cos(rotation.x) * get_d_cos(rotation.y)) / RADIAN_NORMALIZER

	};

}


inline DVector3Di32 scale_d_vector3i_in_thousands(DVector3Di32 vec, std::int32_t scale) {
	return {
		(vec.x * scale) / RADIAN_NORMALIZER,
		(vec.y * scale) / RADIAN_NORMALIZER,
		(vec.z * scale) / RADIAN_NORMALIZER
	};
}


inline DVector3Di32 d_cross_product(DVector3Di32 a, DVector3Di32 b) {
	return {
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	};
}

inline std::int32_t d_dot_product(DVector3Di32 a, DVector3Di32 b) {
	return (a.x * b.x + a.y * b.y + a.z * b.z) / RADIAN_NORMALIZER;
}

inline std::int32_t d_int_sqrt(std::int32_t value) {
	if (value <= 0) return 0;

	int64_t low = 1;
	int64_t high = value;
	int64_t result = 0;

	while (low <= high) {
		int64_t mid = (low + high) / 2;
		if (mid <= value / mid) {
			result = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return (int32_t)result;
}

inline DVector3Di32 d_normalize_vector3i(DVector3Di32 vector) {
	std::int16_t length = d_int_sqrt((vector.x * vector.x + vector.y * vector.y + vector.z * vector.z));
	if (length == 0) {
		return { 0,0,0 };
	}
	return {
		(vector.x * RADIAN_NORMALIZER) / length,
		(vector.y * RADIAN_NORMALIZER) / length,
		(vector.z * RADIAN_NORMALIZER) / length
	};
}

inline std::int32_t d_magnitude_vector3i(DVector3Di32 vector) {
	return d_int_sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}


#pragma endregion

#pragma region MatrixMath

inline float GetMatrix4DfValue(const DMatrix4Df& m, int row, int col) {
	const DVector4Df& c = m.columns[col];
	switch (row) {
	case 0: return c.x;
	case 1: return c.y;
	case 2: return c.z;
	case 3: return c.w;
	}
	return 0.0f;
}

inline void SetMatrix4DfValue(DMatrix4Df arg_matrix, int row, int col, float value) {
	DVector4Df& c = arg_matrix.columns[col];

	switch (row) {
	case 0: c.x = value; break;
	case 1: c.y = value; break;
	case 2: c.z = value; break;
	case 3: c.w = value; break;
	}

}

inline DMatrix4Df MultiplyMatrix4Df( const DMatrix4Df a, const DMatrix4Df b ) {
	DMatrix4Df returnMatrix;
	for (unsigned col = 0; col < 4; ++col) {
		for (unsigned row = 0; row < 4; ++row) {
			float sum = 0.0f;
			for (unsigned k = 0; k < 4; ++k) {
				sum += GetMatrix4DfValue(a, row, k) *
					GetMatrix4DfValue(b, k, col);
			}
			SetMatrix4DfValue( returnMatrix, row, col, sum );
		}
	}
	return returnMatrix;
}

inline DMatrix4Df MakeIdentityMatrix4Df(DMatrix4Df& arg_matrix) {
	arg_matrix.columns[0].x = 1.0f;
	arg_matrix.columns[0].y = 0.0f;
	arg_matrix.columns[0].z = 0.0f;
	arg_matrix.columns[0].w = 0.0f;

	arg_matrix.columns[1].x = 0.0f;
	arg_matrix.columns[1].y = 1.0f;
	arg_matrix.columns[1].z = 0.0f;
	arg_matrix.columns[1].w = 0.0f;

	arg_matrix.columns[2].x = 0.0f;
	arg_matrix.columns[2].y = 0.0f;
	arg_matrix.columns[2].z = 1.0f;
	arg_matrix.columns[2].w = 0.0f;

	arg_matrix.columns[3].x = 0.0f;
	arg_matrix.columns[3].y = 0.0f;
	arg_matrix.columns[3].z = 0.0f;
	arg_matrix.columns[3].w = 1.0f;

	return arg_matrix;
};

inline DMatrix4Df TranslateMatrix4Df(DMatrix4Df& arg_matrix, const DVector3Di16& arg_vec3) {
	arg_matrix.columns[3].x = (float)arg_vec3.x;
	arg_matrix.columns[3].y = (float)arg_vec3.y;
	arg_matrix.columns[3].z = (float)arg_vec3.z;
	arg_matrix.columns[3].w = 1.0f;
	return arg_matrix;
}

inline DMatrix4Df Rotate_XAxis_Matrix4Df(DMatrix4Df& arg_matrix, const DVector3Di16& rotation) {
	float cosX = get_d_cos(rotation.x) / FLOAT_RADIAN_NORMALIZER;
	float sinX = get_d_sin(rotation.x) / FLOAT_RADIAN_NORMALIZER;

	DMatrix4Df rotationMatrix;
	MakeIdentityMatrix4Df(rotationMatrix);

	rotationMatrix.columns[1].y = cosX;
	rotationMatrix.columns[1].z = sinX;

	rotationMatrix.columns[2].y = -sinX;
	rotationMatrix.columns[2].z = cosX;

	arg_matrix = MultiplyMatrix4Df(arg_matrix, rotationMatrix);

	return arg_matrix;

}

inline DMatrix4Df Rotate_YAxis_Matrix4Df(DMatrix4Df& arg_matrix, const DVector3Di16& rotation) {
	float cosY = get_d_cos(rotation.y) / FLOAT_RADIAN_NORMALIZER;
	float sinY = get_d_sin(rotation.y) / FLOAT_RADIAN_NORMALIZER;

	DMatrix4Df rotationMatrix;
	MakeIdentityMatrix4Df(rotationMatrix);

	rotationMatrix.columns[0].x = cosY;
	rotationMatrix.columns[0].z = -sinY;

	rotationMatrix.columns[2].x = sinY;
	rotationMatrix.columns[2].z = cosY;

	arg_matrix = MultiplyMatrix4Df(arg_matrix, rotationMatrix);

	return arg_matrix;

}

inline DMatrix4Df Rotate_ZAxis_Matrix4Df(DMatrix4Df& arg_matrix, const DVector3Di16& rotation) {
	float cosZ = get_d_cos(rotation.z) / FLOAT_RADIAN_NORMALIZER;
	float sinZ = get_d_sin(rotation.z) / FLOAT_RADIAN_NORMALIZER;

	DMatrix4Df rotationMatrix;
	MakeIdentityMatrix4Df(rotationMatrix);

	rotationMatrix.columns[0].x = cosZ;
	rotationMatrix.columns[0].y = sinZ;

	rotationMatrix.columns[1].x = -sinZ;
	rotationMatrix.columns[1].y = cosZ;

	arg_matrix = MultiplyMatrix4Df(arg_matrix, rotationMatrix);

	return arg_matrix;

}

inline DMatrix4Df RotateMatrix4Df(DMatrix4Df& arg_matrix, const DVector3Di16& rotation) {
	Rotate_YAxis_Matrix4Df(arg_matrix, rotation);
	Rotate_XAxis_Matrix4Df(arg_matrix, rotation);
	Rotate_ZAxis_Matrix4Df(arg_matrix, rotation);

	return arg_matrix;
}

#pragma endregion

#endif // !DeterministicMath
