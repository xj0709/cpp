#include<iostream>
using namespace std;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int* arr, int size) {

    if (size <= 1) {
        return;
    }

    int i = 0;
    int j = size-1;
    int temp = 0;

    while (j > 0) {
        while (i < j) {
            if (arr[i] > arr[i+1]) {
                swap(&arr[i], &arr[i+1]);
            }
            i++;
        }
        i = 0;
        j--;
    }
    return;
}

void insertionSort(int* arr, int size) {

    if (size <= 1) {
        return;
    }

    int index = 1;
    int loop = 0;
    int key = 0;

    while (index < size) {
        key = arr[index];
        loop = index-1;
        while (loop >= 0 && key < arr[loop]) {
            arr[loop+1] = arr[loop];
            loop--;
        }
        arr[loop+1] = key;
        index++;
    }
    return;
}

int partition (int* arr, int left, int right) {
    int pivot = arr[left];
    int temp = 0;

    int i = left;
    int j = right;

    while (i < j) {

        while (i < j && arr[j] >= pivot) {
            j--;
        }

        while (i < j && arr[i] <= pivot) {
            i++;
        }

        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }

    arr[left] = arr[i];
    arr[i] = pivot;

    return i;
}

void quickSort(int* arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int p = partition(arr, left, right);

    quickSort(arr, left, p-1);
    quickSort(arr, p+1, right);

    return;
}


int main() {
    int arr[] = {15, 6, 3, 8, 5, 15, 11, 18, 10, 7};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"before: ";
    for (int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // bubbleSort(arr, size);
    // insertionSort(arr, size);
    quickSort(arr, 0, size-1);

    cout<<"after: ";
    for (int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}