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
		cout << "\t�Է� >> ";
		cin >> select;

		system("cls");

		switch (select)
		{
		case 0:
		{
			cout << "\n\n\t����~~~~~!!!!!" << endl;
			cout << "\t";
			break;
		}
		case 1:
		{
			cout << "\t1. �� �� ��� ����" << endl;
			break;
		}
		case 2:
		{
			cout << "\t2. �� �� �߰�" << endl;
			break;
		}
		case 3:
		{
			cout << "\t3. �� �� ����" << endl;
			break;
		}
		case 4:
		{
			cout << "\t4. �� �� ����" << endl;
			break;
		}
		case 5:
		{
			cout << "\t5. �� �� �˻�" << endl;
			break;
		}
		case 6:
		{
			cout << "\t6. ���� ����" << endl;
			break;
		}
		case 7:
		{
			cout << "\t7. ���� ����" << endl;
			break;
		}
		default:
		{
			cout << "\n\n\t�ٽ� �Է��ϼ���!!!!" << endl;
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
	cout << "\t=========== �޴� ===========" << endl;
	cout << "\t0. ����" << endl;
	cout << "\t1. �� �� ��� ����" << endl;
	cout << "\t2. �� �� �߰�" << endl;
	cout << "\t3. �� �� ����" << endl;
	cout << "\t4. �� �� ����" << endl;
	cout << "\t5. �� �� �˻�" << endl;
	cout << "\t6. ���� ����" << endl;
	cout << "\t7. ���� ����" << endl;
	cout << "\t============================" << endl;
}
