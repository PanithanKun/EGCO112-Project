#include "LL_and_Elemental Monster.h" 
#include <iostream>
#include <ctime>
using namespace std;
El_monster::El_monster(int atk,int hp,int size,string name):NODE(atk,hp,size,name){
           srand(time(NULL));//random from time
           E=(rand())%100; //random number 0-100
           element();
} 
El_monster::~El_monster(){

}
void El_monster::element(){
     if(E>=0 && E<=25){ //first 25%
      E=1; 
     }else if(E>25 && E<=50){ //second 25%
      E=2;
     }else if(E>50 && E<=75){ //third 25%
      E=3;
     }else if(E>75 && E<=100){//last 25%
      E=4;
     }
      switch (E)
       {
       case (1):
         Pyro=1; //set Fire
        break;
         case (2): 
        Hydro=1; //set Water
        break;
         case (3):
        Geo=1; //set Geo
        break;
         case (4):
        Anemo=1; //set Wind
        break;

       default:
        break;
       }   
}
void El_monster::Show_NODE(){
       cout<<"Type: ";
       if(Pyro==1){
       cout<<"Pyro"<<endl; //print Pyro
       }else if(Hydro==1){
       cout<<"Hydro"<<endl;//print Hydro
       }else if(Geo==1){
       cout<<"Geo"<<endl; //print Geo
       }else if(Anemo==1){
       cout<<"Anemo"<<endl; //print Anemo
       }
       NODE::Show_NODE();
}
