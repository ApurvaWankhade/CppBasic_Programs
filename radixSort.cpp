#include <iostream>

using namespace std;

// to get the maximum value in the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// A function to do counting sort of the elements based on significant places (exp).
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // Count the number of occurrences of each digit in the current place value.
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Calculate the cumulative count.
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array.
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the sorted elements back to the original array.
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort function to sort an array of integers.
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Perform counting sort for every digit, starting from the least significant to the most significant.
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    radixSort(arr, n);

    // Print the sorted array.
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
