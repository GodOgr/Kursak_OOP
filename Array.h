#pragma once
#include"Object.h"
#include<iostream>
class Array
{
public:
	Object** array;
	int size;
	void Add(Object&);
	Object* Add_S(Object& x, int location);
	void Add(Object&, int);
	void Remove(Object&);
	void Remove(int);
	void Add_empty();
	void Add_empty(int);
	Object* Add_empty_S(int location);
	Array(int size);
	void Norm();
	void Expanse(int);
	void Swap(int a, int b);
	void Print();
	Object* Search(Object&);
	void Get_raven(int);
};

