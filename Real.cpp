#include "Real.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//#define TEST

//��������������� ������� - ����� ��������� � ������������
void FindChZn(double num, double eps, int& ch, int& zn)
{
	int a = 1; int b = 1;
	int mn = 2; // ��������� ��� ���������� �����������
	int iter = 0;
	ch = a; zn = b;
	// ����� ���������� �����������
	double c = 1;
	do {
		b++;
		c = (double)a / b;
	} while ((num - c) < 0);
	if ((num - c) < eps)
	{
		ch = a; zn = b;
		return;
	}
	b--;
	c = (double)a / b;
	if ((num - c) > -eps)
	{
		ch = a; zn = b;
		return;
	}
	// ���������
	while (iter < 20000)
	{
		int cc = a * mn, zz = b * mn;
		iter++;
		do {
			zz++;
			c = (double)cc / zz;
		} while ((num - c) < 0);
		if ((num - c) < eps)
		{
			ch = cc; zn = zz;
			return;
		}
		zz--;
		c = (double)cc / zz;
		if ((num - c) > -eps)
		{
			ch = cc; zn = zz;
			return;
		}
		mn++;
	}
}
//������ ����� �� � � ����� ������
std::ostream& Fraction::print(std::ostream& oStream, Object& a)  {
	oStream << *this;
	return oStream;
}
std::istream& Fraction::scan(std::istream& iStream, Object& a) {
	iStream >> *this;
	return iStream;
}
//������� ���� ���������(��� � ���������� ��������� ����������� ��������)
int Fraction::get_id() {
	return typeid(Fraction).hash_code();
}
//������� ������ �� ������ � ������ �����
std::string Fraction::get_name() {
	return typeid(Fraction).name();
}
Object& Fraction::unite(Object& val)
{
	return val;
}
//��������� ��������������
Fraction::operator double() {
	double val = number[0] + (double(number[1]) / number[2]);
	if (minus) val *= -1;
	return val;
}

Object& Fraction::copy(Object& val)
{
	return val;
}






//������-������������
//1. ������ �����������. ������ �����, ������������� 0.
Fraction::Fraction() {
	minus = false;
	number = new int[3];
	for (int i = 0; i < 2; i++)
		number[i] = 0;
	number[2] = 1;
#ifdef TEST
	std::cout << "Created!\n";
#endif // TEST
}

//2. ����������� �� ���������-������
Fraction::Fraction(std::string& str) {
	this->load_from_str(str);
	this->normalize();
#ifdef TEST
	std::cout << "Created!\n";
#endif // TEST
}

//3. ����������� �� ���������-�������
		//������ ������ ��������� ������ � ���� {����� �����, ���������, �����������}
Fraction::Fraction(const int* mas) {
	//���� � ����� ���� ������������� ����� - ������ � �������������
	if ((mas[0] < 0) || (mas[1] < 0) || (mas[2] < 0))
		minus = true;
	else
		minus = false;
	number = new int[3];
	number[0] = mas[0];
	number[1] = mas[1];
	number[2] = mas[2];
	this->normalize();
#ifdef TEST
	std::cout << "Created!\n";
#endif // TEST
}

// 4. ������������ �����������
Fraction::Fraction(const Fraction& src)
{
	minus = src.minus;
	number = new int[3];
	for (int i = 0; i < 3; i++)
		number[i] = src.number[i];
}

Fraction::Fraction(Fraction&& src)
{
	delete[] number;
	number = src.number;
	src.number = nullptr;
	minus = src.minus;
	// this->move(src) //������ ������ ���?
}

Fraction::Fraction(const int i)
{
	minus = false;
	number = new int[3];
	number[0] = i;
	number[1] = 0;
	number[2] = 0;
	normalize();
}

//����� ����������� �������
	//src - �����-��������
void Fraction::copy(const Fraction& src) {
	this->minus = src.minus;
	this->number[0] = src.number[0];
	this->number[1] = src.number[1];
	this->number[2] = src.number[2];
}

void Fraction::move(Fraction&& src)
{
	delete[] number;
	number = src.number;
	src.number = nullptr;
	minus = src.minus;
}

//������ ����� ����� �����
void Fraction::set_whole(const int i)
{
	this->number[0] = i;
}

//������ ��������� �����
void Fraction::set_numerator(const int i)
{
	this->number[1] = i;
	this->normalize();
}

//������ ����������� �����
void Fraction::set_denominator(const int i)
{
	this->number[2] = i;
	this->normalize();
}

