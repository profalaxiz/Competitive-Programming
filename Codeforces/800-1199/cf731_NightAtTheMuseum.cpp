#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

// wheel's initial position is a pointer on the letter 'a'.
// find the minimum number of rotations of the wheel required to print the name
// name : zeus 
// a-z : 1 , z-e: 5, e-u: 
// length of the wheel = 26 (alphabet letters)
// rotation from x to y = |x - y| or 26 - |x - y|

void solve() {
    string name;
    cin >> name;
    int n = name.length();
    int rot = 0;
    int c = 'a';
    for (int i = 0; i < n; i++)
    {
        rot += min(abs(name[i] - c), 26 - abs(name[i] - c));
        c = name[i];
    }

    cout << rot << '\n';
    
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