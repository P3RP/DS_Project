#include "Application.h"



Application::Application()
{
	cout << "���� ��� �ʱ�ȭ ��******" << endl;
	td_list.initialize_list();
	td_srch.initialize();
	td_plan.initialize();
	exist_now_work = false;
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
			_updt_td_srch();
			_search_todo();
			break;
		}
		case 4:
		{
			_updt_td_plan();
			break;
		}
		case 5:
		{
			_check_td_plan();
			break;
		}
		case 6:
		{
			_get_now_work();
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
	td_srch.initialize();
	_title();

	int select;
	cout << "\t========= TYPE  INFO =========" << endl;
	cout << "\t1. ����" << endl;
	cout << "\t2. ����" << endl;
	cout << "\t3. �Ϸ���" << endl;
	cout << "\t4. ���� �ҿ� �ð�" << endl;
	cout << "\t5. �켱����" << endl;
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

	cout << "\t�˻� ��� �ʱ�ȭ ��******" << endl;
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
			cout << "\t���� >> ";
			cin >> idx;
			
			if (idx > 0 && idx <= temp.size())
			{
				_title();
				temp.print_todo_info(idx);
			}
			else
			{
				cout << "\n\t�߸� �Է��ϼ̽��ϴ�...." << endl;
			}
		}
	}
	else
	{
		_title();
		cout << "\n\t�������� �ʴ� �� ���Դϴ�...." << endl;
	}
}

void Application::_updt_td_plan()
{
	if (td_list.size() > 0)
	{
		cout << "\tToday Plan ���� ��******" << endl;

		td_plan.initialize();
		_title();

		int select;
		cout << "\t========= TYPE  INFO =========" << endl;
		cout << "\t1. ����" << endl;
		cout << "\t2. ����" << endl;
		cout << "\t3. �Ϸ���" << endl;
		cout << "\t4. ���� �ҿ� �ð�" << endl;
		cout << "\t5. �켱����" << endl;
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
		td_plan.set_std(std);

		int length = td_list.size();
		Todo* temp;

		td_list.reset_list();
		for (int i = 0; i < length; i++)
		{
			temp = new Todo;
			*temp = td_list.get_next_item();
			temp->set_chk(std);
			if (!temp->get_fin())
			{
				td_plan.enqueue(*temp);
			}
		}

		td_plan.set_exist(true);

		cout << "\n\tToday Plan ���� �Ϸ�!!" << endl;
	}
	else
	{
		_title();
		cout << "\t�� ���� �������� �ʽ��ϴ�....." << endl;
	}
}

void Application::_check_td_plan()
{
	if (td_plan.get_exist())
	{
		_title();
		TdPlan temp_pl;
		Todo temp;
		int idx = 1;

		cout << "\t========= TODAY PLAN =========" << endl;
		
		if (exist_now_work)
		{
			cout << "\t" << idx << ") " << now_work.get_title() << endl;
			idx++;
		}

		while (!td_plan.is_empty())
		{
			td_plan.dequeue(temp);
			cout << "\t" << idx << ") " << temp.get_title() << endl;
			temp_pl.enqueue(temp);
			idx++;
		}

		cout << "\t==============================" << endl;

		while (!temp_pl.is_empty())
		{
			temp_pl.dequeue(temp);
			td_plan.enqueue(temp);
		}
	}
	else
	{
		_title();
		cout << "\tToday Plan�� �������� �ʽ��ϴ�...." << endl;
	}
}

void Application::_get_now_work()
{
	if (td_plan.get_exist())
	{
		_title();

		td_plan.dequeue(now_work);
		exist_now_work = true;

		cout << "\t========== NOW WORK ==========" << endl;
		cout << "\t[ ���� ]" << endl;
		cout << "\t>> " << now_work.get_title() << endl;

		cout << endl << "\t[ ���� ]" << endl;
		cout << "\t>> " << now_work.get_content() << endl;

		cout << endl << "\t[ �Ϸ��� ( YYYY / MM / DD ) ]" << endl;
		cout << "\t>> " << now_work.get_deadline() << endl;

		cout << endl << "\t[ ���� �ҿ� �ð� (�ð�) ]" << endl;
		cout << "\t>> " << now_work.get_time() << endl;

		cout << endl << "\t[ �켱���� (�⺻�� 0) ]" << endl;
		cout << "\t>> " << now_work.get_priority() << endl;

		cout << endl << "\t[ �Ϸ� ���� ]" << endl;
		if (now_work.get_fin())
		{
			cout << "\t>> �Ϸ�" << endl << endl;
		}
		else
		{
			cout << "\t>> �̿Ϸ�" << endl << endl;
		}

		cout << "\t==============================" << endl;
	}
	else
	{
		_title();
		cout << "\tToday Plan�� �������� �ʽ��ϴ�...." << endl;
	}
}
