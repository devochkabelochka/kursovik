#include <iostream>
using namespace std;

//TODO: Fix menu, add more functions

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
	cout << "1. Показать строку" << endl;
	cout << "2. Добавить символ в начало строки" << endl;
	cout << "3. Добавить символ в конец строки" << endl;
	cout << "4. Выход" << endl;
	int choosingVar;
	cin >> choosingVar;
	char c;
	bool loop = true;

	while (loop)
	{
		loop = false;
		switch (choosingVar)
		{
		case 1:
			str.ShowString();
			loop = true;
			break;
		case 2:
			cout << "Введите символ: ";
			cin >> c;
			cout << "\n";
			str.AddToStart(c);
			cout << "Результат: ";
			str.ShowString();
			cout << "\n";
			loop = true; 
			break;
		case 3:
			cout << "Введите символ: ";
			cin >> c;
			cout << "\n";
			str.AddToEnd(c);
			cout << "Результат: ";
			str.ShowString();
			cout << "\n";
			loop = true;
			break;
		case 4:
			ChooseString();
			break;
		}
		break;
	}
}

void IDStringMenu(IDString IDstr)
{
	cout << "1. Показать строку" << endl;
	cout << "2. Добавить символ в начало строки" << endl;
	cout << "3. Добавить символ в конец строки" << endl;
	cout << "4. Выход" << endl;
	int choosingVar;
	cin >> choosingVar;
	char c;
	bool loop = false;

	while (loop == true)
	{
		loop = false;
		switch (choosingVar)
		{
		case 1:
			IDstr.ShowString();
			loop = true;
			break;
		case 2:
			cout << "Введите символ: ";
			cin >> c;
			cout << "\n";
			IDstr.AddToStart(c);
			cout << "Результат: ";
			IDstr.ShowString();
			cout << "\n";
			loop = true;
			break;
		case 3:
			cout << "Введите символ: ";
			cin >> c;
			cout << "\n";
			IDstr.AddToEnd(c);
			cout << "Результат: ";
			IDstr.ShowString();
			cout << "\n";
			loop = true;
			break;
		case 4:
			ChooseString();
			break;
		}
	}
}

void BinStringMenu(BinString binStr)
{
	cout << "1. Показать строку" << endl;
	cout << "2. Добавить символ в начало строки" << endl;
	cout << "3. Добавить символ в конец строки" << endl;
	cout << "4. Выход" << endl;
	int choosingVar;
	cin >> choosingVar;
	char c;
	bool loop = true;

	while (loop == true)
	{
		loop = false;
		switch (choosingVar)
		{
		case 1:
			binStr.ShowString();
			loop = true;
			break;
		case 2:
			cout << "Введите символ: ";
			cin >> c;
			cout << "\n";
			binStr.AddToStart(c);
			cout << "Результат: ";
			binStr.ShowString();
			cout << "\n";
			loop = true;
			break;
		case 3:
			cout << "Введите символ: ";
			cin >> c;
			cout << "\n";
			binStr.AddToEnd(c);
			cout << "Результат: ";
			binStr.ShowString();
			cout << "\n";
			loop = true;
			break;
		case 4:
			ChooseString();
			break;
		}
	}
}

void ChooseString()
{
	cout << "1. Строка" << endl;
	cout << "2. Строка-идентификатор" << endl;
	cout << "3. Бинарная строка" << endl;
	cout << "4. Выход" << endl;
	int choosingVar;
	cin >> choosingVar;
	cout << "Введите строку: ";
	char content[100];
	cin >> content;
	Base str(content);
	BinString binStr(content);
	IDString IDstr(content);

	bool loop = true;

	while (loop == true)
	{
		loop = false;
		switch (choosingVar)
		{
		case 1:
			BaseStringMenu(str);
			loop = true;
			break;
		case 2:
			IDStringMenu(IDstr);
			loop = true;
			break;
		case 3:
			BinStringMenu(binStr);
			loop = true;
			break;
		case 4:
			return;
		}
		return;
	}

}

int main()
{
	setlocale(LC_ALL, "Rus");
	ChooseString();
}
