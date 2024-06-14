#include "MyString.h"
#include "MyStrLen.h"
using namespace std;

MyString::MyString()
{
	str = nullptr;
	length = 0;
}

MyString::MyString(const char *str)
{
	//cout << "Вызван конструктор " << this << endl;
	length = myStrLen(str);
	this->str = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		this->str[i] = str[i];
	}
	this->str[length] = '\0';
}

MyString MyString::Print()
{
	return str;
}

MyString::MyString(const MyString& other)
{
	//cout << "Вызван конструктор копирования копирования " << this << endl;
	length = myStrLen(other.str);
	this->str = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		this->str[i] = other.str[i];
	}
	this->str[length] = '\0';
}

MyString::MyString(MyString&& other)
{
	//cout << "Вызван конструктор перемещения копирования " << this << endl;
	this->length = other.length;
	this->str = other.str;
	other.str = nullptr;
}

MyString& MyString::operator=(const MyString& other)
{
	if (this->str!=nullptr)
	{
		delete[] str;
	}

	//cout << "Вызван переопределённый метод присваивания " << this << endl;
	length = myStrLen(other.str);
	this->str = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		this->str[i] = other.str[i];
	}
	this->str[length] = '\0';

	return *this;
}


MyString MyString::operator+(const MyString& other)
{
	//cout << "Вызван переопределённый метод конкатенации " << this << endl;
	length = myStrLen(this->str);
	otherLength = myStrLen(other.str);

	MyString subString;
	subString.str = new char[length + otherLength + 1];

	int i = 0;
	for (; i < length; i++)
	{
		subString.str[i] = this->str[i];
	}
	for (int j = 0; j < otherLength; j++,i++)
	{
		subString.str[i] = other.str[j];
	}
	subString.str[length + otherLength] = '\0';

	subString.length += otherLength + length;

	return subString;
}

bool MyString::operator==(const MyString& other)
{
	if (this->length!=other.length)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < this->length; i++)
		{
			if (this->str[i]!=other.str[i])
			{
				return false;
			}
		}
	}
	return true;
}

bool MyString::operator!=(const MyString& other)
{
	return !(this->operator==(other));
}

char MyString::operator[](int index)
{
	return this->str[index];
}

MyString::~MyString()
{
	//cout << "Вызван деструктор " << this << endl;
	delete[] this->str;
}

int MyString::getLength() const
{
	//cout << "Вызов метода получения длины" << endl;
	return length;
}

std::ostream& MyString::show(std::ostream& os) const
{
	//cout << "Вызов переопределенного оператора побайтового сдвига влево" << endl;
	return os << (str ? str : "");
}

std::istream& MyString::write(std::istream& is)
{
	//cout << "Вызов переопределенного оператора побайтового сдвига вправо" << endl;
	if (this->str != nullptr)
	{
		delete[] str;
	}

	char temp[255]{};
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	is.getline(temp,255);
	SetConsoleOutputCP(866);
	SetConsoleCP(866);

	int i = 0;
	while (temp[i] != '\0')
	{
		i++;
	}

	str = new char[i+1];
	for (int j = 0; j < i; j++)
	{
		str[j] = temp[j];
	}

	str[i] = '\0';
	length = myStrLen(str);
	
	return is;
}
