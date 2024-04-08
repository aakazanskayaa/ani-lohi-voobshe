#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    static int count; 
    char* organization; 
    char* position; 
    double experience; 
    char* name; 
    char gender; 
    int age; 
    double salary; 

public:
    // конструктор
    friend bool operator==(const Employee& lhs, const Employee& rhs); 
    Employee(const char* org, const char* pos, double exp, const char* name, char gen, int age, double sal)
        : organization(new char[strlen(org) + 1]), position(new char[strlen(pos) + 1]),
          experience(exp), name(new char[strlen(name) + 1]), gender(gen), age(age), salary(sal) {
        strcpy(this->organization, org);
        strcpy(this->position, pos);
        strcpy(this->name, name); 
        
        count++;
        
    }
    bool operator==(const Employee& rhs) {  // перегрузка оператора равенства
    return organization == rhs.organization &&
           position == rhs.position &&
           experience == rhs.experience &&
           name == rhs.name &&
           gender == rhs.gender &&
           age == rhs.age &&
           salary == rhs.salary;
        }
    Employee& operator= (const Employee& other) {  //  Перегрузка операторa присваивания
        if (this != &other) {
            organization = other.organization;
            position = other.position;
            experience = other.experience;
            name = other.name;
            gender = other.gender;
            age = other.age;
            salary = other.salary;
        }

        return *this;
    }

    // деструктор                                                                                                                        Деструктор используется для освобождения памяти
    ~Employee() {
        delete[] organization;
        delete[] position;
        delete[] name;
        count--;
    }

    void display() const {
        cout << endl;
        cout << "Имя: " << name << "\n";
        cout << "Организация: " << organization << "\n";
        cout << "Должность: " << position << "\n";
        cout << "Опыт: " << experience << " лет\n";
        cout << "Пол: " << (gender == 'M' ? "Мужской" : "Женский") << "\n";
        cout << "Возраст: " << age << "\n";
        cout << "Зарплата: " << salary << "\n\n";
    }
    void display1() const{
        cout << endl;
        cout << "Имя: " << name << endl;
        cout << "Пол: " << (gender == 'M' ? "Мужской" : "Женский") << endl;
    }

// Функция для изменения позиции сотрудника
void changePosition(Employee& emp) {
    cout << endl << "Введите новую позицию для сотрудника " << emp.name << ": ";
    cin >> emp.position;
}

// Функция для добавления зарплаты сотруднику
void addSalary(Employee& emp) {
    double additionalSalary;
    cout << endl << "Введите сумму, на которую увеличить зарплату сотруднику " << emp.name << ": ";
    cin >> additionalSalary;
    emp.salary += additionalSalary;
    emp.display();
}

// Функции для сравнения сотрудников по возрасту, зарплате и опыту

void compareAge(const Employee& emp1, const Employee& emp2) {
    if (emp1.age == emp2.age) {
        cout << endl << "Сотрудники " << emp1.name << "и " << emp2.name << " имеют одинаковый возраст." << endl << endl;
    } else if (emp1.age > emp2.age) {
        cout << endl << "Сотрудник " << emp1.name << " старше, чем " << emp2.name << "." << endl << endl;
    }  else {
        cout << endl << "Сотрудник " << emp2.name << " старше, чем " << emp1.name << "." << endl << endl;
    }
}
void compareSalary(const Employee& emp1, const Employee& emp2) {
    if (emp1.salary == emp2.salary) {
        cout << endl << "Заработная плата сотрудников " << emp1.name << "и " << emp2.name << "равна." << endl << endl;
    } else if (emp1.salary < emp2.salary) {
        cout << endl << "Заработная плата сотрудника " << emp1.name << " меньше, чем у сотрудника" << emp2.name << "." << endl << endl;
    } else {
        cout << endl << "Заработная плата сотрудника " << emp2.name << " меньше, чем у сотрудника "<< emp1.name << "." << endl << endl;
    }
}
void compareExperience(const Employee& emp1, const Employee& emp2) {
    if (emp1.experience == emp2.experience){
        cout << endl << "Сотрудники  "<< emp1.name << "и " << emp2.name << " имеют одинаковое количество лет стажа работы." << endl;
    } else if (emp1.experience > emp2.experience) {
        cout << endl << "У сотрудника "<< emp1.name <<" больше стаж работы." << endl;
    } else{
        cout << endl << "У сотрудника "<< emp2.name <<" больше стаж работы." << endl;
    }
}

    
    static void displayCount() {
        cout << "Количество сотрудников: " << count <<  "\n";
    }
    static int getCount() {
        return count;

    }
};
int Employee::count = 0;

