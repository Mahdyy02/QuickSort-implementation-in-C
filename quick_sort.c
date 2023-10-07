#include <stdio.h>

void swap(int *x, int *y);
void quicksort_recursion(int arr[], int low, int high);
void quicksort(int arr[], int size);
int partition(int arr[], int low, int high);

void swap(int *x, int *y){
    int aux = *y;
    *y = *x;
    *x = aux;
}

void quicksort_recursion(int arr[], int low, int high){
    if(low < high){   
        int pivot_index = partition(arr, low, high);
        quicksort_recursion(arr, low, pivot_index-1);
        quicksort_recursion(arr, pivot_index+1, high);
    }   
}

void quicksort(int arr[], int size){
    quicksort_recursion(arr, 0, size-1);
}

int partition(int arr[], int low, int high){

    int pivot_value = arr[high];
    int i = low;

    for(int j = low; j < high; j++){
        if(arr[j] >= pivot_value){
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);

    return i;
}