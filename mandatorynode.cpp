#include "mandatorynode.h"

using namespace std;

bool MandatoryNode::isConditionMet(vector<string> configList)
{
	string name = getName();
	for (int i=0;i<configList.size();i++)
	{
		if (name == configList[i])
			return true;
	}
	return false;
}