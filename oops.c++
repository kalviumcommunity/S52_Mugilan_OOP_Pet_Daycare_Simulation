#include <iostream>
#include <string>
using namespace std;

class Pet {
    private:
        string name;

    public:
        // Constructor
        Pet(string pet_name) {
            name = pet_name;
            cout << "Pet " << name << " is created." << endl;
        }

        // Destructor
        ~Pet() {
            cout << "Pet " << name << " is destroyed." << endl;
        }


        string getName() {
            return name;
        }


        void speak() {
            cout << name << " says: Meow!" << endl;
        }
};

class Caretaker {
    private:
        string name;
        Pet* pet;  

    public:
        // Constructor
        Caretaker(string caretaker_name, Pet* pet) {
            name = caretaker_name;
            this->pet = pet;
            cout << "Caretaker " << name << " is taking care of " << pet->getName() << "." << endl;
        }

        // Destructor
        ~Caretaker() {
            cout << "Caretaker " << name << " is no longer taking care of " << pet->getName() << "." << endl;
        }


        void takeCareOfPet() {
            cout << name << " is taking care of " << pet->getName() << "." << endl;
            pet->speak();
        }
};

int main() {

    Pet* pets[3];
    pets[0] = new Pet("Whiskers");
    pets[1] = new Pet("Fluffy");
    pets[2] = new Pet("Mittens");


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
