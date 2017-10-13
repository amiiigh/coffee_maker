#include "ornode.h"

using namespace std;

bool orInList(string name,vector<string> configList)
{
	for (int i=0;i<configList.size();i++)
	{
		if (name == configList[i])
			return true;
	}
	return false;
}

bool OrNode::isConditionMet(vector<string> configList)
{
	bool isCondtionMet = false;
	FeatureNode * parent = getParent();
	vector<string> siblingsName = parent->getChilds();
	for (int i=0;i<siblingsName.size();i++)
	{
		isCondtionMet = isCondtionMet || orInList(siblingsName[i],configList);
	}
	return isCondtionMet;
}