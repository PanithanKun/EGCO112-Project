#include "NODE.h"
class Queue{
   NODE* HeadPtr;
   NODE* TailPtr;
   int size;
   public:
   Queue();
   ~Queue();
   void ENQueue(Queue*,int,int);
   int DEQueue();
};