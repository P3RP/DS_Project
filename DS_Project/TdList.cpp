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
	// 임시 Todo 및 information value 선언
	Todo* temp = new Todo;
	
	string temp_title;
	string temp_content;
	int temp_time;
	string temp_deadline;
	int temp_priority;
	getline(cin, temp_title);

	// Value 정보 입력
	cout << "\t====== 할 일의 정보 입력 ====="<<endl;

	cout << "\t[ 제목 ]" << endl;
	cout << "\t>> ";
	getline(cin, temp_title);

	cout << endl << "\t[ 내용 ]" << endl;
	cout << "\t>> ";
	getline(cin, temp_content);

	cout << endl << "\t[ 완료일 ( YYYY / MM / DD ) ]" << endl;
	cout << "\t>> ";
	getline(cin, temp_deadline);

	cout << endl << "\t[ 예상 소요 시간 (시간) ]" << endl;
	cout << "\t>> ";
	cin >> temp_time;

	cout << endl << "\t[ 우선순위 (기본값 0) ]" << endl;
	cout << "\t>> ";
	cin >> temp_priority;

	// Value 정보 Todo에 넣기
	temp->set_idx(idx_cnt);
	temp->set_title(temp_title);
	temp->set_content(temp_content);
	temp->set_time(temp_time);
	temp->set_deadline(temp_deadline);
	temp->set_priority(temp_priority);
	temp->set_fin(false);

	// list에 Todo 넣기
	insert_item(*temp);
	idx_cnt++;
}

void TdList::print_list()
{
	cout << "\t============ LIST ============" << endl;
	if (size() == 0)
	{
		cout << "\t비어있는 List입니다!!!!!" << endl;
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
	cout << "\t[ 제목 ]" << endl;
	cout << "\t>> " << temp->get_title() << endl;

	cout << endl << "\t[ 내용 ]" << endl;
	cout << "\t>> " << temp->get_content() << endl;

	cout << endl << "\t[ 완료일 ( YYYY / MM / DD ) ]" << endl;
	cout << "\t>> " << temp->get_deadline() << endl;

	cout << endl << "\t[ 예상 소요 시간 (시간) ]" << endl;
	cout << "\t>> " << temp->get_time() << endl;

	cout << endl << "\t[ 우선순위 (기본값 0) ]" << endl;
	cout << "\t>> " << temp->get_priority() << endl;

	cout << endl << "\t[ 완료 여부 ]" << endl;
	if (temp->get_fin())
	{
		cout << "\t>> 완료" << endl << endl;
	}
	else
	{
		cout << "\t>> 미완료" << endl << endl;
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
	cout << "\t1. 제목" << endl;
	cout << "\t2. 내용" << endl;
	cout << "\t3. 완료일" << endl;
	cout << "\t4. 예상 소요 시간" << endl;
	cout << "\t5. 우선순위" << endl;
	cout << "\t6. 완료 여부" << endl;
	cout << "\t==============================" << endl;
	cout << "\t수정할 Info 선택 >> ";
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
		cout << "\t[ 기존 제목 ]" << endl;
		cout << "\t>> " << temp->get_title() << endl << endl;
		cout << "\t[ 변경할 제목 ]" << endl;
		cout << "\t>> ";
		getline(cin, temp_title);
		getline(cin, temp_title);

		cout << "\t==============================" << endl;

		temp->set_title(temp_title);
		cout << "\t변경되었습니다!!!!" << endl;

		break;
	}
	case 2:
	{
		string temp_content;

		system("cls");
		cout << endl;
		cout << "\t\t< To do List >" << endl;
		cout << "\t========= TODO  INFO =========" << endl;
		cout << "\t[ 기존 내용 ]" << endl;
		cout << "\t>> " << temp->get_content() << endl << endl;
		cout << "\t[ 변경할 내용 ]" << endl;
		cout << "\t>> ";
		getline(cin, temp_content);
		getline(cin, temp_content);

		cout << "\t==============================" << endl;

		temp->set_content(temp_content);
		cout << "\t변경되었습니다!!!!" << endl;

		break;
	}
	case 3:
	{
		string temp_deadline;

		system("cls");
		cout << endl;
		cout << "\t\t< To do List >" << endl;
		cout << "\t========= TODO  INFO =========" << endl;
		cout << "\t[ 기존 완료일 ( YYYY / MM / DD ) ]" << endl;
		cout << "\t>> " << temp->get_deadline() << endl << endl;
		cout << "\t[ 변경할 완료일 ( YYYY / MM / DD ) ]" << endl;
		cout << "\t>> ";
		getline(cin, temp_deadline);
		getline(cin, temp_deadline);

		cout << "\t==============================" << endl;

		temp->set_deadline(temp_deadline);
		cout << "\t변경되었습니다!!!!" << endl;

		break;
	}
	case 4:
	{
		int temp_time;

		system("cls");
		cout << endl;
		cout << "\t\t< To do List >" << endl;
		cout << "\t========= TODO  INFO =========" << endl;
		cout << "\t[ 기존 예상 소요 시간 (시간) ]" << endl;
		cout << "\t>> " << temp->get_time() << endl << endl;
		cout << "\t[ 변경할 예상 소요 시간 (시간) ]" << endl;
		cout << "\t>> ";
		cin >> temp_time;

		cout << "\t==============================" << endl;

		temp->set_time(temp_time);
		cout << "\t변경되었습니다!!!!" << endl;

		break;
	}
	case 5:
	{
		int temp_priority;

		system("cls");
		cout << endl;
		cout << "\t\t< To do List >" << endl;
		cout << "\t========= TODO  INFO =========" << endl;
		cout << "\t[ 기존 우선순위 (기본값 0) ]" << endl;
		cout << "\t>> " << temp->get_priority() << endl << endl;
		cout << "\t[ 변경할 우선순위 (기본값 0) ]" << endl;
		cout << "\t>> ";
		cin >> temp_priority;

		cout << "\t==============================" << endl;

		temp->set_priority(temp_priority);
		cout << "\t변경되었습니다!!!!" << endl;

		break;
	}
	case 6:
	{
		int temp_priority;

		system("cls");
		cout << endl;
		cout << "\t\t< To do List >" << endl;
		cout << "\t========= TODO  INFO =========" << endl;
		cout << "\t[ 기존 완료여부 ]" << endl;

		if (temp->get_fin())
		{
			cout << "\t>> 완료" << endl << endl;
		}
		else
		{
			cout << "\t>> 미완료" << endl << endl;
		}

		cout << "\t[ 변경할 우선순위 ]" << endl;
		cout << "\t1. 완료" << endl;
		cout << "\t2. 미완료" << endl;
		cout << "\t>> ";
		cin >> temp_priority;

		cout << "\t==============================" << endl;

		if (temp_priority == 1)
		{
			temp->set_fin(true);
			cout << "\t변경되었습니다!!!!" << endl;
		}
		else if (temp_priority == 2)
		{
			temp->set_fin(false);
			cout << "\t변경되었습니다!!!!" << endl;
		}

		break;
	}
	default:
	{
		cout << "\t잘못 번호입니다..." << endl;
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
	cout << "\n\t" << idx << "번째 Todo가 삭제되었습니다!!!!" << endl;
}

int TdList::get_idx_cnt()
{
	return idx_cnt;
}

void TdList::set_idx_cnt(int new_idx)
{
	idx_cnt = new_idx;
}
