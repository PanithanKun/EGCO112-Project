#include "NODE.h"
#include <iostream>
using namespace std;
class LL{
   NodePtr HeadPtr;
   int size;
   public:
   LL();
   ~LL();
   void ADD(LL*);
   void Show_all();
   void Random(int&,int&);
   NODE* Tail_next();
   void Delete_all();
   bool Select(char);
   int Select_treat(NODE*);
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