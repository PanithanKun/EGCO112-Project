#include "LL_and_Elemental Monster.h" 
#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;
El_monster::El_monster(int atk,int hp,int size,string name):NODE(atk,hp,size,name){
           srand(time(NULL));//random from time
           E=(rand())%100; //random number 0-100
           element();
           set_DMG();
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
void El_monster::attack(NODE* t,LL* q){
     int DMG;
    int Crit;
     if(Pyro==1){
         Pyro_DMG=t->show_atk()*(1+0.1);//set Pyro DMG
         DMG=Pyro_DMG;
       }else if(Hydro==1){
         Hydro_DMG=t->show_atk()*(1+0.1);//set Hydro DMG
         DMG=Hydro_DMG;
       }else if(Geo==1){
        DMG=Geo_DMG;
        Geo_DMG=t->show_atk()*(1+0.1);//set Geo DMG
       }else if(Anemo==1){
       Anemo_DMG=t->show_atk()*(1+0.1);//set Anemo DMG
        DMG=Anemo_DMG;
       }

   if(q!=NULL){
     if(q->show_size()==0){
    
    srand(time(NULL));
    Crit=(int)(rand()%100);
    if(Crit>=95){
      Crit=1;
    }else{
      Crit=0;
    }
    DMG*=(0.1*t->show_Max_hp());
   if(Crit==1){

    DMG=DMG*(1+0.5);
   }
   Sleep(1500);
   if(q->show_hp()>=0){
if(q->show_hp()-(DMG)>0){
  q->change_hp(DMG);
  if(Crit==0){
   cout<<'['<<q->show_name()<<" takes "<<DMG<<" DMG!]"<<endl;
  }else if(Crit==1){
    cout<<"[Critical ATK!]"<<endl;
    cout<<'['<<q->show_name()<<" takes "<<DMG<<" DMG!]"<<endl;
  }
} else if(q->show_hp()-(DMG)<=0){
     q->change_hp(0);
    Sleep(1500);
   }     
   }
  }
   }
   
}
void El_monster::set_DMG(){
  int DMG;
      if(Pyro==1){
         Pyro_DMG=show_atk()*(1+0.1);//set Pyro DMG
         DMG=Pyro_DMG;
       }else if(Hydro==1){
         Hydro_DMG=show_atk()*(1+0.1);//set Hydro DMG
         DMG=Hydro_DMG;
       }else if(Geo==1){
        DMG=Geo_DMG;
        Geo_DMG=show_atk()*(1+0.1);//set Geo DMG
       }else if(Anemo==1){
       Anemo_DMG=show_atk()*(1+0.1);//set Anemo DMG
        DMG=Anemo_DMG;
       }
     NODE::set_elemental_DMG(DMG);
}
string El_monster::show_elemental(){
    string e;
     if(Pyro==1){
       e="Pyro";
       }else if(Hydro==1){
        e= "Hydro";
       }else if(Geo==1){
        e="Geo"; 
       }else if(Anemo==1){
        e="Anemo";
       }

    return e;
}