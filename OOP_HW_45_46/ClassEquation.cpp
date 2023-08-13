#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <time.h>
#include <math.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;


// Задание 1.
// Создать виртуальный базовый класс с виртуальной функцией — корни уравнения.
// Создать производные классы:
// 1) класс линейных уравнений;
// 2) класс квадратных уравнений.
// Написать функцию, которая по выбору пользователя создает экземпляр класса Liner или SquareEqu 
// (функция "фабрики класса" по аналогии с CreateShape()) и 
// возвращает через указатель на базовый класс Equation.

// Базовый класс с виртуальной функцией — корни уравнения
class Equation 
{
private:
    string Name;
public:
    Equation(string name) : Name(name) {}
    Equation() = delete;

    string GetName() const { return Name; }

    virtual void Calc() = 0;
    virtual void Input() = 0;

    virtual void Print()
    {
        cout << typeid(*this).name() << endl;
        cout << "Name: " << GetName() << endl;
    }

    virtual ~Equation() {}
};


// Класс линейных уравнений
class Liner : virtual public Equation
{
private:
    float a, b;
protected:
    float x;
public:
    Liner() : Equation("Liner"), a(), b() {}
    Liner(float val1, float val2) : Equation("Liner"), a(val1), b(val2) {}

    virtual void Calc() override
    {
        if (a == 0)
        {
            if (b == 0)
            {
                cout << "Error: Infinite number of roots!" << endl;
            }
            else
            {
                cout << "No roots" << endl;
            }
        }
        else
        {
            x = -b / a;
        }
    }

    virtual void Input() override
    {
        cout << "Enter a and b coefficients: ";
        (cin >> a >> b).ignore();
    }

    virtual void Print() override
    {
        Equation::Print();
        // Пример: 3x - 2 = 0
        cout << "x = " << x << endl;
    }

    virtual ~Liner() {}
};


// Класс квадратных уравнений
class SquareEqu : virtual public Equation
{
private:
    float a, b, c;
protected:
    float D, x1, x2, x3;
public:
    SquareEqu() : Equation("SquareEqu"), a(), b(), c() {}
    SquareEqu(float val1, float val2, float val3) : Equation("SquareEqu"), a(val1), b(val2), c(val3) {}

    virtual void Calc() override
    {
        D = pow(b, 2) - 4 * a * c;
        if (D > 0)
        {
            x1 = ((-b) + sqrt(D)) / (2 * a);
            x2 = ((-b) - sqrt(D)) / (2 * a);
        }
        else if (D == 0)
        {
            x3 = (- b) / (2 * a);
        }
    }
    virtual void Input() override
    {
        cout << "Enter a, b and c coefficients: ";
        (cin >> a >> b >> c).ignore();
    }

    virtual void Print() override
    {
        Equation::Print();
        if (D > 0)
        {
            // Пример: 14x^2 - 5x - 1 = 0
            cout << "x1 = " << x1 << "\nx2 = " << x2 << endl;
        }
        else if (D == 0)
        {
            // Пример: 9x^2 - 30x + 25 = 0
            cout << "x = " << x3 << endl;
        }
        else
        {
            // Пример: 2x^2 + x + 67 = 0
            cout << "No roots" << endl;
        }
    }

    virtual ~SquareEqu() {}
};


// функция "Фабрики класса Equation" 
Equation* CreateEquation()
{
    int choice;
    cout << "1. Liner." << endl;
    cout << "2. SquareEqu." << endl;
    cout << "0. Exit." << endl;
    cout << "Enter choice: ";
    (cin >> choice).ignore();

    switch (choice)
    {
        case 1: return new Liner;
        case 2: return new SquareEqu;
        case 0: return nullptr;
    }

    return nullptr;
}

int main()
{
    for(;;)
    {
        Equation* equation = CreateEquation();

        if (equation == nullptr) { break; }
        cout << "--------------------------------------------------\n";
        equation->Input();
        cout << "--------------------------------------------------\n";
        equation->Calc();
        equation->Print();
        cout << "--------------------------------------------------\n";
        delete equation;
    }
    cout << "Good bye...\n";
}