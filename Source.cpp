// ������������ � ��������� �������� ���������� ����
#include <iostream>
using namespace std;
enum posneg {pos, neg};

class Distance // ����� ��� ���������� ��� �����
{
protected:
	int feet; 
	float inches; 

public:
	// ����������� ��� ����������
	Distance (): feet(0), inches(0.0)
	{}
	// ����������� � 2 �����������
	Distance(int ft, float in): feet (ft), inches(in)
	{}
	// ��������� �������� �� ������������
	void getdist()
	{
		cout << "/n ������� ����: "; cin >> feet;
		cout << "/n ������� �����: "; cin >> inches;
	}
	// ����� �������� �� �����
	void showdist ()
	{
		cout << feet << "\'-" << inches << '\"';
	}
};
////////////////////////////////////////////////////////////////
class DistSing: public Distance //������������ ������. ���������� ������ �����
{
private:
	posneg sing; // �������� ����� ���� pos ��� neg

public:
	// ����������� ��� ����������
	DistSing() : Distance()
	{sing = pos;}
	// ����������� � 2 ��� 3 �����������
	DistSing(int ft, float in, posneg sg = pos):
	Distance(ft, in) // ����� ������������ �������� ������
	{
		sing = sg;
	} // ��������� ��������� �����
	void getdist()
	{
		Distance::getdist(); // ����� ������� getdist �� ������� ������
		char ch;
		cout << "������� ���� (+ ��� -):"; 
		cin >> ch;
		sing = (ch == '+') ? pos : neg;
	}
	void showdist() // ����� ���������
	{
		//����� ���� ���������� ������� ����
		
		cout << ((sing == pos) ? "(+)" : "(-)");
		Distance::showdist();
	}
};
////////////////////////////////////////////////////////////////////////////
int main() {
	setlocale(LC_ALL, "Russian");
	DistSing alpha;  //���������� ����������� �� ���������
	alpha.getdist(); //�������� ������ �� ������������
	DistSing beta(11, 6.25); //����������� � ����� �����������
	DistSing gamma(100, 5.5, neg); //����������� � ����� �����������
	// ������� ������ ��� ���� ����������
	cout << "\nA="; alpha.showdist();
	cout << "\nB="; beta.showdist();
	cout << "\nC="; gamma.showdist();
	cout << endl;
	return 0;
}