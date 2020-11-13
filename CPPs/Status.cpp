#include <iostream>
#include <string>
#include "../Headers/Status.h"


void Status::SetWealth(Player &x)
{
    if (x.Difficulty() == 0 )
        wealth = 3;
    else if (x.Difficulty() == 1)
        wealth = 300;
    else
        wealth = 30000;
}

int Status::ReturnWealth() const
{
    return wealth;
}

void Status::HealthLuck(const Player& x) {
    if (x.Luck() % 7 < 3 ) {
        std::cout
                << '\n' << " You were born with a bad malformation. There will be surgeries needed in order to fix your health." << '\n' ;
        health = 40;
    }
    if (x.Luck() % 7 >= 3 && x.Luck() % 7 < 5)
    {
        std :: cout << '\n' << " You were born with some lung problems. Nothing to worry about but you'll need to pay for a treatment."<< '\n';
        health = 75;
    }
    if (x.Luck() % 7 >= 5)
    {
        std::cout << '\n' << "You were born perfectly healthy."<< '\n' ;
        health=100;
    }
}
void Status::showStats(Player x) {

    if (x.showAge() == 0){
        Status::HealthLuck(x);
        Status::SetWealth(x);
        std::cout << '\n' << "Your initial stats are:" << '\n' << "Health: " << health << "\n" << "Hygiene: " << hygiene
                  << '\n' << "Fun: " << fun << '\n' << "Wealth: " << Status::ReturnWealth() << "$" << '\n';

    }
    else {
        std::cout << '\n' << "Your stats are: " << '\n' << "Health: " << health << "\n" << "Hygiene: " << hygiene
                  << '\n' << "Fun: " << fun << '\n' << "Wealth: " << Status::ReturnWealth() << "$" << '\n'<<"Age: "<<x.showAge();
        Status::Died(x);
    }
}

void Status::PermanentBuffHygiene() {
    if (hygiene<=97)
        hygiene=hygiene+3;
    else
        hygiene= 100;
}

void Status::PermanentNerfFun() {
    fun=fun-5;
}

int Status::ReturnHealth() const {
    return health;
}

int Status::ReturnFun() const {
    return fun;
}

void Status::Died(Player x) const {
    if (health <= 0 || hygiene <= 0 || fun <= 0)
        x.Death();
}

void Status::ChangeStats(int x, int y, int z, int t) {
    health= health + x;
    hygiene= hygiene + y;
    fun = fun + z;
    wealth = wealth + t;
}

void Status::LoseHealth(int x) {
    health = health - x;
}