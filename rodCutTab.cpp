#include <iostream>
using namespace std;

int maxProfit(int arr[], int n) {
    int dp[100]={};
    for(int len = 1; len <= n; len++){
        int best = 0;
        for(int cut = 1; cut <= len; cut++)
            best = max(best, arr[cut - 1] + dp[len - cut]);
        dp[len] = best;
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << maxProfit(arr, n);
}
