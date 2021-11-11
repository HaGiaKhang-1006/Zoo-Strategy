#include "header.h"

	 void Live::live() { cout << ""; }
	 Live::~Live() = default;

	 void Eat::eat() { cout << ""; }
	 Eat::~Eat() = default;


	void Move::move() { cout << ""; }
	Move::~Move() = default;


	void Reproduce::reproduce() { cout << ""; }
	Reproduce::~Reproduce() = default;


	void Animal::display() {
		cout << name << endl;
		m_live->live();
		m_eat->eat();
		m_move->move();
		m_reproduce->reproduce();
	}
	Animal::Animal(string n, Live* a, Eat* b, Move* c, Reproduce* d) : name(n), m_live(a), m_eat(b), m_move(c), m_reproduce(d) {}
	Animal::~Animal() { delete m_live; delete m_eat; delete m_move; delete m_reproduce; }



	void LiveUnderwater::live() {
		cout << "Live Underwater" << endl;
	}


	void LiveOnLand::live() {
		cout << "Live on land" << endl;
	}


	void LiveOnTree::live() {
		cout << "Live on the Tree" << endl;
	}



	void EatMeat:: eat() {
		cout << "Eat Meat" << endl;
	}


	void EatGrass::eat() {
		cout << "Eat Grass" << endl;
	}



	void Swim::move() {
		cout << "Move by Swim" << endl;
	}


	void Fly::move() {
		cout << "Move by Fly" << endl;
	}


	void Feet::move() {
		cout << "Move on Feet" << endl;
	}


	void Crawwing::move() {
		cout << "Move by Crawwing" << endl;
	}



	void GiveBirth::reproduce() {
		cout << "Reproduce by Give Birth" << endl;
	}


	void LayEgg::reproduce() {
		cout << "Reproduce by Lay Egg" << endl;
	}



	Zoo::~Zoo() {
		for (size_t i = 0; i < m_animal.size(); i++) {
			delete m_animal[i];
		}
	}


void menu() {
	cout << "====== Enter =======" << endl;
	cout << "\t 1: Enter Animal..." << endl;
	cout << "\t 0: Out..." << endl;
}
void menuLive() {
	cout << "Living: " << endl;
	cout << "1: Underwater" << endl;
	cout << "2. On Land" << endl;
	cout << "3. On Tree" << endl;
}
void menuEat() {
	cout << "Eating: " << endl;
	cout << "1: Meat" << endl;
	cout << "2. Grass" << endl;
}
void menuMove() {
	cout << "Moving: " << endl;
	cout << "1: Swim" << endl;
	cout << "2. Fly" << endl;
	cout << "3. Feet" << endl;
	cout << "4. Crawwing" << endl;
}
void menuReproduce() {
	cout << "Reproduce: " << endl;
	cout << "1: Give Birth" << endl;
	cout << "2. Lay Egg" << endl;
}

Live* LivingType(int a) {
	if (a == 1) { return new LiveUnderwater; }
	if (a == 2) { return new LiveOnLand; }
	if (a == 3) { return new LiveOnTree; }
	return nullptr;
}
Eat* EatingType(int a) {
	if (a == 1) { return new EatMeat; }
	if (a == 2) { return new EatGrass; }
	return nullptr;
}
Move* MovingType(int a) {
	if (a == 1) { return new Swim; }
	if (a == 2) { return new Fly; }
	if (a == 3) { return new Feet; }
	if (a == 4) { return new Crawwing; }
	return nullptr;
}
Reproduce* ReproducingType(int a) {
	if (a == 1) { return new GiveBirth; }
	if (a == 2) { return new LayEgg; }
	return nullptr;
}

void Zoo::input() {
	int flag;
	menu();
	cin >> flag;

	Live* live;
	Eat* eat;
	Move* move;
	Reproduce* reproduce;

	while (flag == 1) {

		cout << "Enter Name of Animal : ";
		string curName;
		cin.ignore(1000, '\n');
		getline(cin, curName);

		menuLive();
		cout << "You choose : ";
		cin >> flag;
		live = LivingType(flag);

		menuEat();
		cout << "You choose : ";
		cin >> flag;
		eat = EatingType(flag);

		menuMove();
		cout << "You choose : ";
		cin >> flag;
		move = MovingType(flag);

		menuReproduce();
		cout << "You choose : ";
		cin >> flag;
		reproduce = ReproducingType(flag);

		Animal* animal = new Animal(curName, live, eat, move, reproduce);
		m_animal.push_back(animal);

		menu();
		cin >> flag;
	}

}
void Zoo::display() {
	int size = m_animal.size();
	for (size_t i = 0; i < size; i++) {
		cout << "\nAnimal " << i + 1 << ":" << endl;
		m_animal[i]->display();
		cout << endl;
	}
}
