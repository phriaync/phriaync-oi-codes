#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
const long long BASE = 11011009;
const long long HASH_RMODS[] = {2955124349, 3926273941, 2262704629, 2210897573, 2633841323, 2158963633, 2637981179, 2836216651, 2735674427, 3526243561, 3497826133, 3599307451, 2565242107, 2791169273, 2669695153, 2396639143};

long long hash_mods[3];
inline void hash_init() {
	mt19937 rd(time(0));
	for (int i = 0; i < 3; i++)
		hash_mods[i] = HASH_RMODS[rd() % 16];
}
struct hc {
	long long v1;
	long long v2;
	long long v3;
}hcs[MAXN];
bool operator < (const hc& h1, const hc& h2) {
	if (h1.v1 != h2.v1) return h1.v1 < h2.v1;
	if (h1.v2 != h2.v2) return h1.v2 < h2.v2;
	return h1.v3 < h2.v3;
}
bool operator == (const hc& h1, const hc& h2) {
	return h1.v1 == h2.v1 && h1.v2 == h2.v2 && h1.v3 == h2.v3;
}
bool operator != (const hc& h1, const hc& h2) {
	return !(h1 == h2);
}
inline hc hashing(const string& s) {
	int l = s.size();
	long long b1 = 1, b2 = 1, b3 = 1, v1 = 0, v2 = 0, v3 = 0;
	for (int i = 0; i < l; i++) {
		v1 = (v1 + s[i] * b1) % hash_mods[0];
		b1 = b1 * BASE % hash_mods[0];
		v2 = (v2 + s[i] * b2) % hash_mods[1];
		b2 = b2 * BASE % hash_mods[1];
		v3 = (v3 + s[i] * b3) % hash_mods[2];
		b3 = b3 * BASE % hash_mods[2];
	}
	return {v1, v2, v3};
}

int n, ans;
string s;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
    hash_init();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		hcs[i] = hashing(s);
	}
	hcs[0] = {-1, -1, -1};
	sort(hcs + 1, hcs + n + 1);
	for (int i = 1; i <= n; i++)
		if (hcs[i] != hcs[i - 1]) ans++;
	cout << ans;
	
	
	return 0;
}