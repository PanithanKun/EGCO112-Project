#include <iostream>
#include "LEAGUE.h"
using namespace std;
int main() {
    int check;
    Character* character = new Character{"Warrior", 100 , 10, new Character{"mage",80,10,nullptr}};

    Monster* monsters = new Monster{"Goblin", 50, 8, new Monster{"Orc", 80, 12, nullptr}};

    while (monsters != nullptr||character != nullptr) {
        check = characterVsMonster(character, monsters);
        if(check == 1) monsters = monsters->next;
        else if (check == 0) character = character->next;
    }

    return 0;
}