#include<iostream>
using namespace std;

int maxProfit(int arr[], int be, int en, int yr) {
    if(be > en) return 0;
    int q1 = arr[be] * yr + maxProfit(arr, be + 1, en, yr + 1);
    int q2 = arr[en] * yr + maxProfit(arr, be, en - 1, yr + 1);
    return max(q1, q2);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << maxProfit(arr, 0, n-1, 1);
}
