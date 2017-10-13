#include "featurenode.h"

using namespace std;

FeatureNode::FeatureNode()
{
	parent = NULL;
}

FeatureNode::FeatureNode(string initName)
{
	name = initName;
	parent = NULL;
}

FeatureNode::FeatureNode(string initName,vector<string> initChildsName)
{
	name = initName;
	childsName = initChildsName;
	parent = NULL;
}

string FeatureNode::getName()
{
	return name;
}

void FeatureNode::setParent(FeatureNode * initParent)
{
	parent = initParent;
}

void FeatureNode::setChilds(vector<string> initChildsName)
{
	childsName = initChildsName;
}

bool FeatureNode::isParentSet()
{
	if (parent == NULL)
		return false;
	return true;
}

FeatureNode* FeatureNode::getParent()
{
	return parent;
}

vector<string> FeatureNode::getChilds()
{
	return childsName;
}