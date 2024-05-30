﻿//Task 1

#include <iostream>
using namespace std;
// Базовий клас
class Base {
    int data;
};

// Проміжні класи з не-віртуальним успадкуванням
class Derived1 : public Base {
    int data1;
};

class Derived2 : public Base {
    int data2;
};

// Кінцевий похідний клас з не-віртуальним успадкуванням
class FinalNonVirtual : public Derived1, public Derived2 {
    int finalData;
};

// Проміжні класи з віртуальним успадкуванням
class VirtualDerived1 : virtual public Base {
    int data1;
};

class VirtualDerived2 : virtual public Base {
    int data2;
};

// Кінцевий похідний клас з віртуальним успадкуванням
class FinalVirtual : public VirtualDerived1, public VirtualDerived2 {
    int finalData;
};

int main() {
    setlocale(LC_CTYPE, "Ukr");
    FinalNonVirtual nonVirtualObj;
    FinalVirtual virtualObj;

    cout << "Розмір об'єкта з не-віртуальним успадкуванням: " << sizeof(nonVirtualObj) << " байтів" << endl;
    cout << "Розмір об'єкта з віртуальним успадкуванням: " << sizeof(virtualObj) << " байтів" << endl;

    return 0;
}


//Task2
/*
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Абстрактний клас рівняння
class Equation {
public:
    // Віртуальна функція для обчислення кореня рівняння
    virtual void calculateRoots() const = 0;

    // Віртуальний деструктор
    virtual ~Equation() {}
};

// Похідний клас лінійного рівняння
class LinearEquation : public Equation {
private:
    double a, b;

public:
    // Конструктор
    LinearEquation(double _a, double _b) : a(_a), b(_b) {}

    // Обчислення кореня рівняння
    void calculateRoots() const override {
        if (a == 0) {
            cout << "Це не лінійне рівняння\n";
        }
        else {
            double root = -b / a;
            cout << "Корінь лінійного рівняння: " << root << endl;
        }
    }
};

// Похідний клас квадратного рівняння
class QuadraticEquation : public Equation {
private:
    double a, b, c;

public:
    // Конструктор
    QuadraticEquation(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}

    // Обчислення кореня рівняння
    void calculateRoots() const override {
        double discriminant = b * b - 4 * a * c;
        if (discriminant > 0) {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Корені квадратного рівняння: " << root1 << " i " << root2 << endl;
        }
        else if (discriminant == 0) {
            double root = -b / (2 * a);
            cout << "Корінь квадратного рівняння: " << root << endl;
        }
        else {
            cout << "Корені квадратного рівняння у вигляді комплексних чисел\n";
        }
    }
};

// Похідний клас біквадратного рівняння
class BiquadraticEquation : public Equation {
private:
    double a, b, c, d;

public:
    // Конструктор
    BiquadraticEquation(double _a, double _b, double _c, double _d) : a(_a), b(_b), c(_c), d(_d) {}

    // Обчислення кореня рівняння
    void calculateRoots() const override {
        cout << "Це біквадратне рівняння, обчислення коренів неможливе\n";
    }
};

int main() {
    setlocale(LC_CTYPE, "Ukr");
    // Масив вказівників на абстрактний клас
    vector<Equation*> equations;

    // Додавання об'єктів похідних класів до масиву вказівників
    equations.push_back(new LinearEquation(2, -3));
    equations.push_back(new QuadraticEquation(1, -3, 2));
    equations.push_back(new BiquadraticEquation(1, 2, 3, 4));

    // Обчислення коренів для кожного рівняння
    for (const auto& equation : equations) {
        equation->calculateRoots();
    }

    // Видалення об'єктів
    for (const auto& equation : equations) {
        delete equation;
    }

    return 0;
}
*/
//Task3
/*
#include <iostream>
#include <string>

using namespace std;

// базовий клас
class Transport {
protected:
    string model;
    int year;

public:
    //конструктор
    Transport(string _model, int _year) : model(_model), year(_year) {}

    //віртуальний деструктор
    virtual ~Transport() {}

    //введення даних
    virtual void input() {
        cout << "Введіть модель: ";
        cin >> model;
        cout << "Введіть рік випуску: ";
        cin >> year;
    }

    // Виведення даних
    virtual void output() const {
        cout << "Модель: " << model << ", Рік випуску: " << year << endl;
    }
};

//похідний
class Ship : public Transport {
protected:
    string shipType;

public:
    //конструктор
    Ship(string _model, int _year, string _shipType) : Transport(_model, _year), shipType(_shipType) {}

    //введення
    void input() override {
        Transport::input();
        cout << "Введіть тип корабля: ";
        cin >> shipType;
    }

    //виведення
    void output() const override {
        Transport::output();
        cout << "Тип корабля: " << shipType << endl;
    }
};

// Похідний клас
class PassengerTransport : public Transport {
protected:
    int passengerCapacity;

public:
    //конструктор
    PassengerTransport(string _model, int _year, int _passengerCapacity) : Transport(_model, _year), passengerCapacity(_passengerCapacity) {}

    //введення
    void input() override {
        Transport::input();
        cout << "Введіть пасажиромісткість: ";
        cin >> passengerCapacity;
    }

    // виведення
    void output() const override {
        Transport::output();
        cout << "Пасажиромісткість: " << passengerCapacity << " осіб" << endl;
    }
};

//похідний клас  який успадковує два батьківських класи
class PassengerShip : public Ship, public PassengerTransport {
public:
    //конструктор
    PassengerShip(string _model, int _year, string _shipType, int _passengerCapacity) : Ship(_model, _year, _shipType), PassengerTransport(_model, _year, _passengerCapacity) {}

    //введення даних
    void input() override {
        Ship::input();
        PassengerTransport::input();
    }

    //виведення даних
    void output() const override {
        Ship::output();
        PassengerTransport::output();
    }
};

int main() {
    setlocale(LC_CTYPE, "Ukr");
    // cтворення об'єкта
    PassengerShip myShip("Titanic", 1912, "Пасажирський", 2200);
    cout << "Виведення даних"<<endl;
    myShip.output();

    return 0;
}
*/