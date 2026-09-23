#include <iostream>
using namespace std;

int partition(int arr[],int start,int end){
    int positionofpivot = start;
    for(int i=start;i<=end;i++){
        if(arr[i] <= arr[end]){
            swap(arr[i],arr[positionofpivot]);
            positionofpivot++;
        }
    }
    return positionofpivot - 1;
}



void quicksort(int arr[],int start,int end){
    if(start>= end){
        return;
    }

    int pivot = partition(arr,start,end);

    quicksort(arr,start,pivot-1);
    quicksort(arr,pivot+1,end);
}




int main(){
    int arr[]={6,4,2,8,13,7,11,9,3,6};
    quicksort(arr,0,9);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}