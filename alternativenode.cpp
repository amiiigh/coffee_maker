#include "alternativenode.h"

using namespace std;

int altInList(string name,vector<string> configList)
{
	for (int i=0;i<configList.size();i++)
	{
		if (name == configList[i])
			return 1;
	}
	return 0;
}

bool AlternativeNode::isConditionMet(vector<string> configList)
{
	int count = 0;
	FeatureNode * parent = getParent();
	vector<string> siblingsName = parent->getChilds();
	for (int i=0;i<siblingsName.size();i++)
	{
		count += altInList(siblingsName[i],configList);
	}
	if (count == 1)
		return true;
	else
		return false;
}

string AlternativeNode::nodeType()
{
	return "alternative";
}