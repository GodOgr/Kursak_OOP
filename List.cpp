#include "List.h"
using namespace std;
void List::Add_El(Object& x)
{
	Node* cur = find_right(x);
	if (cur == nullptr)
	{
		Head = new Node(x);
		Head->vector->Add(x);
		Normalize();
		return;
	}
	int hash_x = typeid(x).hash_code();
	if (cur->hash == hash_x)
	{
		cur->vector->Add(x);
		Normalize();
		return;
	}
	cur->next = new Node(x);
	cur->next->Add_to_array(x);
	Normalize();
}

List::List(Object& x)
{
	Head = nullptr;
	Add_El(x);
}

List::List()
{
	Head = nullptr;
	n = 2;
}

void List::Show()
{
	if (Head == nullptr)return;
	Node* current = Head;
	int c = 0;
	while (current != nullptr)
	{
		cout<<current->name.substr(6);
		cout << "		";
		current = current->next;
	}
	current = Head;
	cout << "\n";
	while (c!=Head->vector->size)
	{
		while (current != nullptr) {
			if (current->vector->array[c] != nullptr)
				cout << *current->vector->array[c];
			else cout << "[slot]";
			cout << "		";
			current = current->next;
			
		}
		cout << "\n";
		c++;
		current = Head;
	}
}

void List::RemoveColon(int hash_x)
{
	if (Head == nullptr)
		return;
	
	if (Head->hash == hash_x)
	{
		Node* nt = Head->next;
		delete Head->vector;
		delete Head;
		Head = nt;
		return;
	}
	Node* current = Head;
	Node* precurrent = Head;
	while (current != nullptr)
	{
		if (current->hash != hash_x)
		{
			precurrent = current;
			current = current->next;
		}
		else
		{
			delete current->vector;
			precurrent->next = current->next;
			delete current;
			return;
		}
	}

}


Object* List::Remove_obj(Object& x)
{
	Node* cur = find_right(x);
	if ((cur == nullptr) || (x.get_id() != cur->hash))
		return nullptr;
	cur->vector->Remove(x);
}

Node* List::find_right(Object& x)
{
	if (Head == nullptr)
		return nullptr;
	Node* current = Head;
	Node* precurrent = Head;
	int hash_x = typeid(x).hash_code();
	while (current != nullptr)
	{
		if (current->hash != hash_x)
		{
			precurrent = current;
			current = current->next;
		}
		else
			return current;
	}
	return precurrent;
	
}

Object* List::Search(Object& x)
{
	Node* cur = find_right(x);
	if ((cur == nullptr) || (x.get_id() != cur->hash))
		return nullptr;
	return cur->vector->Search(x);
	
}

void List::add_empty(int x)
{
	if (Head == nullptr)return;
	Node* current = Head;
	while (current != nullptr)
	{
		if (x == current->hash)
		{
			current->vector->Add_empty(); break;
		}
		current = current->next;
	}
}

void List::add_empty(int hash, int loc)
{
	
	Node* current = Head;
	
	
	while (current != nullptr)
	{
		if (current->hash == hash)
		{
			
			current->vector->Add_empty_S(loc);
			Normalize();
			break;
		}
		current = current->next;
	}
	
}

void List::InsideSwap(int i, int j)
{
	if (Head == nullptr)
		return;
	Node* current = Head;
	Node* precurrent = Head;
	Object* buf;
	while (current != nullptr)
	{
		
			if (i < current->vector->size && j < current->vector->size)
			{
				buf = current->vector->array[j];
				current->vector->array[j] = current->vector->array[i];
				current->vector->array[i] = buf;
			}
		
		current = current->next;
	}
	
}

void List::Print_txt()
{
	ofstream out("Tablix.txt");
	out << "[System info]";
	Node* current = Head;
	int sizeH=0;
	while (current != nullptr)
	{
		out <<"#"<<current->hash;
		sizeH++;
		current = current->next;
	}
	out <<"#"<< Head->vector->size<<endl;
	current = Head;
	while (current != nullptr)
	{
		out<<current->vector->array[0]->get_name().substr(6)<<"   ";
		current = current->next;
	}
	out << endl;
	int counter = 0;
	while (counter != Head->vector->size)
	{
		current = Head;
		while (current != nullptr)
		{
			if (current->vector->array[counter] != nullptr)
				out <<"["<< *current->vector->array[counter] << "]" << "	";
			else out << "[slot]   ";
			current = current->next;
		}
		out << endl;
		counter++;
	}
	out.close();
}

