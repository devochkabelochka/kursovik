#include <iostream>
#include <stdio.h>


class BaseString
{
public:
	char content[100];
	int length;

	void StringCopy(char* dest, const char* source)
	{
		int i = 0;
		while (1)
		{
			dest[i] = source[i];

			if (dest[i] == '\0')
			{
				break;
			}

			i++;
		}
	}

	int StringLength(char str[])
	{
		int length = 0;
		while (str[length] != '\0')
		{
			length++;
		}
		return length;
	}

	void AddToStart(char c)
	{
		for (int i = length - 2; i >= 0; i--)
		{
			content[i + 1] = content[i];
		}

		content[0] = c;

	}

	BaseString* AddToEnd(char arr[], char c)
	{
		size_t i = 0;
		while (arr[i] != '\0')
			i++;
		arr[i] = c;
		arr[i] = '\0';
		return new BaseString(content, i);
	}

	void ShowString()
	{
		printf("%s", content);
	}

	BaseString(char arr[])
	{
		for (int i = 0; i < length; i++)
		{
			content[i] = arr[i];
		}
		length = StringLength(arr);
	}

	BaseString(char arr[], int size)
	{
		for (int i = 0; i < length; i++)
		{
			content[i] = arr[i];
		}
		length = size;
	}

};

int main()
{
	char content[100];

	printf("Input:\n");
	scanf_s("%s", &content, (unsigned)_countof(content));

	BaseString based{ content };

	char c = 'h';

	based.AddToEnd(content, c);
	printf("Output:\n");
	based.ShowString();
}
