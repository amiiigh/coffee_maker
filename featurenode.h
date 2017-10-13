#ifndef FEATURE_NODE_H_
#define FEATURE_NODE_H_

#include <vector>
#include <string>

class FeatureNode
{
public:
	FeatureNode();
	FeatureNode(std::string initName);
	FeatureNode(std::string initName,std::vector<std::string> childsName);
	virtual bool isConditionMet(std::vector<std::string> configList) = 0;
	void addChild(std::string nodeName,int relation);
	bool isParentSet();
	void setParent(FeatureNode *initParent);
	void setChilds(std::vector<std::string> initChildsName);
	std::string getName();
	FeatureNode* getParent();
	std::vector<std::string> getChilds();
private:
	std::string name;
	FeatureNode *parent;
	std::vector<std::string> childsName;
};

#endif