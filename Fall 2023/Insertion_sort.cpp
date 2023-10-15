#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[5]= {43, 31, 26, 23, 12};
    cout<<"Before Sorting: "<<endl;
    for(int i=0;i<5;i++){
        cout<<a[i]<<endl;
    }
    int key=0, j;
    for(int i=1;i<5;i++ ){
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1]=key;
    }
   cout<<"After Sorting: "<<endl;
    for(int i=0;i<5;i++){
        cout<<a[i]<<endl;
    }
}
