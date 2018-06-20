#include "TdPlan.h"



TdPlan::TdPlan()
{
	std = TTL;
	exist = false;
}


TdPlan::~TdPlan()
{
}

Type TdPlan::get_std()
{
	return std;
}

bool TdPlan::get_exist()
{
	return exist;
}

void TdPlan::set_std(Type new_std)
{
	std = new_std;
}

void TdPlan::set_exist(bool new_exist)
{
	exist = new_exist;
}

void TdPlan::initialize()
{
	make_empty();
	std = TTL;
}
