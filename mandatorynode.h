#ifndef MANDATORY_NODE_H_
#define MANDATORY_NODE_H_

#include <iostream>
#include <vector>
#include <string>
#include "featurenode.h"

class MandatoryNode : public FeatureNode
{
public:
	MandatoryNode(std::string featureName,std::vector<std::string> childsName)
	: FeatureNode(featureName,childsName){}
	MandatoryNode(std::string featureName)
	: FeatureNode(featureName){}
	virtual bool isConditionMet(std::vector<std::string> configList);
};

#endif