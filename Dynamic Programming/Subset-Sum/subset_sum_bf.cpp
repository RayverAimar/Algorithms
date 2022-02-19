#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define FORN(i,m,n) for(ll i=(m); i<int(n); i++)
typedef long long ll;

bool subset_sum(vector<ll> n, ll target) {
    ll max_sum{ 0 }, min_sum{ 0 };
    for (ll a : n) a < 0 ? min_sum += a : max_sum += a;
    if (target < min_sum || target > max_sum) return 0;
    FORN(bm, 1, 16) {
        ll ans{ target };
        FORN(i, 0, 4) if (bm & 1 << i) ans -= n[i];
        if (ans == 0) return 1;
    }
    return 0;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        vector<ll> n; ll target;
        FORN(i, 0, 4) {
            ll a;
            cin >> a;
            n.push_back(a);
        }
        cin >> target;
        cout << (subset_sum(n, 0) ? "YES" : "NO") << "\n";
    }
}