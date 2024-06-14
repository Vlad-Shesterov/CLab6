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

	cout << "Результат присваивания между: \"" << firstString << "\" и \"" << secondString << "\" это - \"" << assignmentResult << "\"." << endl;

	MyString concatenateResult = firstString + secondString;

	cout<< "Результат конкатенации между: \"" << firstString << "\" и \"" << secondString << "\" это - \"" << concatenateResult << "\"." << endl;
	cout << "После конкатенации размер первой строки будет: " << firstString.getLength() << ", размер второй строки: " << secondString.getLength() << ", а размер итоговой строки станет: " << concatenateResult.getLength() << "." << endl;

	if (firstString == secondString)
	{
		cout << "Первая строка точно такая же, как и вторая." << endl;
	}
	else cout << "Первая строка отличается от второй." << endl;

	cout << "Введите собственную строку: " << endl;
	MyString stringIn;
	cin >> stringIn;
	cout << "Вы ввели: " << stringIn << ". Размер этой строки: " << stringIn.getLength() << endl;


	return 0;
}