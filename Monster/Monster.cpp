#include "NODE.h"
#include <iostream>
using namespace std;
NODE::NODE(int Atk ,int Hp,string name){
          atk=Atk;
          hp=Hp;
          Name=name;
}
NODE::~NODE(){
      

}
void NODE::Show_NODE(){
    //Print Stats
    cout<<"Monster: "<<Name<<endl;
    cout<<"ATK:"<<atk<<endl;
    cout<<"HP: "<<hp<<endl;;
}
