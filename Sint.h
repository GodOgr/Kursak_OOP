#pragma once
#include<string>
#include"Object.h"
#include<iostream>
class Sint : public Object
{
private:
	int data;
public:
	Sint(int x);
	Sint(Sint&);
	Sint(std::string);
	Sint();
	int Get_int();
	void Set_int(int);
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
	friend std::ostream& operator<<(std::ostream& out, Sint& el);
	friend std::istream& operator>>(std::istream& out, Sint& el);
	Object& unite(Object&);
	Object& copy(Object&);
};

