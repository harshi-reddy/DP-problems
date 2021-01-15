#include<iostream>
#include<algorithm>
using namespace std;
const int inf = (int)1e9;

int reduceNo(int n){
    int dp[10000];
    dp[0] = 0; dp[1] = 0;
    dp[2] = 1; dp[3] = 1;
    
    for(int curNum = 4; curNum <= n; curNum++) {
        int q1 = inf, q2 = inf, q3 = inf;
        if(curNum % 3 == 0) q1 = 1 + dp[curNum/3];
        if(curNum % 2 == 0) q2 = 1 + dp[curNum/2];
        q3 = 1 + dp[curNum-1];
        dp[curNum] = min(q1, min(q2, q3));
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << reduceNo(n);
}
