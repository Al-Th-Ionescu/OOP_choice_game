#include "../Headers/Player.h"

Player::Player(std::string name){
    std::cout << "Introduce your name: ";
    std::cin >>name;
    this->name=name;
}

Player::~Player() {
    if (dead)
        std::cout << '\n' << name << " has died at age of "<<showAge()<<".";
}

int Player::Difficulty() const {
    if (luck % 3 ==0 )
        return 0;
    if (luck %3 == 1)
        return 1;
    return 2;
}


unsigned int Player::showAge() const  {
    return age;
}

int Player::Luck() const {
    return luck;
}
void Player::Death() {
    dead = true;
}

void Player::showPlayer() {
    {
        std::cout <<'\n' << "Your character was created successfully!"<<'\n' << " Your name is "<<name<<"." << '\n';
        srand(time(nullptr));
        luck = rand();
        if (Player::Difficulty() == 0)
            std::cout << " You are a poor child born in Syria."; //Hardest difficulty
        else
        if (Player::Difficulty() == 1)
            std::cout << " You were born in a modest family from Ukraine."; //Moderate difficulty
        else
            std::cout<< " What a luxury! You were born in Sweden and you are a part of the royal family!"; //Easy difficulty
    }
}

void Player::Aging() {
    age++;
}