
#include "stdafx.h"
#include <iostream>
using namespace std;

class Base
{
protected:
	char content[100];
	int length;
public:
	Base(char arr[])
	{
		int i = 0;
		while (arr[i] != '\0')
		{
			content[i] = arr[i];
			i++;
		}
		content[i] = '\0';
		length = i;

	}

	Base(char c)
	{
		content[0] = c;
		content[1] = '\0';
		length = 1;
	}

	Base()
	{
		content[0] = '\0';
		length = 0;
	}

	void StringCopyIn(char source[])
	{
		for (int i = 0; i < length; i++)
		{
			content[i] = source[i];
		}
	}

	void FillString(char arr[])
	{
		int i = 0;
		while (arr[i] != '\0')
		{
			content[i] = arr[i];
			i++;
		}
		content[i] = '\0';
		length = i;
	}

	void AddToStart(char c)
	{
		for (int i = length; i >= 0; --i)
		{
			content[i + 1] = content[i];
		}
		content[0] = c;
		length++;
	}

	void AddToEnd(char c)
	{
		content[length] = c;
		content[++length] = '\0';
	}

	void RemoveCharByNumber(int numToDel)
	{
		if (length <= numToDel)
		{
			return;
		}
		for (int i = numToDel - 1; i < length - 1; i++)
		{
			content[i] = content[i + 1];
		}
		length--;
		content[length] = '\0';
	}


	void RemoveLast()
	{
		content[--length ] = '\0';
		 
	}

	void ShowString()
	{
		cout << "content: " << content << ", length: " << length << endl;
	}
};

class IDString : public Base
{
public:
	using Base::Base;
};

class BinString : public Base
{
public:
	using Base::Base;
};

void ChooseString(); //сама функция ниже

void BaseStringMenu(Base str)
{
	int choosingVar;
	char c;
	int numToDel;
	do
	{
		
		cout << "1. Показать строку" << endl;
		cout << "2. Добавить символ в начало строки" << endl;
		cout << "3. Добавить символ в конец строки" << endl;
		cout << "4. Удалить символ строки по номеру" << endl;
		cout << "5. Удалить последний символ строки" << endl;
		cout << "6. Выход" << endl;
		cin >> choosingVar;
		switch (choosingVar)
		{
		case 1:
			str.ShowString();
			break;
		case 2:
			cout << "Введите символ: ";
			cin >> c;
			cout << "\n";
			str.AddToStart(c);
			cout << "Результат: ";
			str.ShowString();
			cout << "\n";
			break;
		case 3:
			cout << "Введите символ: ";
			cin >> c;
			cout << "\n";
			str.AddToEnd(c);
			cout << "Результат: ";
			str.ShowString();
			cout << "\n";
			break;
		case 4:
			cout << "Укажите номер: ";
			cin >> numToDel;
			cout << '\n';
			str.RemoveCharByNumber(numToDel);
			cout << "Результат: ";
			str.ShowString();
			cout << "\n";
			break;
		case 5:
			str.RemoveLast();
			cout << "Результат: ";
			str.ShowString();
			break;
		}
	} while (choosingVar != 6);
}

void IDStringMenu(IDString IDstr)
{
	int choosingVar;
	int numToDel;
	char c;

	do
	{
		cout << "1. Показать строку" << endl;
		cout << "2. Добавить символ в начало строки" << endl;
		cout << "3. Добавить символ в конец строки" << endl;
		cout << "4. Удалить символ строки по номеру" << endl;
		cout << "5. Удалить последний символ строки" << endl;
		cout << "6. Выход" << endl;
		cin >> choosingVar;
		switch (choosingVar)
		{
		case 1:
			IDstr.ShowString();
			break;
		case 2:
			cout << "Введите символ: ";
			cin >> c;
			cout << "\n";
			if (c < 48 || c > 57)
			{
				cout << "Ошибка" << endl;
				break;
			}
			IDstr.AddToStart(c);
			cout << "Результат: ";
			IDstr.ShowString();
			cout << "\n";
			break;
		case 3:
			cout << "Введите символ: ";
			cin >> c;
			cout << "\n";
			IDstr.AddToEnd(c);
			cout << "Результат: ";
			IDstr.ShowString();
			cout << "\n";
			break;
		case 4:
			cout << "Укажите номер: ";
			cin >> numToDel;
			cout << '\n';
			IDstr.RemoveCharByNumber(numToDel);
			cout << "Результат: ";
			IDstr.ShowString();
			cout << "\n";
			break;
		case 5:
			IDstr.RemoveLast();
			cout << "Результат: ";
			IDstr.ShowString();
			break;
		}
	} while (choosingVar != 6);
}

