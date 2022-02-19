#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define tt ll testcase; cin>>testcase; while(testcase--)
#define FORN(i,m,n) for(ll i=(m); i<int(n); i++)
#define p_b(x) push_back(x)
typedef long long ll;

int n;

bool subset_sum(vector<ll> arr, ll sum) {
    ll max_sum{ 0 }, min_sum{ 0 };
    for (ll a : arr) a < 0 ? min_sum += a : max_sum += a;
    if (sum < min_sum || sum > max_sum) return 0;
    FORN(bm, 1, 1<<n) {
        ll ans{ sum };
        FORN(i, 0, 4) if (bm & 1 << i) ans -= arr[i];
        if (!ans) return 1;
    }
    return 0;
}

int main() {
    tt{
        vector<ll> arr; ll sum;
        cin>>n;
        FORN(i, 0, n) {
            ll a;
            cin >> a;
            arr.p_b(a);
        }
        cin >> sum;
        cout << (subset_sum(arr, sum) ? "YES" : "NO") << "\n";
    }
}