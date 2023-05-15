#include <iostream>

using namespace std;

class Character{
    public :
    string name;
    int hp;
    int attackDamage;
    Character* next;
};

class Monster {
    public :
    string name;
    int hp;
    int attackDamage;
    Monster* next;
};

int characterVsMonster(Character* character, Monster* monster) {
    cout << character->name << " fights " << monster->name << " (HP: " << monster->hp << ", Attack Damage: " << monster->attackDamage << ")!" << endl;

    while (character->hp > 0 && monster->hp > 0) {
        monster->hp -= character->attackDamage;
        if (monster->hp <= 0) {
            cout << character->name << " wins!" << endl;
            return 1;
            break;
        }

        character->hp -= monster->attackDamage;
        if (character->hp <= 0) {
            cout << monster->name << " wins!" << endl;
            return 2;
            break;
        }
    }
    return 0;
}