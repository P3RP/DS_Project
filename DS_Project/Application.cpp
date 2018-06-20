#include "Application.h"



Application::Application()
{
}


Application::~Application()
{
}

void Application::start()
{
	int select;
	do
	{
		_interface();
		cout << "\t입력 >> ";
		cin >> select;

		system("cls");

		switch (select)
		{
		case 0:
		{
			cout << "\n\n\t종료~~~~~!!!!!" << endl;
			cout << "\t";
			break;
		}
		case 1:
		{
			cout << "\t1. 할 일 목록 보기" << endl;
			break;
		}
		case 2:
		{
			cout << "\t2. 할 일 추가" << endl;
			break;
		}
		case 3:
		{
			cout << "\t3. 할 일 삭제" << endl;
			break;
		}
		case 4:
		{
			cout << "\t4. 할 일 수정" << endl;
			break;
		}
		case 5:
		{
			cout << "\t5. 할 일 검색" << endl;
			break;
		}
		case 6:
		{
			cout << "\t6. 일정 생성" << endl;
			break;
		}
		case 7:
		{
			cout << "\t7. 일정 보기" << endl;
			break;
		}
		default:
		{
			cout << "\n\n\t다시 입력하세요!!!!" << endl;
			cout << "\t";
			system("pause");
			break;
		}
		}

	} while (select != 0);
}

void Application::_interface()
{
	system("cls");
	cout << endl << endl;
	cout << "\t=========== 메뉴 ===========" << endl;
	cout << "\t0. 종료" << endl;
	cout << "\t1. 할 일 목록 보기" << endl;
	cout << "\t2. 할 일 추가" << endl;
	cout << "\t3. 할 일 삭제" << endl;
	cout << "\t4. 할 일 수정" << endl;
	cout << "\t5. 할 일 검색" << endl;
	cout << "\t6. 일정 생성" << endl;
	cout << "\t7. 일정 보기" << endl;
	cout << "\t============================" << endl;
}
