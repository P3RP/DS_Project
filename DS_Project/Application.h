#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

#include "TdList.h"
#include "TdSearch.h"
#include "TdPlan.h"
#include "Todo.h"

using std::cout;
using std::cin;
using std::endl;

using std::string;
using std::getline;

using std::ofstream;
using std::ifstream;

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


	/*
	[ Today Plan ]
	*/

	/*
		Function : td_plan의 Todo를 통해 td_plan를 update하는 함수
		Pre : td_list가 초기화되어야 함
		Post : td_plan를 update함
	*/
	void _updt_td_plan();

	/*
		Function : td_plan 내의 Todo를 조회하는 함수
		Pre : td_plan이 초기화되어야 함
		Post : td_plan 내의 Todo를 조회함
	*/
	void _check_td_plan();

	/*
		Function : now_work를 update하고 정보를 출력하는 함수
		Pre : td_plan이 초기화되어야 함
		Post : now_work를 update하고 정보를 출력함
	*/
	void _get_now_work();

	
	/*
		Function : Todo 목록을 외부 파일에서 불러오는 함수
		Pre : td_list가 초기화되어야 함
		Post : Todo 목록을 외부 파일에서 불러와 저장함
	*/
	void _get_todo_file();

	/*
		Function : Todo 목록을 외부 파일에 내보내는 함수
		Pre : td_list가 초기화되어야 함
		Post : Todo 목록을 가진 외부 파일을 생성함
	*/
	void _let_todo_file_out();

private:
	TdList td_list;
	TdSearch td_srch;
	TdPlan td_plan;
	Todo now_work;
	bool exist_now_work;
};

