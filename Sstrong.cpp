#include "Sstrong.h"
Sstrong::Sstrong(std::string x)
{
	data = x;
}





Sstrong::Sstrong()
{
	data = "";
}

std::string Sstrong::Get_int()
{
	return data;
}

void Sstrong::Set_int(std::string a)
{
	data = a;
}

void Sstrong::out()
{
	std::cout << data;
}

void Sstrong::in()
{
	std::cin >> data;
}

int Sstrong::get_id()
{
	return typeid(*this).hash_code();
}

std::string Sstrong::get_name()
{
	return std::string(typeid(*this).name());
}

void* Sstrong::get_info()
{
	return &data;
}

bool Sstrong::cmp(Object& x)
{
	if (get_id() == x.get_id())
	{
		if (data == ((const Sstrong&)x).data)
			return true;
	}
	return false;
}

bool Sstrong::bigger(Object& x)
{
	if (get_id() == x.get_id())
	{
		if (data > ((const Sstrong&)x).data)
			return true;
	}
	return false;
}
bool Sstrong::smaller(Object& x)
{

	if (get_id() == x.get_id())
	{
		if (data < ((const Sstrong&)x).data)
			return true;
	}
	return false;
}

std::ostream& Sstrong::print(std::ostream& oStream, Object& a) {
	oStream << data;
	return oStream;
}
std::istream& Sstrong::scan(std::istream& iStream, Object& a) {
	iStream >> data;
	return iStream;
}

Object& Sstrong::unite(Object& x)
{
	Sstrong* temp = new Sstrong(*(std::string*)(x.get_info()));
	return *temp;
}

Object& Sstrong::copy(Object& x)
{
	Sstrong* temp = new Sstrong(*(std::string*)(x.get_info()));
	return *temp;
}

Sstrong::operator std::string() {
	return Get_int();
}

std::ostream& operator<<(std::ostream& out, Sstrong& el)
{
	out << el.Get_int();
	return out;
}

std::istream& operator>>(std::istream& out, Sstrong& el)
{
	el.scan(out, el);
	return out;
}