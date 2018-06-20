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
	
	int temp_idx;
	string temp_title;
	string temp_content;
	int temp_time;
	string temp_deadline;
	int temp_priority;

	// Value ���� �Է�
	cout << "\t====== �� ���� ���� �Է� ====="<<endl;

	cout << "\t[ ���� ]" << endl;
	cout << "\t>> ";
	cin >> temp_title;

	cout << endl << "\t[ ���� ]" << endl;
	cout << "\t>> ";
	cin >> temp_content;

	cout << endl << "\t[ �Ϸ��� ]" << endl;
	cout << "\t>> ";
	cin >> temp_deadline;

	cout << endl << "\t[ ���� �ҿ� �ð� ]" << endl;
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
	Todo* temp = new Todo;
	for (int i = 0; i < idx; i++)
	{
		*temp = get_next_item();
	}

	cout << "\t========= TODO  INFO =========" << endl;
	cout << "\t[ ���� ]" << endl;
	cout << "\t>> " << temp->get_title() << endl;

	cout << endl << "\t[ ���� ]" << endl;
	cout << "\t>> " << temp->get_content() << endl;

	cout << endl << "\t[ �Ϸ��� ]" << endl;
	cout << "\t>> " << temp->get_deadline() << endl;

	cout << endl << "\t[ ���� �ҿ� �ð� ]" << endl;
	cout << "\t>> " << temp->get_time() << endl;

	cout << endl << "\t[ �켱���� (�⺻�� 0) ]" << endl;
	cout << "\t>> " << temp->get_priority() << endl;

	cout << "\t==============================" << endl;
}

void TdList::delete_todo(int idx)
{
	reset_list();
	Todo* temp = new Todo;
	for (int i = 0; i < idx; i++)
	{
		*temp = get_next_item();
	}
	delete_item(*temp);
	cout << "\t" << idx << "��° Todo�� �����Ǿ����ϴ�!!!!" << endl;
}
