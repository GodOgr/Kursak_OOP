#define _CRT_NO_VA_START_VALIDATION
#include"Object.h"

#include<iostream>
#include<locale>
#include"List.h"
#include<random>
#include<ctime>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "C");
	
	srand(time(NULL));

		/*Sint* int1 = new Sint(0);
	Sint* int2 = new Sint(11);
	Sint* int3 = new Sint(-90);
	Sint* int4 = new Sint(160);
	Sint* int5 = new Sint(18880);

	Sdob* dob1 = new Sdob(7.14);
	Sdob* dob2 = new Sdob(6.14);
	Sdob* dob3 = new Sdob(-0.99);
	Sdob* dob4 = new Sdob(500.4);
	Sdob* dob5 = new Sdob(110.4);

	List* Tablix = new List();
	
	Tablix->Add_El(*int1);

	Tablix->Add_El(*int2);
	
	Tablix->Add_El(*int3);
	
	Tablix->Add_El(*int4);
	
	Tablix->AddElement(*int5, 2);


	Tablix->Add_El(*dob1);
	
	Tablix->Add_El(*dob2);
	
	Tablix->Add_El(*dob3);
	
	Tablix->Add_El(*dob4);


	
	Tablix->Print_txt();*/
	int key;
	int key2;
	int line;
	int colon;
	
	Sdob* obj2 = nullptr;Sint *obj1 = nullptr;
	Fraction* obj3 = nullptr;
	Sstrong* obj4 = nullptr;
	Object* a;
	List* tabl = nullptr;
	string stroka;
	tabl = new List();
	List* tabl2 = new List();
	//for (int i = 0; i < 1500; i++)
	//{
	//	tabl->Add_El(*(new Sint(rand())));
	//}
	//for (int i = 0; i < 1500; i++)
	//{
	//	tabl->Add_El(*(new Sdob(rand())));
	//}
	//for (int i = 0; i < 1500; i++)
	//{
	//	tabl->Add_El(*(new Sstrong("NeNovayaStroka"+ to_string(i))));
	//}
	//tabl->Print_txt();
	//tabl->wbin();

	int s1 = clock();
	tabl->Read_txt();
	cout <<"����� �� ���������� �� ���������� ����� "<< clock() - s1<<"\n";

	 s1 = clock();
	tabl2->rbin();
	cout << "����� �� ���������� �� ��������� ����� " << clock() - s1 << "\n";

	 s1 = clock();
	tabl2->Sort(1);
	cout << "����� �� ���������� ������� ����� " << clock() - s1 << "\n";


	bool pr = true;
	while (pr)
	{
		cout << "1 - ������� �������\n";//+

		cout << "2 - ��������� � �������� ����\n";//+
		cout << "3 - ��������� �� ���������� �����\n";//+

		cout << "4 - ��������� � �������� ����\n";//+
		cout << "5 - ��������� �� ��������� �����\n";//+

		cout << "6 - �������� �������\n";//+PLOXO
		cout << "7 - ������������� �� �������\n";//+

		cout << "8 - �������� ��� �������� �������\n";
		cout << "9 - �������� ������\n";

		cout << "10 - �����\n";
		cout << "11- ������� ������\n";
		
		cout << "12 - �������� �������\n";
		cout << "13 - �����\n";
		if (tabl != nullptr)
			tabl->Show();
		else cout << "������� �����������";
		cin >> key;
		switch (key)
		{
		case 1:
			system("cls");
			if (tabl == nullptr)
			{
				tabl = new List();
				cout << "������� �������";
			}
			break;
		case 2:
			system("cls");
			if (tabl != nullptr)
			{
				tabl->Print_txt();
				cout << "������� ���������";
			}
			break;
		case 3:
			system("cls");
			if (tabl == nullptr)
			{
				tabl->Read_txt();
				cout << "������� ���������";
			}
			else
			{
				delete tabl;
				tabl = new List();
				tabl->Read_txt();
				cout << "������� ���������";
			}
			break;
		case 4:
			system("cls");
			if (tabl != nullptr)
			{
				tabl->wbin();
				cout << "������� ���������";
			}
			break;
		case 5:
			system("cls");
			if (tabl == nullptr)
				tabl->rbin();
			else
			{
				delete tabl;
				tabl = new List();
				tabl->rbin();
			}
			cout << "������� ���������";
			break;
		case 6:
			if (tabl != nullptr)
				tabl->Show();
			break;
		case 7:
			cout << "������� ����� �������: ";
			cin >> colon;
			tabl->Sort(colon);
			break;
		case 8:
			cout << "�������� ������� (1-Sint,2-Sdob,3-Fraction): ";
			cin >> key2;
			cout << "�������� ������: ";
			cin >> line;
			switch (key2)
			{
			case 1:
				cin >> stroka;
				obj1 = new Sint(stroka);
				tabl->AddElement(*obj1, line);
				cout << "������ ��������";
				break;
			case 2:
				cin >> stroka;
				obj2 = new Sdob(stroka);
				tabl->AddElement(*obj2, line);
				cout << "������ ��������";
				break;
			case 3:
				cin >> stroka;
				obj3 = new Fraction(stroka);
				tabl->AddElement(*obj3, line );
				cout << "������ ��������";
				break;
			case 4:
				cin >> stroka;
				obj4 = new Sstrong(stroka);
				tabl->AddElement(*obj4, line );
				cout << "������ ��������";
				break;
			default:
				cout << "������� �� ��������";
				break;
			}
			break;
		case 9:
			cout << "������� ����� ������: ";
			cin >> line;
			tabl->addline(line - 1);
			break;
		case 10:
			cout << "�������� ������� (1-��� 2-���� 3-����� 4-������ ): ";
			cin >> key2;
			cout << "������ ��� ������: ";
			cin >> stroka;
			switch (key2)
			{
			case 1:
				obj1 = new Sint(stroka);
				if (tabl->Search(*obj1) == nullptr) cout << "�� �������";
				else cout << "�������";
				break;
			case 2:
				obj2 = new Sdob(stroka);
				if (tabl->Search(*obj2) == nullptr) cout << "�� �������";
				else cout << "�������";
				break;
			case 3:
				obj3 = new Fraction(stroka);
				if (tabl->Search(*obj3) == nullptr) cout << "�� �������";
				else cout << "�������";
				break;
			case 4:
				obj4 = new Sstrong(stroka);
				if (tabl->Search(*obj4) == nullptr) cout << "�� �������";
				else cout << "�������";
				break;
			default:
				break;
			}
		case 11:
			cout << "������� ����� ������: ";
			cin >> line;
			tabl->RemoveLine(line-1);
			break;
		case 12:
			delete tabl;
			cout << "������� ��������";
			break;
		case 13:
			pr = false;
			break;
		}







		cout << endl;
	}
}