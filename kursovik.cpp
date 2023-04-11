#include <iostream>
#include <stdio.h>


class BaseString
{
public:
	char* content;
	unsigned int length;

	BaseString(char* arr)
	{
		content = arr;
		length = GetSize(arr);
	}

	BaseString(char* arr, int size)
	{
		content = arr;
		length = size;
	}

	int GetSize(char* str) 
	{
		int result = 0;
		while (str[result] != '\0')
		{
			result++;
		}
		return result;
	}

	char* StringCopy(char* dest, const char* src)
	{
		if (dest == NULL) 
		{
			return NULL;
		}

		char* ptr = dest;

		while (*src != '\0')
		{
			*dest = *src;
			dest++;
			src++;
		}

		*dest = '\0';

		return ptr;
	}

	BaseString* AddToEnd(char* c)
	{
		return AddToEnd(new BaseString(c));
	}

	BaseString* AddToEnd(BaseString* c)
	{
		int totalSize = this->length + c->length;
		char* buffer = new char[totalSize];

		buffer = StringCopy(buffer, content);

		for (int j = 0; j < c->length - 1; j++)
		{
			buffer[this->length + j] = c->content[j];
		}

		return new BaseString(buffer, totalSize);
	}

	BaseString* AddToStart(char* c)
	{
		return AddToStart(new BaseString(c));
	}

	BaseString* AddToStart(BaseString* c)
	{
		int totalSize = this->length + c->length;
		char* buffer = new char[totalSize];

		for (int i = 0; i < c->length; i++)
		{
			buffer[this->length + i] = c->content[i];
		}

		buffer = StringCopy(buffer, content);

		return new BaseString(buffer, totalSize);
	}

	void ShowString()
	{
		std::cout << content << std::endl;
	}

};

int main()
{
	BaseString* balls = new BaseString((char*)"content");

	balls->AddToEnd((char*)"dlc");
	balls->ShowString();

	return 0;
}

