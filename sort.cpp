#include<iostream>
using namespace std;

int* popBubble(int* arr, int size) {

    if (size <= 1) {
        return arr;
    }

    int i = 0;
    int j = size-1;
    int temp = 0;

    while (j > 0) {
        while (i < j) {
            if (arr[i] > arr[i+1]) {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
            i++;
        }
        i = 0;
        j--;
    }
    return arr;
}


int main() {
    int arr[] = {4,6,3,8,5,2};
    int size = sizeof(arr)/sizeof(arr[0]);

    popBubble(arr, size);

    for (int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}