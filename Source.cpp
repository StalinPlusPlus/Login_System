#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	fstream file;
	int menu_choice = 10;
	string login_register, password_register, file_name, password_login, login_login, login_buf, password_buf;
	char file_nameChar[100];
	//���� ����
	while (menu_choice != 0)
	{
		cout << "\t����\n1.�����������\n2.�����������\n0.�����\n";
		cin >> menu_choice;
		cin.get();
		switch (menu_choice)
		{
		case 1:
			cout << "������� �����: ";
			getline(cin, login_login);
			cout << endl;
			if (login_login == "")
			{
				cout << "������ �����!" << endl;
				break;
			}
			file_name = login_login + ".txt";
			cout << "������� ������: ";
			getline(cin, password_login);
			cout << endl;
			file.open(file_name, fstream::out | fstream::app | fstream::in);
			if (!file.is_open())
			{
				cout << "������ �������� �����!" << endl;
			}
			else
			{
				strcpy(file_nameChar, file_name.c_str());
				if (fopen(file_nameChar, "r"))
				{
					cout << "������������ � ����� ������� ��� ����������!";
					file.close();
					break;
				}

				getline(file, login_buf);
				getline(file, password_buf);
				if (password_buf == password_login)
				{
					cout << "�� ������� ����� � �������!" << endl;
				}
				else
				{
					cout << "�������� ������!" << endl;
				}
			}
			file.close();
			break;
		case 2:
			cout << "������� �����: ";
			getline(cin, login_register);
			cout << endl;
			file_name = login_register + ".txt";
			cout << "������� ������: ";
			getline(cin, password_register);
			cout << endl;
			file.open(file_name, fstream::out);
			if (!file.is_open())
			{
				cout << "������ �������� �����!" << endl;
			}
			else
			{
				file << login_register << "\n";
				file << password_register << "\n";
				cout << "����������� ������ �������!" << endl;
			}
			file.close();
			break;
		case 0:
			break;
		default:
			cout << "�������� ����� ����!";
		}
	}

	return 0;
}