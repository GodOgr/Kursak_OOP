#pragma once
#include<string>
#include"Object.h"
#include<iostream>
class Sdob : public Object
{
private:
	
public:
	double data;
	Sdob(double x);
	Sdob(Sdob&);
	Sdob();
	Sdob(std::string);
	double Get_double();
	void Set_double(double);
	std::ostream& print(std::ostream& oStream, Object& a);
	std::istream& scan(std::istream& iStream, Object& a);
	void out();
	void in();
	int get_id();
	std::string get_name();
	void* get_info();
	bool cmp(Object&);
	bool bigger(Object& x);
	bool smaller(Object& x);
	operator int();
	friend std::ostream& operator<<(std::ostream& out, Sdob& el);
	Object& unite(Object&);
	Object& copy(Object&);
};

