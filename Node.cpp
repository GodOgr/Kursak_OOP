#include "Node.h"
using namespace std;
void Node::Add_to_array(Object& x)
{
	vector->Add(x);
}

Node::Node(Object& x)
{
	hash = typeid(x).hash_code();
	name = typeid(x).name();
	vector = new Array(0);
	next = nullptr;
}

Node::Node()
{
	next = nullptr;
	vector = nullptr;
	hash = -1;
}



