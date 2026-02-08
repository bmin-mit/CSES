#include <bits/stdc++.h>
using namespace std;

#define int long long
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

void solve()
{
    int graph_size, edge_count;
    cin >> graph_size >> edge_count;

    map<int, vector<pair<int, int>>> edges;

    for (int i = 0; i < edge_count; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
    }

    array<array<int, 2>, 100005> dist;
    for (auto &elem : dist)
        elem.fill(1e15);

    bitset<100005> mark;
    dist[1][0] = 0;
    dist[1][1] = 0;

    priority_queue<
        tuple<int, int, bool>, vector<tuple<int, int, bool>>, greater<tuple<int, int, bool>>>
        pq; // {dist, vertex, used_discount}
    pq.push({0, 1, false});

    while (pq.size())
    {
        int curr_dist = get<0>(pq.top());
        int u = get<1>(pq.top());
        int used = get<2>(pq.top());
        pq.pop();

        if (dist[u][used] != curr_dist)
            continue;
        if (u == graph_size)
            break;

        for (auto [v, w] : edges[u])
        {

            if (!used)
            {
                int next_dist = curr_dist + w / 2;
                if (next_dist < dist[v][1])
                {
                    dist[v][1] = next_dist;
                    pq.push({next_dist, v, true});
                }
            }

            int next_dist = curr_dist + w;
            if (next_dist < dist[v][used])
            {
                dist[v][used] = next_dist;
                pq.push({next_dist, v, used});
            }
        }
    }

    cout << dist[graph_size][1];
}

signed main()
{
    FAST_IO;

    solve();

    return 0;
}
