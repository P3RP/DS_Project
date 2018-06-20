#pragma once

#include <iostream>
#include <string>
#include <Windows.h>

#include "UnsortedList.h"
#include "Todo.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

class TdList : public UnsortedList<Todo>
{
public:
	TdList();
	~TdList();

	/*
		Function : List�� �ʱ�ȭ�ϴ� �Լ�
		Pre : X
		Post : List�� �ʱ�ȭ��
	*/
	void initialize_list();

	/*
		Function : ���ο� todo�� list �ȿ� �ִ� �Լ�
		Pre : X
		Post : ���ο� todo�� list �ȿ� ��
	*/
	void add_todo();

	/*
		Function : List�� item���� ����ϴ� �Լ�
		Pre : List�� �ʱ�ȭ�Ǿ��־�� ��
		Post : Todo�� ������ List���·� �����
	*/
	void print_list();

	/*
		Function : idx��°�� �ִ� Todo�� info�� ���
		Pre : List�� �ʱ�ȭ�Ǿ��־�� ��
		Post : idx��°�� �ִ� Todo�� info�� ���
	*/
	void print_todo_info(int idx);

private:
	int idx_cnt;
};

