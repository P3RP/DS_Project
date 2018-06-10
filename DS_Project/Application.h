#pragma once

#include <iostream>

using std::cout;
using std::endl;

class Application
{
public:
	Application();
	~Application();

	void menu();
private:
	int selection;
};

