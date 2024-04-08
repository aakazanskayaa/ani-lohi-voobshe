#include <iostream>

using namespace std;

class Rectangle {
    int width, lenght;
public:
    void Set_values(int w, int l) {
        width = 1;
        if (w <= 0) cout << "Ошибка в ширине" << endl;
        else width = w;
        lenght = 1;
        if (l <= 0) cout << "Ошибка в длине" << endl;
        else lenght = l;
    }
    int Get_width() {
        return width;
    }
    int Get_lenght() {
        return lenght;
    }
    int Area() {
        return width * lenght;
    }
};

int main() {
    int n;
    cout << "Введите количество прямоугольников: ";
    cin >> n;
    if (n <= 0 || n > 10) {
        cout << "Ошибка в количестве прямоугольников" << endl;
        return 1;
    }
    Rectangle E[n];
    for (int i = 0; i < n; i++) {
        int w, l;
        cout << "Введите ширину и длину прямоугольника " << i + 1 << ": ";
        cin >> w >> l;
        E[i].Set_values(w, l);
    }
    cout << "Решение: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Прямоугольник " << i + 1 << ": ширина = " << E[i].Get_width() << ", длина = " << E[i].Get_lenght() << ", площадь = " << E[i].Area() << endl;
    }
    return 0;
}