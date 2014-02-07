#pragma once
#include <unordered_map>
#include <string>

typedef unsigned long int component_id;

// each component has a class id indicating the type of component it is
// this is a single bit number allowing bitwise operations 
// to compare multiple component types at a fast rate

class Component
{
public:
	const component_id type_id;
	virtual ~Component(void);
protected:
	Component(std::string);
private:
	// the shift value of the next class id to be created
	static int nextId_;
	// a list of all the currently created class ids
	static std::unordered_map<std::string, component_id> idList_;
};

