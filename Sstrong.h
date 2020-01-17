#pragma once
#include<string>
#include"Object.h"
#include<iostream>
class Sstrong : public Object
{
private:
	std::string data;
public:
	
	Sstrong(Sstrong&);
	Sstrong(std::string);
	Sstrong();
	std::string Get_int();
	void Set_int(std::string);
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
	operator std::string();
	friend std::ostream& operator<<(std::ostream& out, Sstrong& el);
	Object& unite(Object&);
	Object& copy(Object&);
};

