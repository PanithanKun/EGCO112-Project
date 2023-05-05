#include<iostream>
using namespace std;
class NODE {
       int E; //Elemental type
       int atk; // monster Attack DMG
       int order;
       int hp; // monster HP
       string Name; // monster name
       //==============================
        NODE *nextPtr;// next pointer
        NODE *pPtr;// Previous pointer
public:
      NODE(int,int,int,string="Unknown");
      ~NODE();
      virtual void Show_NODE();// temp show
      void Delete_NODE();//delete
      NODE* move_next();//nextptr
      NODE* move_back();//previousptr
      void set_next(NODE*); //set nextptr
      void set_back(NODE*); //set backptr
      string show_name();//show name
};
typedef NODE* NodePtr;