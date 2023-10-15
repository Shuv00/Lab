#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* next;
};
struct node *f= NULL, *r=NULL;
void enqueue(int data){
   struct node *ptr=new node();
    ptr->data= data;
    ptr->next=NULL;
    if(f==NULL){
        r=f=ptr;
    }
    else {
        r->next=ptr;
        r=ptr;
    }
}
void print(struct node* n){
    struct node* temp= n;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void dequeue(){
    struct node* ptr= f;
    f=f->next;
    free(ptr);
}
int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(7);
    print(f);
    cout<<endl;
    dequeue();
    print(f);

}
