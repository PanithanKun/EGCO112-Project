#include<iostream>
using namespace std;
class NODE {
       int E; //Elemental type
       int atk; // monster Attack DMG
       int hp; // monster HP
       string Name; // monster name
       //==============================
        int Pyro=0; //Fire
        int Hydro=0; //Water
        int Geo=0; //Stone
        int Anemo=0; //Wind
        int Pyro_DMG; //Fire DMG
        int Hydro_DMG; //Water DMG
        int Geo_DMG; //Stone DMG
      //================================
        NODE *nextPtr;// next pointer
public:
      NODE(int,int,string="Unknown");
      void Show_NODE();
      ~NODE();
};