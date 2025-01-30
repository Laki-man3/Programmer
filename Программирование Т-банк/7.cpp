#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 998244353;

long long FP(long long base, long long exp, long long mod) 
{
    long long res = 1;
    while (exp > 0) 
    {
        if (exp % 2 == 1) 
        {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() 
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) 
    {
        cin >> a[i];
    }

    vector<long long> sums;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = i + 1; j < n; ++j) 
        {
            sums.push_back((a[i] + a[j]) % MOD);
        }
    }

    for (int p = 1; p <= k; ++p) 
    {
        long long res = 0;
        for (long long sum : sums) 
        {
            res = (res + FP(sum, p, MOD)) % MOD;
        }
        cout << res << endl;
    }

    return 0;
}
