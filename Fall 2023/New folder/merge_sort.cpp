#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int left, int mid, int right){
        int i, j, k;
        int n1= mid- left+1, n2= right-mid;
        int larr[n1], rarr[n2];
        for(int i=0;i<n1;i++){
            larr[i]=arr[left+i];
        }
        for(int i=0;i<n2;i++){
            rarr[i]=arr[mid+1+i];
        }
        i=0 , j=0, k=left;
        while(i<n1 && j<n2){
            if(larr[i]<= rarr[i]){
                arr[k]=larr[i++];
            }
            else {
                arr[k]= rarr[j++];
            }
            k++;
        }
        while(i<n1){
            arr[k++] = larr[i++];
        }
        while(i<n1){
            arr[k++] = rarr[j++];
        }





}
void mergesort(int arr[], int l, int r){
        int m;
        while(l<r){
                m=l+(r-l)/2;
            mergesort(arr, l ,m);
            mergesort(arr, m+1, r);
            merge(arr, l ,m ,r);
        }
}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];     //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   for(int i=0;i<n;i++) cout<<arr[i]<<endl;
   mergesort(arr, 0, n-1);     //(n-1) for last index
   cout << "Array after Sorting: ";
   for(int i=0;i<n;i++) cout<<arr[i]<<endl;
}