void List::wbin()
{
	ofstream out("Tablixbin.bin",ios::binary|ios::out);
	Node* current = Head;
	char br = '~';
	int size=0;
	while (current != nullptr)
	{
		size++;
		current = current->next;
	}
	out << size;
	out << br;
	current = Head;
	while (current != nullptr)
	{
		out << current->hash;
		out << br;
		current = current->next;
	}
	current = Head;
	out << Head->vector->size;
	out << br;
	while (current != nullptr)
	{
		
		for (int i = 0; i < Head->vector->size; i++)
		{
			if (current->vector->array[i] != nullptr)
			{
				out << "#";
				out << *current->vector->array[i];
			}
			else
				out<<"~";
		}
		if (current->hash == typeid(Sstrong).hash_code())
			out <<'#'<< ' ';
		current = current->next;
	}
	out.close();
}

void List::rbin()
{
	fstream in("Tablixbin.bin", ios::binary | ios::in);
	Node* current;
	char key;
	int sizeH=0,vecsize;
	int key2;
	string line;
	string curline;
	bool a = false;
	in >> sizeH;
	in >> key;
	if (hashes != nullptr)
		delete[] hashes;
	hashes = new int[sizeH];
	for (int i = 0; i < sizeH; i++)
	{
		in >> hashes[i];
		in >> key;
	}
	in>>vecsize;
	in >> key;
	
	for (int i = 0; i < sizeH;i++)
	{
		for (int j = 0; j < vecsize; j++) {
			switch (hashes[i])
			{
			case 941965535:
				in >> key;
				if (key == '~')
					add_empty(typeid(Sint).hash_code(), j);
				else
				{
					Sint* obj = new Sint;
					in >> *obj;
					AddElement(*obj, j);

				}
				break;
			case 2037582563:
				in >> key;
				if (key == '~')
					add_empty(typeid(Sdob).hash_code(), j);
				else
				{
					Sdob* obj = new Sdob;
					in >> *obj;
					AddElement(*obj, j);
				}
				break;
			case 44468887:
				in >> key;
				if (key == '~')
					add_empty(typeid(Fraction).hash_code(), j);
				else
				{
					Fraction* obj = new Fraction;
					in >> *obj;
					AddElement(*obj, j);
				}
				break;
			case 587127345:
				int pos;
				in >> line;
				while (true)
				{
					if (line.size()== 1)
					{
						a = true; in >> key; break;
					}
					int k = line.find('~');
					if (line.find('#') < line.find('~'))
					{
						if (line.substr(1).find('#') < line.substr(1).find('~'))
						{
							pos = line.substr(1).find('#');
						}
						else pos = line.substr(1).find('~');
						Sstrong* obj = new  Sstrong(line.substr(1, pos ));
						AddElement(*obj, j);
						j++;
						line = line.substr(pos+1);
					}
					else
					{
						add_empty(typeid(Sstrong).hash_code(), j);
						j++;
						line = '#' + line.substr(1);
					}

				}
				//in >> line;
				//int pos1, pos2, pos3;
				//int j = 0;
				//while (true)
				//{
				//	if (line == "~" || line.size()==0)
				//	{
				//		add_empty(typeid(Sstrong).hash_code(), j);
				//		a = true; 
				//		in >> pos1; 
				//		break;
				//	}
				//	pos1 = line.find('#');
				//	pos2 = line.find('~');
				//	if (pos2 = -1)pos2 = 1000000000;
				//	if (pos1 < pos2)
				//	{
				//		
				//		curline = line.substr(pos1 + 1);
				//		pos3 = curline.find('#') + 1;
				//		if (pos3 < pos2 && pos3 != 0)
				//		{
				//			Sstrong* obj = new  Sstrong(line.substr(1, pos3 - 1));
				//			AddElement(*obj, j);
				//			j++;
				//			line = line.substr(pos3);
				//		}
				//		else
				//		{
				//			if (pos2 < 10000000) {
				//				Sstrong* obj = new  Sstrong(line.substr(1, pos2 - 1));
				//				AddElement(*obj, j);
				//				j++;
				//				line = line.substr(pos2);
				//			}
				//		}
				//	}
				//	else
				//	{
				//		add_empty(typeid(Sstrong).hash_code(), j);
				//		j++;

				//		line = line.substr(1);
				//	}

				//}
				break;
			
			}
			if (a) { a = false; break; }
		}
	}
}

