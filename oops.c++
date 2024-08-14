#include <iostream>
#include <string>
using namespace std;

class Pet {
    private:
        string name;

    public:
        Pet(string pet_name) {
            this->name = pet_name; 
        }

        string getName() {
            return this->name; 
        }

        void speak() {
            cout << this->name << " says: Meow!" << endl; 
        }
};

class Caretaker {
    public:
        Caretaker(string caretaker_name, Pet& pet) : pet(pet) {
            this->name = caretaker_name; 
        }

        string getName() {
            return this->name; 
        }

        void takeCareOfPet() {
            cout << this->name << " is taking care of " << this->pet.getName() << "." << endl; 
            this->pet.speak(); 
        }

    private:
        string name;
        Pet& pet; 
};

int main() {
    Pet whiskers("Whiskers");
    whiskers.speak();
    
    Caretaker john("John", whiskers);
    john.takeCareOfPet();

    return 0;
}
