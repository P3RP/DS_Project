#include "TdSearch.h"



TdSearch::TdSearch()
{
}


TdSearch::~TdSearch()
{
}

Type TdSearch::get_std()
{
	return std;
}

void TdSearch::set_std(Type new_std)
{
	std = new_std;
}

void TdSearch::initialize()
{
	make_empty();
	std = TTL;
}

bool TdSearch::search_todo_by_std(TdList & list)
{
	Todo temp;
	temp.set_chk(std);

	cout << "\t=========== SEARCH ===========" << endl;
	switch (std)
	{
	case IDX:
	{
		int srch_idx;
		cout << "\t검색어 입력 >> ";
		cin >> srch_idx;
		temp.set_idx(srch_idx);

		if (retrieve_item(temp))
		{
			list.insert_item(temp);
			return true;
		}
		else
		{
			return false;
		}

		break;
	}
	case TTL:
	{
		string srch_title;
		cout << "\t검색어 입력 >> ";
		getline(cin, srch_title);
		getline(cin, srch_title);
		temp.set_title(srch_title);

		if (retrieve_item(temp))
		{
			list.insert_item(temp);
			return true;
		}
		else
		{
			return false;
		}

		break;
	}
	case CNTT:
	{
		string srch_content;
		cout << "\t검색어 입력 >> ";
		getline(cin, srch_content);
		getline(cin, srch_content);
		temp.set_content(srch_content);

		if (retrieve_item(temp))
		{
			list.insert_item(temp);
			return true;
		}
		else
		{
			return false;
		}

		break;
	}
	case TIME:
	{
		int srch_time;
		cout << "\t검색어 입력 >> ";
		cin >> srch_time;
		temp.set_time(srch_time);

		if (retrieve_item(temp))
		{
			list.insert_item(temp);
			return true;
		}
		else
		{
			return false;
		}

		break;
	}
	case DDL:
	{
		string srch_deadline;
		cout << "\t검색어 입력 >> ";
		getline(cin, srch_deadline);
		getline(cin, srch_deadline);
		temp.set_deadline(srch_deadline);

		if (retrieve_item(temp))
		{
			list.insert_item(temp);
			return true;
		}
		else
		{
			return false;
		}

		break;
	}
	case PRR:
	{
		int srch_priority;
		cout << "\t검색어 입력 >> ";
		cin >> srch_priority;
		temp.set_priority(srch_priority);

		if (retrieve_item(temp))
		{
			list.insert_item(temp);
			return true;
		}
		else
		{
			return false;
		}

		break;
	}
	default:
		break;
	}
}
