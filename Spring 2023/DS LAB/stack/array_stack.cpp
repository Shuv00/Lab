#include<bits/stdc++.h>
using namespace std;
int top=-1,size=5, a[5];

void display(){
    if(top==-1){
        cout<<"stack empty"<<endl;
        return;
    }
   for(int i=0;i<=top;i++){
    cout<<a[i]<<" ";
   }
   cout<<endl;

}
void insert(int data){

    a[++top]=data;
}
void pop(){
 top--;
 //display();
}
int main(){
    insert(10);
    insert(11);
    insert(12);
    display();
    pop();
    cout<<"after dlt"<<endl;
    display();

}

