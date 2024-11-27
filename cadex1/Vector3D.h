#pragma once

class Vector3D
{
protected:
	float m_x;
	float m_y;
	float m_z;
public:
	Vector3D(float x = 0.f, float y = 0.f, float z = 0.f);
	Vector3D(const Vector3D&) = default;
	Vector3D(Vector3D&&) = default;
	Vector3D& operator=(const Vector3D&) = default;
	Vector3D& operator=(Vector3D&&) = default;
	~Vector3D() = default;
	const float& x() const { return m_x; };
	const float& y() const { return m_y; };
	const float& z() const { return m_z; };
};

