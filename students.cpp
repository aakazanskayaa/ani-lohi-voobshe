#include <iostream>

using namespace std;

class STUDENT {
private:
	string name;
	int age; 
	float grade; 

public:
	
	STUDENT() : name(""), age(0), grade(0.0f) {} //  объявление конструктора по умолчанию с пустым списком инициализаторов, который инициализирует переменные-члены пустыми строками 0 и 0.0f соответственно.

	
	STUDENT(string n, int a, float g) : name(n), age(a), grade(g) {} // объявление конструктора с тремя параметрами, который инициализирует переменные-члены заданными значениями.

	
	string GetName() const { return name; } //  объявление общедоступной функции с именем GetName, которая возвращает переменную-член name в виде строки.
	int GetAge() const { return age; }
	float GetGrade() const { return grade; }

	void SetName(string n) { name = n; }
	void SetAge(int a) { age = a; }
	void SetGrade(float g) { grade = g; }

	// функция для установки всех трех полей
	void Set(string n, int a, float g) { //  объявление общедоступной функция с именем Set, которая устанавливает для всех трех переменных-членов заданные значения.
		name = n;
		age = a;
		grade = g;
	}

	
	void Show() const { //  объявление общедоступной функция с именем Show, которая отображает значения переменных-членов.
		cout << "Имя: " << name << endl;
		cout << "Возраст: " << age << endl;
		cout << "Рейтинг: " << grade << endl;
	}
};


int main() {
	int groupSize;
    cout << "Введите количество человек в группе: " << endl;
    cin >> groupSize;
	STUDENT students[groupSize]; // массив объектов STUDENT размером groupSize.


	for (int i = 0; i < groupSize; i++) { // цикл, который перебирает массив студентов.
		string name;
		int age;
		float grade;

		cout << "Введите информацию о студенте " << i + 1 << ":" << endl;
		cout << "Имя: ";
		cin >> name;
		cout << "Возраст: ";
		cin >> age;
		cout << "Рейтинг: ";
		cin >> grade;

		students[i].Set(name, age, grade); // установка значения переменных для текущего объекта STUDENT в массиве студентов.
	}

	
	cout << "Информация о группе студентов:" << endl;
	for (int i = 0; i < groupSize; i++) { // Эта строка запускает цикл, который перебирает массив студентов.
		students[i].Show(); // В этой строке отображается информация о текущем объекте STUDENT в массиве студентов.
		cout << endl;
	}

	return 0;
}