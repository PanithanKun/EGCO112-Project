#include <iostream>
#include <cstring>
#include <conio.h>
#include <windows.h>
#include "LEAGUE.h"
#include "display.h"
#include "LL_and_Elemental Monster.h" 
int main(){
   display a;
   string name;
   cout<<"Your name:";
    cin>>name;
    a.loading(name);
     a.welcome();
    int atk;
    int hp;
    char choose;
    
     LL trainer(name);
     
     do{
    cout<<"Hi "<<name<<'!'<<endl;
    cout<<""<<trainer.show_size()<<"/"<<"6"<<endl;
    cout<<"trainer: "<<trainer.show_name()<<"\t"<<trainer.show_hp()<<"/"<<trainer.show_Max_hp()<<endl;
    trainer.Show_all();
    cout<<"CHOOSE:"<<endl;
    cout<<"A.Random Monster"<<endl;
    cout<<"B.Delete Monster"<<endl;
    cout<<"C.heal All"<<endl;
    cout<<"D. Exit"<<endl;
    choose=getch();//input
    choose=tolower(choose);//lowercase
    try{
     if(choose<97||choose>100){
        throw "Try Again!";
     }
    }
    catch(const char* error){
         cout<<error<<endl;
         cin.clear();
        cin.ignore(50,'\n');
      }
    switch(choose){
         case('a'):
         if(trainer.show_size()<=6){
             trainer.ADD(&trainer);//add note
          system("cls");
         }else{
           cout<<"Maximum of monsters are 6!"<<endl;
         }
         break;
         case('b'):
         trainer.Delete(&trainer);//delete node
         trainer.Show_all();
         break;
         case('c'):
         trainer.heal_all(&trainer);
         break;
         case('d'):
         break;
    }
     }while(choose!='d'&&trainer.show_hp()>0);
    if(trainer.show_hp()<=0){
      system("cls");
      cout<<"GAME OVER"<<endl;
    }
    

    return 0;
}