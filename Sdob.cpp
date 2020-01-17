#include "Sdob.h"

Sdob::Sdob(double x)
{
	data = x;
}
Sdob::Sdob(Sdob& x)
{
	data = x.Get_double();
}
Sdob::Sdob()
{
	data = 0;
}
Sdob::Sdob(std::string x)
{
	data = std::stod(x);
}

double Sdob::Get_double()
{
	return data;
}

void Sdob::Set_double(double a)
{
	data = a;
}

void Sdob::out()
{
	std::cout << data;
}

void Sdob::in()
{
	std::cin >> data;
}

int Sdob::get_id()
{
	return typeid(*this).hash_code();
}

std::string Sdob::get_name()
{
	return std::string(typeid(*this).name());
}

void* Sdob::get_info()
{
	return &data;
}

bool Sdob::cmp(Object& x)
{
	if (get_id() == x.get_id())
	{
		if (data == ((const Sdob&)x).data)
			return true;
	}
	return false;
}

bool Sdob::bigger(Object& x)
{
	if (get_id() == x.get_id())
	{
		if (data > ((const Sdob&)x).data)
			return true;
	}
	return false;
}
bool Sdob::smaller(Object& x)
{
	if (get_id() == x.get_id())
	{
		if (data < ((const Sdob&)x).data)
			return true;
	}
	return false;
}

std::ostream& Sdob::print(std::ostream& oStream, Object& a) {
	oStream << data;
	return oStream;
}
std::istream& Sdob::scan(std::istream& iStream, Object& a) {
	iStream >> data;
	return iStream;
}

Object& Sdob::unite(Object& x)
{
	Sdob* temp = new Sdob(*(double*)(x.get_info()));
	return *temp;
}

Object& Sdob::copy(Object& x)
{
	Sdob* temp = new Sdob(*(double*)(x.get_info()));
	return *temp;
}

Sdob::operator int() {
	return int(Get_double());
}

std::ostream& operator<<(std::ostream& out, Sdob& el)
{
	out << el.Get_double();
	return out;
}
