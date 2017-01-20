#include <iostream>
#include <stdexcept>
#include <memory>
#include <vector>
#include <assert.h>

#include "Vector.h"
#include "ArrayPointer.h"

int main() 
{

	{
		Vector<std::string> v2;
		v2.push_back("matt");
		v2.print();
		v2.push_back("yoshi");
		v2.print();
	}

	{
		Vector<int> v;
		v.print();
		v.push_back(1);
		v.print();
		v.push_back(2);
		v.print();
		v.push_back(3);
		v.print();
		v.resize(2);
		v.print();
		v.pop_back();
		v.print();
		v.pop_back();
		v.print();
		v.pop_back();
		v.print();

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.print();
		std::cout << "front: " << v.front() << '\n';
		std::cout << "back: " << v.back() << '\n';
		std::cout << "capacity: " << v.capacity() << '\n';
		v.shrink_to_fit();
		std::cout << "capacity: " << v.capacity() << '\n';
	}

	{
		Vector<char> v;
		v.push_back('a');
		assert(v[0] == 'a');
		v.print();
	}

	{
			Vector<int> v;
			v.front();
			v.back();
			v.shrink_to_fit();
	}
	


	return 0;
}
