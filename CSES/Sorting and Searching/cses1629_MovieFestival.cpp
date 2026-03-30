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
using str = string;
using vi = vector<int>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using si = set<int>;

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
const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define each_perm(x) sort(all(x)); do
#define end_perm(x) while(next_permutation(all(x))) 

// Loops
#define Trav(a,x) for (auto& a: x)
#define For(i,a,b) for (int i = (a); i < (b); ++i)

void setIO(string name = "") {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

void solve() {
    int n;
    cin >> n;
    int minT = INT_MAX, maxT = INT_MIN;
    vpi moviesT;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        moviesT.push_back({b, a});
    }
    sor(moviesT);
    
    int curr_end = 0;
    int cnt = 0;

    for (auto movie: moviesT)
    {
        if (movie.second >= curr_end) 
        {
            cnt++;
            curr_end = movie.first;
        }
    }
    
    cout << cnt << '\n';
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