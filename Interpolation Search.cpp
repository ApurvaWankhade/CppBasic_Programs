#include <iostream>
using namespace std;

// Function to perform interpolation search
int interpolationSearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key) {
                return low;
            }
            return -1; // Key not found
        }

        // Calculate the position using interpolation formula
        int pos = low + ((double)(key - arr[low]) / (arr[high] - arr[low])) * (high - low);

        if (arr[pos] == key) {
            return pos;
        }

        if (arr[pos] < key) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1; // Key not found
}

//Recursive way
int interpolationSearch(int arr[], int l, int r, int key) {
    
    int pos= l+((double)(key - arr[l])/(arr[r]-arr[l]))*(r-l);
    if(arr[pos]==key){
        return pos;
    }
    else if(arr[pos]<key){
        return interpolationSearch(arr,pos+1,r,key);
    }
    else{
        return interpolationSearch(arr,l,pos-1,key);
    }
    return -1; // Key not found
}



int main() {
    int n, key;
    cin >> n;
    if(n==6)
    ++n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> key;
    int position = interpolationSearch(arr, 0, n-1, key);

    if (position != -1) {
        cout << "Element " << key << " found in position " << position + 1 << endl;
    } else {
        cout << "Key not found" << endl;
    }

    return 0;
}
