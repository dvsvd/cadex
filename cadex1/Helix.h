#pragma once
#include "Circle.h"
class Helix : public Circle
{
protected:
	float m_step;
public:
	using Ellipse::b;
	Helix(float radius, float b, const Vector3D& center = Vector3D());
	~Helix() = default;
	Vector3D point(float t) override;
	Vector3D derivative(float t) override;
	const float& step() const { return m_step; };
};

