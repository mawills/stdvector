#include <iostream>
#include <stdexcept>
#include<memory>

#include "Vector.h"
#include "ArrayPointer.h"

int main() {

	ArrayPointer<int> myPointer(new int[500]);
	//int* thing = myPointer.get();

	std::unique_ptr<int> p1(new int);
	//std::unique_ptr<int> p2(p1);
	std::unique_ptr<int> p3;
	p3 = nullptr;
	Vector<int> v;
	v.push_back(1);

	v[0] = 2;

	v.resize(10);

	v.print();
	v.push_back(1);
	v.print();
	v.push_back(2);
	v.print();
	v.push_back(6);
	v.print();

	v.pop_back();
	v.print();
	v.push_back(3);
	v.print();

	std::cout << "at index 1: " << v.at(1) << " " << v[1] << std::endl;
	Vector<int> v2;

	v2 = v;
	v2.print();
	v.print();

	v2[0] = 50;
	v2.print();
	v.print();
}
