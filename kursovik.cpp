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

	void AddToStart(Base added)
	{
		int i;
		for (i = length; i >= 0; --i)
		{
			content[i + added.length] = content[i];
		}

		for (i = 0; i < added.length; ++i)
		{
			this->content[i] = added.content[i];
			length++;
		}
	}

	void AddCharToEnd(char c)
	{
		content[length] = c;
		content[++length] = '\0';
	}

	void Concat(Base added)
	{
		int i = 0;
		while (added.content[i] != '\0')
		{
			content[length + i] = added.content[i];
			i++;
		}
		length = i;
		content[length + i] = '\0';
	}

	bool RemoveCharByNumber(int numToDel)
	{
		if (length == 0)
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
		char temp;
		for (int i = 0; i < length / 2; i++)
		{
			temp = content[i];
			content[i] = content[length - 1 - i];
			content[length - 1 - i] = temp;
		}
	}

	bool RemoveLast()
	{
		if (length == 0)
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

	void AddToStart(IDString added)
	{
		int i;
		for (i = length; i >= 0; --i)
		{
			content[i + added.length] = content[i];
		}

		for (i = 0; i < added.length; ++i)
		{
			this->content[i] = added.content[i];
			length++;
		}
	}

	void AddCharToEnd(char c)
	{
		content[length] = c;
		content[++length] = '\0';
	}

	void Concat(IDString added)
	{
		int i = 0;
		while (added.content[i] != '\0')
		{
			content[length + i] = added.content[i];
			i++;
		}
		length = i;
		content[length + i] = '\0';
	}

	bool InversionString()
	{
		if (content[length - 1] < 48 || content[length - 1] > 57)
		{
			cout << "Ошибка" << endl;
			return 0;
		}
		char temp;
		for (int i = 0; i < length / 2; i++)
		{
			temp = content[i];
			content[i] = content[length - 1 - i];
			content[length - 1 - i] = temp;
		}
		return 1;
	}

	bool RemoveCharByNumber(int numToDel)
	{
		if (numToDel == 1)
		{
			if (content[1] >= 48 || content[1] <= 57)
			{
				cout << "Ошибка" << endl;
				return 0;
			}
		}

		if (length == 0)
		{
			cout << "Ошибка" << endl;
			return 0;
		}

		if (length <= numToDel)
		{
			cout << "Ошибка" << endl;
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
};

class BinString : public Base
{
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
			content[1] = '\0';
			length = 1;
		}
		else
		{
			content[0] = '\0';
			length = 0;
		}
	}

	BinString()
	{
		content[0] = '\0';
		length = 0;
	}

	void AddToStart(BinString added)
	{
		int i;
		for (i = length; i >= 0; --i)
		{
			content[i + added.length] = content[i];
		}

		for (i = 0; i < added.length; ++i)
		{
			this->content[i] = added.content[i];
			length++;
		}
	}

	void AddCharToEnd(char c)
	{
		content[length] = c;
		content[++length] = '\0';
	}

	void Concat(BinString added)
	{
		int i = 0;
		while (added.content[i] != '\0')
		{
			content[length + i] = added.content[i];
			i++;
		}
		length = i;
		content[length + i] = '\0';
	}

	void BitWiseMult(char arr[])
	{
		BinString firstMult(content);
		BinString secondMult(arr);
		if (firstMult.length > secondMult.length)
		{
			int diff = firstMult.length - secondMult.length;
			for (int i = length; i >= 0; --i)
			{

			}
		}
		for (int i = 0; i < length; i++)
		{
			if (content[i] == '1')
			{
				if (arr[i] == '1')
				{
					content[i] = '1';
				}
				else
				{
					content[i] = '0';
				}
			}
		}
	}
};

void ChooseString(); //сама функция ниже

void BaseStringMenu(Base str)
{
	int choosingVar;
	int numToDel;
	char c[100];
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
		{
			cout << "Введите символ: ";
			cin >> c;
			cout << "\n";
			Base added(c);
			str.AddToStart(added);
			cout << "Результат: ";
			str.ShowString();
			cout << "\n";
			break;
		}
		case 3:
		{
			cout << "Введите символ: ";
			cin >> c;
			cout << "\n";
			Base added(c);
			str.AddToEnd(added);
			cout << "Результат: ";
			str.ShowString();
			cout << "\n";
			break;
		}
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
				break;
			}
			else
			{
				break;
			}
			break;
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
	char c[100];
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
		{
			cout << "Введите символ: ";
			cin >> c;
			cout << "\n";
			IDString added(c);
			IDstr.AddToStart(added);
			cout << "Результат: ";
			IDstr.ShowString();
			cout << "\n";
			break;
		}
		case 3:
			cout << "Введите символ: ";
			cin >> c;
			cout << "\n";
			//IDstr.AddToEnd(c);
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
	char arr[100];
	char c[100];
	do
	{
		cout << "1. Показать строку" << endl;
		cout << "2. Добавить символ в начало строки" << endl;
		cout << "3. Добавить символ в конец строки" << endl;
		cout << "4. Сдвиг влево" << endl;
		cout << "5. Сдвиг вправо" << endl;
		cout << "6. Удалить символ по номеру" << endl;
		cout << "7. Побитовое умножение" << endl;
		cout << "8. Выход" << endl;
		cin >> choosingVar;
		switch (choosingVar)
		{
		case 1:
			binStr.ShowString();
			break;
		case 2:
		{
			cout << "Введите символ: ";
			cin >> c;
			cout << "\n";
			BinString added(c);
			binStr.AddToStart(added);
			cout << "Результат: ";
			binStr.ShowString();
			cout << "\n";
			break;
		}
		case 3:
			cout << "Введите символ: ";
			cin >> c;
			cout << "\n";
			//if (binStr.AddToEnd(c));
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
		case 7:
			cout << "Укажите строку-множитель: ";
			cin >> arr;
			cout << '\n';
			binStr.BitWiseMult(arr);
			cout << "Результат: ";
			binStr.ShowString();
			cout << "\n";
			break;
		}
	} while (choosingVar != 8);
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
	setlocale(LC_ALL, "Rus");
	ChooseString();
}