//������ ���� �����
void Fraction::set_pos_neg(const bool znak)
{
	this->minus = znak;
}

//����������
Fraction::~Fraction() {
	delete[] number;
#ifdef TEST
	std::cout << "Deleted!\n";
#endif // TEST
}

//����� ������ ����� �� �����
void Fraction::out() {
	if (minus)
		std::cout << "- ";
	std::cout << number[0] << " " << number[1] << "/" << number[2];
}

//����� ����� (��������������) ����� � ����������
void Fraction::in() {
	std::cout << "������� �������� ���������� ����� � ��������� �������: ����� �����, ���������, �����������: ";
	std::cin >> number[0] >> number[1] >> number[2];
	this->normalize();
}

//����� ������ ����� � ������
std::string Fraction::fraction_to_string() {
	std::string Fraction_str;
	//����������� ���������� ������
	char* whole_num_char = new char[lenof(number[0]) + 1];
	sprintf_s(whole_num_char, lenof(number[0]) + 1, "%d", number[0]);
	char* numerator_char = new char[lenof(number[1]) + 1];
	sprintf_s(numerator_char, lenof(number[1]) + 1, "%d", number[1]);
	char* denominator_char = new char[lenof(number[2]) + 1];
	sprintf_s(denominator_char, lenof(number[2]) + 1, "%d", number[2]);
	if (minus)
		Fraction_str += "-";
	Fraction_str += whole_num_char;
	Fraction_str += " ";
	Fraction_str += numerator_char;
	Fraction_str += "/";
	Fraction_str += denominator_char;

	//����������� ������
	delete whole_num_char;
	delete numerator_char;
	delete denominator_char;
	return Fraction_str;
}

//������������� �����: ������ � ����������, ����� ��������� ������ ����������� � ������� ����� �����,
	//���� ����������.
void Fraction::normalize() {
	// ����������� �� ����� ���� ����� 0
	if (this->number[2] == 0) {
		this->number[2] = 1;
	}
	this->abs_frac();
	//������� ��� ��������� � ����������� � ����� �� �� ����
	int nod = this->nod(number[1], number[2]);
	if (nod > 1) {
		number[1] /= nod;
		number[2] /= nod;
	}
	//���� ��������� ������ �����������, ������ �� ������
	if (number[1] < number[2])
		return;
	//���� ����������� ����� 0 - ������ �� ������
	if (number[2] == 0) {
		std::cout << "��������� ����������� ������ ����!\n";
		//printf_s("��������� ����������� ������ ����!\n");
		return;
	}
	//����� �������� �� ��������� �����������, ���������� ����� �����, ���� ���-�� �� ������ ������ ����-��
	while (number[1] >= number[2]) {
		number[0]++;
		number[1] -= number[2];
	}
}

//��������������� �������: ������ ��� �������� ����� ���������������� �������
	//� ������ ���� minus, ���� ����������.
void Fraction::abs_frac() {
	if ((minus) || (number[0] < 0) || (number[1] < 0) || (number[2] < 0))
		minus = true;
	else {
		minus = false;
		return;
	}
	number[0] = abs(number[0]);
	number[1] = abs(number[1]);
	number[2] = abs(number[2]);
}

//��������������� �������: ���������� ����� ����� x
int Fraction::lenof(int x) const {
	int len = 0;
	if (x == 0)
		return 1;
	while (x >= 1)
	{
		x /= 10;
		len++;
	}
	return len;
}

