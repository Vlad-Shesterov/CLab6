#include "stdafx.h"
#include "MyString.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	MyString firstString("HelloWorld! ");
	MyString secondString = "\\0_0/";

	MyString assignmentResult = firstString;
	assignmentResult = secondString;

	cout << "��������� ������������ �����: \"" << firstString << "\" � \"" << secondString << "\" ��� - \"" << assignmentResult << "\"." << endl;

	MyString concatenateResult = firstString + secondString;

	cout<< "��������� ������������ �����: \"" << firstString << "\" � \"" << secondString << "\" ��� - \"" << concatenateResult << "\"." << endl;
	cout << "����� ������������ ������ ������ ������ �����: " << firstString.getLength() << ", ������ ������ ������: " << secondString.getLength() << ", � ������ �������� ������ ������: " << concatenateResult.getLength() << "." << endl;

	if (firstString == secondString)
	{
		cout << "������ ������ ����� ����� ��, ��� � ������." << endl;
	}
	else cout << "������ ������ ���������� �� ������." << endl;

	cout << "������� ����������� ������: " << endl;
	MyString stringIn;
	cin >> stringIn;
	cout << "�� �����: " << stringIn << ". ������ ���� ������: " << stringIn.getLength() << endl;


	return 0;
}