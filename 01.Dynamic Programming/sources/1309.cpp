#include <bits/stdc++.h>

using namespace std;

int n;
int dp[100001];

int go(int i)
{
    if (i == 0) return 1;
    if (i == 1) return 3;
    if (dp[i] != 0) return dp[i];
    dp[i] = (2 * go(i-1) + go(i-2)) % 9901;
    return dp[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;
    cout << go(n);
}
