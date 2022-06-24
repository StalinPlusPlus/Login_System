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
	//Цикл меню
	while (menu_choice != 0)
	{
		cout << "\tМеню\n1.Авторизация\n2.Регистрация\n0.Выход\n";
		cin >> menu_choice;
		cin.get();
		switch (menu_choice)
		{
		case 1:
			cout << "Введите логин: ";
			getline(cin, login_login);
			cout << endl;
			if (login_login == "")
			{
				cout << "Пустой логин!" << endl;
				break;
			}
			file_name = login_login + ".txt";
			cout << "Введите пароль: ";
			getline(cin, password_login);
			cout << endl;
			file.open(file_name, fstream::out | fstream::app | fstream::in);
			if (!file.is_open())
			{
				cout << "Неверный логин" << endl;
			}
			else
			{
				getline(file, login_buf);
				getline(file, password_buf);
				if (password_buf == password_login)
				{
					cout << "Вы успешно вошли в систему!" << endl;
				}
				else
				{
					cout << "Неверный пароль!" << endl;
				}
			}
			file.close();
			break;
		case 2:
			cout << "Введите логин: ";
			getline(cin, login_register);
			cout << endl;
			file_name = login_register + ".txt";
			cout << "Введите пароль: ";
			getline(cin, password_register);
			cout << endl;
			file.open(file_name, fstream::out);
			if (!file.is_open())
			{
				cout << "Ошибка создания файла!" << endl;
			}
			else
			{
				file << login_register << "\n";
				file << password_register << "\n";
				cout << "Регистрация прошла успешно!" << endl;
			}
			file.close();
			break;
		case 0:
			break;
		default:
			cout << "Неверный пункт меню!";
		}
	}

	//херота для проврки веток

	return 0;
}