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

private:
	TdList td_list;
	TdSearch td_srch;
};

