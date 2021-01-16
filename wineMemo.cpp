#include <iostream>
#include <cstring>
using namespace std;

int memo[1000][1000];

int maxProfit(int arr[], int be, int en, int yr) {
    if(be > en) return 0;
    if(memo[be][en] != -1) return memo[be][en];
    int q1 = arr[be] * yr + maxProfit(arr, be + 1, en, yr + 1);
    int q2 = arr[en] * yr + maxProfit(arr, be, en - 1, yr + 1);
    memo[be][en] = max(q1, q2);
    return memo[be][en];
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    memset(memo, -1, sizeof(memo));
    cout << maxProfit(arr, 0, n-1, 1);
}
