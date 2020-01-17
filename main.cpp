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
	cout <<"Время на считывания из текстового файла "<< clock() - s1<<"\n";

	 s1 = clock();
	tabl2->rbin();
	cout << "Время на считывания из бинарного файла " << clock() - s1 << "\n";

	 s1 = clock();
	tabl2->Sort(1);
	cout << "Время на сортировку таблицы файла " << clock() - s1 << "\n";


	bool pr = true;
	while (pr)
	{
		cout << "1 - Создать таблицу\n";//+

		cout << "2 - Сохранить в тектовый файл\n";//+
		cout << "3 - Загрузить из текстового файла\n";//+

		cout << "4 - сохранить в бинарный файл\n";//+
		cout << "5 - Загрузить из бинарного файла\n";//+

		cout << "6 - Показать таблицу\n";//+PLOXO
		cout << "7 - Отсортировать по столбцу\n";//+

		cout << "8 - Добавить или изменить элемент\n";
		cout << "9 - Добавить строку\n";

		cout << "10 - Поиск\n";
		cout << "11- Удалить строку\n";
		
		cout << "12 - Очистить таблицу\n";
		cout << "13 - Выход\n";
		if (tabl != nullptr)
			tabl->Show();
		else cout << "Таблица отсутствует";
		cin >> key;
		switch (key)
		{
		case 1:
			system("cls");
			if (tabl == nullptr)
			{
				tabl = new List();
				cout << "Таблица создана";
			}
			break;
		case 2:
			system("cls");
			if (tabl != nullptr)
			{
				tabl->Print_txt();
				cout << "Таблица сохранена";
			}
			break;
		case 3:
			system("cls");
			if (tabl == nullptr)
			{
				tabl->Read_txt();
				cout << "Таблица загружена";
			}
			else
			{
				delete tabl;
				tabl = new List();
				tabl->Read_txt();
				cout << "Таблица загружена";
			}
			break;
		case 4:
			system("cls");
			if (tabl != nullptr)
			{
				tabl->wbin();
				cout << "Таблица сохранена";
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
			cout << "Таблица загружена";
			break;
		case 6:
			if (tabl != nullptr)
				tabl->Show();
			break;
		case 7:
			cout << "Введите номер столбца: ";
			cin >> colon;
			tabl->Sort(colon);
			break;
		case 8:
			cout << "Выберите столбец (1-Sint,2-Sdob,3-Fraction): ";
			cin >> key2;
			cout << "Выберите строку: ";
			cin >> line;
			switch (key2)
			{
			case 1:
				cin >> stroka;
				obj1 = new Sint(stroka);
				tabl->AddElement(*obj1, line);
				cout << "элемет добавлен";
				break;
			case 2:
				cin >> stroka;
				obj2 = new Sdob(stroka);
				tabl->AddElement(*obj2, line);
				cout << "элемет добавлен";
				break;
			case 3:
				cin >> stroka;
				obj3 = new Fraction(stroka);
				tabl->AddElement(*obj3, line );
				cout << "элемет добавлен";
				break;
			case 4:
				cin >> stroka;
				obj4 = new Sstrong(stroka);
				tabl->AddElement(*obj4, line );
				cout << "элемет добавлен";
				break;
			default:
				cout << "елемент не добавлен";
				break;
			}
			break;
		case 9:
			cout << "Введите номер строки: ";
			cin >> line;
			tabl->addline(line - 1);
			break;
		case 10:
			cout << "Выберите столбец (1-Инт 2-Дабл 3-Дробь 4-строка ): ";
			cin >> key2;
			cout << "Данные для поиска: ";
			cin >> stroka;
			switch (key2)
			{
			case 1:
				obj1 = new Sint(stroka);
				if (tabl->Search(*obj1) == nullptr) cout << "Не найдено";
				else cout << "Найдено";
				break;
			case 2:
				obj2 = new Sdob(stroka);
				if (tabl->Search(*obj2) == nullptr) cout << "Не найдено";
				else cout << "Найдено";
				break;
			case 3:
				obj3 = new Fraction(stroka);
				if (tabl->Search(*obj3) == nullptr) cout << "Не найдено";
				else cout << "Найдено";
				break;
			case 4:
				obj4 = new Sstrong(stroka);
				if (tabl->Search(*obj4) == nullptr) cout << "Не найдено";
				else cout << "Найдено";
				break;
			default:
				break;
			}
		case 11:
			cout << "Введите номер строки: ";
			cin >> line;
			tabl->RemoveLine(line-1);
			break;
		case 12:
			delete tabl;
			cout << "Таблица очищенна";
			break;
		case 13:
			pr = false;
			break;
		}







		cout << endl;
	}
}