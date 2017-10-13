#include "featuretree.h"

using namespace std;

vector<string> childsNameFromStr(string featureModel)
{
	bool eqSeen = false;
	vector<string> childsName;
	string name = "";
	for(int i=0;i<featureModel.size();i++)
	{
		if (featureModel[i] == '=')
		{
			eqSeen = true;
			continue;
		}
		if (eqSeen)
		{
			if(featureModel[i] != '+' && featureModel[i] != '|' && featureModel[i] != '^')
				name+=featureModel[i];
			else
			{
				childsName.push_back(name);
				name = "";
				continue;
			}
		}
	}
	childsName.push_back(name);
	return childsName;
}

string featureNameFromStr(string featureModel)
{
	string featureName = "";
	for (int i = 0 ; i < featureModel.size() ; i++)
	{
		if (featureModel[i] != '=')
			featureName +=featureModel[i];
		else
			break;
	}
	return featureName;
}

string removeOptionalChar(string featureName)
{
	string name = "";
	for(int i=0;i<featureName.size();i++)
	{
		if (featureName[i]!='?')
			name +=featureName[i];
	}
	return name;
}	

int featureModelRelFromStr(string featureModel)
{
	if (featureModel.find('+') != string::npos) 
		return MANDATORY_OPTIONAL;
	else if(featureModel.find('|') != string::npos)
		return OR;
	else if(featureModel.find('^') != string::npos)
		return ALTERNATIVE;
	else 
		return -1;
}

bool nodeInList(string nodeName,vector<string>nodeList)
{
	for (int i =0;i<nodeList.size();i++)
	{
		if (nodeName == nodeList[i])
			return true;
	}
	return false;
}

bool isMyParentPresent(FeatureNode* a,vector<string> configList)
{
	FeatureNode * parent = a->getParent();
	if ( parent == NULL)
		return true;
	else if (nodeInList(parent->getName(),configList))
		return isMyParentPresent(parent,configList);
	else 
		return false;
}

FeatureNode* FeatureTree::getNodeByName(string nodeName)
{
	for (int i=0; i<nodes.size();i++)
	{
		if (nodes[i]->getName() == nodeName)
			return nodes[i];
	}
	return NULL;
}

void FeatureTree::createNodes(string featureName,vector<string> featureChilds,int relation)
{
	FeatureNode * parentNode = getNodeByName(featureName);
	if (parentNode == NULL)
	{
		FeatureNode *root = new MandatoryNode(featureName,featureChilds);
		root->setChilds(featureChilds);
		nodes.push_back(root);
	}
	else
	{
		parentNode->setChilds(featureChilds);
	}

	for(int i=0;i<featureChilds.size();i++)
	{
		FeatureNode * node = getNodeByName(featureChilds[i]);
		if (node == NULL)
		{
			if (relation == MANDATORY_OPTIONAL)
			{
				if (featureChilds[i][0] == '?')
					node = new OptionalNode(removeOptionalChar(featureChilds[i]));
				else
					node = new MandatoryNode(featureChilds[i]);
			}
			else if (relation == OR)
			{
				node = new OrNode(featureChilds[i]);
			}
			else
			{
				node = new AlternativeNode(featureChilds[i]);
			}
			node->setParent(getNodeByName(featureName));
			nodes.push_back(node);
		}
		else 
		{
			if(node->isParentSet() == false)
				node->setParent(getNodeByName(featureName));
		}
	}
}

void FeatureTree::buildTree(vector<string> featureModels)
{
	for (int i=0;i<featureModels.size();i++)
	{
		string featureName = featureNameFromStr(featureModels[i]);
		vector<string> featureChilds = childsNameFromStr(featureModels[i]);
		int relation = featureModelRelFromStr(featureModels[i]);
		createNodes(featureName,featureChilds,relation);
	}

}

bool FeatureTree::validate(vector<string> configList)
{
	for (int i=0;i<nodes.size();i++)
	{
		if (nodes[i]->isConditionMet(configList) == false)
		{
			return false;
		}
	}
	for (int i=0;i<configList.size();i++)
	{
		FeatureNode * node = getNodeByName(configList[i]);
		if (isMyParentPresent(node,configList) == false)
			return false;
	}
	return true;
}