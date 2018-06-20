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
		Function : Application을 시작하는 함수
		Pre : X
		Post : Application이 시작된다.
	*/
	void start();

private:
	/*
		Function : Title을 콘솔에 출력하는 함수
		Pre : X
		Post : Console에 Title를 출력함
	*/
	void _title();

	/*
		Function : Main Interface를 콘솔에 출력하는 함수
		Pre : X
		Post : Console에 Main Interface를 출력함
	*/
	void _main_interface();

	/*
		Function : List Interface를 콘솔에 출력하는 함수
		Pre : X
		Post : Console에 List Interface를 출력함
	*/
	void _list_interface();

private:
	TdList td_list;
};

