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

// New Derived class: Bird (New pet added without modifying existing code)
class Bird : public Pet {
public:
    Bird(string bird_name) : Pet(bird_name) {}

    void speak() override {
        cout << name << " says: Tweet!" << endl;
    }
};

// Caretaker class responsible for managing caretaker details only
class Caretaker {
private:
    string name;

public:
    Caretaker(string caretaker_name) {
        name = caretaker_name;
        cout << "Caretaker " << name << " is created." << endl;
    }

    ~Caretaker() {
        cout << "Caretaker " << name << " is destroyed." << endl;
    }

    string getName() {
        return name;
    }
};

class PetCareManager {
private:
    Caretaker* caretaker;
    Pet* pet;

public:
    PetCareManager(Caretaker* caretaker, Pet* pet) {
        this->caretaker = caretaker;
        this->pet = pet;
        cout << "Caretaker " << caretaker->getName() << " is taking care of " << pet->getName() << "." << endl;
    }

    void takeCareOfPet() {
        pet->speak();  
    }
};

int main() {
    Pet* pets[4];  
    pets[0] = new Cat("Whiskers");
    pets[1] = new Dog("Buddy");
    pets[2] = new Cat("Fluffy");
    pets[3] = new Bird("Tweety");  // Adding a new pet type (Bird)

    Caretaker* john = new Caretaker("John");

    PetCareManager* petCareManager = new PetCareManager(john, pets[0]);

    for (int i = 0; i < 4; i++) {
        pets[i]->speak();
    }

    petCareManager->takeCareOfPet();

    for (int i = 0; i < 4; i++) {
        delete pets[i];
    }
    delete john;
    delete petCareManager;

    return 0;
}
