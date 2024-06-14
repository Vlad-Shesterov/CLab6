#pragma once
#include "stdafx.h"

class MyString
{
private:
	char* str;
	int length, otherLength;
public:
	MyString();
	MyString Print();
	MyString(const char* str);
	MyString(const MyString& other);
	MyString(MyString&& other);
	MyString& operator =(const MyString& other);
	MyString operator +(const MyString& other);
	bool operator==(const MyString& other);
	bool operator!=(const MyString& other);
	char operator [](int index);
	~MyString();
	int getLength() const;
	std::ostream& show(std::ostream& os) const;
	friend std::ostream& operator << (std::ostream& os, const MyString& s)
	{
		return s.show(os);
	}
	std::istream& write(std::istream& is);
	friend std::istream& operator >> (std::istream& is, MyString& s)
	{
		return s.write(is);
	}
};

