#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void moveDisk(int num, vector<vi>& moves, int source, int dest, int aux)
{
    if (num == 1)
    {
        moves.push_back({source, dest});
        return;
    }

    moveDisk(num - 1, moves, source, aux, dest);
    moves.push_back({source, dest});
    moveDisk(num - 1, moves, aux, dest, source);
}


void solve() {
    int n;
    cin >> n;
    vector<vi> moves;
    int source = 1, dest = 3, aux = 2;
    moveDisk(n, moves, source, dest, aux);
    
    cout << moves.size() << '\n';

    for (auto move: moves)
    {
        cout << move[0] << " " << move[1] << '\n';
    }
    
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