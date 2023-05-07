#include <iostream>
#include "NODE.h"
using namespace std;
class LL{
   NodePtr HeadPtr;
   int size;
   public:
   LL();
   ~LL();
   void ADD(LL*);//add node
   void Show_all();//show all nodes
   void Random(int&,int&);//random stats
   void Set_order(LL*);
   void Delete(LL*);//delete
   void Delete_all();//delete all nodes
   bool Select(char);//select (yes or no
   int Select_treat(NODE*);
   bool Check_num(string);
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
};