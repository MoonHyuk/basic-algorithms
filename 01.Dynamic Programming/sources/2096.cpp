#include <bits/stdc++.h>

using namespace std;

int n;
int dp[3];
int dp2[3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;
    while (n--) {
        int a, b, c, t1, t2, t3, s1, s2, s3;
        cin >> a >> b >> c;
        t1 = max(dp[0], dp[1]) + a;
        t2 = max(max(dp[0], dp[1]), dp[2]) + b;
        t3 = max(dp[1], dp[2]) + c;
        dp[0] = t1; dp[1] = t2; dp[2] = t3;
        s1 = min(dp2[0], dp2[1]) + a;
        s2 = min(min(dp2[0], dp2[1]), dp2[2]) + b;
        s3 = min(dp2[1], dp2[2]) + c;
        dp2[0] = s1; dp2[1] = s2; dp2[2] = s3;
    }
    cout << max(max(dp[0], dp[1]), dp[2]) << ' ';
    cout << min(min(dp2[0], dp2[1]), dp2[2]);
}
