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
		Function : idx��°�� �ִ� Todo�� info�� ����ϴ� �Լ�
		Pre : List�� �ʱ�ȭ�Ǿ��־�� ��
		Post : idx��°�� �ִ� Todo�� info�� ���
	*/
	void print_todo_info(int idx);

	/*
		Function : idx��°�� �ִ� Todo�� �����ϴ� �Լ�
		Pre : List�� �ʱ�ȭ�Ǿ��־�� ��
		Post : idx��°�� �ִ� Todo�� �����ϴ� �Լ�
	*/
	void modify_todo(int idx);

	/*
		Function : idx��°�� �ִ� Todo�� �����ϴ� �Լ�
		Pre : List�� �ʱ�ȭ�Ǿ��־�� ��
		Post : idx��°�� �ִ� Todo�� �����ϴ� �Լ�
	*/
	void delete_todo(int idx);

	/*
		Function : idx_cnt�� return�ϴ� �Լ�
		Pre : X
		Post : idx_cnt�� return��
	*/
	int get_idx_cnt();

	/*
		Function : idx_cnt�� new_idx�� �����ϴ� �Լ�
		Pre : X
		Post : idx_cnt�� new_idx�� ������
	*/
	void set_idx_cnt(int new_idx);

private:
	int idx_cnt;
};

