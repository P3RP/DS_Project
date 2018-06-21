#include "TdList.h"



TdList::TdList()
{
	idx_cnt = 0;
}


TdList::~TdList()
{
}

void TdList::initialize_list()
{
	idx_cnt = 0;
}

void TdList::add_todo()
{
	// �ӽ� Todo �� information value ����
	Todo* temp = new Todo;
	
	string temp_title;
	string temp_content;
	int temp_time;
	string temp_deadline;
	int temp_priority;
	getline(cin, temp_title);

	// Value ���� �Է�
	cout << "\t====== �� ���� ���� �Է� ====="<<endl;

	cout << "\t[ ���� ]" << endl;
	cout << "\t>> ";
	getline(cin, temp_title);

	cout << endl << "\t[ ���� ]" << endl;
	cout << "\t>> ";
	getline(cin, temp_content);

	cout << endl << "\t[ �Ϸ��� ( YYYY / MM / DD ) ]" << endl;
	cout << "\t>> ";
	getline(cin, temp_deadline);

	cout << endl << "\t[ ���� �ҿ� �ð� (�ð�) ]" << endl;
	cout << "\t>> ";
	cin >> temp_time;

	cout << endl << "\t[ �켱���� (�⺻�� 0) ]" << endl;
	cout << "\t>> ";
	cin >> temp_priority;

	// Value ���� Todo�� �ֱ�
	temp->set_idx(idx_cnt);
	temp->set_title(temp_title);
	temp->set_content(temp_content);
	temp->set_time(temp_time);
	temp->set_deadline(temp_deadline);
	temp->set_priority(temp_priority);
	temp->set_fin(false);

	// list�� Todo �ֱ�
	insert_item(*temp);
	idx_cnt++;
}

void TdList::print_list()
{
	cout << "\t============ LIST ============" << endl;
	if (size() == 0)
	{
		cout << "\t����ִ� List�Դϴ�!!!!!" << endl;
	}
	else
	{
		reset_list();
		Todo temp;
		for (int i = 0; i < size(); i++)
		{
			temp = get_next_item();
			cout << "\t" << i + 1 << ". " << temp.get_title() << endl;
		}
	}
	cout << "\t==============================" << endl;
}

void TdList::print_todo_info(int idx)
{
	reset_list();
	Todo* temp = nullptr;
	for (int i = 0; i < idx; i++)
	{
		temp = &get_next_item();
	}

	cout << "\t========= TODO  INFO =========" << endl;
	cout << "\t[ ���� ]" << endl;
	cout << "\t>> " << temp->get_title() << endl;

	cout << endl << "\t[ ���� ]" << endl;
	cout << "\t>> " << temp->get_content() << endl;

	cout << endl << "\t[ �Ϸ��� ( YYYY / MM / DD ) ]" << endl;
	cout << "\t>> " << temp->get_deadline() << endl;

	cout << endl << "\t[ ���� �ҿ� �ð� (�ð�) ]" << endl;
	cout << "\t>> " << temp->get_time() << endl;

	cout << endl << "\t[ �켱���� (�⺻�� 0) ]" << endl;
	cout << "\t>> " << temp->get_priority() << endl;

	cout << endl << "\t[ �Ϸ� ���� ]" << endl;
	if (temp->get_fin())
	{
		cout << "\t>> �Ϸ�" << endl << endl;
	}
	else
	{
		cout << "\t>> �̿Ϸ�" << endl << endl;
	}

	cout << "\t==============================" << endl;
}

