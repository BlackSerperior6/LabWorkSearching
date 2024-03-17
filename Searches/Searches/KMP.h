#pragma once

#include <iostream>

using namespace std;

void generate_pref_functions(string substring, int* d) 
{
	d[0] = 0;
	int j = 0;
	int i = 1;

	while (i < substring.length())
	{
		if (substring[i] == substring[j])
		{
			d[i] = j + 1;
			j++;
			i++;
		}
		else if (j == 0)
		{
			d[i] = 0;
			i++;
		}
		else
			j = d[j - 1];
	}
}

pair<int, int> KMPSearch(string Line, string subLine)
{
	cout << "Ìועמה ÊÌÏ!" << endl;
	int* d = new int[subLine.length()];

	generate_pref_functions(subLine, d);

	int i = 0, j = 0;

	pair<int, int> result = { -1, -1 };

	while (i < Line.length() && result.first == -1)
	{
		if (j == subLine.length() - 1)
		{
			result.first = i - subLine.length() + 1;
			result.second = i;
		}

		else if (subLine[j] == Line[i])
		{
			i++;
			j++;
		}

		else if (i < Line.length())
		{
			if (j == 0)
				i++;
			else
				j = d[j - 1];
		}
	}

	delete[] d;
	return result;
}