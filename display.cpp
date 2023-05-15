#include <iostream>
#include <conio.h>
#include <windows.h>
#include "display.h"
using namespace std;
void display::loading(string g){
    system("cls");
    cout<<"Loading "<<g<<"..."<<endl;
    Sleep(100);
    fflush(stdin);
}
void display::welcome(){
  system("cls");
    cout<<"__          __  _   "<<endl;
    Sleep(100);
    cout<<"\\ \\        / / | |"<<endl;
    Sleep(100);
    cout<<" \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___  "<<endl;
    Sleep(100);
    cout<<"  \\ \\/  \\/ / _ \\ |/ __/ _ \\| \'_ ` _ \\ / _ \\"<<endl;
    Sleep(100);
    cout<<"   \\  /\\  /  __/ | (_| (_) | | | | | |  __/"<<endl;
    Sleep(100);
    cout<<"    \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|"<<endl;
    Sleep(100);
}