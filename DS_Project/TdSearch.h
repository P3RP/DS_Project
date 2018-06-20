#pragma once


#include <iostream>
#include <string>


#include "Tree.h"
#include "Todo.h"
#include "TdList.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

class TdSearch : public Tree<Todo>
{
public:
	TdSearch();
	~TdSearch();

	/*
		Function : std�� ��ȯ�ϴ� �Լ�
		Pre : std�� �ʱ�ȭ�Ǿ��־�� ��
		Post : std�� return��
	*/
	Type get_std();

	/*
		Function : std�� ���� �����ϴ� �Լ�
		Pre : X
		Post : std�� ���� ������
	*/
	void set_std(Type new_std);

	/*
		Function : TdSearch�� �ʱ�ȭ�ϴ� �Լ�
		Pre : X
		Post : TdSearch�� �ʱ�ȭ��
	*/
	void initialize();

	bool search_todo_by_std(TdList& list);

private:
	Type std;
};

