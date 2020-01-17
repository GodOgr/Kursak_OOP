#pragma once
#include <string>
#include <iostream>
#include "Object.h"

//����� "�����"
class Fraction : public Object {
public:
	//������ ��� ������������ ������
	//������ ����� �� � � ����� ������
	std::ostream& print(std::ostream& oStream,Object&a) ;
	std::istream& scan(std::istream& iStream, Object& a);
	//������� ���� ���������(��� � ���������� ��������� ����������� ��������)
	int get_id();
	//������� ������ �� ������ � ������ �����
	std::string get_name();
	//��������(�����������)
	Object& unite(Object& val);
	//��������� ��������������
	operator double();
	//�������� ����� ����� �������
	Object& copy(Object& val);
public:
	//������-������������

	//1. ������ �����������. ������ �����, ������������� 0.
	Fraction();

	//2. ����������� �� ���������-������
	Fraction(std::string& str);

	//3. ����������� �� ���������-�������
		//������ ������ ��������� ������ � ���� {����� �����, ���������, �����������}
	Fraction(const int* mas);

	//4. ����������� �����������
	Fraction(const Fraction&);

	// ����������� �����������
	Fraction(Fraction&&);

	// ��������������� ����������� �� int-�. ����� ����� ����� ������ ����� �����.
	Fraction(const int);

	//����������
	~Fraction();

	//������ ����� ����� �����
	void set_whole(const int i);

	//������ ��������� �����
	void set_numerator(const int i);

	//������ ����������� �����
	void set_denominator(const int i);

	//������ ���� �����
	void set_pos_neg(const bool znak);

	//����� ������ ����� �� �����
	void out();

	//����� ����� (��������������) ����� � ����������
	void in();

	//����� ������ ����� � ������
	std::string fraction_to_string();

	//���������� ��������� �� number
	int* get_number();
	void* get_info();
	// ���������� ���� �����
	bool get_minus();

	bool cmp(Object& fract_2);
	bool smaller(Object& fract_2);
	bool bigger(Object& fract_2);
	// ���������� = (����������� ������������)
	Fraction& operator=(const Fraction& right);
	// ���������� = (������������� ������������)
	Fraction& operator=(Fraction&& right);

	// ���������� <<
	friend std::ostream& operator<<(std::ostream& out, Fraction& fract);
	// ���������� >>
	friend std::istream& operator>>(std::istream& in, Fraction& fract);

	// ���������� ���������
	// ���������� ==
	bool operator==(const Fraction& right) const;

	// ���������� <
	bool operator<(const Fraction& right) const;

	// ���������� >
	bool operator>(const Fraction& right) const;

	// ���������� <=
	bool operator<=(const Fraction& right) const;

	// ���������� >=
	bool operator>=(const Fraction& right) const;


	//�������� �������������� �������� (��� �����)
	// ���������� +
	Fraction& operator+(const Fraction& fract_2) const;
	// ���������� -
	Fraction& operator-(const Fraction& fract_2) const;
	// ���������� *
	Fraction& operator*(const Fraction& fract_2) const;
	// ���������� /
	Fraction& operator/(const Fraction& fract_2) const;


	//�������� �������������� �������� (� �����)
	//���������� +=
	Fraction& operator+=(const Fraction& fract_2);

	//���������� /=
	Fraction& operator/=(const Fraction& fract_2);

	//���������� -=
	Fraction& operator-=(const Fraction& fract_2);

	//���������� *=
	Fraction& operator*=(const Fraction& fract_2);

private:
	//����� ����������� �������
	//src - �����-��������
	void copy(const Fraction& src);

	//����� ����������� ��������
	//src - �����-��������
	void move(Fraction&& scr);

	//������������� �����: ������ � ����������, ����� ��������� ������ ����������� � ������� ����� �����,
	//���� ����������.
	void normalize();

	//��������������� �������: ������ ��� �������� ����� ���������������� �������
	//� ������ ���� minus, ���� ����������.
	void abs_frac();

	//��������������� �������: ���������� ����� ����� x
	int lenof(int x) const;

	//��������������� �������: ���������� ��� ����� a � b
	int nod(int a, int b) const;

	//��������������� �������: ���������� ��� ����� a � b
	int nok(int n1, int n2) const;

	//���������� ������� ����� � fract_2 � ���������� ��������� � ������� �����
	void f_plus(const Fraction& fract_2);

	//���������� ������� ����� � fract_2 � ���������� ��������� � ������� �����
	void f_minus(const Fraction& fract_2);

	//����������� ������� ����� � fract_2 � ���������� ��������� � ������� �����
	void f_mult(const Fraction& fract_2);

	//����� ������� ����� �� fract_2 � ���������� ��������� � ������� �����
	void f_div(const Fraction& fract_2);

	//���������� ���������
	// ���������� 0, ���� ����� �����, -1 - ������ ����� ������, 1 - ������ ����� ������
	int compare(const Fraction& fract_2) const;

	// ������� �������� ����� �� ������
	bool load_from_str(std::string& str);

private:
	//���� �������
	bool minus; //�������� �� ����� �������������
	int* number; //������������ ������ �� 3-� �����

	//int whole_num; //����� �����
	//int numerator; //���������
	//int denominator; //�����������
};