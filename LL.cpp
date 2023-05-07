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
if(atk<10){ //atk>=10
atk=10;
}
if(hp<30){ //hp>=30
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
     cin>>select;//input 
     select=tolower(select); //change to lowercase (just in case for the input is an Uppercase)
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
void LL::Delete(LL* q){
     string select;
     NodePtr PreviousPtr=q->HeadPtr;
     NodePtr CurrentPtr=PreviousPtr->move_next();
     NodePtr temp=NULL;
     NodePtr temp2=NULL;
     do{
     cout<<"Input Monster Number to DELETE:";
     cin>>select;
     cout<<"["<<stoi(select)<<"]"<<endl;
     if(Check_num(select)){
           if(stoi(select) == PreviousPtr->show_order()&&PreviousPtr==q->HeadPtr){
           temp=PreviousPtr;
           PreviousPtr=PreviousPtr->move_next();
           q->HeadPtr=PreviousPtr;
           delete(temp);
           size--;
           q->Set_order(q);
           break;
       }else {
          
          while(stoi(select) != PreviousPtr->show_order()&&CurrentPtr!=NULL){
                 PreviousPtr=CurrentPtr;
                 CurrentPtr=CurrentPtr->move_next();
          }
          
          if(CurrentPtr!=NULL&& stoi(select) == PreviousPtr->show_order()){
               temp=PreviousPtr;
               PreviousPtr=PreviousPtr->move_back();
               PreviousPtr->set_next(CurrentPtr);
               CurrentPtr->set_back(PreviousPtr);
               delete(temp);
               size--; 
             q->Set_order(q);
               break;                         
          }
          if(CurrentPtr==NULL){
               temp=PreviousPtr;
               PreviousPtr=PreviousPtr->move_back();
               PreviousPtr->set_next(NULL);
               temp->set_back(NULL);
               delete(temp);
               size--;
               if(size==1){
                 CurrentPtr=PreviousPtr;
               }else if(size>1){
                  CurrentPtr=PreviousPtr;
               PreviousPtr=PreviousPtr->move_back();
     
               }   
              q->Set_order(q);
               break;
          }
          
  
          
       }

     }else{
      cout<<"Try again!"<<endl;
      continue;
     }

     }while(1);

}
bool LL::Check_num(string str){
      int i;
      for(i=0; i<str.length(); i++){ //.length() like strlen()
          if(isdigit(str[i])==false){
               return false;
          }

      }
    return true;
}
void LL::Set_order(LL*q){
      int i;
      NodePtr t = q->HeadPtr;
      for(i=1; i<=size; i++){
         t->set_order_node(i);//set number
        t=t->move_next();
      }
}


