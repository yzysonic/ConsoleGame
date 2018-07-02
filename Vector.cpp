#include "Vector.h"
#include <math.h>

const Vector2 Vector2::zero(0.0f, 0.0f);
const Vector2 Vector2::one(1.0f, 1.0f);

Vector2 Vector2::Lerp(Vector2 const& a, Vector2 const& b, float t)
{
	if (t >= 1)
		return b;
	else if (t <= 0)
		return a;
	else
		return (a + (b - a)*t);
}

float Vector2::Dot(Vector2 const& a, Vector2 const& b)
{
	return a.x * b.x + a.y * b.y;
}

float Vector2::Cross(Vector2 const & a, Vector2 const & b)
{
	return a.x * b.y - a.y * b.x;
}

Vector2 & Vector2::operator+=(const Vector2 v)
{
	this->x += v.x;
	this->y += v.y;
	return *this;
}

Vector2 & Vector2::operator-=(const Vector2 v)
{
	this->x -= v.x;
	this->y -= v.y;
	return *this;
}

Vector2 & Vector2::operator*=(const float f)
{
	this->x *= f;
	this->y *= f;
	return *this;
}

Vector2 & Vector2::operator/=(const float f)
{
	this->x /= f;
	this->y /= f;
	return *this;
}

Vector2 Vector2::operator+(void) const
{
	return *this;
}

Vector2 Vector2::operator-(void) const
{
	return Vector2(-this->x, -this->y);
}

Vector2 Vector2::operator+(const Vector2 v) const
{
	return Vector2(this->x + v.x, this->y + v.y);
}

Vector2 Vector2::operator-(const Vector2 v) const
{
	return Vector2(this->x - v.x, this->y - v.y);
}

Vector2 Vector2::operator*(const float f) const
{
	return Vector2(this->x * f, this->y * f);
}

Vector2 Vector2::operator/(const float f) const
{
	return Vector2(this->x / f, this->y / f);
}

bool Vector2::operator==(const Vector2 v) const
{
	return (this->x == v.x) && (this->y == v.y);
}

bool Vector2::operator!=(const Vector2 v) const
{
	return (this->x != v.x) || (this->y != v.y);
}

Vector2::Vector2() : Vector2(Vector2::zero) {}

Vector2::Vector2(const Vector2 & vector2)
{
	*this = vector2;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Vector2::length(void)
{
	return sqrtf(this->x * this->x + this->y * this->y);
}

float Vector2::sqrLength(void)
{
	return this->x * this->x + this->y * this->y;
}

Vector2 Vector2::normalized(void)
{
	float m = this->length();
	return Vector2(this->x / m, this->y / m);
}

Vector2 operator*(float f, const Vector2 & v)
{
	return v * f;
}
