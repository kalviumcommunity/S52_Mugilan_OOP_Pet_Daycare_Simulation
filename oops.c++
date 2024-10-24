#include <iostream>
#include <string>
using namespace std;

// Base class: Pet
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

        // Virtual method for polymorphism 
        virtual void speak() {
            cout << name << " makes a sound!" << endl;  
        }
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

// Caretaker class to demonstrate interaction with polymorphic objects
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
            cout << name << " is taking care of " << pet->getName() << "." << endl;
            pet->speak();  // Polymorphism
        }
};

int main() {
    Pet* pets[3];
    pets[0] = new Cat("Whiskers");  // Cat object
    pets[1] = new Dog("Buddy");     // Dog object
    pets[2] = new Cat("Fluffy");    // Another Cat object

    Caretaker* john = new Caretaker("John", pets[0]);

    for (int i = 0; i < 3; i++) {
        pets[i]->speak();  // Polymorphism
    }

    john->takeCareOfPet();

    for (int i = 0; i < 3; i++) {
        delete pets[i];  
    }
    delete john;  

    return 0;
}
