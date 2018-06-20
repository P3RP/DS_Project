#include "Application.h"



Application::Application()
{
	cout << "내부 요소 초기화 중******" << endl;
	td_list.initialize_list();
}


Application::~Application()
{
}

void Application::start()
{
	int select;
	do
	{
		_title();
		_main_interface();

		cout << "\t입력 >> ";
		cin >> select;

		switch (select)
		{
		case 0:
		{
			_title();
			cout << "\n\t종료~~~~~!!!!!" << endl;
			break;
		}
		case 1:
		{
			_title();
			td_list.add_todo();

			cout << "\n\t완료!!!!" << endl;
			break;
		}
		case 2:
		{
			int sub_select;
			do
			{
				_title();
				_list_interface();
				cout << "\t입력 >> ";
				cin >> sub_select;

				switch (sub_select)
				{
				case 0:
				{
					break;
				}
				case 1:
				{
					_get_todo_info();
					break;
				}
				case 2:
				{
					_change_todo_info();
					break;
				}
				case 3:
				{
					_delete_todo();
					break;
				}
				default:
				{
					cout << "\n\n\t다시 입력하세요!!!!" << endl;
					break;
				}
				}
			} while (sub_select < 0 || sub_select > 3);
			break;
		}
		case 3:
		{
			_updt_td_srch();
			_search_todo();
			break;
		}
		case 4:
		{
			_updt_td_plan();
			cout << "\n\tToday Plan 생성 완료!!" << endl;
			break;
		}
		case 5:
		{
			_check_td_plan();
			break;
		}
		case 6:
		{
			break;
		}
		default:
		{
			cout << "\n\n\t다시 입력하세요!!!!" << endl;
			break;
		}
		}

		cout << "\t";
		system("pause");
	} while (select != 0);
}

void Application::_title()
{
	system("cls");
	cout << endl;
	cout << "\t\t< To do List >" << endl;
}

void Application::_main_interface()
{
	cout << "\t============ MENU ============" << endl;
	cout << "\t0. 종료" << endl;
	cout << "\t1. 할 일 추가" << endl;
	cout << "\t2. 할 일 조회 및 관리" << endl;
	cout << "\t3. 할 일 검색" << endl;
	cout << "\t4. 일정 생성" << endl;
	cout << "\t5. 일정 조회" << endl;
	cout << "\t6. 현재 할 일 조회" << endl;
	cout << "\t==============================" << endl;
}

void Application::_list_interface()
{
	cout << "\t========= LIST  MENU =========" << endl;
	cout << "\t0. 종료" << endl;
	cout << "\t1. 할 일 조회" << endl;
	cout << "\t2. 할 일 수정" << endl;
	cout << "\t3. 할 일 삭제" << endl;
	cout << "\t==============================" << endl;
}

void Application::_get_todo_info()
{
	_title();
	td_list.print_list();

	int idx;
	if (td_list.size() != 0)
	{
		cout << "\t선택 >> ";
		cin >> idx;
		Todo temp;
		if (idx > 0 && idx <= td_list.size())
		{
			_title();
			td_list.print_todo_info(idx);
		}
		else
		{
			cout << "\n\t잘못 입력하셨습니다...." << endl;
		}
	}
}

void Application::_change_todo_info()
{
	_title();
	td_list.print_list();

	int idx;
	if (td_list.size() != 0)
	{
		cout << "\t선택 >> ";
		cin >> idx;
		if (idx > 0 && idx <= td_list.size())
		{
			_title();
			td_list.modify_todo(idx);
		}
		else
		{
			cout << "\n\t잘못 입력하셨습니다...." << endl;
		}
	}
}

void Application::_delete_todo()
{
	_title();
	td_list.print_list();

	int idx;
	if (td_list.size() != 0)
	{
		cout << "\t선택 >> ";
		cin >> idx;
		Todo temp;
		if (idx > 0 && idx <= td_list.size())
		{
			_title();
			td_list.delete_todo(idx);
		}
		else
		{
			cout << "\n\t잘못 입력하셨습니다...." << endl;
		}
	}
}

void Application::_updt_td_srch()
{
	td_srch.initialize();
	_title();

	int select;
	cout << "\t========= TYPE  INFO =========" << endl;
	cout << "\t1. 제목" << endl;
	cout << "\t2. 내용" << endl;
	cout << "\t3. 완료일" << endl;
	cout << "\t4. 예상 소요 시간" << endl;
	cout << "\t5. 우선순위" << endl;
	cout << "\t==============================" << endl;
	cout << "\t분류 기준 선택 >> ";
	cin >> select;

	Type std;
	switch (select)
	{
	case 1:
		std = TTL;
		break;
	case 2:
		std = CNTT;
		break;
	case 3:
		std = DDL;
		break;
	case 4:
		std = TIME;
		break;
	case 5:
		std = PRR;
		break;
	case 6:
		std = FIN;
		break;
	default:
		std = TTL;
		break;
	}
	td_srch.set_std(std);

	int length = td_list.size();
	Todo* temp;

	td_list.reset_list();
	for (int i = 0; i < length; i++)
	{
		temp = new Todo;
		*temp = td_list.get_next_item();
		temp->set_chk(std);
		td_srch.insert_item(*temp);
	}

	cout << "\t검색 목록 초기화 중******" << endl;
}

void Application::_search_todo()
{
	_title();
	TdList temp;
	bool chk = td_srch.search_todo_by_std(temp);
	if (chk)
	{
		_title();
		cout << "\t======= SEARCH  RESULT =======" << endl;
		temp.print_list();

		int idx;
		if (temp.size() != 0)
		{
			cout << "\t선택 >> ";
			cin >> idx;
			
			if (idx > 0 && idx <= temp.size())
			{
				_title();
				temp.print_todo_info(idx);
			}
			else
			{
				cout << "\n\t잘못 입력하셨습니다...." << endl;
			}
		}
	}
	else
	{
		_title();
		cout << "\n\t존재하지 않는 할 일입니다...." << endl;
	}
}

void Application::_updt_td_plan()
{
	td_plan.initialize();
	_title();

	int select;
	cout << "\t========= TYPE  INFO =========" << endl;
	cout << "\t1. 제목" << endl;
	cout << "\t2. 내용" << endl;
	cout << "\t3. 완료일" << endl;
	cout << "\t4. 예상 소요 시간" << endl;
	cout << "\t5. 우선순위" << endl;
	cout << "\t==============================" << endl;
	cout << "\t분류 기준 선택 >> ";
	cin >> select;

	Type std;
	switch (select)
	{
	case 1:
		std = TTL;
		break;
	case 2:
		std = CNTT;
		break;
	case 3:
		std = DDL;
		break;
	case 4:
		std = TIME;
		break;
	case 5:
		std = PRR;
		break;
	case 6:
		std = FIN;
		break;
	default:
		std = TTL;
		break;
	}
	td_plan.set_std(std);

	int length = td_list.size();
	Todo* temp;

	td_list.reset_list();
	for (int i = 0; i < length; i++)
	{
		temp = new Todo;
		*temp = td_list.get_next_item();
		temp->set_chk(std);
		td_plan.enqueue(*temp);
	}

	cout << "\tToday Plan 생성 중******" << endl;
}

void Application::_check_td_plan()
{
	_title();

	cout << "\t========= TODAY PLAN =========" << endl;
	
}
