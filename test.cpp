#include <iostream>
#include <cstring>
#include <conio.h>
#include "LL_and_Elemental Monster.h"
int main(int argc,char **argv){
    int atk;
    int hp;
    string name;
    char choose;
     LL l;
     do{
    cout<<"CHOOSE:"<<endl;
    cout<<"A.Random Monster"<<endl;
    cout<<"B.Delete Monster"<<endl;
    choose=getch();//input
    choose=tolower(choose);//lowercase
    switch(choose){
         case('a'):
          l.ADD(&l);//add note
          system("cls");
          l.Show_all();//show all nodes
         break;
         case('b'):
         l.Delete(&l);//delete node
         l.Show_all();
         break;
         default:
         cout<<"Invalid! Try again!"<<endl;
    }
    
     }while(choose!='x');
    
    

    return 0;
}