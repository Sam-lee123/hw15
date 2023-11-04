#include <iostream>
#include "LinkedList.h"

int main()
{

	LinkedList a;
	a.Insert(12, 7);
	std::cout << a;
	a.Insert(-3, 2);
	std::cout << a;
	a.Insert(0, 4);
	std::cout << a;
	a.Insert(12, 7);
	std::cout << a;
	a.Insert(3, 17);
	std::cout << a;
	a.Insert(6, 52);
	std::cout << a;
	a.Insert(6, 76);
	std::cout << a;
	a.Erase(-1);
	std::cout << a;
	a.Erase(0);
	std::cout << a;
	a.Erase(5);
	std::cout << a;
	a.Erase(2);
	std::cout << a;



	system("PAUSE");
	return 0;

}