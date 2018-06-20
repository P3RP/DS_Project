#include "TdPlan.h"



TdPlan::TdPlan()
{
}


TdPlan::~TdPlan()
{
}

Type TdPlan::get_std()
{
	return std;
}

void TdPlan::set_std(Type new_std)
{
	std = new_std;
}

void TdPlan::initialize()
{
	make_empty();
	std = TTL;
}
