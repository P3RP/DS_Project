#pragma once



#include "Todo.h"
#include "PQueue.h"


class TdPlan : public PQueue<Todo>
{
public:
	TdPlan();
	~TdPlan();

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
		Function : std�� ���� �����ϴ� �Լ�
		Pre : X
		Post : std�� ���� ������
	*/
	void initialize();

private:
	Type std;
};

