#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> problems(n + 1);
    for (int i = 1; i <= n; i++) 
    {
        cin >> problems[i];
    }
    int best = 1, day = 1;

    sort(problems.begin(), problems.end());
    for (int i = 1; i <= n; i++)
    {
        if (problems[i] >= day) 
        {
            best = day;
            day++;
        }
    }

    cout << best;
    
    return 0;
}