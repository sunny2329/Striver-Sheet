#include <bits/stdc++.h>
using namespace std;

// Selection Sort algo 

void selectionSort(int arr[],int size){
    for(int i = 0;i<size;i++){
        int min_idx = i;
        for(int j = i+1;j<size;j++){
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[i],arr[min_idx]);
    }
}

// bubble Sort algo 

void bubbleSort(int arr[],int size){
    for(int i = 0;i<size-1;i++){
        for(int j = 0;j<size-i-1;j++){
            if(arr[j] > arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}

// insertion sort algo 

void insertionSort(int arr[],int size){
    for(int i = 1;i<size;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}



int main()
{

}