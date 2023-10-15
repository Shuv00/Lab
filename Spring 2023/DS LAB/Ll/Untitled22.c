#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;
};
void insert(int data, int n) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    int i = 1;
    struct node* p = head;
    ptr->data = data;

    if(n == 1) {
        ptr->next = head;
        head = ptr;
        return;
    }

    while(i != n-1 && p != NULL) {
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;
}
void display(){
    struct node* temp= new node();
    while(temp!=NULL){
        printf("%d->"temp->data);
        temp=temp->next;

    }
}
int main(){

}
