

#include "stdafx.h"
#include <iostream>
using namespace std;

class BaseString
{
protected:
	char content[100];
	int length;

public:
	BaseString(char arr[])
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

	BaseString(char c)
	{
		content[0] = c;
		content[1] = '\0';
		length = 1;
	}

	BaseString()
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
		content [length] = c;
		content[++length] = '\0';
	}

	void ShowString()
	{
		cout << "content: " << content << ", length: " << length << endl;
	}

};

int main()
{
	char Content[100], CC='*', AA='x';

	cout<<"Input:"<<endl;
	cin >> Content;
	BaseString first(Content);
	first.ShowString();
	first.AddToStart('!');
	first.ShowString();
	BaseString second(CC);
	second.ShowString();
	second.AddToStart(CC);
	second.ShowString();
	BaseString third;
	third.ShowString();
	third.AddToStart(AA);
	third.ShowString();

	/*scanf("%s", &content);

	BaseString based{ content };

	char c;
	scanf("%s", &c);

	based.AddToEnd(content, c);
	printf("Output:\n");
	based.ShowString();*/
}
