#include<bits/stdc++.h>

#define pl(a) " [" << #a << ": " << (a) << "] "
#define pts(a) " [" << #a << ": { first: " << (a.first) << ", second: " << (a.second) << "}] "

#define all(vi) vi.begin(), vi.end()
#define endl "\n"
#define ll long long

using namespace std;

pair<int, int> n4[4] { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
pair<int, int> n8[8] { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1} };

template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "[" << p.first << ", " << p.second << "]"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) { cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) { cin >> p.first; return cin >> p.second; }

void set_in(string s) {
    if (s.length() > 0) {
        freopen ((s+".in").c_str(), "r", stdin);
        freopen ((s+".out").c_str(), "w", stdout);
    }
}

vector<vector<int>> sat;
vector<int> _left;
vector<int> dp;
vector<vector<int>> adj;
vector<int> current_path;

vector<bool> vis;

void dfs(int u, int person) {
    if (vis[u]) return;
    vis[u] = 1;
    // cerr << pl(u) << endl;
    for (int v : adj[u]) {
        dfs(v, person);
        dp[u] = max(dp[u], dp[v]);
    }
    if (_left[u] > 0) {
        dp[u] += sat[person][u];
    }
}

void get_path(int u) {
    if (_left[u] > 0) {
        current_path.push_back(u);
        _left[u] -= 1;
    }
    if (adj[u].size() == 0) return;

    int best = adj[u][0];

    for (int v : adj[u]) {
        if (dp[best] < dp[v]) best = v;
    }

    get_path(best);
}

void solve() {
    int n, m; cin >> n >> m;
    sat = vector<vector<int>>(n, vector<int>(m)); for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> sat[i][j];
    vector<tuple<int, int, int>> events(m);
    _left = vector<int>(m, 0);
    dp = vector<int>(m, 0);
    vis = vector<bool>(m, 0);

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        events[i] = {a, b, c};
        _left[i] = c;
    }

    auto intersects = [&](int a, int b) -> bool {
        if (get<0>(events[a]) > get<0>(events[b])) {
            swap(a, b);
        }

        return get<1>(events[a]) > get<0>(events[b]);
    };

    
}

int main() {
#ifndef DEBUG
    set_in("");
#endif
#ifdef DEBUG
    auto clock_start = chrono::high_resolution_clock::now();
    cout << endl;
#endif
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    // Clock
#ifdef DEBUG
    auto clock_end = chrono::high_resolution_clock::now();
    cout << endl;
    chrono::duration<double> elapsed = clock_end - clock_start;
    cout << "Execution time: " << elapsed.count() << "s" << endl;
#endif
    return 0;
}
