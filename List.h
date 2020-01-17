#pragma once
#include"Object.h"
#include<string>
#include<iostream>
#include<fstream>
#include"Sint.h"
#include"Sdob.h"
#include"Sstrong.h"
#include"Real.h"
#include "Node.h"
class List
{
public:

	
	void Add_El(Object&);
	List(Object&);
	List();
	~List();
	void Show();
	void Sort(int x);
	void RemoveColon(Object&);
	void addline(int);
	void AddElement(Object&, int);
	void RemoveLine(int x);
	void wbin();
	void rbin();
	void RemoveColon(int x);
	Object* Remove_obj(Object&);
	void Kill();
	void InsideSwap(int i, int j);
	Object* Search(Object&);
	void add_empty(int x);
	void add_empty(int hash, int loc);
	void Print_txt();
	Object* getel(int, int);
	void Read_txt();
private:
	int n;
	int* hashes;
	Node* Head;
	void Normalize();
	Node* find_right(Object&);
};

