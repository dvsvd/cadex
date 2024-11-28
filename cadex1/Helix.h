#pragma once
#include "Circle.h"
class Helix : public Circle
{
protected:
	float m_step;
public:
	Helix(float radius, float step, const Vector3D& center = Vector3D());
	~Helix() = default;
	Vector3D point(float t) override;
	std::array<Vector3D, 2> derivative(float t) override;
	const float& step() const { return m_step; };
};

