#pragma once
#include "Object.h"
#include "Array.h"
#include<string>
class Array;

class Node
{
public:
	Array* vector;
	Node* next;
	std::string name;
	void Add_to_array(Object&);
	void Add_to_array(Object&,int);
	int hash;
	Node(Object&);
	Node();
	
};


