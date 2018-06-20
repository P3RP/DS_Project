#pragma once

#include <string>

using std::string;

enum Type {
	IDX, TTL, CNTT, TIME, DDL, PRR, FIN
};

class Todo
{
public:
	/*
		Function : ������
		Pre : X
		Post : ��ü ����
	*/
	Todo();

	/*
		Function : �Ҹ���
		Pre : X
		Post : ��ü �Ҹ�
	*/
	~Todo();

	/*
		Function : ���� ������
		Pre : X
		Post : other�� ������ ���� ��ü ����
	*/
	Todo(const Todo& other);

	/*
		Function : ���� ������
		Pre : X
		Post : ��ü�� other�� ������ ����
	*/
	Todo& operator=(const Todo& other);

	/*
		[ Get Function ]
		Function : Todo ��ü�� value�� get�ϴ� �Լ�
		Pre : Value�� �ʱ�ȭ�Ǿ��־�� ��
		Post : Value�� ���� return��
	*/
	int get_idx();
	string get_title();
	string get_content();
	int get_time();
	string get_deadline();
	int get_priority();
	bool get_fin();
	Type get_chk();


	/*
		[ Set Function ]
		Function : Todo ��ü�� value�� ���� �����ϴ� �Լ�
		Pre : X
		Post : Value�� ���� �ش� �Ķ������ ������ ������
	*/
	void set_idx(int new_idx);
	void set_title(string new_title);
	void set_content(string new_content);
	void set_time(int new_time);
	void set_deadline(string new_deadline);
	void set_priority(int new_priority);
	void set_fin(bool new_fin);
	void set_chk(Type new_type);


	/*
		[ �� ������ ]
		Function : �ٸ� Todo ��ü�� ���� ���� return�ϴ� operator
		Pre : X
		Post : �ٸ� Todo ��ü�� ���� ���� return��
	*/
	bool operator== (const Todo& other);
	bool operator<= (const Todo& other);
	bool operator< (const Todo& other);
	bool operator>= (const Todo& other);
	bool operator> (const Todo& other);

private:
	int idx;
	string title;
	string content;
	int time;
	string deadline;
	int priority;
	bool fin;
	Type chk;
};

