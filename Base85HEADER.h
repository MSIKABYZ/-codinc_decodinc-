#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

/**
\brief Base85 class

Class of coding program module
*/
class Base85
{
private:
	/**
	\brief String alphabet

	The string is used for coding/decoding
*/
	string alfabet = "&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz";
public:
	/**
	\brief Function coder
	The function is used to code the text with base85

	Input parameters:

	input: Input text string

	len: Length of the input string

	\return Complited code string

	Code:
	\code
	string output("");
	int a = len, b = a * 8 / 6;
	if (a * 8 % 6 != 0)
		b++;
	unsigned char *q;
	bool *buff;
	int j = 0;
	buff = new bool[a * 8];
	q = new unsigned char[b];
	for (int i = 1; i < a + 1; i++)
	{
		for (int k = 1; k < 9; k++)
		{
			buff[j] = (input[i - 1] >> (k - 1)) & 1;
			j++;
		}
	}
	int num = 0;
	cout << endl;
	for (int l = 0; l < b; l++)
	{
		q[l] = 0;
		for (int i = 0; i < 6; i++)
		{
			if (buff[num] == 1)
				q[l] = q[l] | (1 << i);
			num++;
		}
		output += alfabet[(unsigned int)q[l]];
	}
	return output;
	\endcode
*/
	string coder(char* input, int len);
	/**
	\brief Function decoder
	The function is used to decode the text with base85

	Input parameters :

	input: Input text string

	len: Length of the input string

	\return Complited decode string

	Code:
	\code
	string Base85::decoder(char* input, int len)
	{
		string output("");
		int a = len, b = a * 6 / 8;
		if (a * 6 % 8 != 0)
			b++;
		unsigned char* q;
		bool* buff;
		int j = 0;
		buff = new bool[a * 6];
		q = new unsigned char[b];
		for (int i = 1; i < a + 1; i++)
		{
			for (int k = 1; k < 7; k++)
			{
				for (int l = 0; l < 85; l++)
					if (input[i - 1] == alfabet[l])
						buff[j] = (l >> (k - 1)) & 1;
				j++;
			}
		}
		int num = 0;
		for (int l = 0; l < b; l++)
		{
			q[l] = 0;
			for (int i = 0; i < 8; i++)
			{
				if (buff[num] == 1)
					q[l] = q[l] | (1 << i);
				num++;
			}
			output += q[l];
		}
		return output;
	}
	\endcode
	*/
	string decoder(char* input, int len);
};
string Base85::coder(char* input, int len)
{
	string output("");
	int a = len, b = a * 8 / 6;
	if (a * 8 % 6 != 0)
		b++;
	unsigned char *q;
	bool *buff;
	int j = 0;
	buff = new bool[a * 8];
	q = new unsigned char[b];
	for (int i = 1; i < a + 1; i++)
	{
		for (int k = 1; k < 9; k++)
		{
			buff[j] = (input[i - 1] >> (k - 1)) & 1;
			j++;
		}
	}
	int num = 0;
	cout << endl;
	for (int l = 0; l < b; l++)
	{
		q[l] = 0;
		for (int i = 0; i < 6; i++)
		{
			if (buff[num] == 1)
				q[l] = q[l] | (1 << i);
			num++;
		}
		output += alfabet[(unsigned int)q[l]];
	}
	return output;
}
string Base85::decoder(char* input, int len)
{
	string output("");
	int a = len, b = a * 6 / 8;
	if (a * 6 % 8 != 0)
		b++;
	unsigned char *q;
	bool *buff;
	int j = 0;
	buff = new bool[a * 6];
	q = new unsigned char[b];
	for (int i = 1; i < a + 1; i++)
	{
		for (int k = 1; k < 7; k++)
		{
			for (int l = 0; l < 85; l++)
				if (input[i - 1] == alfabet[l])
					buff[j] = (l >> (k - 1)) & 1;
			j++;
		}
	}
	int num = 0;
	for (int l = 0; l < b; l++)
	{
		q[l] = 0;
		for (int i = 0; i < 8; i++)
		{
			if (buff[num] == 1)
				q[l] = q[l] | (1 << i);
			num++;
		}
		output += q[l];
	}
	return output;
}