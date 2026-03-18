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

// X, Y      (0 <= X, Y < 1e250)
// return the product of X and Y

// (a * b) % n = ((a % n) * (b % n)) % n    

string x, y;

/*
      1 2 
      1 2
     -----
      2 4
    1 2 .
   -------
    1 4 4
*/

string multiplyStrings(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    
    int n1 = num1.size();
    int n2 = num2.size();
    // The maximum possible length of the product is n1 + n2
    vector<int> res(n1 + n2, 0);
    
    // Multiply digit by digit from right to left
    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + res[i + j + 1]; // Add to whatever is already at this position
            
            res[i + j + 1] = sum % 10;      // Keep the last digit
            res[i + j] += sum / 10;         // Carry over to the next position left
        }
    }
    
    // Convert the result array back into a string, skipping any leading zeros
    string result = "";
    for (int digit : res) {
        if (!(result.empty() && digit == 0)) {
            result += to_string(digit);
        }
    }
    
    return result.empty() ? "0" : result;
}


void solve() {
    cout << multiplyStrings(x, y) << '\n';
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

    // int t = 1;
    // cin >> t;
    while (cin >> x >> y) {
        solve();
    }

    auto end_time = chrono::high_resolution_clock::now();
    #ifndef ONLINE_JUDGE
        chrono::duration<double, milli> duration = end_time - start_time;
        cerr << "\n--- Execution Time: " << fixed << setprecision(2) << duration.count() << " ms ---" << endl;
    #endif
    return 0;
}