#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1000005];
int b[1000005];
long long sum[1000005];
long long sum2[1000005];
long long ans = INT_MAX;

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] * a[i];
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
        sum2[i] = sum2[i - 1] + b[i];
    }

    for (int i = 0; i <= n - m; i++) {
        ans = min(ans, (m * (sum2[i + m] - sum2[i]) - (sum[i + m] - sum[i]) * (sum[i + m] - sum[i])));
    }

    cout << ans << endl;

    return 0;
}