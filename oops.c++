#include <iostream>
#include <string>
using namespace std;

class Pet {
    private:
        string name; 

    public:

        Pet(string pet_name) {
            setName(pet_name);
        }

        string getName() {
            return name;
        }

        void setName(string pet_name) {
            name = pet_name;  
        }

        // abstracting the details from the outside world
        void speak() {
            cout << getName() << " says: Meow!" << endl;
        }
};

class Caretaker {
    private:
        string name;  
        Pet* pet;     

    public:

        Caretaker(string caretaker_name, Pet* pet) {
            setName(caretaker_name);  
            this->pet = pet;  // abstracts away the internal working of Pet
        }

        string getName() {
            return name;
        }

        void setName(string caretaker_name) {
            name = caretaker_name;  
        }

        void takeCareOfPet() {
            cout << getName() << " is taking care of " << pet->getName() << "." << endl;
            pet->speak();  // Abstraction: Caretaker doesn't need to know how pet speaks
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
