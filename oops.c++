#include <iostream>
#include <string>
using namespace std;

class Pet {
    // Private attribute for encapsulation
    private:
        string name;

    public:
        Pet(string pet_name) {
            this->name = pet_name;
        }

        string getName() {
            return name;
        }

        void setName(string pet_name) {
            name = pet_name; // Encapsulation, hiding direct access
        }

        void speak() {
            cout << getName() << " says: Meow!" << endl;
        }
};

class Caretaker {
    private:
        string name;  // Private attribute for encapsulation
        Pet* pet;     // Private pointer to a Pet object

    public:
        Caretaker(string caretaker_name, Pet* pet) {
            this->name = caretaker_name ;  
            this->pet = pet;  
        }

        string getName() {
            return name;
        }

        void setName(string caretaker_name) {
            name = caretaker_name; // Encapsulation to set the name
        }

        void takeCareOfPet() {
            cout << getName() << " is taking care of " << pet->getName() << "." << endl;
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
