#include <iostream>
using namespace std;
#include <string>

class Person {
private:

	string name;
	float hp;
	float damage;
	float pts;
	float armor;

public:
	Person() :name(" "), hp(0), damage(0), pts(0), armor(0) {}

	Person(string fname,float fhp, float fdamage, float fpts,
		float farmor) : name(fname), hp(fhp), damage(fdamage), pts(fpts), armor(farmor) {}
	////////////////////////

	void showParametrs() { 
		cout << "Name: " << name << " ; HP: " << hp << " ; Damage: " << damage << " ; Attack speed: " << pts << " ; Armor: " << armor<<endl;}

	void showWinner(Person first, Person second) {
		if (second.hp > 0)  cout << second.name << " WIN!!!" << endl;
		else if (first.hp > 0) cout << first.name << " WIN!!!" << endl;
	}

	void Fight(Person first, Person second) 
	{
		while (first.hp > 0 || second.hp > 0) {
			second.hp -= (first.damage * first.pts) / second.armor;
			first.hp -= (second.damage * second.pts) / first.armor;
		}
	}
};

int main()
{
	Person per1("Paladin", 100, 5, 5, 3), per2("Knight", 25, 3, 2, 1),resFIGHT;
	per1.showParametrs();
	per2.showParametrs();
	resFIGHT.Fight(per1,per2);
	resFIGHT.showWinner(per1, per2);
	return 0;
}