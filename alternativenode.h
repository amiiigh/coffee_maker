#ifndef ALTERNATIVE_NODE_H_
#define ALTERNATIVE_NODE_H_

#include <iostream>
#include <vector>
#include <string>
#include "featurenode.h"

class AlternativeNode : public FeatureNode
{
public:
	AlternativeNode(std::string featureName,std::vector<std::string> childsName)
	: FeatureNode(featureName,childsName){}
	AlternativeNode(std::string featureName)
	: FeatureNode(featureName){}
	virtual bool isConditionMet(std::vector<std::string> configList);
	virtual std::string nodeType();
};

#endif