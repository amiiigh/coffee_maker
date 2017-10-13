#ifndef OPTIONAL_NODE_H_
#define OPTIONAL_NODE_H_

#include <iostream>
#include <vector>
#include <string>
#include "featurenode.h"

class OptionalNode : public FeatureNode
{
public:
	OptionalNode(std::string featureName,std::vector<std::string> childsName)
	: FeatureNode(featureName,childsName){}
	OptionalNode(std::string featureName)
	: FeatureNode(featureName){}
	virtual bool isConditionMet(std::vector<std::string> configList);
};

#endif