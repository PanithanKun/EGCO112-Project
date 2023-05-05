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
    choose=getch();
    choose=tolower(choose);
    switch(choose){
         case('a'):
          l.ADD(&l);
          system("cls");
          l.Show_all();
         break;
    }
    
     }while(choose!='x');
    
    

    return 0;
}