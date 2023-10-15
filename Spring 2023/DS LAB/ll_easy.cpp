#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
void insert(int data){
    struct node* newnode=new node();
    newnode->data=data;
    newnode->next=head;
    head=newnode;
}
int main(){
    insert(4);
    insert(6);
    while(head!=NULL){
        cout<<head->data<<endl;
        head=head->next;
    }
}

