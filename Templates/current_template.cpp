#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <numeric>
#include <climits>
#include <iomanip>
#include <chrono>

using namespace std;

// Types & Containers
using ll = long long;
using ld = long double;
using str = string;
using vi = vector<int>;
using pi = pair<int,int>;
using vpi = vector<pi>;

// Macros
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define del(x, i) erase(begin(x)+i)
#define rem(x,i) erase(begin(x), begin(x)+i)
#define mp make_pair

// Constants
const int MAX_N = 1e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ld EPS = 1e-9;

// Permutation
#define each_perm(x) sort(all(x)); do
#define end_perm(x) while(next_permutation(all(x))) 

void setIO(string name = "") {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // setIO("");

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    auto start_time = chrono::high_resolution_clock::now();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    auto end_time = chrono::high_resolution_clock::now();
    #ifndef ONLINE_JUDGE
        chrono::duration<double, milli> duration = end_time - start_time;
        cerr << "\n--- Execution Time: " << fixed << setprecision(2) << duration.count() << " ms ---" << endl;
    #endif
    return 0;
}
