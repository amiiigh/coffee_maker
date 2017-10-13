#ifndef FEATURE_TREE_H_
#define FEATURE_TREE_H_

#define MANDATORY_OPTIONAL 0
#define OR 1
#define ALTERNATIVE 2

#include <vector>
#include <string>
#include <iostream>

#include "featurenode.h"
#include "mandatorynode.h"
#include "optionalnode.h"
#include "ornode.h"
#include "alternativenode.h"


class FeatureTree
{
public:
	FeatureTree(){}
	void buildTree(std::vector<std::string> featureModels);
	FeatureNode* getNodeByName(std::string nodeName);
	void createNodes(std::string featureName,std::vector<std::string> featureChilds,int relation);
	bool validate(std::vector<std::string> configList);
private:
	std::vector<FeatureNode*> nodes;
};

#endif