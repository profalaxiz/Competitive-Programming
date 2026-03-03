#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

// string s: i-th character = i-th second = i-th strip
// wastes exactly a_i calories on touching the i-th strip
// example: a_i: 1 2 3 4    , s: 123214
// sec  : 1  2  3  4  5  6
// strip: 1  2  3  2  1  4
// cal  : 1+ 2+ 3+ 2+ 1+ 4  ==> total calories = 13
// hashmap: count of strips
// total calories = sum(a1 * hashmap['1'], a2 * hashmap['2'], ...)


void solve() {
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    string s;
    cin >> s;
    int seconds = s.length();
    unordered_map<char, int> hashmap;
    
    for (int i = 0; i < seconds; i++)
    {
        hashmap[s[i]] += 1;
    }

    ll cal = a1 * hashmap['1'] + a2 * hashmap['2'] + a3 * hashmap['3'] + a4 * hashmap['4'];
    cout << cal << '\n';
    
    return;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}