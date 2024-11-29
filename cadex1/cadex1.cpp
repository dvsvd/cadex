// cadex1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _USE_MATH_DEFINES

#include <iostream>
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#include <vector>
#include <random>
#include <memory>

int main()
{
	std::vector<std::unique_ptr<ICurve>> vec;
	std::mt19937 rd;
	std::uniform_int_distribution<> rngi;
	std::uniform_real_distribution<float> rngf(0.f, 500.f);
	//Fill the vector "in random manner"
	size_t size = 4 + rngi(rd) % 12;
	vec.reserve(size);
	for (size_t i = 0; i < size; i++)
	{
		// ROLL THE DICE
		int n = rngi(rd) % 3;
		switch (n)
		{
		case 0: // Ellipse
		{
			vec.push_back(std::make_unique<Ellipse>(rngf(rd), rngf(rd)));
			break;
		}
		case 1: // Circle
			vec.push_back(std::make_unique<Circle>(rngf(rd)));
			break;
		case 2: // Helix
			vec.push_back(std::make_unique<Helix>(rngf(rd), rngf(rd)));
			break;
		default:
			break;
		}
	}
	const float t = static_cast<float>(M_PI_4);
	for (auto& e : vec)
	{
		Vector3D pt = e->point(t);
		Vector3D deriv = e->derivative(t);
		std::cout << "Curve: " << typeid(*e).name() << std::endl
			<< "Point: (" << pt.x() << "; " << pt.y() << "; " << pt.z() << ')' << std::endl
			<< "Derivative: (" << deriv.x() << "; " << deriv.y() << "; " << deriv.z() << ')' << std::endl;
	}
	return 0;
}

