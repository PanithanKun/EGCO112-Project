#include <iostream>
using namespace std;
class monster {
       string Name; // monster name
       int atk; // monster Attack DMG
       int hp; // monster HP
public:

     monster(int,int,int,string="Unknown");
     ~monster();
     virtual void display();
};