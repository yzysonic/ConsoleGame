#pragma once
#include "Common.h"

class Vector2
{
public:
	static const Vector2 zero;
	static const Vector2 one;

	static Vector2 Lerp(Vector2 const& a, Vector2 const& b, float t);
	static float Dot(Vector2 const& a, Vector2 const& b);
	static float Cross(Vector2 const& a, Vector2 const& b);
public:
	float x;
	float y;

	Vector2& operator += (const Vector2 v);
	Vector2& operator -= (const Vector2 v);
	Vector2& operator *= (const float f);
	Vector2& operator /= (const float f);

	Vector2 operator + (void) const;
	Vector2 operator - (void) const;

	Vector2 operator + (const Vector2 v) const;
	Vector2 operator - (const Vector2 v) const;
	Vector2 operator * (const float f) const;
	Vector2 operator / (const float f) const;

	friend Vector2 operator * (float f, const class Vector2& v);

	bool operator == (const Vector2 v) const;
	bool operator != (const Vector2 v) const;

	Vector2();
	Vector2(const Vector2&);
	Vector2(float x, float y);

	float length(void);
	float sqrLength(void);
	Vector2 normalized(void);
};