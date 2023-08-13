#include <iostream>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;


// Задание 2
// Создать абстрактный базовый класс "Домашнее животное" с виртуальными функциями - методами
// Sound() - издает звук животного(пишем текстом в консоль);
// Show() - отображает имя животного;
// Type() - отображает название его подвида.
// Создайте производные классы "Собака", "Кошка", "Попугай", "Хомяк".
// С помощью конструктора установить имя каждого животного и его характеристики.
// В каждом дочернем классе переопределите виртуальные функции базового класса.
// Написать функцию, которая по выбору пользователя создает экземпляр класса "Собака", "Кошка", "Попугай", "Хомяк" (функция "фабрики класса" по аналогии с CreateShape()) и возвращает через указатель на базовый класс "Домашнее животное".

// А бстрактный базовый класс "Домашнее животное"
class Pet
{
private:
    string Name;
protected:
    string Breed;
public:
    Pet() = delete;
    Pet(string name) : Name(name) {}

    string GetName()  const { return Name; }
    string GetBreed() const { return Breed; }

    void SetName(string val)  { Name = val; }
    void SetBreed(string val) { Breed = val; }

    virtual void Input()
    {
        cout << "Enter info for " << typeid(*this).name() << endl;

        string tmp;
        cout << "Enter breed: ";
        getline(cin, tmp);
        SetBreed(tmp);
    }

    // Sound() - издает звук животного(пишем текстом в консоль);
    virtual void Sound() = 0;

    // Show() - отображает имя животного;
    virtual void Show()
    {
        cout << typeid(*this).name() << endl;
        cout << "Name: " << GetName() << endl;
    }

    // Type() - отображает название его подвида.
    virtual void Type() = 0;

    virtual ~Pet() {}
};


// Класс "Собака"
class Dog : virtual public Pet
{
protected:
    string Toy;			// любимая игрушка собаки
public:
    Dog() : Pet("Dog") {}
    Dog(string toy, string breed) : Pet("Dog"), Toy(toy) {}

    string GetToy()   const { return Toy; }
    void SetToy(string val) { Toy = val; }

    virtual void Input() override
    {
        Pet::Input();
        string tmp;
        cout << "Enter favorite toy: "; 
        getline(cin, tmp); 
        SetToy(tmp);
    }

    virtual void Sound() override
    {
        cout << typeid(*this).name() << endl;
        cout << "Sound: woof-woof" << endl;
    }

    virtual void Show() override
    {
        Pet::Show();
        cout << "Toy: " << GetToy() << endl;
    }

    virtual void Type() override
    {
        cout << typeid(*this).name() << endl;
        cout << "Breed: " << GetBreed() << endl;
    }
    
    virtual ~Dog() override {}
};


// Класс "Кошка"
class Cat : virtual public Pet
{
private:
    int LifeCount;
public:
    Cat() : Pet("Cat"), LifeCount() {}
    Cat(int count) : Pet("Cat"), LifeCount(count) {}

    int GetLifeCount()   const { return LifeCount; }
    void SetLifeCount(int val) { LifeCount = val; }

    virtual void Input() override
    {
        Pet::Input();
        int tmp;
        cout << "Enter life count: ";
        (cin >> tmp).ignore();
        SetLifeCount(tmp);
    }

    virtual void Sound() override
    {
        cout << typeid(*this).name() << endl;
        cout << "Sound: meow-meow" << endl;
    }

    virtual void Show() override
    {
        Pet::Show();
        cout << "Life Count: " << GetLifeCount() << endl;
    }

    virtual void Type() override
    {
        cout << typeid(*this).name() << endl;
        cout << "Breed: " << GetBreed() << endl;
    }

    virtual ~Cat() override {}
};


// Класс "Попугай"
class Parrot : virtual public Pet
{
private:
    string Word;		// любимое или повторяемое слово попугая(?)
public:
    Parrot() : Pet("Parrot") {}
    Parrot(string word) : Pet("Parrot"), Word(word) {}

    string GetWord() const { return Word; }
    void SetWord(string val) { Word = val; }

    virtual void Input() override
    {
        Pet::Input();
        string tmp;
        cout << "Enter favorite word: ";
        getline(cin, tmp);
        SetWord(tmp);
    }

    virtual void Sound() override
    {
        cout << typeid(*this).name() << endl;
        cout << "Sound: squawk-squawk" << endl;
    }

    virtual void Show() override
    {
        Pet::Show();
        cout << "Word: " << GetWord() << endl;
    }

    virtual void Type() override
    {
        cout << typeid(*this).name() << endl;
        cout << "Breed: " << GetBreed() << endl;
    }

    virtual ~Parrot() override {}
};


// Класс "Хомяк"
class Hamster : virtual public Pet
{
private:
    string Food;		// любимая еда
public:
    Hamster() : Pet("Hamster") {}
    Hamster(string food) : Pet("Hamster"), Food(food) {}

    string GetFood() const { return Food; }
    void SetFood(string val) { Food = val; }

    virtual void Input() override
    {
        Pet::Input();
        string tmp;
        cout << "Enter favorite food: ";
        getline(cin, tmp);
        SetFood(tmp);

    }
    virtual void Sound() override
    {
        cout << typeid(*this).name() << endl;
        cout << "Sound: squeak-squeak" << endl;
    }

    virtual void Show() override
    {
        Pet::Show();
        cout << "Food: " << GetFood() << endl;
    }

    virtual void Type() override
    {
        cout << typeid(*this).name() << endl;
        cout << "Breed: " << GetBreed() << endl;
    }

    virtual ~Hamster() override {}
};

// функция "Фабрики класса Pet" 
Pet* CreatePet()
{
    int choice;
    cout << "1. Dog." << endl;
    cout << "2. Cat." << endl;
    cout << "3. Parrot." << endl;
    cout << "4. Hamster." << endl;
    cout << "0. Exit." << endl;
    cout << "Enter choice: ";
    (cin >> choice).ignore();

    switch (choice)
    {
    case 1: return new Dog;
    case 2: return new Cat;
    case 3: return new Parrot;
    case 4: return new Hamster;
    case 0: return nullptr;
    }

    return nullptr;
}

int main()
{
    for (;;)
    {
        Pet* pet = CreatePet();

        if (pet == nullptr) { break; }
        cout << "--------------------------------------------------\n";
        pet->Input();
        cout << "--------------------------------------------------\n";
        pet->Sound();
        cout << "--------------------------------------------------\n";
        pet->Show();
        cout << "--------------------------------------------------\n";
        pet->Type();
        cout << "--------------------------------------------------\n";
        delete pet;
    }
    cout << "Good bye...\n";
}