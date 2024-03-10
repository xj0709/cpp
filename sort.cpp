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

void quickSort(int* arr, int left, int right) {
    if (left >= right) {
        return;
    }

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

    quickSort(arr, left, i-1);
    quickSort(arr, i+1, right);

    return;
}

int binarySearch(int arr[], int size, int value) {
    int low = 0;
    int high = size - 1;

    if (low >= high) {
        if (arr[low] != value) {
            return -1;
        }
        else {
            return 0;
        }
    }
    int mid = 0;
    while (low <= high) {
        mid = (low+high)/2;

        if (value < arr[mid]) {
            high = mid - 1;
        }
        else if (value > arr[mid]) {
            low = mid + 1;
        }
        else {
            return mid;
        }
    }

    return -1;

}

void testSearch(int arr[], int size) {
    int target = 3;

    int index = binarySearch(arr, size, target);
    if (-1 == index) {
        cout<<target<<" is not found"<<endl;
    }
    else {
        cout<<target<<" is the: "<<index+1<<endl;
    }

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
    cout<<endl;
    
    // testSearch(arr, size);
    
    return 0;
}