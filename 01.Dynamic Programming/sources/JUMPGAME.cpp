#include <bits/stdc++.h>

using namespace std;

int a[101][101];
// dp[i][j] = (i,j) 에서 (n,n) 까지 가는 경로의 수
// bool형으로 하면 이미 계산 된 경우인지 아닌지를 알수 없기 때문에 int형으로 해줍니다.
int dp[101][101];
int n;

int go(int i, int j)
{
    if (i > n || j > n) return 0;
    if (i == n && j == n) return 1;
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = go(i+a[i][j], j) + go(i, j+a[i][j]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(dp, -1, sizeof(dp));
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cin >> a[i][j];
            }
        }
        if (go(1, 1)) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
}
