#include <iostream>
#include <string>
using namespace std;

// Abstract base class: Pet
class Pet {
    protected:
        string name;

    public:
        Pet(string pet_name) {
            name = pet_name;
            cout << "Pet " << name << " is created." << endl;
        }

        virtual ~Pet() {
            cout << "Pet " << name << " is destroyed." << endl;
        }

        string getName() {
            return name;
        }

        // Pure virtual function making Pet an abstract class
        virtual void speak() = 0;
};

// Derived class: Cat
class Cat : public Pet {
    public:
        Cat(string cat_name) : Pet(cat_name) {}

        void speak() override {
            cout << name << " says: Meow!" << endl;
        }
};

// Derived class: Dog 
class Dog : public Pet {
    public:
        Dog(string dog_name) : Pet(dog_name) {}

        void speak() override {
            cout << name << " says: Woof!" << endl;
        }
};

// Caretaker class
class Caretaker {
    private:
        string name;
        Pet* pet;

    public:
        Caretaker(string caretaker_name, Pet* pet) {
            name = caretaker_name;
            this->pet = pet;
            cout << "Caretaker " << name << " is taking care of " << pet->getName() << "." << endl;
        }

        ~Caretaker() {
            cout << "Caretaker " << name << " is no longer taking care of " << pet->getName() << "." << endl;
        }

        void takeCareOfPet() {
            pet->speak();  // Calls the overridden speak function (virtual function)
        }
};

int main() {
    Pet* pets[3];
    pets[0] = new Cat("Whiskers");
    pets[1] = new Dog("Buddy");
    pets[2] = new Cat("Fluffy");

    Caretaker* john = new Caretaker("John", pets[0]);

    for (int i = 0; i < 3; i++) {
        pets[i]->speak();
    }

    john->takeCareOfPet();

    for (int i = 0; i < 3; i++) {
        delete pets[i];
    }
    delete john;

    return 0;
}
