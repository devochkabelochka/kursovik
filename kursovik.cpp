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

	void ShowString()
	{
		cout << "content: " << content << ", length: " << length << endl;
	}

};

class IDString : public Base
{
protected:
	char content[100];
	int length;
public:
	IDString(char arr[])
	{
		int i = 0;
		while (arr[i] != '\0')
		{
			i++;
		}
		content[i] = '\0';
		length = i;
	}

	IDString(char c)
	{
		content[0] = c;
		content[1] = '\0';
		length = 1;
	}

	IDString()
	{
		content[0] = '\0';
		length = 0;
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
		while (arr[i] != '\0')
		{
			i++;
		}
		content[i] = '\0';
		length = i;
	}

	BinString(char c)
	{
		content[0] = c;
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

	do
	{
		cout << "1. Показать строку" << endl;
		cout << "2. Добавить символ в начало строки" << endl;
		cout << "3. Добавить символ в конец строки" << endl;
		cout << "4. Выход" << endl;
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
			ChooseString();
			break;
		}
	} while (choosingVar != 4);
}

void IDStringMenu(IDString IDstr)
{
	int choosingVar;
	char c;

	do
	{
		cout << "1. Показать строку" << endl;
		cout << "2. Добавить символ в начало строки" << endl;
		cout << "3. Добавить символ в конец строки" << endl;
		cout << "4. Выход" << endl;
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
			ChooseString();
			break;
		}
	} while (choosingVar != 4);
}

void BinStringMenu(BinString binStr)
{
	int choosingVar;
	char c;

	do
	{
		cout << "1. Показать строку" << endl;
		cout << "2. Добавить символ в начало строки" << endl;
		cout << "3. Добавить символ в конец строки" << endl;
		cout << "4. Выход" << endl;
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
			ChooseString();
			break;
		}
	} while (choosingVar != 4);
}

void ChooseString()
{
	int choosingVar;
	char arr[100];
	char content[100] = { '0' };
	Base str(content);
	BinString binStr(content);
	IDString IDstr(content);
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
			IDStringMenu(arr);
			break;
		case 3:
			cout << "Введите строку: ";
			cin >> arr;
			BinStringMenu(arr);
			break;
		case 4:
			return;
		}
		return;
	}while (choosingVar != 4);
}

int main()
{
	setlocale(LC_ALL, "Rus");
	ChooseString();
	
}
