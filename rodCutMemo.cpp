#include <iostream>
#include <cstring>
using namespace std;

int memo[100];

int maxProfit(int arr[], int n) {
    if(n == 0) return 0;
    if(memo[n] != -1) return memo[n];
    int best = 0;
    for(int len=1; len<=n; len++)
        best = max(best, arr[len - 1] + maxProfit(arr, n - len));
    memo[n] = best;
    return best;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    memset(memo, -1, sizeof(memo));
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << maxProfit(arr, n);
}
