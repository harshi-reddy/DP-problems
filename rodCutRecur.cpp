#include <iostream>
using namespace std;

int maxProfit(int arr[], int n) {
    if(n == 0) return 0;
    int best = 0;
    for(int len=1; len<=n; len++)
        best = max(best, arr[len - 1] + maxProfit(arr, n - len));
    return best;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << maxProfit(arr, n);
}
