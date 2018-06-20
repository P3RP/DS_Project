#pragma once

#include <iostream>
#include <string>
#include <Windows.h>

#include "TdList.h"
#include "TdPlan.h"
#include "TdSearch.h"
#include "Todo.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Application
{
public:
	Application();
	~Application();

	/*
		Function : Application�� �����ϴ� �Լ�
		Pre : X
		Post : Application�� ���۵ȴ�.
	*/
	void start();

private:
	/*
		Function : Title�� �ֿܼ� ����ϴ� �Լ�
		Pre : X
		Post : Console�� Title�� �����
	*/
	void _title();

	/*
		Function : Main Interface�� �ֿܼ� ����ϴ� �Լ�
		Pre : X
		Post : Console�� Main Interface�� �����
	*/
	void _main_interface();

	/*
		Function : List Interface�� �ֿܼ� ����ϴ� �Լ�
		Pre : X
		Post : Console�� List Interface�� �����
	*/
	void _list_interface();

private:
	TdList td_list;
};

