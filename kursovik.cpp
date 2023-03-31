#include <iostream>
#include <stdio.h>


class BaseString
{
public:
	char content[100];
	int length = sizeof(content) / sizeof(content[0]);

	void AddToStart(char c)
	{
		for (int i = length - 2; i >= 0; i--)
		{
			content[i + 1] = content[i];
		}

		content[0] = c;

	}

	void AddToEnd(char c)
	{
		int i = 0;
		while (content[i] != '\0')
		{
			i++;
			if (content[i] == '\0')
			{
				content[i] = c;
				content[i + 1] = '\0';
			}
		}
	}

	void ShowString()
	{
		std::cout << content << std::endl;
	}

	BaseString(char arr[])
	{
		for (int i = 0; i < length; i++)
		{
			content[i] = arr[i];
		}
	}

};

int main()
{
	char content[100];

	printf("Input:\n");
	scanf_s("%s", &content, (unsigned)_countof(content));

	BaseString based{ content };

	char c = 'h';

	based.AddToStart(c);
	printf("Output:\n");
	based.ShowString();
}

