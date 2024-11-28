// cadex1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

int main()
{
	Ellipse e(3.f, 5.f, { 1.f, -2.f, 0.f });
	auto deriv = e.derivative(5.4554f);
	Circle c(1);
	Helix h(1, 1);
	return 0;
}

