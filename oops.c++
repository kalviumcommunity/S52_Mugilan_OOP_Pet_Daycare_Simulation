#include <iostream>
#include <string>
using namespace std;

class Pet {
    private:
        string name;

    public:
        Pet(string pet_name) {
            name = pet_name;
        }

        string getName() {
            return name;
        }

        void speak() {
            cout << name << " says: Meow!" << endl;
        }

    
};

class Caretaker {
    public:
        Caretaker(string caretaker_name) {
            name = caretaker_name;
        }

        string getName() {
            return name;
        }

        void takeCareOfPet(Pet& pet) {
            cout << name << " is taking care of " << pet.getName() << "." << endl;
            pet.speak();
        }

    private:
        string name;
    };

int main() {
    Pet whiskers("Whiskers");
    whiskers.speak();
    Caretaker john("John");

    john.takeCareOfPet(whiskers);

    return 0;
}
