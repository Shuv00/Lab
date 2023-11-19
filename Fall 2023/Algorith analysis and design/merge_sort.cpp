#include<bits/stdc++.h>
using namespace std;

void display(int *array, int size) {
    for(int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void merge(int a[], int l, int m, int h) {
    int n1 = m - l + 1, n2 = h - m;
    int larr[n1], rarr[n2];

    for(int i = 0; i < n1; i++) {
        larr[i] = a[l + i];
    }
    for(int j = 0; j < n2; j++) {
        rarr[j] = a[m + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if(larr[i] <= rarr[j]) {
            a[k] = larr[i];
            i++;
        } else {
            a[k] = rarr[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        a[k] = larr[i];
        i++;
        k++;
    }

    while(j < n2) {
        a[k] = rarr[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int h) {
    if(l < h) {
        int m = l + (h - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, h);
        merge(a, l, m, h);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Array before Sorting: ";
    display(arr, n);
    mergeSort(arr, 0, n - 1);
    cout << "Array after Sorting: ";
    display(arr, n);

    return 0;
}
