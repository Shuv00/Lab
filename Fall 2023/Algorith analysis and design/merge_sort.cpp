#include<bits/stdc++.h>
using namespace std;
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void merge(int a[], int l , int m , int h){
    int n1= m-l+1, n2 = h-m;
    int larr[n1], rarr[n2];
    for(int i=0;i<n1;i++){
        larr[i]=a[l+i];
    }
    for(int i=0;i<n2;i++){
        larr[i]=a[m+1+i];
    }
int    i=0, j=0 , k=1;
    while(i<n1 && j <n2){
        if(larr[i]<=rarr[j]){
            a[k]=larr[i];
            i++;
        }
        else {
            a[k]=larr[j];
        }
        k++;
    }
    while(i<n1){
        a[k]=a[i], i++, k++;
    }
    while(j<n2){
        a[k]=a[j], j++, k++;
    }


}
void mergesort(int a[], int l , int h){
    int m;
    if(l<h){
        m = l+(h-l)/2;
        mergesort(a, l , m);
        mergesort(a, m+1, h);
        merge(a, l , m , h);
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
   display(arr, n);
   mergesort(arr, 0, n-1);     //(n-1) for last index
   cout << "Array after Sorting: ";
   display(arr, n);
}
