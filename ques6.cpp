#include <iostream>
using namespace std;

int main(){
    int i,j;
    int arr[100];
    int size;
    bool swapped;
    int count = 0;

     cout << "Enter the number of elements in the array: ";
     cin >> size;

    cout << "Enter " << size << " elements in the array: ";
    for(i=0;i<size;i++){
        cin >> arr[i];
    }

    for(i=0;i<size-1;i++){
        swapped = false;
        for(j=0;j<size-i-1;j++){
            if(arr[j] < arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
                count++;
            }
        }
        if(!swapped){
            break;
        }
    }

    cout << "Sorted array: ";
    for(i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Number of swaps: " << count << endl;
}