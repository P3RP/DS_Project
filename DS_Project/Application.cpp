#include "Application.h"



Application::Application()
{
	cout << "���� ��� �ʱ�ȭ ��******" << endl;
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

		cout << "\t�Է� >> ";
		cin >> select;

		switch (select)
		{
		case 0:
		{
			_title();
			cout << "\n\t����~~~~~!!!!!" << endl;
			break;
		}
		case 1:
		{
			_title();
			td_list.add_todo();

			cout << "\n\t�Ϸ�!!!!" << endl;
			break;
		}
		case 2:
		{
			int sub_select;
			do
			{
				_title();
				_list_interface();
				cout << "\t�Է� >> ";
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
					cout << "\n\n\t�ٽ� �Է��ϼ���!!!!" << endl;
					break;
				}
				}
			} while (sub_select < 0 || sub_select > 3);
			break;
		}
		case 3:
		{
			_title();
			_updt_td_srch();
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
			break;
		}
		default:
		{
			cout << "\n\n\t�ٽ� �Է��ϼ���!!!!" << endl;
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
	cout << "\t0. ����" << endl;
	cout << "\t1. �� �� �߰�" << endl;
	cout << "\t2. �� �� ��ȸ �� ����" << endl;
	cout << "\t3. �� �� �˻�" << endl;
	cout << "\t4. ���� ����" << endl;
	cout << "\t5. ���� ��ȸ" << endl;
	cout << "\t6. ���� �� �� ��ȸ" << endl;
	cout << "\t==============================" << endl;
}

void Application::_list_interface()
{
	cout << "\t========= LIST  MENU =========" << endl;
	cout << "\t0. ����" << endl;
	cout << "\t1. �� �� ��ȸ" << endl;
	cout << "\t2. �� �� ����" << endl;
	cout << "\t3. �� �� ����" << endl;
	cout << "\t==============================" << endl;
}

void Application::_get_todo_info()
{
	_title();
	td_list.print_list();

	int idx;
	if (td_list.size() != 0)
	{
		cout << "\t���� >> ";
		cin >> idx;
		Todo temp;
		if (idx > 0 && idx <= td_list.size())
		{
			_title();
			td_list.print_todo_info(idx);
		}
		else
		{
			cout << "\n\t�߸� �Է��ϼ̽��ϴ�...." << endl;
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
		cout << "\t���� >> ";
		cin >> idx;
		Todo temp;
		if (idx > 0 && idx <= td_list.size())
		{
			_title();
			td_list.modify_todo(idx);
		}
		else
		{
			cout << "\n\t�߸� �Է��ϼ̽��ϴ�...." << endl;
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
		cout << "\t���� >> ";
		cin >> idx;
		Todo temp;
		if (idx > 0 && idx <= td_list.size())
		{
			_title();
			td_list.delete_todo(idx);
		}
		else
		{
			cout << "\n\t�߸� �Է��ϼ̽��ϴ�...." << endl;
		}
	}
}

void Application::_updt_td_srch()
{
	int select;
	cout << "\t========= TYPE  INFO =========" << endl;
	cout << "\t1. ����" << endl;
	cout << "\t2. ����" << endl;
	cout << "\t3. �Ϸ���" << endl;
	cout << "\t4. ���� �ҿ� �ð�" << endl;
	cout << "\t5. �켱����" << endl;
	cout << "\t6. �Ϸ� ����" << endl;
	cout << "\t==============================" << endl;
	cout << "\t�з� ���� ���� >> ";
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

	int length = td_list.size();
	Todo temp;
	for (int i = 0; i < length; i++)
	{
		temp = td_list.get_next_item();
		temp.set_chk(std);
		td_srch.insert_item(temp);
	}
}