int main() {
    Employee employees[5] = {
        Employee("Electronic Arts", "Бэкэнд программист", 5.2, "Kоровашкова Анна", 'F', 18, 5000),
        Employee("Big Hit", "Проектный менеджер", 7.5, "Влада Сыртмач", 'F', 17, 4000),
        Employee("Turkish Airlines", "Фронтэнд программист", 2.1, "Kaзанская Анна", 'F', 18, 827000),
        Employee("Black Star", "Переводчик песен на персидский", 3.5, "Искусных Дарья", 'F', 18, 750000),
        Employee("GHI Enterprise", "Веб-разработчик", 4.8, "Гренкова Гангрена", 'F', 29, 65000)
    };
    Employee::displayCount();  // Вызов статической функцию-член displayCount, чтобы отобразить значение счетчика статических переменных-членов.

    for (int i = 0; i < 5; i++) {  // Проход по массиву объектов и вызов функции-член display, чтобы отобразить значения переменных-членов.
        employees[i].display1();
    }
    
    int choice;
    int choice2;
    int employeeIndex;
    do{

        cout << "Меню:" << endl;
        cout << "1. Изменить позицию сотрудника" << endl;
        cout << "2. Добавить зарплату сотруднику" << endl;
        cout << "3. Сравнить сотрудников" << endl << endl;
        cout << "Введите номер операции (1, 2 или 3) или 0 для выхода: " << endl << endl;
        cin >> choice;
    
        if (choice == 1) {
            cout << endl << "Введите номер сотрудника, для которого вы хотите изменить позицию: ";
            cin >> employeeIndex;
            Employee employee(employees[employeeIndex - 1]); // создание объекта класса Сотрудник
            employee.changePosition(employee); 
            employees[employeeIndex - 1].display();
            cout << endl << "Позиция успешно изменена" << endl << endl;
        } else if (choice == 2) {
            cout << endl << "Введите номер сотрудника, для которого вы хотите добавить зарплату: ";
            cin >> employeeIndex;
            Employee employee(employees[employeeIndex - 1]); 
            employee.addSalary(employee); 
            cout << endl << "Зарплата успешно увеличена" << endl;
        } else if(choice == 3) {
            cout << endl << "Выберите, по какому параметру сравнить сотрудников: " << endl;
            cout << "[1] По возрасту"  << endl;
            cout << "[2] По зарплате" << endl;
            cout << "[3] По опыту" << endl << endl;
            cin >> choice2;
            if (choice2 == 1){
                cout << endl << "Введите номера сотрудников, которых вы хотите сравнить, не более двух цифр. " << endl << endl;
                int employeeIndex1, employeeIndex2;
                cin >> employeeIndex1;
                cin >> employeeIndex2;
                Employee employee1(employees[employeeIndex1 - 1]);
                Employee employee2(employees[employeeIndex2 - 1]);
                employee1.compareAge(employee1, employee2);
            } else if (choice2 == 2){
                cout << endl << "Введите номера сотрудников, которых вы хотите сравнить, не более трех цифр. " << endl << endl;
                int employeeIndex1, employeeIndex2;
                cin >> employeeIndex1;
                cin >> employeeIndex2;
                Employee employee1(employees[employeeIndex1 - 1]);
                Employee employee2(employees[employeeIndex2 - 1]);
                employee1.compareSalary(employee1, employee2);
            } else if (choice2 == 3){
                cout << endl << "Введите номера сотрудников, которых вы хотите сравнить, не более трех цифр. " << endl << endl;
                int employeeIndex1, employeeIndex2;
                cin >> employeeIndex1;
                cin >> employeeIndex2;
                Employee employee1(employees[employeeIndex1 - 1]);
                Employee employee2(employees[employeeIndex2 - 1]);
                employee1.compareExperience(employee1, employee2);
            }


    }
    } while (choice != 0);

    return 0;
}