void BinStringMenu(BinString binStr)
{
	int choosingVar;
	int numToDel;
	char c;
	do
	{
		cout << "1. Показать строку" << endl;
		cout << "2. Добавить символ в начало строки" << endl;
		cout << "3. Добавить символ в конец строки" << endl;
		cout << "4. Сдвиг влево" << endl;
		cout << "5. Сдвиг вправо" << endl;
		cout << "6. Удалить символ по номеру" << endl;
		cout << "7. Выход" << endl;
		cin >> choosingVar;
		switch (choosingVar)
		{
		case 1:
			binStr.ShowString();
			break;
		case 2:
			cout << "Введите символ: ";
			cin >> c;
			cout << "\n";
			if (c != '1' && c != '0')
			{
				cout << "Ошибка" << endl;
				break;
			}
			binStr.AddToStart(c);
			cout << "Результат: ";
			binStr.ShowString();
			cout << "\n";
			break;
		case 3:
			cout << "Введите символ: ";
			cin >> c;
			cout << "\n";
			if (c != '1' && c != '0')
			{
				cout << "Ошибка" << endl;
				break;
			}
			binStr.AddToEnd(c);
			cout << "Результат: ";
			binStr.ShowString();
			cout << "\n";
			break;
		case 4:
			binStr.AddToEnd('0');
			cout << "Результат: ";
			binStr.ShowString();
			cout << '\n';
			break;
		case 5:
			binStr.RemoveLast();
			cout << "Результат: ";
			binStr.ShowString();
			cout << '\n';
			break;
		case 6:
			cout << "Укажите номер: ";
			cin >> numToDel;
			cout << '\n';
			binStr.RemoveCharByNumber(numToDel);
			cout << "Результат: ";
			binStr.ShowString();
			cout << "\n";
			break;
		}
	} while (choosingVar != 7);
}

void ChooseString()
{
	int choosingVar;
	int i = 0;
	char arr[100];
	char content[100] = { '0' };
	Base str(content);
	IDString IDstr(content);
	BinString binStr(content);
	do
	{
		cout << "1. Строка" << endl;
		cout << "2. Строка-идентификатор" << endl;
		cout << "3. Бинарная строка" << endl;
		cout << "4. Выход" << endl;
		cin >> choosingVar;
		switch (choosingVar)
		{
		case 1:
			cout << "Введите строку: ";
			cin >> arr;
			str.FillString(arr);

			BaseStringMenu(str);
			break;
		case 2:
			cout << "Введите строку: ";
			cin >> arr;
			IDstr.FillString(arr);
			if (arr[0] < 48 || arr[0] > 57)
			{
				cout << "Строка введена неверно" << endl;
				break;
			}
			IDStringMenu(IDstr);
			break;
		case 3:
			cout << "Введите строку: ";
			cin >> arr;
			binStr.FillString(arr);
			if (arr[i] != '1' && arr[i] != '0')
			{
				cout << "Строка введена неверно" << endl;
				break;
			}
			else
			{
				while (arr[i] == '1' || arr[i] == '0')
				{
					i++;
				}
				if (arr[i] != '1' && arr[i] != '0')
				{
					if (arr[i] == '\0')
					{
						BinStringMenu(binStr);
						break;
					}
					cout << "Строка введена неверно" << endl;
					break;
				}
			}
		}
	} while (choosingVar != 4);
}

int main()
{
	setlocale(LC_ALL, "Rus");
	ChooseString();
}
