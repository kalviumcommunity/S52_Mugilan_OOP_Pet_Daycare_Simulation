#include <iostream>
#include <string>
using namespace std;

class Pet {
    private:
        string name;
        static int petCount;
        static int speakCount;

    public:
        Pet(string pet_name) {
            this->name = pet_name;
            petCount++;
        }

        string getName() {
            return this->name;
        }

        void speak() {
            cout << this->name << " says: Meow!" << endl;
            speakCount++;
        }

        static int getPetCount() {
            return petCount;
        }

};

// Initialize static variables
int Pet::petCount = 0;

class Caretaker {
    public:
        Caretaker(string caretaker_name, Pet* pet) : pet(pet) {
            this->name = caretaker_name;
        }

        string getName() {
            return this->name;
        }

        void takeCareOfPet() {
            cout << this->name << " is taking care of " << this->pet->getName() << "." << endl;
            this->pet->speak();
        }

    private:
        string name;
        Pet* pet;
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

    cout << "Total number of pets created: " << Pet::getPetCount() << endl;


    for (int i = 0; i < 3; i++) {
        delete pets[i];
    }
    delete john;

    return 0;
}