void List::Read_txt()
{
	ifstream in("Tablix.txt");
	Node* current;
	string line;
	while (line.substr(0, 13) != "[System info]")
	{
		string a = line.substr(0, 13);
		std::getline(in, line);
	}
	int pos;
	int pos2;
	int colons = 0;
	line = line.substr(13);
	string line2 = line;
	do
	{
		colons++;
		pos = line2.find("#");
		line2 = line2.substr(pos+1);
	} while (pos != string::npos);
	colons -= 2;
	hashes = new int[colons];

	for(int i=0;i<colons;i++){
		pos = line.find("#");
		pos2 = line.substr(pos+1).find("#");
		hashes[i] = atoi(line.substr(pos+1, pos2 - pos+1).c_str());
		line = line.substr(pos2+1);
	}
	line = line.substr(1);
	int vecsize = stoi(line);
	string curline;
	int Vcounter = 0;
	int Hcounter = 0;
	std::getline(in, line);
	line = "";
	while (Vcounter != vecsize)
	{
		Vcounter++;
		Hcounter = 0;
		std::getline(in, line);
		while (colons!=Hcounter)
		{
			pos=line.find("[");
			pos2=line.find("]");
			curline = line.substr(pos+1, pos2-pos-1);
			switch (hashes[Hcounter])
			{
			case 941965535:
				if (curline == "slot")
				{
					add_empty(typeid(Sint).hash_code(), Vcounter - 1);
				}else
				AddElement(*(new Sint(curline)),Vcounter-1);
				break;
			case 2037582563:
				if (curline == "slot")
				{
					add_empty(typeid(Sdob).hash_code(), Vcounter - 1);
				}else
					AddElement(*(new Sdob(curline)), Vcounter-1);
				break;
			case 44468887:
				if (curline == "slot")
				{
					add_empty(typeid(Fraction).hash_code(), Vcounter - 1);
				}
				else
					AddElement(*(new Fraction(curline)), Vcounter - 1);
			case 587127345:
				if (curline == "slot")
				{
					add_empty(typeid(Sstrong).hash_code(), Vcounter - 1);
				}
				else
					AddElement(*(new Sstrong(curline)), Vcounter - 1);
				break;
			default:
				cout << "Log: unregister class";
				break;
			}
			line = line.substr(pos2 + 1);
			Hcounter++;
		}
	}
}

Object* List::getel(int x, int y)
{
	Node* current = Head;
	int counter = 0;
	while (counter!= x)
	{
		if(current==nullptr) return nullptr;
		current = current->next;
		counter++;
	}
	if (current->vector->size > y)
		return current->vector->array[y];
	else return nullptr;

}

void List::Kill()
{
	if (Head == nullptr)
		return;
	Node* current = Head;
	Node* precurrent = Head;
	while (current != nullptr)
	{
		precurrent = current;
		current = current->next;
		delete precurrent->vector;
		delete precurrent;
	}
	Head = nullptr;
}

List::~List()
{
	Kill();
}

void List::Sort(int x)
{
	if (Head == nullptr)
		return;
	Node* current = Head;
	int c = 0;
	while (current != nullptr)
	{
		c++;
		if (x == c)break;
		current = current->next;
		
	}
	c--;
	int hash_x = current->hash;
	current = Head;
	while (current != nullptr)
	{
		if (current->hash != hash_x)
		{
			current = current->next;
		}
		else
		{
			Object* buf;
			for (int i = 0; i < current->vector->size; i++) {
				for (int j = 0; j < current->vector->size-1; j++) {
					if (current->vector->array[j+1]== nullptr);
					else if (current->vector->array[j] == nullptr) {
						InsideSwap(j, j + 1);
					}else
					if (current->vector->array[j]->smaller(*current->vector->array[j + 1])) {
						InsideSwap(j, j + 1);
					}
				}
			}

					
				
			break;
		}
	}
}

void List::RemoveColon(Object& x)
{
	RemoveColon(x.get_id());
}



void List::addline(int x)
{
	Node* current;
	current = Head;
	if (x > Head->vector->size || x<0)x = Head->vector->size;
	while (current != nullptr)
	{
		current->vector->Add_empty(x);
		current = current->next;
	}
}

void List::AddElement(Object& x, int location)
{
	Node* cur = find_right(x);
	if (cur == nullptr)
	{
		Head = new Node(x);
		Head->vector->Add_S(x,location);
		Normalize();
		return;
	}
	int hash_x = typeid(x).hash_code();
	if (cur->hash == hash_x)
	{
		cur->vector->Add_S(x, location);
		Normalize();
		return;
	}
	cur->next = new Node(x);
	cur->next->Add_to_array(x);
	Normalize();
}

void List::RemoveLine(int location)
{
	if (Head == nullptr)
		return;
	Node* current = Head;
	int hash_x = current->hash;
	while (current != nullptr)
	{
		current->vector->Remove(location);
		current = current->next;
	}
	Normalize();
	return;
}

void List::Normalize()
{
	if (Head == nullptr)
		return ;
	Node* current = Head;
	
	int max = Head->vector->size;
	while (current != nullptr)
	{
		if (current->vector->size > max)
			max = current->vector->size;
		current = current->next;
	}
	current = Head;
	while (current != nullptr)
	{
		current->vector->Get_raven(max);
		current = current->next;
	}

}