void TdList::modify_todo(int idx)
{
	reset_list();
	Todo* temp = nullptr;
	for (int i = 0; i < idx; i++)
	{
		temp = &get_next_item();
	}
	
	int select;
	cout << "\t========= TODO  INFO =========" << endl;
	cout << "\t1. ����" << endl;
	cout << "\t2. ����" << endl;
	cout << "\t3. �Ϸ���" << endl;
	cout << "\t4. ���� �ҿ� �ð�" << endl;
	cout << "\t5. �켱����" << endl;
	cout << "\t6. �Ϸ� ����" << endl;
	cout << "\t==============================" << endl;
	cout << "\t������ Info ���� >> ";
	cin >> select;

	switch (select)
	{
	case 1:
	{
		string temp_title;

		system("cls");
		cout << endl;
		cout << "\t\t< To do List >" << endl;
		cout << "\t========= TODO  INFO =========" << endl;
		cout << "\t[ ���� ���� ]" << endl;
		cout << "\t>> " << temp->get_title() << endl << endl;
		cout << "\t[ ������ ���� ]" << endl;
		cout << "\t>> ";
		getline(cin, temp_title);
		getline(cin, temp_title);

		cout << "\t==============================" << endl;

		temp->set_title(temp_title);
		cout << "\t����Ǿ����ϴ�!!!!" << endl;

		break;
	}
	case 2:
	{
		string temp_content;

		system("cls");
		cout << endl;
		cout << "\t\t< To do List >" << endl;
		cout << "\t========= TODO  INFO =========" << endl;
		cout << "\t[ ���� ���� ]" << endl;
		cout << "\t>> " << temp->get_content() << endl << endl;
		cout << "\t[ ������ ���� ]" << endl;
		cout << "\t>> ";
		getline(cin, temp_content);
		getline(cin, temp_content);

		cout << "\t==============================" << endl;

		temp->set_content(temp_content);
		cout << "\t����Ǿ����ϴ�!!!!" << endl;

		break;
	}
	case 3:
	{
		string temp_deadline;

		system("cls");
		cout << endl;
		cout << "\t\t< To do List >" << endl;
		cout << "\t========= TODO  INFO =========" << endl;
		cout << "\t[ ���� �Ϸ��� ( YYYY / MM / DD ) ]" << endl;
		cout << "\t>> " << temp->get_deadline() << endl << endl;
		cout << "\t[ ������ �Ϸ��� ( YYYY / MM / DD ) ]" << endl;
		cout << "\t>> ";
		getline(cin, temp_deadline);
		getline(cin, temp_deadline);

		cout << "\t==============================" << endl;

		temp->set_deadline(temp_deadline);
		cout << "\t����Ǿ����ϴ�!!!!" << endl;

		break;
	}
	case 4:
	{
		int temp_time;

		system("cls");
		cout << endl;
		cout << "\t\t< To do List >" << endl;
		cout << "\t========= TODO  INFO =========" << endl;
		cout << "\t[ ���� ���� �ҿ� �ð� (�ð�) ]" << endl;
		cout << "\t>> " << temp->get_time() << endl << endl;
		cout << "\t[ ������ ���� �ҿ� �ð� (�ð�) ]" << endl;
		cout << "\t>> ";
		cin >> temp_time;

		cout << "\t==============================" << endl;

		temp->set_time(temp_time);
		cout << "\t����Ǿ����ϴ�!!!!" << endl;

		break;
	}
	case 5:
	{
		int temp_priority;

		system("cls");
		cout << endl;
		cout << "\t\t< To do List >" << endl;
		cout << "\t========= TODO  INFO =========" << endl;
		cout << "\t[ ���� �켱���� (�⺻�� 0) ]" << endl;
		cout << "\t>> " << temp->get_priority() << endl << endl;
		cout << "\t[ ������ �켱���� (�⺻�� 0) ]" << endl;
		cout << "\t>> ";
		cin >> temp_priority;

		cout << "\t==============================" << endl;

		temp->set_priority(temp_priority);
		cout << "\t����Ǿ����ϴ�!!!!" << endl;

		break;
	}
	case 6:
	{
		int temp_priority;

		system("cls");
		cout << endl;
		cout << "\t\t< To do List >" << endl;
		cout << "\t========= TODO  INFO =========" << endl;
		cout << "\t[ ���� �ϷῩ�� ]" << endl;

		if (temp->get_fin())
		{
			cout << "\t>> �Ϸ�" << endl << endl;
		}
		else
		{
			cout << "\t>> �̿Ϸ�" << endl << endl;
		}

		cout << "\t[ ������ �켱���� ]" << endl;
		cout << "\t1. �Ϸ�" << endl;
		cout << "\t2. �̿Ϸ�" << endl;
		cout << "\t>> ";
		cin >> temp_priority;

		cout << "\t==============================" << endl;

		if (temp_priority == 1)
		{
			temp->set_fin(true);
			cout << "\t����Ǿ����ϴ�!!!!" << endl;
		}
		else if (temp_priority == 2)
		{
			temp->set_fin(false);
			cout << "\t����Ǿ����ϴ�!!!!" << endl;
		}

		break;
	}
	default:
	{
		cout << "\t�߸� ��ȣ�Դϴ�..." << endl;
		break;
	}
	}
}

void TdList::delete_todo(int idx)
{
	reset_list();
	Todo* temp = nullptr;
	for (int i = 0; i < idx; i++)
	{
		temp = &get_next_item();
	}
	delete_item(*temp);
	cout << "\n\t" << idx << "��° Todo�� �����Ǿ����ϴ�!!!!" << endl;
}

int TdList::get_idx_cnt()
{
	return idx_cnt;
}

void TdList::set_idx_cnt(int new_idx)
{
	idx_cnt = new_idx;
}
