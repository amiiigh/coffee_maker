#ifndef OR_NODE_H_
#define OR_NODE_H_

#include <iostream>
#include <vector>
#include <string>
#include "featurenode.h"

class OrNode : public FeatureNode
{
public:
	OrNode(std::string featureName,std::vector<std::string> childsName)
	: FeatureNode(featureName,childsName){}
	OrNode(std::string featureName)
	: FeatureNode(featureName){}
	virtual bool isConditionMet(std::vector<std::string> configList);
};

#endif