#pragma once
#include<string>
class Object
{
public:
	virtual std::ostream& print(std::ostream& oStream, Object& a) = 0;
	virtual std::istream& scan(std::istream& iStream, Object& a) = 0;
	virtual void out() = 0;
	virtual void in() = 0;
	virtual int get_id() = 0;
	virtual std::string get_name() = 0;
	virtual void* get_info()=0;
	virtual bool cmp(Object& x) = 0;
	virtual bool smaller(Object& x) = 0;
	virtual bool bigger(Object& x) = 0;
	virtual Object& unite(Object&) = 0;
	virtual Object& copy(Object&) = 0;
	
protected:
	friend std::ostream& operator<<(std::ostream& oStream, Object& a) {
		return a.print(oStream, a);
	}
	friend std::istream& operator>>(std::istream& iStream, Object& a) {
		return a.scan(iStream, a);
	}
};