#ifndef COFFEE_MAKER_H_
#define COFFEE_MAKER_H_

#include <iostream>
#include <vector>
#include <string>

#include "featuretree.h"

class CoffeeMaker
{
public:
	CoffeeMaker(std::vector<std::string> initFeatureModels);
	void validate(std::string config);
private:
	std::vector<std::string> cleanFeatureModels(std::vector<std::string> featureModels);
	FeatureTree featureTree;
	std::vector<std::string> featureModels;
};

#endif