#include<bits/stdc++.h>
using namespace std;
int partition(int a[], int l, int h){
    int piv = a[h], i = l-1;
    for(int j=l;j<h; j++){
        if(a[j]<=piv){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[h]);
    return(i+1);
}
void qs(int a[], int l, int h){
    if(l<h){
        int pi = partition(a, l, h);
        qs(a, l, pi-1);
        qs(a, pi+1, h);


    }
}
int main(){
    int a[7] =  {8, 7, 6, 1, 0, 9, 2};
    qs(a, 0, 7-1);
    cout<<"after sorting"<<endl;
    for(int i=0;i<7;i++){
        cout<<a[i]<<endl;
    }
}
