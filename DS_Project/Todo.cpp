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
	chk = TTL;
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

Type Todo::get_chk()
{
	return chk;
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

void Todo::set_chk(Type new_type)
{
	chk = new_type;
}

bool Todo::operator==(const Todo & other)
{
	switch (chk)
	{
	case IDX:
		if (idx != other.idx)
			return false;
		else
			return true;
		break;
	case TTL:
		if (title != other.title)
			return false;
		else
			return true;
		break;
	case CNTT:
		if (content != other.content)
			return false;
		else
			return true;
		break;
	case DDL:
		if (deadline != other.deadline)
			return false;
		else
			return true;
		break;
	case PRR:
		if (priority != other.priority)
			return false;
		else
			return true;
		break;
	case FIN:
		if (fin != other.fin)
			return false;
		else
			return true;
		break;
	default:
		break;
	}
}

bool Todo::operator<=(const Todo & other)
{
	switch (chk)
	{
	case IDX:
		if (idx <= other.idx)
			return false;
		else
			return true;
		break;
	case TTL:
		if (title <= other.title)
			return false;
		else
			return true;
		break;
	case CNTT:
		if (content <= other.content)
			return false;
		else
			return true;
		break;
	case DDL:
		if (deadline <= other.deadline)
			return false;
		else
			return true;
		break;
	case PRR:
		if (priority <= other.priority)
			return false;
		else
			return true;
		break;
	case FIN:
		if (fin <= other.fin)
			return false;
		else
			return true;
		break;
	default:
		break;
	}
}

bool Todo::operator<(const Todo & other)
{
	switch (chk)
	{
	case IDX:
		if (idx < other.idx)
			return false;
		else
			return true;
		break;
	case TTL:
		if (title < other.title)
			return false;
		else
			return true;
		break;
	case CNTT:
		if (content < other.content)
			return false;
		else
			return true;
		break;
	case DDL:
		if (deadline < other.deadline)
			return false;
		else
			return true;
		break;
	case PRR:
		if (priority < other.priority)
			return false;
		else
			return true;
		break;
	case FIN:
		if (fin < other.fin)
			return false;
		else
			return true;
		break;
	default:
		break;
	}
}

bool Todo::operator>=(const Todo & other)
{
	switch (chk)
	{
	case IDX:
		if (idx >= other.idx)
			return false;
		else
			return true;
		break;
	case TTL:
		if (title >= other.title)
			return false;
		else
			return true;
		break;
	case CNTT:
		if (content >= other.content)
			return false;
		else
			return true;
		break;
	case DDL:
		if (deadline >= other.deadline)
			return false;
		else
			return true;
		break;
	case PRR:
		if (priority >= other.priority)
			return false;
		else
			return true;
		break;
	case FIN:
		if (fin >= other.fin)
			return false;
		else
			return true;
		break;
	default:
		break;
	}
}

bool Todo::operator>(const Todo & other)
{
	switch (chk)
	{
	case IDX:
		if (idx > other.idx)
			return false;
		else
			return true;
		break;
	case TTL:
		if (title > other.title)
			return false;
		else
			return true;
		break;
	case CNTT:
		if (content > other.content)
			return false;
		else
			return true;
		break;
	case DDL:
		if (deadline > other.deadline)
			return false;
		else
			return true;
		break;
	case PRR:
		if (priority > other.priority)
			return false;
		else
			return true;
		break;
	case FIN:
		if (fin > other.fin)
			return false;
		else
			return true;
		break;
	default:
		break;
	}
}
