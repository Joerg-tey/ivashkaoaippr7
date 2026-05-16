#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Animal {
protected:
	string name;
public:
	Animal(string n) : name(n) {}
	virtual void makeSound() const {
		cout << name << "Makes unidentified sound" << endl;
	}
	virtual void move() const = 0;
	virtual ~Animal() {
		cout << "Object destroyed" << endl;
	}
};
class Cat : public Animal {
public:
	Cat(const string n) : Animal(n) {}
	void makeSound() const override {
		cout << name << " meows" << endl;
	}
	void move() const override {
		cout << name << " sneaks quietly" << endl;
	}
};
class Dog : public Animal {
private:
	string breed;
public:
	Dog(const string n, const string b) : Animal(n), breed(b) {}
	void makeSound() const override {
		cout << name << "bread: " << breed << " barks" << endl;
	}
	void move() const override {
		cout << name << " chases the ball" << endl;
	}
};
class Bird : public Animal {
private:
	bool fly;
public:
	Bird(const string n, bool f) : Animal(n), fly(f) {}
	void makeSound() const override {
		cout << name << " chirps: kirk-kirk" << endl;
	}
	void move() const override {
		if (fly) {
			cout << name << " flies" << endl;
		}
		else {
			cout << name << " doesn't fly" << endl;
		}
	}
};
void animalShow(Animal* animal) {
	animal->makeSound();
	animal->move();
}

int main()
{
	const int SIZE = 3;
	Animal* animals[SIZE] = {
	  new Cat("Murzik"),
	  new Dog("Chappie", "Biggle"),
	  new Bird("Barmaley", true),
	};

	for (int i = 0; i < SIZE; i++) {
		cout << "Animal #" << i + 1 << endl;
		animalShow(animals[i]);
	}

	cout << "\nMemory" << endl;

	for (int i = 0; i < SIZE; i++) {
		delete animals[i];
	}

	return 0;
}
