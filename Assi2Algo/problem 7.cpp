#include <iostream>

using namespace std;


int partition(int arr[], int l, int r);

// function returns K'th largest element in arr[l..r]
// using QuickSort based method.
int kthLargest(int arr[], int l, int r, int K)
{
    // If k is smaller than number of elements in array
    if (K > 0 && K <= r - l + 1) {
        // Partition the array around last element and get
        // position of pivot element in sorted array
        int pos = partition(arr, l, r);
        // If position is same as k
        if (pos - l == K - 1)
            return arr[pos];
        // If position is more, recursive
        if (pos - l > K - 1) // for left sub array
            return kthLargest(arr, l, pos - 1, K);

        // Else recursive for right sub array
        return kthLargest(arr, pos + 1, r,K - pos + l - 1);
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;//x: pivot
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[r]);
    return i;
}


int main()
{
    int arr[] = { 14, 5, 6, 12, 8 ,10,25};
    int N = sizeof(arr) / sizeof(arr[0]), K = 3;
    K=N-(K-1);
    cout << "K'th Largest element is " << kthLargest(arr, 0, N - 1, K);



    return 0;
}
