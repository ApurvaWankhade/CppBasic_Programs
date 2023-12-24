#include <iostream>
#include <algorithm>
using namespace std;

int knapsack_game(int weights[], int values[], int n, int capacity) {
    // Create an array to store the maximum value for each subproblem
    int dp[capacity + 1] = {0};
    
    for (int i = 0; i < n; i++) {
        for (int w = capacity; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    
    return dp[capacity];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    
    int weights[n];
    int values[n];
    
    cout << "Enter the weight and value of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }
    
    int knapsack_capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> knapsack_capacity;
    
    int max_value = knapsack_game(weights, values, n, knapsack_capacity);
    
    cout << "Max Value: " << max_value << endl;
    
    return 0;
}

