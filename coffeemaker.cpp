#include "coffeemaker.h"

using namespace std;

string removeWhitespaces(string input)
{
	string clean = "";
	for (int i=0; i<input.size();i++)
	{
		if (input[i] != ' ')
			clean += input[i];
	}
	return clean;
}

vector<string> toConfigVector(string configListStr)
{
	vector<string> configList;
	string config = "";
	for(int i=0;i<configListStr.size();i++)
	{
		if (configListStr[i] != '{' && configListStr[i] != '}' && configListStr[i] != ',' && configListStr[i] != ' ')
			config += configListStr[i];
		if (configListStr[i] == ',')
		{
			configList.push_back(config);
			config = "";
		}
	}
	configList.push_back(config);
	return configList;
}

CoffeeMaker::CoffeeMaker(vector<string> initFeatureModels)
{
	featureModels = cleanFeatureModels(initFeatureModels);
	featureTree.buildTree(featureModels);
}

void CoffeeMaker::validate(string config)
{
	vector<string> configList = toConfigVector(config);
	if (featureTree.validate(configList) == false)
		cout << "Invalid" <<endl;
	else
		cout << "Valid" <<endl;
}

vector<string> CoffeeMaker::cleanFeatureModels(vector<string> featureModels)
{
	for (int i=0;i<featureModels.size();i++)
		featureModels[i] = removeWhitespaces(featureModels[i]);
	return featureModels;
}


