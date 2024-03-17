#include <iostream>
#include <string>

using namespace std;

typedef pair<int, int>(*functionPointer)(string, string);

#include "BM.h"
#include "KMP.h"


int main()
{
	setlocale(LC_ALL, "RUS");

	functionPointer functions[] = {&KMPSearch};

	for (functionPointer function : functions)
	{
		cout << "Введите строку" << endl;

		string Line;
		string subLine;

		getline(cin, Line);

		cout << "Введите под строку" << endl;

		getline(cin, subLine);

		pair<int, int> result = function(Line, subLine);

		if (result.first == -1)
			cout << "Подстрока не найдена" << endl;
		else
			cout << "Начало подстроки: " << result.first << " конец: " << result.second;
	}
}
