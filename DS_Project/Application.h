#pragma once

#include <iostream>
#include <Windows.h>

#include "TdList.h"
#include "TdPlan.h"
#include "TdSearch.h"
#include "Todo.h"

using std::cout;
using std::cin;
using std::endl;

class Application
{
public:
	Application();
	~Application();

	// Function:
	// Pre:
	// Post: 
	void start();
private:
	// Print interface
	void _interface();

private:
	TdList td_list;
	TdPlan td_plan;
	TdSearch td_search;
};

