#pragma once

#include <iostream>
#include <string>
#include <Windows.h>

#include "TdList.h"
#include "TdSearch.h"
#include "TdPlan.h"
#include "Todo.h"

using std::cout;
using std::cin;
using std::endl;

using std::string;
using std::getline;

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
		[ Interface ]
	*/

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


	/*
		[ Todo List ]
	*/

	/*
		Function : Todo를 조회하는 함수
		Pre : Todo가 초기화되어있어야 함
		Post : Todo의 info를 조회함
	*/
	void _get_todo_info();

	/*
		Function : Todo를 수정하는 함수
		Pre : Todo가 초기화되어있어야 함
		Post : Todo의 info를 수정함
	*/
	void _change_todo_info();

	/*
		Function : Todo를 조회하는 함수
		Pre : Todo가 초기화되어있어야 함
		Post : Todo의 info를 조회함
	*/
	void _delete_todo();


	/*
		[ Todo Search ]
	*/

	/*
		Function : td_list의 Todo를 통해 td_srch를 update하는 함수
		Pre : td_list가 초기화되어야 함
		Post : td_srch를 update함
	*/
	void _updt_td_srch();

	/*
		Function : td_srch에서 검색 기준을 토대로 검색을 함 
		Pre : td_srch가 초기화되어있어야 함
		Post : 검색 결과를 제공해줌
	*/
	void _search_todo();

private:
	TdList td_list;
	TdSearch td_srch;
};

