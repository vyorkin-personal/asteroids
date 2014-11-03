#pragma once

#include <cmath>

class Vector2f {
    public:
	Vector2f() = default;
	Vector2f(const float x, const float y):
	    x{x}, y{y} {}

	static const Vector2f Zero;
	static const Vector2f One;

	float dist(const Vector2f& rhs) const {
	    return hypot(rhs.x - x, rhs.y - y);
	}

	float dot(const Vector2f& rhs) const {
	    return x * rhs.x + y * rhs.y;
	}

	float cross(const Vector2f& rhs) const {
	    return x * rhs.y - y * rhs.x;
	}

	void normalize() {
	    const float mag = magnitude();
	    x = x / mag;
	    y = y / mag;
	}

	Vector2f normalized() const {
	    const float mag = magnitude();
	    return Vector2f(x / mag, y / mag);
	}

	float direction() const {
	    return atan2(x, y);
	}

	float magnitudeSquared() const {
	    return x * x + y * y;
	}

	float magnitude() const {
	    return hypot(x, y);
	}

	Vector2f& rotate(float angle) {
	    float s = sin(angle);
	    float c = cos(angle);

	    float nx = x * c - y * s;
	    float ny = x * s + y * c;

	    x = nx;
	    y = ny;

	    return *this;
	}

	bool operator == (const Vector2f& rhs) const {
	    return x == rhs.x && y == rhs.y;
	}

	bool operator != (const Vector2f& rhs) const {
	    return x != rhs.x || y != rhs.y;
	}

	Vector2f operator - () const {
	    return Vector2f(-x, -y);
	}

	Vector2f operator + (const Vector2f& rhs) const {
	    return Vector2f(x + rhs.x, y + rhs.y);
	}

	Vector2f operator + (const float value) const {
	    return Vector2f(x + value, y + value);
	}

	Vector2f operator - (const Vector2f& rhs) const {
	    return Vector2f(x - rhs.x, y - rhs.y);
	}

	Vector2f operator - (const float value) const {
	    return Vector2f(x - value, y - value);
	}

	Vector2f operator * (const Vector2f& rhs) const {
	    return Vector2f(x * rhs.x, y * rhs.y);
	}

	Vector2f operator * (const float value) const {
	    return Vector2f(x * value, y * value);
	}

	Vector2f operator / (const Vector2f& rhs) const {
	    return Vector2f(x / rhs.x, y / rhs.y);
	}

	Vector2f operator / (const float value) const {
	    return Vector2f(x / value, y / value);
	}

	Vector2f& operator += (const Vector2f& rhs) {
	    x += rhs.x;
	    y += rhs.y;
	    return *this;
	}

	Vector2f& operator -= (const Vector2f& rhs) {
	    x -= rhs.x;
	    y -= rhs.y;
	    return *this;
	}

	Vector2f& operator *= (const Vector2f& rhs) {
	    x *= rhs.x;
	    y *= rhs.y;
	    return *this;
	}

	Vector2f& operator *= (const float value) {
	    x *= value;
	    y *= value;
	    return *this;
	}

	Vector2f& operator /= (const Vector2f& rhs) {
	    x /= rhs.x;
	    y /= rhs.y;
	    return *this;
	}

	Vector2f& operator /= (const float value) {
	    x /= value;
	    y /= value;
	    return *this;
	}

	float x, y;
};

const Vector2f Vector2f::Zero = Vector2f(0.0F, 0.0F);
const Vector2f Vector2f::One = Vector2f(1.0F, 1.0F);
