#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[5]= {43, 31, 26, 23, 12};
    int n=5;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
    for(int i=0;i<5;i++){
        cout<<a[i]<<endl;
    }
}

