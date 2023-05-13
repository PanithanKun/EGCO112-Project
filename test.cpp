#include <iostream>
#include <cstring>
#include <conio.h>
#include "LL_and_Elemental Monster.h" 
int main(int argc,char **argv){
    int atk;
    int hp;
    string name;
    char choose;
    cout<<"Your name:";
    cin>>name;
     LL trainer(name);
     do{
    cout<<"Hi "<<name<<'!'<<endl;
    cout<<""<<trainer.show_size()<<"/"<<"6"<<endl;
    trainer.Show_all();
    cout<<"CHOOSE:"<<endl;
    cout<<"A.Random Monster"<<endl;
    cout<<"B.Delete Monster"<<endl;
    choose=getch();//input
    choose=tolower(choose);//lowercase
    try{
     if(choose<97||choose>98){
        throw "for i in range(100) Stupid Fuck";
     }
    }
    catch(const char* error){
         cout<<error<<endl;
         cin.clear();
      }
    switch(choose){
         case('a'):
         trainer.Show_all();//show all nodes
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
    }
     }while(choose!='x'&&trainer.show_hp()>0);
    if(trainer.show_hp()<=0){
      system("cls");
      cout<<"GAME OVER"<<endl;
    }
    

    return 0;
}