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
		Function : Application�� �����ϴ� �Լ�
		Pre : X
		Post : Application�� ���۵ȴ�.
	*/
	void start();

private:
	/*
		[ Interface ]
	*/

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


	/*
		[ Todo List ]
	*/

	/*
		Function : Todo�� ��ȸ�ϴ� �Լ�
		Pre : Todo�� �ʱ�ȭ�Ǿ��־�� ��
		Post : Todo�� info�� ��ȸ��
	*/
	void _get_todo_info();

	/*
		Function : Todo�� �����ϴ� �Լ�
		Pre : Todo�� �ʱ�ȭ�Ǿ��־�� ��
		Post : Todo�� info�� ������
	*/
	void _change_todo_info();

	/*
		Function : Todo�� ��ȸ�ϴ� �Լ�
		Pre : Todo�� �ʱ�ȭ�Ǿ��־�� ��
		Post : Todo�� info�� ��ȸ��
	*/
	void _delete_todo();


	/*
		[ Todo Search ]
	*/

	/*
		Function : td_list�� Todo�� ���� td_srch�� update�ϴ� �Լ�
		Pre : td_list�� �ʱ�ȭ�Ǿ�� ��
		Post : td_srch�� update��
	*/
	void _updt_td_srch();

	/*
		Function : td_srch���� �˻� ������ ���� �˻��� �� 
		Pre : td_srch�� �ʱ�ȭ�Ǿ��־�� ��
		Post : �˻� ����� ��������
	*/
	void _search_todo();


	/*
	[ Today Plan ]
	*/

	/*
		Function : td_plan�� Todo�� ���� td_plan�� update�ϴ� �Լ�
		Pre : td_list�� �ʱ�ȭ�Ǿ�� ��
		Post : td_plan�� update��
	*/
	void _updt_td_plan();

	/*
		Function : td_plan ���� Todo�� ��ȸ�ϴ� �Լ�
		Pre : td_plan�� �ʱ�ȭ�Ǿ�� ��
		Post : td_plan ���� Todo�� ��ȸ��
	*/
	void _check_td_plan();

	/*
		Function : now_work�� update�ϰ� ������ ����ϴ� �Լ�
		Pre : td_plan�� �ʱ�ȭ�Ǿ�� ��
		Post : now_work�� update�ϰ� ������ �����
	*/
	void _get_now_work();

	
	/*
		Function : Todo ����� �ܺ� ���Ͽ��� �ҷ����� �Լ�
		Pre : td_list�� �ʱ�ȭ�Ǿ�� ��
		Post : Todo ����� �ܺ� ���Ͽ��� �ҷ��� ������
	*/
	void _get_todo_file();

	/*
		Function : Todo ����� �ܺ� ���Ͽ� �������� �Լ�
		Pre : td_list�� �ʱ�ȭ�Ǿ�� ��
		Post : Todo ����� ���� �ܺ� ������ ������
	*/
	void _let_todo_file_out();

private:
	TdList td_list;
	TdSearch td_srch;
	TdPlan td_plan;
	Todo now_work;
	bool exist_now_work;
};

