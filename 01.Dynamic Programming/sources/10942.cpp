#include <bits/stdc++.h>

using namespace std;

int a[2001];
int d[2001][2001];

bool go(int i, int j) {
    if (i == j) return true;
    if (j - i == 1) {
        return a[i] == a[j];
    }
    if (d[i][j] != 0) return d[i][j] == 1;
    if (a[i] != a[j]) return false;
    else {
        bool temp = true;
        temp = temp && go(i+1, j-1);
        if (temp) d[i][j] = 1;
        else d[i][j] = -1;
        return temp;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    while (m--) {
        int s, e;
        cin >> s >> e;
        cout << go(s, e) << '\n';
    }
}
