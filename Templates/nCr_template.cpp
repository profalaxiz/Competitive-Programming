#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 200005; // adjust this based on the problem's N

long long fact[MAXN];
long long invFact[MAXN];

// Binary Exponentiation to calculate (base^exp) % MOD in O(log exp)
long long binpow(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Precompute factorials and inverse factorials in O(N)
void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    
    // Building inverse factorials using Fermat's Little Theorem
    // Only need to do the expensive power operation once for the largest number
    invFact[MAXN - 1] = binpow(fact[MAXN - 1], MOD - 2);
    
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

// Get nCr in O(1) time
long long nCr(int n, int k) {
    if (k < 0 || k > n) return 0;
    long long num = fact[n];
    long long den = (invFact[k] * invFact[n - k]) % MOD;
    return (num * den) % MOD;
}

int main()
{
    precompute();       // must call this once before solving!
    cout << nCr(150, 52) << '\n';
}