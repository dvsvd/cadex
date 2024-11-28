#pragma once
#include "Vector3D.h"
#include "Ellipse.h"

class Circle : public Ellipse
{
private:
	using Ellipse::a;
	using Ellipse::b;
public:
	Circle(float radius, const Vector3D& center = Vector3D());
	~Circle() = default;
	Vector3D point(float t) override;
	std::array<Vector3D, 2> derivative(float t) override;
	const float& r() const { return m_a; };
};

