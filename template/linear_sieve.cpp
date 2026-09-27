#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1E8 + 5;

int n, q;

int prm[MAXN], prmc;
bool isnp[MAXN];
void sieve(int n) {
    isnp[1] = true;
    for (int i = 2; i <= n; i++) {
        if (!isnp[i]) prm[++prmc] = i;
        for (int j = 1; j <= prmc && i * prm[j] <= n; j++) {
            isnp[i * prm[j]] = true;
            if (i % prm[j] == 0) break;
        }
    }
}

int main() {
    sieve(1E8);
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> q;
    for (int i = 1, k; i <= q; i++) {
        cin >> k;
        cout << prm[k] << '\n';
    }

    return 0;
}