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
		Function : std를 반환하는 함수
		Pre : std가 초기화되어있어야 함
		Post : std를 return함
	*/
	Type get_std();

	/*
		Function : std의 값을 설정하는 함수
		Pre : X
		Post : std의 값을 설정함
	*/
	void set_std(Type new_std);

	/*
		Function : TdSearch를 초기화하는 함수
		Pre : X
		Post : TdSearch를 초기화함
	*/
	void initialize();

	bool search_todo_by_std(TdList& list);

private:
	Type std;
};

