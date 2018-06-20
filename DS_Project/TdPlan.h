#pragma once



#include "Todo.h"
#include "PQueue.h"


class TdPlan : public PQueue<Todo>
{
public:
	TdPlan();
	~TdPlan();

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
		Function : std의 값을 설정하는 함수
		Pre : X
		Post : std의 값을 설정함
	*/
	void initialize();

private:
	Type std;
};

