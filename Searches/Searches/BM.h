#pragma once
#include <iostream>

using namespace std;

pair<int, int> BMSearch(string mainString, string substring)
{
	cout << "Метод Бойлера - Мура!" << endl;

	if (substring.size() < 1 || mainString.size() < 1)
		return {-1, -1};

	int sbLenght = substring.length();

	int* tablet = new int[256];

	for (int i = 0; i < 256; i++)
		tablet[i] = sbLenght;

	for (int i = sbLenght - 2; i > -1; i--)
	{
		if (tablet[(int)((unsigned char)substring[i])] == sbLenght)
			tablet[(int)((unsigned char)substring[i])] = sbLenght - i - 1;
	}

	pair<int, int> result = {-1, -1};
	int currentIndexOnMain = sbLenght - 1;

	while (currentIndexOnMain < mainString.length() && result.first == -1)
	{
		bool flag = true;
		for (int i = sbLenght - 1; i > -1 && flag; i--)
		{
			int indexOfMainString = currentIndexOnMain - sbLenght + i + 1;

			flag = substring[i] == mainString[indexOfMainString];

			if (!flag)
				currentIndexOnMain += tablet[(int)((unsigned char)mainString[indexOfMainString])];

			else if (i == 0)
			{
				int startIndex = indexOfMainString;
				int endIndex = indexOfMainString + sbLenght - 1;
				result = { startIndex, endIndex };
			}
		}
	}

	delete[] tablet;
	return result;
}
