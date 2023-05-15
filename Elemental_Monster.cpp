#include "LL_and_Elemental Monster.h"
#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;
El_monster::El_monster(int atk,int hp,int size,string name):NODE(atk,hp,size,name){
           srand(time(NULL));//random from time
           E=(rand())%100; //random number 0-100
           element();
           set_DMG(atk);
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
void El_monster::attack(NODE* t){
     int DMG;
    int Crit;
    DMG=this->show_elemental_DMG();
       DMG=this->weakness_resistance(t,DMG);
    srand(time(NULL));
    Crit=(int)(rand()%100);
    if(Crit>=95){
      Crit=1;
    }else{
      Crit=0;
    }
    DMG+=(0.1*this->show_Max_hp());
   if(Crit==1){

    DMG=DMG*(1+0.5);
   }
   Sleep(1500);
   if(t->show_hp()>=0){
if(t->show_hp()-(DMG)>0){
  t->change_hp(DMG);
  if(Crit==0){
   cout<<'['<<t->show_name()<<" takes "<<DMG<<" DMG!]"<<endl;
  }else if(Crit==1){
    cout<<"[Critical ATK!]"<<endl;
    cout<<'['<<t->show_name()<<" takes "<<DMG<<" DMG!]"<<endl;
  }
} else if(t->show_hp()-(DMG)<=0){
   t->change_hp(DMG); 
    if(Crit==0){
   cout<<'['<<t->show_name()<<" takes "<<DMG<<" DMG!]"<<endl;
  }else if(Crit==1){
    cout<<"[Critical ATK!]"<<endl;
    cout<<'['<<t->show_name()<<" takes "<<DMG<<" DMG!]"<<endl;
    Sleep(1500);
   }     
  } 
   }
}
void El_monster::set_DMG(int atk){
      if(Pyro==1){
         Pyro_DMG=atk*(1+0.1);//set Pyro DMG
         elemental_DMG=Pyro_DMG;
       }else if(Hydro==1){
         Hydro_DMG=atk*(1+0.1);//set Hydro DMG
         elemental_DMG=Hydro_DMG;
       }else if(Geo==1){
        elemental_DMG=Geo_DMG;
        Geo_DMG=atk*(1+0.1);//set Geo DMG
       }else if(Anemo==1){
       Anemo_DMG=atk*(1+0.1);//set Anemo DMG
        elemental_DMG=Anemo_DMG;
       }
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
int El_monster::weakness_resistance(NODE*t,int dmg){
   //weakness +30%dmg
   if(this->show_elemental()=="Pyro"&&t->show_elemental()=="Anemo"){
      dmg+=(0.3*dmg);
      Sleep(1000);
      cout<<"It's more Effective!"<<endl;
      Sleep(1000);
   }else if(this->show_elemental()=="Anemo"&&t->show_elemental()=="Geo"){
      dmg+=(0.3*dmg);
      Sleep(1000);
      cout<<"It's more Effective!"<<endl;
      Sleep(1000);
   }else if(this->show_elemental()=="Geo"&&t->show_elemental()=="Hydro"){
      dmg+=(0.3*dmg);
      Sleep(1000);
      cout<<"It's more Effective!"<<endl;
      Sleep(1000);
   }else if(this->show_elemental()=="Hydro"&&t->show_elemental()=="Pyro"){
      dmg+=(0.3*dmg);
      Sleep(1000);
      cout<<"It's more Effective!"<<endl;
      Sleep(1000);
   }
   //resistance less 30%dmg
    if(this->show_elemental()=="Anemo"&&t->show_elemental()=="Pyro"){
      dmg-=(0.3*dmg);
      Sleep(1000);
      cout<<"It's not Effective!"<<endl;
      Sleep(1000);
   }else if(this->show_elemental()=="Geo"&&t->show_elemental()=="Anemo"){
      dmg-=(0.3*dmg);
      Sleep(1000);
      cout<<"It's not Effective!"<<endl;
      Sleep(1000);
   }else if(this->show_elemental()=="Hydro"&&t->show_elemental()=="Geo"){
      dmg-=(0.3*dmg);
      Sleep(1000);
      cout<<"It's not Effective!"<<endl;
      Sleep(1000);
   }else if(this->show_elemental()=="Pyro"&&t->show_elemental()=="Hydro"){
      dmg-=(0.3*dmg);
      Sleep(1000);
      cout<<"It's not Effective!"<<endl;
      Sleep(1000);
   }

   return dmg;
}
void El_monster::Take_DMG(NODE*t){
     int DMG;
    int Crit;
    DMG=t->show_elemental_DMG();
    cout<<"["<<DMG<<"]"<<endl;
    Sleep(1000);
       DMG=t->weakness_resistance(this,DMG);
    srand(time(NULL));
    Crit=(int)(rand()%100);
    if(Crit>=95){
      Crit=1;
    }else{
      Crit=0;
    }
    DMG+=(0.1*t->show_Max_hp());
   if(Crit==1){

    DMG=DMG*(1+0.5);
   }
   Sleep(1500);
   if(this->show_hp()>=0){
if(this->show_hp()-(DMG)>0){
  this->change_hp(DMG);
  if(Crit==0){
   Sleep(1000);
   cout<<'['<<this->show_name()<<" takes "<<DMG<<" DMG!]"<<endl;
   Sleep(1000);
  }else if(Crit==1){
   Sleep(1000);
    cout<<"[Critical ATK!]"<<endl;
    Sleep(1000);
    cout<<'['<<this->show_name()<<" takes "<<DMG<<" DMG!]"<<endl;
    Sleep(1000);
  }
} else if(this->show_hp()-(DMG)<=0){
   this->change_hp(DMG); 
    if(Crit==0){
      Sleep(1000);
   cout<<'['<<this->show_name()<<" takes "<<DMG<<" DMG!]"<<endl;
   Sleep(1000);
  }else if(Crit==1){
    Sleep(1500);
    cout<<"[Critical ATK!]"<<endl;
    Sleep(1000);
    cout<<'['<<this->show_name()<<" takes "<<DMG<<" DMG!]"<<endl;
    Sleep(1500);
   }     
  } 
   }
}
int El_monster::show_elemental_DMG(){
   return  elemental_DMG;
}