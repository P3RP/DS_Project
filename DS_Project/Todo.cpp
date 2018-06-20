#include "Todo.h"



Todo::Todo()
{
	idx = -1;
	title = "";
	content = "";
	time = -1;
	deadline = "";
	priority = -1;
	fin = false;
}


Todo::~Todo()
{
}

Todo::Todo(const Todo & other)
{
	idx = other.idx;
	title = other.title;
	content = other.content;
	time = other.time;
	deadline = other.deadline;
	priority = other.priority;
	fin = other.fin;
}

Todo & Todo::operator=(const Todo & other)
{
	idx = other.idx;
	title = other.title;
	content = other.content;
	time = other.time;
	deadline = other.deadline;
	priority = other.priority;
	fin = other.fin;

	return *this;
}

int Todo::get_idx()
{
	return idx;
}

string Todo::get_title()
{
	return title;
}

string Todo::get_content()
{
	return content;
}

int Todo::get_time()
{
	return time;
}

string Todo::get_deadline()
{
	return deadline;
}

int Todo::get_priority()
{
	return priority;
}

bool Todo::get_fin()
{
	return fin;
}

void Todo::set_idx(int new_idx)
{
	idx = new_idx;
}

void Todo::set_title(string new_title)
{
	title = new_title;
}

void Todo::set_content(string new_content)
{
	content = new_content;
}

void Todo::set_time(int new_time)
{
	time = new_time;
}

void Todo::set_deadline(string new_deadline)
{
	deadline = new_deadline;
}

void Todo::set_priority(int new_priority)
{
	priority = new_priority;
}

void Todo::set_fin(bool new_fin)
{
	fin = new_fin;
}

bool Todo::operator==(const Todo & other)
{
	return (title == other.title);
}
