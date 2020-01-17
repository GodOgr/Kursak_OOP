#include "Array.h"

void Array::Add(Object& x)
{
	bool bal = true;
	for (int i = 0; i < size; i++)
	{
		if (array[i] == nullptr) {
			array[i] = &x;
			bal = false;
			break;
		}
	}
	if (bal)
	{
		Expanse(1);
		array[size - 1] = &x;
	}
}
Object* Array::Add_S(Object& x, int location)
{
	if (location < size)
	{

		Object* temp = array[location];
		array[location] = &x;
		return temp;
	}
	
	Expanse(1);
	array[size - 1] = &x;
	return nullptr;

}
void Array::Add(Object& x, int location)
{
	Expanse(1);
	for (int i = size; i >location; i--)
	{
		array[i] = array[i - 1];
	}
	array[location] = &x;
}

void Array::Remove(Object& x)
{
	for (int i = 0; i < size; i++)
	{
		if(array[i]!=nullptr)
		if (array[i]->cmp(x))
		{
			array[i] = nullptr;
			
			break;
		}
	}
	Norm();
}

void Array::Remove(int location)
{
	for (int i = location; i < size-1;i++)
	{
		array[i] = array[i + 1];
	}
	Expanse(-1);
}

Array::Array(int size)
{
	this->size = size;
	array = new Object* [size];
	for (int i = 0; i < size; i++)
		array[i] = nullptr;
}

void Array::Norm()
{
	for (int i = 0; i < size - 1; i++)
	{
		if (array[i] == nullptr) {
			for (int j = i; j < size; j++)
			{
				if (array[j] != nullptr)
				{
					array[i] = array[j];
					array[j] = nullptr;
					break;
				}
			}
		}
	}
}

void Array::Add_empty()
{
	Object** temp = new Object * [size + 1];
	for (int i = 0; i < size; i++)
		temp[i] = array[i];
	delete(array);
	array = temp;
	size += 1;
	array[size - 1] = nullptr;
}

void Array::Add_empty(int location)
{
	Expanse(1);
	for (int i = size; i > location; i--)
	{
		array[i] = array[i - 1];
	}
	array[location] = nullptr;
}
Object* Array::Add_empty_S(int location)
{
	if (location < size)
	{
		Object* temp = array[location];
		array[location] = nullptr;
		return temp;
	}

	Expanse(1);
	array[size - 1] = nullptr;
	return nullptr;
}


void Array::Expanse(int k)
{
	Object** temp= new Object * [size+k];
	for (int i = 0; i < size+k; i++)
		temp[i] = array[i];
	delete(array);
	array = temp;
	size += k;
}

void Array::Swap(int a, int b)
{
	Object* temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

void Array::Print()
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] != nullptr) {
			array[i]->out();
			std::cout << "  ";
		}
		else std::cout << "[Empty_slot]";
	}
}

Object* Array::Search(Object& x)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i]->cmp(x))
			return array[i];
	}
	return nullptr;
}

void Array::Get_raven(int x)
{
	if (x > size)
	{
		int sdvig = x - size;
		Expanse(sdvig);
		while (sdvig)
		{
			array[size - sdvig] = nullptr;
			sdvig--;
		}
	}
}


