#include<stdio.h>
#include<stdbool.h>
#define capacity 5
int  q[capacity];
int front =0 , rare = -1, totalitem=0;

bool isempty(){
    if(totalitem==0) return true;
    else return false ;
}
void enqueue(int item){
    //if(isfull){
       // printf("the queue is full");
       // return;
    //}
    rare= (rare  +1)%capacity;//circluer queue
    q[rare]= item;
    totalitem++;
}
void dequeue( ){
    q[front]=-1;
     front= front+1;

}
void print(){
    printf("\n");
    for(int i=front;i<totalitem;i++){
        printf("%d ", q[i]);
    }
}
 int main(){
    enqueue(10);
    enqueue(20);
    enqueue(40);
    print();
    dequeue();
    print();
 }
