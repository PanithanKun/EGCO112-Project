#include "NODE.h"
#include <iostream>
using namespace std;
NODE::NODE(int Atk ,int Hp,int Or,string name){
          atk=Atk;
          hp=Hp;
          Name=name;
          order=Or;
          nextPtr=NULL;
          pPtr=NULL;
}
NODE::~NODE(){
      
}
void NODE::Show_NODE(){
    //Print Stats
    cout<<"No."<<order<<endl;
    cout<<"Monster: "<<Name<<endl;
    cout<<"ATK:"<<atk<<endl;
    cout<<"HP: "<<hp<<endl;;
}
NODE* NODE::move_next(){
      return nextPtr;
}
void NODE::set_next(NODE* node){
       nextPtr = node; 
}
void NODE::set_back(NODE* node){
       pPtr = node;
}
string NODE::show_name(){
    return Name;
}
NODE* NODE::move_back(){
    return pPtr;
}

