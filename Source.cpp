// наследование в программе перевода английских длин
#include <iostream>
using namespace std;
enum posneg {pos, neg};

class Distance // класс для английских мер длины
{
protected:
	int feet; 
	float inches; 

public:
	// конструктор без параметров
	Distance (): feet(0), inches(0.0)
	{}
	// конструктор с 2 параметрами
	Distance(int ft, float in): feet (ft), inches(in)
	{}
	// получение значений от пользователя
	void getdist()
	{
		cout << "/n Введите футы: "; cin >> feet;
		cout << "/n Введите дюймы: "; cin >> inches;
	}
	// вывод значений на экран
	void showdist ()
	{
		cout << feet << "\'-" << inches << '\"';
	}
};
////////////////////////////////////////////////////////////////
class DistSing: public Distance //Наследование класса. Добавление знакак длине
{
private:
	posneg sing; // значение может быть pos или neg

public:
	// конструктор без параметров
	DistSing() : Distance()
	{sing = pos;}
	// конструктор с 2 или 3 параметрами
	DistSing(int ft, float in, posneg sg = pos):
	Distance(ft, in) // вызов конструктора базового класса
	{
		sing = sg;
	} // начальная установка знака
	void getdist()
	{
		Distance::getdist(); // вызов функции getdist из базовоо класса
		char ch;
		cout << "Введите знак (+ или -):"; 
		cin >> ch;
		sing = (ch == '+') ? pos : neg;
	}
	void showdist() // Вывод растояния
	{
		//Вывод всей информации включая знак
		
		cout << ((sing == pos) ? "(+)" : "(-)");
		Distance::showdist();
	}
};
////////////////////////////////////////////////////////////////////////////
int main() {
	setlocale(LC_ALL, "Russian");
	DistSing alpha;  //Используем конструктор по умолчанию
	alpha.getdist(); //Получаем данные от пользователя
	DistSing beta(11, 6.25); //Конструктор с двумя аргументами
	DistSing gamma(100, 5.5, neg); //Конструктор с тремя аргументами
	// Выводим данные для всех переменных
	cout << "\nA="; alpha.showdist();
	cout << "\nB="; beta.showdist();
	cout << "\nC="; gamma.showdist();
	cout << endl;
	return 0;
}