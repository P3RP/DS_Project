#pragma once

#include <string>

using std::string;

class Todo
{
public:
	/*
		Function : 생성자
		Pre : X
		Post : 객체 생성
	*/
	Todo();

	/*
		Function : 소멸자
		Pre : X
		Post : 객체 소멸
	*/
	~Todo();

	/*
		Function : 복사 생성자
		Pre : X
		Post : other의 정보를 가진 객체 생성
	*/
	Todo(const Todo& other);

	/*
		Function : 대입 연산자
		Pre : X
		Post : 객체가 other의 정보를 가짐
	*/
	Todo& operator=(const Todo& other);

	/*
		[ Get Function ]
		Function : Todo 객체의 value를 get하는 함수
		Pre : Value가 초기화되어있어야 함
		Post : Value의 값을 return함
	*/
	int get_idx();
	string get_title();
	string get_content();
	int get_time();
	string get_deadline();
	int get_priority();
	bool get_fin();

	/*
		[ Set Function ]
		Function : Todo 객체의 value의 값을 설정하는 함수
		Pre : X
		Post : Value의 값가 해당 파라미터의 값으로 설정됨
	*/
	void set_idx(int new_idx);
	void set_title(string new_title);
	void set_content(string new_content);
	void set_time(int new_time);
	void set_deadline(string new_deadline);
	void set_priority(int new_priority);
	void set_fin(bool new_fin);

private:
	int idx;
	string title;
	string content;
	int time;
	string deadline;
	int priority;
	bool fin;
};

