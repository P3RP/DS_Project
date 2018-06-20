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
		Function : TdPlan ��ü�� value�� get�ϴ� �Լ�
		Pre : Value�� �ʱ�ȭ�Ǿ��־�� ��
		Post : Value�� ���� return��
	*/
	Type get_std();
	bool get_exist();

	/*
		[ Set Function ]
		Function : TdPlan ��ü�� value�� ���� �����ϴ� �Լ�
		Pre : X
		Post : Value�� ���� �ش� �Ķ������ ������ ������
	*/
	void set_std(Type new_std);
	void set_exist(bool new_exist);

	/*
		Function : std�� ���� �����ϴ� �Լ�
		Pre : X
		Post : std�� ���� ������
	*/
	void initialize();

private:
	Type std;
	bool exist;
};

