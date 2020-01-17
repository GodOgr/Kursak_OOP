#include "Sint.h"
Sint::Sint(int x)
{
	data = x;
}

Sint::Sint(Sint& x)
{
	data = x.Get_int();
}

Sint::Sint(std::string x)
{
	data = atoi(x.c_str());
}

Sint::Sint()
{
	data = 0;
}

int Sint::Get_int()
{
	return data;
}

void Sint::Set_int(int a)
{
	data = a;
}

void Sint::out()
{
	std::cout << data;
}

void Sint::in()
{
	std::cin >> data;
}

int Sint::get_id()
{
	return typeid(*this).hash_code();
}

std::string Sint::get_name()
{
	return std::string(typeid(*this).name());
}

void* Sint::get_info()
{
	return &data;
}

bool Sint::cmp(Object& x)
{
	if (get_id() == x.get_id())
	{
		if (data == ((const Sint&)x).data)
			return true;
	}
	return false;
}

bool Sint::bigger(Object& x)
{
	if (get_id() == x.get_id())
	{
		if (data > ((const Sint&)x).data)
			return true;
	}
	return false;
}
bool Sint::smaller(Object& x)
{
	
	if (get_id() == x.get_id())
	{
		if (data < ((const Sint&)x).data)
			return true;
	}
	return false;
}

std::ostream& Sint::print(std::ostream& oStream, Object& a) {
	oStream << data;
	return oStream;
}
std::istream& Sint::scan(std::istream& iStream, Object& a) {
	iStream >> data;
	return iStream;
}

Object& Sint::unite(Object& x)
{
	if (get_id() == x.get_id())
	{
		Sint* temp = new Sint(((const Sint&)x).data);
		temp += data;
		return *temp;
	}
	return x;
}

Object& Sint::copy(Object& x)
{
	Sint* temp = new Sint(*(int*)(x.get_info()));
	return *temp;
}

Sint::operator int() {
	return Get_int();
}

std::ostream& operator<<(std::ostream& out, Sint& el)
{
	out << el.Get_int();
	return out;
}

std::istream& operator>>(std::istream& out, Sint& el)
{
	el.scan(out,el);
	return out;
}