#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Live {
public:
	virtual void live();
	~Live();
};
class Eat {
public:
	virtual void eat();
	~Eat();
};
class Move {
public:
	virtual void move();
	~Move();
};
class Reproduce {
public:
	virtual void reproduce();
	~Reproduce();
};
class Animal {
public:
	void display();
	Animal(string n, Live* a, Eat* b, Move* c, Reproduce* d);
	~Animal();
private:
	string name;
	Live* m_live;
	Eat* m_eat;
	Move* m_move;
	Reproduce* m_reproduce;
};

class LiveUnderwater : public Live {
public:
	void live();
};
class LiveOnLand : public Live {
public:
	void live();
};
class LiveOnTree :public Live {
public:
	void live();
};

class EatMeat : public Eat {
public:
	void eat();
};
class EatGrass : public Eat {
public:
	void eat();
};

class Swim : public Move {
public:
	void move();
};
class Fly : public Move {
public:
	void move();
};
class Feet : public Move {
public:
	void move();
};
class Crawwing : public Move {
public:
	void move();
};

class GiveBirth :public Reproduce {
public:
	void reproduce();
};
class LayEgg :public Reproduce {
public:
	void reproduce();
};

class Zoo {
private:
	vector<Animal*> m_animal;
public:
	void input();
	void display();
	~Zoo();
};





#endif