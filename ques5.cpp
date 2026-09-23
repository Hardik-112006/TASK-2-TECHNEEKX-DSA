#include <bits/stdc++.h>
using namespace std;

int merge(vector<int>& arr, int start, int mid, int end) {

    int count = 0;
    int i = start;
    int j = mid + 1;
    int index = 0;

    vector<int> temp(end - start + 1);

    while (i <= mid && j <= end) {

        if (arr[i] <= arr[j]) {
            temp[index] = arr[i];
            i++;
        }
        else {
            temp[index] = arr[j];
            count += (mid - i + 1);
            j++;
        }

        index++;
    }

    // Remaining elements of left half
    while (i <= mid) {
        temp[index] = arr[i];
        i++;
        index++;
    }

    // Remaining elements of right half
    while (j <= end) {
        temp[index] = arr[j];
        j++;
        index++;
    }

    // Copy sorted elements back
    for (int k = 0; k < index; k++) {
        arr[start + k] = temp[k];
    }

    return count;
}

int mergeSort(vector<int>& arr, int start, int end) {

    if (start >= end) {
        return 0;
    }

    int mid = start + (end - start) / 2;

    int leftCount = mergeSort(arr, start, mid);
    int rightCount = mergeSort(arr, mid + 1, end);

    int mergeCount = merge(arr, start, mid, end);

    return leftCount + rightCount + mergeCount;
}

int inversionCount(vector<int>& arr) {
    return mergeSort(arr, 0, arr.size() - 1);
}

int main() {

    vector<int> arr = {2, 4, 1, 3, 5};

    int answer = inversionCount(arr);

    cout << "Inversion Count: " << answer << endl;

    return 0;
}