#include <bits/stdc++.h>
using namespace std;

#define long long
#define endl "\n"

#define IF(cond, t, f) (cond ? t : f)
#define OFILE(finp, fout) freopen(finp, "r", stdin), freopen(fout, "w", stdout)
#define FAST_IO ios_base::sync_with_stdio(false), (void)cin.tie()

#define print(...) print_out(__VA_ARGS__)
#define debug(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)

template <typename T>
void print_out(T t) { cerr << t << endl; }
template <typename T, typename... Args>
void print_out(T t, Args... args) { cerr << t << ' ', print_out(args...); }

void dbg_out(const char *names) { cerr << names << endl; }
template <typename T, typename... Args>
void dbg_out(const char *names, T value, Args... args)
{
    const char *comma = strchr(names, ',');
    if (!comma)
        cerr << names << " = " << value << endl;
    else
        cerr.write(names, comma - names) << " = " << value << " |", dbg_out(comma + 1, args...);
}

const int MOD = 1e9 + 7;
array<array<int, 1000005>, 105> dp;

void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);

    for (auto &elem : coins)
        cin >> elem;

    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int tar = 0; tar <= x; ++tar)
        {
            dp[i][tar] = dp[i - 1][tar];
            if (tar - coins[i - 1] >= 0)
                dp[i][tar] += dp[i][tar - coins[i - 1]];
            dp[i][tar] %= MOD;
        }
    }

    cout << dp[n][x];
}

signed main()
{
    FAST_IO;

    solve();

    return 0;
}
