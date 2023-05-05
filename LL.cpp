#include "LL_and_Elemental Monster.h"
#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;
LL::LL(){
     size=0;
     HeadPtr=NULL;
}
LL::~LL(){

  

}    
void LL::ADD(LL* q){
     int sel=1;//chech selection
     srand(time(NULL));
     cout<<".";
      Sleep(500);
    int atk=(rand())%20;//ATK DMG 0-20
      cout<<".";
      Sleep(500);
   int hp=(rand())%60;//HP 0-60
      cout<<"."<<endl;
      Sleep(500);
    string name="Unknown";//Monster name
     NodePtr temp = q->HeadPtr;
     NodePtr Currentptr = NULL;
     NodePtr Previousptr = NULL;
     Random(atk,hp);
     if(!temp){
          temp= new El_monster(atk,hp,size+1,name);  // create NOde 
          sel=Select_treat(temp);
          if(sel==1){
             q->HeadPtr=temp;//head = first NODE
          Previousptr=q->HeadPtr;
          Currentptr=q->HeadPtr;
          size++;
          //prev and current point the same place
          }
          
     }else{
          temp= new El_monster(atk,hp,size+1,name);  // create NOde 
          sel=Select_treat(temp);
          if(sel==1){
           Currentptr=q->HeadPtr;
          while(Currentptr->move_next()!=NULL){
               Currentptr=Currentptr->move_next(); //move current
          }
           Previousptr=Currentptr;
           Currentptr->set_next(temp); //linked NextPtr
           Currentptr=temp;
           Currentptr->set_back(Previousptr);//linked pPtr 
           size++;
          }    
     }

}
void LL::Show_all(){
    NodePtr t=HeadPtr;
    int i;
    for(i=0; i<size; i++){
     t->Show_NODE();
     t=t->move_next();
     cout<<"=================================="<<endl;
    }
}
void LL::Delete_all(){
    NodePtr t = HeadPtr;
    while(t!=NULL){
     cout<<"Delete  "<<t->show_name()<<endl;
     HeadPtr=HeadPtr->move_next();
     delete(t);
     t=HeadPtr;
    }
}
void LL::Random(int& atk, int& hp){
if(atk<10){
atk=10;
}
if(hp<30){
     hp=30;
}    
}
bool LL::Select( char select){
     bool A;
       switch (select)
       {
       case ('y'):
          A=true;
          break;
       case ('n'):
         A=false;
          break;
       }
       return A;
}
int LL::Select_treat(NODE*node){
     char select;
     int sel;
     do{
      node->Show_NODE();
     cout<<"Treat it?"<<endl;
     cout<<"y/n"<<endl;
     cin>>select;
     select=tolower(select);
     if(select!='y'&&select!='n'){
         cout<<"Invalid! Try Again!"<<endl;
         fflush(stdin);
          continue;
     }
     if(select=='y'||select=='n'){
         if(Select(select)){
         sel =1;
         break;
        }else{
         sel = 0;
         break;
        }
     }
     }while(select!='y'&& select!='n');//loop while input wrongly
     return sel;
}




