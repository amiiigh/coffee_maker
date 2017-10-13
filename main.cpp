#include <iostream>
#include <string>
#include <vector>

#include "coffeemaker.h"

using namespace std;

int main()
{
	string line;
	while (getline(cin, line))
	{
		vector<string> featureModels;
		featureModels.push_back(line);

		while(getline(cin,line))
		{
			if (line[0] == '#')
				break;
			featureModels.push_back(line);
		}

		CoffeeMaker CM (featureModels);
		while(getline(cin,line))
		{
			if (line[0] == '#')
				break;
			CM.validate(line);
		}
		cout << "##" << endl;
	}
}