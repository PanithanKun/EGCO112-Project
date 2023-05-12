#include <iostream>
#include "NODE.h"
using namespace std;
class LL{
   NodePtr HeadPtr;
   string trainer;
   int atk;
   int size;
   int max_hp=100;
   int hp=max_hp;
   int potions=3;
   int check_dead=0;
   public:
   LL(string="Hum",int=10);
   ~LL();
   void ADD(LL*);//add node
   void Show_all();//show all nodes
   void Random(int&,int&);//random stats
   void Set_order(LL*);//set order
   bool fight(NODE*,LL*);//fight monster
   void Delete(LL*);//delete
   int show_hp();//show hp
   int show_potion();//show potions
   void Delete_all();//delete all nodes
   bool Select(char);//select (yes or no)
   void attack(NODE*);//attack monster
   int  show_attack();//show ATK
   void use_potion();//use potion
   int Select_fight(NODE*);//select fight
   bool Check_num(string);//check var
   int show_Max_hp();//show max_hp
   bool capture(NODE*t);
};
class El_monster :public NODE{
        int E; //Elemental type
        int Pyro=0; //Fire
        int Hydro=0; //Water
        int Geo=0; //Stone
        int Anemo=0; //Wind

        int Pyro_DMG; //Fire DMG
        int Hydro_DMG; //Water DMG
        int Geo_DMG; //Stone DMG
        int Anemo_DMG; //Wind DMG

public:
     El_monster(int,int,int,string="Unknown"); //Create Element of monster 
     ~El_monster();
     void element(); // set Element
     void Show_NODE();
     void attack(NODE*,LL* = NULL);//monster use elemental skills
};
typedef El_monster* ElPtr;