//��������������� �������: ���������� ��� ����� a � b
int Fraction::nod(int a, int b) const {
	int t;
	if (a < b) {
		t = a;
		a = b;
		b = t;
	}
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int Fraction::nok(int n1, int n2) const
{
	return n1 * n2 / nod(n1, n2);
}

//���������� ��������� �� number
int* Fraction::get_number() {
	return number;
}

void* Fraction::get_info()
{
	return number;
}

bool Fraction::get_minus()
{
	return minus;
}

// ���������� +
Fraction& Fraction::operator+(const Fraction& fract_2) const
{
	Fraction& temp_fract = *(new Fraction(*this));
	temp_fract += fract_2;
	return temp_fract;
}

Fraction& Fraction::operator-(const Fraction& fract_2) const
{
	Fraction& temp_fract = *(new Fraction(*this));
	temp_fract -= fract_2;
	return temp_fract;
}

Fraction& Fraction::operator*(const Fraction& fract_2) const
{
	Fraction& temp_fract = *(new Fraction(*this));
	temp_fract *= fract_2;
	return temp_fract;
}

Fraction& Fraction::operator/(const Fraction& fract_2) const
{
	Fraction& temp_fract = *(new Fraction(*this));
	temp_fract /= fract_2;
	return temp_fract;
}

// ���������� =
Fraction& Fraction::operator=(const Fraction& right)
{
	if (this != &right) {
		this->copy(right);
	}

	return *this; // ������� ������
}

Fraction& Fraction::operator=(Fraction&& right)
{
	if (this != &right) {
		delete[] number;
		number = right.number;
		right.number = nullptr;
		minus = right.minus;
	}

	return *this; // ������� ������
}


std::ostream& operator<<(std::ostream& out, Fraction& fract)
{
	if (fract.minus)
		out << "-";
	if (fract.number[0] != 0) {
		out << fract.number[0] << " ";
	}
	if (fract.number[1] != 0) {
		out << fract.number[1] << "/" << fract.number[2];
	}
	return out;
}

std::istream& operator>>(std::istream& in, Fraction& fract)
{
	fract.minus = false;
	in >> fract.number[0] >> fract.number[1] >> fract.number[2];
	fract.normalize();
	return in;
}


bool Fraction::operator==(const Fraction& right) const
{
	// "compare" ���������� 0, ���� ����� �����. "!" ��������� ��� ������ ���� ������.
	return compare(right) == 0;
}

bool Fraction::operator<(const Fraction& right) const
{
	// ���������: ���� compare ���������� -1, �� ���������� true
	return compare(right) < 0;
}

bool Fraction::operator>(const Fraction& right) const
{
	// ���������: ���� compare ���������� -1, �� ���������� true
	return compare(right) > 0;
}

bool Fraction::operator<=(const Fraction& right) const
{
	return compare(right) <= 0;
}

bool Fraction::operator>=(const Fraction& right) const
{
	return compare(right) >= 0;
}

bool Fraction::cmp(Object& fract_2)
{
	// ������ ����� ������� ��������
	Fraction& temp = *(new Fraction(*this));
	// �������� ���� ����� �� �������
	temp -= (const Fraction&)fract_2;
	// ���� ���������� ����� - ������������� - ������ ����� ������
	if (temp.minus) {
		delete& temp;
		return false;
	}
	// ���� ���������� ����� - ������������� (��������� > 0 ��� ����� ����� > 0) - ������ ����� ������
	if (temp.number[0] > 0 || temp.number[1] > 0) {
		delete& temp;
		return false;
	}
	// ���� ���������� ����� 0 - ����� �����
	delete& temp;
	return true;
	
}

bool Fraction::smaller(Object& fract_2)
{
	// ������ ����� ������� ��������
	Fraction& temp = *(new Fraction(*this));
	// �������� ���� ����� �� �������
	temp -= (const Fraction&)fract_2;
	// ���� ���������� ����� - ������������� - ������ ����� ������
	if (temp.minus) {
		delete& temp;
		return true;
	}
	return false;
}

bool Fraction::bigger(Object& fract_2)
{
	// ������ ����� ������� ��������
	Fraction& temp = *(new Fraction(*this));
	// �������� ���� ����� �� �������
	temp -= (const Fraction&)fract_2;

	// ���� ���������� ����� - ������������� (��������� > 0 ��� ����� ����� > 0) - ������ ����� ������
	if (temp.number[0] > 0 || temp.number[1] > 0) {
		delete& temp;
		return true;
	}
	return false;
}

void Fraction::f_plus(const Fraction& fract_2) {   // f_plus(const Fraction& p2)
	Fraction temp;
	temp.copy(fract_2);

	// ������ ����� �������������
	this->number[1] += this->number[0] * this->number[2];
	this->number[0] = 0;

	temp.number[1] += temp.number[0] * temp.number[2];
	temp.number[0] = 0;

	//���� ����� ������������ - �������� ��������� �� -1
	if (this->minus) {
		this->number[1] *= -1;
		this->minus = false;
	}
	if (temp.minus)
		temp.number[1] *= -1;

	//������� ��� ������������
	int nok_znamen = nok(this->number[2], temp.number[2]);
	//�������� ������ �� ������ (����� ����� �����) �� ���/�����������
	this->number[1] *= nok_znamen / this->number[2];
	this->number[2] *= nok_znamen / this->number[2];
	temp.number[1] *= nok_znamen / temp.number[2];
	temp.number[2] *= nok_znamen / temp.number[2];
	//���������� ���������
	this->number[1] += temp.number[1];
	this->normalize();
}

void Fraction::f_minus(const Fraction& fract_2)
{
	Fraction temp;
	temp.copy(fract_2);
	temp.minus = !temp.minus;
	this->f_plus(temp);
}

void Fraction::f_mult(const Fraction& fract_2) {
	Fraction temp;
	temp.copy(fract_2);

	//���������� � ��������� ����� �����, ���������� �� �����������
	this->number[1] += this->number[0] * this->number[2];
	this->number[0] = 0;
	temp.number[1] += temp.number[0] * temp.number[2];

	this->number[1] *= temp.number[1];
	this->number[2] *= temp.number[2];

	if (temp.minus)
		this->minus = !this->minus;

	this->normalize();
}

void Fraction::f_div(const Fraction& fract_2)
{
	Fraction temp;
	temp.copy(fract_2);
	temp.number[1] += temp.number[0] * temp.number[2];
	temp.number[0] = 0;

	//������ ������� ��������� � �����������
	int t = temp.number[2];
	temp.number[2] = temp.number[1];
	temp.number[1] = t;

	this->f_mult(temp);
}

//���������� +=
Fraction& Fraction::operator+=(const Fraction& fract_2) {
	this->f_plus(fract_2);
	return *this;
}

//���������� /=
Fraction& Fraction::operator/=(const Fraction& fract_2) {
	this->f_div(fract_2);
	return *this;
}

//���������� -=
Fraction& Fraction::operator-=(const Fraction& fract_2) {
	this->f_minus(fract_2);
	return *this;
}

//���������� *=
Fraction& Fraction::operator*=(const Fraction& fract_2) {
	this->f_mult(fract_2);
	return *this;
}

//���������� ���������
// ���������� 0, ���� ����� �����, -1 - ������ ����� ������, 1 - ������ ����� ������
int Fraction::compare(const Fraction& fract_2) const
{
	// ������ ����� ������� ��������
	Fraction& temp = *(new Fraction(*this));
	// �������� ���� ����� �� �������
	temp -= fract_2;
	// ���� ���������� ����� - ������������� - ������ ����� ������
	if (temp.minus) {
		delete& temp;
		return -1;
	}
	// ���� ���������� ����� - ������������� (��������� > 0 ��� ����� ����� > 0) - ������ ����� ������
	if (temp.number[0] > 0 || temp.number[1] > 0) {
		delete& temp;
		return 1;
	}
	// ���� ���������� ����� 0 - ����� �����
	delete& temp;
	return 0;
}

bool Fraction::load_from_str(std::string& str)
{
	char sub_str[3][20] = { NULL };

	int cur_position = 0; //������� ������� "�������" � ������
	int cur_sub_str = 0; //������� ���-������
	int cur_sub_str_pos = 0; //������� ������� "�������" � ���-������

	int found_space = false; //����� �� �� �������?
	int found_slash = false; //����� �� �� �����-�������?

	//������ ������ ��������� ���: 5 4/6
	//��� -5 4/6

	//���� �� ����� �� ����� ������
	while (str[cur_position] != '\0') {
		//���� ����� �����
		if (str[cur_position] == '-') {
			minus = true;
			cur_position++;
			continue;
		}

		//����� ������ ������
		if (found_space) {
			//����� ������ ����-�������
			if (found_slash) {
				//��� �� �����������
				sub_str[cur_sub_str][cur_sub_str_pos] = str[cur_position];
				cur_position++;
				cur_sub_str_pos++;
			}
			else {
				//��� �� ���������
				if (str[cur_position] == '/') {
					found_slash = true;
					cur_position++;
					cur_sub_str = 2;
					cur_sub_str_pos = 0;
					continue;
				}
				sub_str[cur_sub_str][cur_sub_str_pos] = str[cur_position];
				cur_position++;
				cur_sub_str_pos++;
			}
		}
		//����� ��� �� ����� �� �������
		else {
			//��� �� ����� �����
			if (str[cur_position] == ' ') {
				found_space = true;
				cur_position++;
				cur_sub_str = 1;
				cur_sub_str_pos = 0;
				continue;
			}
			sub_str[cur_sub_str][cur_sub_str_pos] = str[cur_position];
			cur_position++;
			cur_sub_str_pos++;
		}
	}
	//����� ��� ���������. ��������� ������ �� ��� � int
	number = new int[3]();
	number[0] = atoi(sub_str[0]);
	number[1] = atoi(sub_str[1]);
	number[2] = atoi(sub_str[2]);
	return true;
}
