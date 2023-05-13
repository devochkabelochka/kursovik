//#include "stdafx.h"
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

	bool RemoveCharByNumber(int numToDel)
	{
		if (content == NULL)
		{
			cout << "Ошибка" << endl;
			return 0;
		}

		if (length <= numToDel)
		{
			return 0;
		}

		for (int i = numToDel - 1; i < length - 1; i++)
		{
			content[i] = content[i + 1];
		}
		length--;
		content[length] = '\0';

		return 1;
	}

	void InversionString()
	{
		char c;
		for (int i = 0; i < length / 2; i++)
		{
			c = content[i];
			content[i] = content[length - 1 - i];
			content[length - 1 - i] = c;
		}
	}

	bool RemoveLast()
	{
		if (content == NULL)
		{
			cout << "Ошибка" << endl;
			return 0;
		}
		content[--length] = '\0';
		return 1;
	}

	void ShowString()
	{
		cout << "content: " << content << ", length: " << length << endl;
	}
};

class IDString : public Base
{
public:
	IDString(char arr[])
	{
		int i = 0;
		while (arr[i] != '\0')
		{
			if (arr[i] < 48 || arr[i] > 57)
			{
				i++;
			}
			else
			{
				break;
			}
		}
		int j = 0;

		while (arr[i] != '\0')
		{
			content[j] = arr[i];
			j++;
			i++;
		}
		content[j] = '\0';
		length = j;
	}

	IDString(char c)
	{
		if (c >= 48 || c <= 57)
		{
			content[0] = c;
			content[1] = '\0';
			length = 1;
		}
		else
		{
			content[0] = '\0';
			length = 0;
		}
	}

	IDString()
	{
		content[0] = '\0';
		length = 0;
	}

	bool AddToStart(char c)
	{
		if (c < 47 || c > 58)
		{
			cout << "Ошибка" << endl;
			return 0;
		}
		for (int i = length; i >= 0; --i)
		{
			content[i + 1] = content[i];
		}
		content[0] = c;
		length++;
		return 1;
	}

	bool InversionString()
	{
		if (content[length - 1] < 48 || content[length - 1] > 57)
		{
			cout << "Ошибка" << endl;
			return 0;
		}
		char c;
		for (int i = 0; i < length / 2; i++)
		{
			c = content[i];
			content[i] = content[length - 1 - i];
			content[length - 1 - i] = c;
		}
		return 1;
	}
};

class BinString : public Base
{
protected:
	char content[100];
	int length;
public:
	BinString(char arr[])
	{
		int i = 0;
		int j = 0;
		while (arr[i] != '\0')
		{
			if (arr[i] == '1' || arr[i] == '0')
			{
				content[j] = arr[i];
				i++;
				j++;
			}
			else
			{
				i++;
			}
		}
		content[j] = '\0';
		length = j;
	}

	BinString(char c)
	{
		if (c == '1' || c == '0')
		{
			content[0] = c;
		}
		content[1] = '\0';
		length = 1;
	}

	BinString()
	{
		content[0] = '\0';
		length = 0;
	}
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
		cout << "6. Инверсия строки" << endl;
		cout << "7. Выход" << endl;
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
			if (str.RemoveCharByNumber(numToDel))
			{
				cout << "Результат: ";
				str.ShowString();
				cout << "\n";
			}
			else
			{
				break;
			}
			break;
		case 5:
			if (str.RemoveLast())
			{
				cout << "Результат: ";
				str.ShowString();
				cout << "\n";
			}
			else
			{
				break;
			}
		case 6:
			str.InversionString();
			cout << "Результат: ";
			str.ShowString();
			cout << "\n";
			break;
		}
	} while (choosingVar != 7);
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
		cout << "6. Инверсия строки" << endl;
		cout << "7. Выход" << endl;
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
			if (IDstr.AddToStart(c))
			{
				cout << "Результат: ";
				IDstr.ShowString();
				cout << "\n";
				break;
			}
			else
			{
				break;
			}
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
			if (IDstr.RemoveCharByNumber(numToDel))
			{
				cout << "Результат: ";
				IDstr.ShowString();
				cout << "\n";
			}
			else
			{
				break;
			}
			break;
		case 5:
			if (IDstr.RemoveLast())
			{
				cout << "Результат: ";
				IDstr.ShowString();
				cout << "\n";
			}
			else
			{
				break;
			}
			break;
		case 6:
			if (IDstr.InversionString())
			{
				cout << "Результат: ";
				IDstr.ShowString();
				cout << "\n";
				break;
			}
			else
			{
				break;
			}
		}
	} while (choosingVar != 7);
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
			binStr.AddToStart(c);
			cout << "Результат: ";
			binStr.ShowString();
			cout << "\n";
			break;
		case 3:
			cout << "Введите символ: ";
			cin >> c;
			cout << "\n";
			binStr.AddToEnd(c);
			cout << "Результат: ";
			binStr.ShowString();
			cout << "\n";
			break;
		case 4:
			binStr.AddToEnd('0');
			cout << "Результат: ";
			binStr.ShowString();
			cout << "\n";
			break;
		case 5:
			if (binStr.RemoveLast())
			{
				cout << "Результат: ";
				binStr.ShowString();
				cout << "\n";
			}
			else
			{
				break;
			}
			break;
		case 6:
			cout << "Укажите номер: ";
			cin >> numToDel;
			cout << '\n';
			if (binStr.RemoveCharByNumber(numToDel))
			{
				cout << "Результат: ";
				binStr.ShowString();
				cout << "\n";
			}
			else
			{
				break;
			}
			break;
		}
	} while (choosingVar != 7);
}

void ChooseString()
{
	int choosingVar;
	int i = 0;
	char content[100];
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
		{ // всё дело было в фигурных скобках...
			cout << "Введите строку: ";
			cin >> content;
			Base str(content);
			BaseStringMenu(str);
			break;
		}
		case 2:
		{
			cout << "Введите строку: ";
			cin >> content;
			IDString IDstr(content);
			IDStringMenu(IDstr);
			break;
		}
		case 3:
		{
			cout << "Введите строку: ";
			cin >> content;
			BinString binStr(content);
			BinStringMenu(binStr);
			break;
		}
		}
	} while (choosingVar != 4);
}

int main()
{
	setlocale(LC_ALL, "RU");
	ChooseString();
}
