#pragma once



#include "Todo.h"
#include "PQueue.h"


class TdPlan : public PQueue<Todo>
{
public:
	TdPlan();
	~TdPlan();

	/*
		[ Get Function ]
		Function : TdPlan 객체의 value를 get하는 함수
		Pre : Value가 초기화되어있어야 함
		Post : Value의 값을 return함
	*/
	Type get_std();
	bool get_exist();

	/*
		[ Set Function ]
		Function : TdPlan 객체의 value의 값을 설정하는 함수
		Pre : X
		Post : Value의 값가 해당 파라미터의 값으로 설정됨
	*/
	void set_std(Type new_std);
	void set_exist(bool new_exist);

	/*
		Function : std의 값을 설정하는 함수
		Pre : X
		Post : std의 값을 설정함
	*/
	void initialize();

private:
	Type std;
	bool exist;
};

