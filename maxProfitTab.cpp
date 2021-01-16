#include<iostream>
using namespace std;

int maxProfit(int arr[], int n) {
    int dp[1000][1000];
    int yr = n;
    for(int i=0; i<n; i++)
        dp[i][i] = yr * arr[i]; //len = 1
    yr--;
    for(int len = 2; len <= n; len++) {
        int st = 0, en = n - len;
        while(st <= en){
            int endWindow = st + len - 1;
            dp[st][endWindow] = max(
                dp[st + 1][endWindow] + arr[st] * yr,
                dp[st][endWindow - 1] + arr[endWindow] * yr
                );
            st++;
        }
        yr--;
    }
    return dp[0][n-1];
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << maxProfit(arr, n);
}
