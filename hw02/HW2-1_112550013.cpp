#include <bits/stdc++.h>

#define int long long
#define endl '\n'
#define For(z, x, y) for(int z = x; z <= y; z++)
using namespace std;

struct Node{
    int in, w, s;
    vector<int> out;
    Node(): in(0), w(0), s(0){}
} g[1005];

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    queue<int> q;
    cin >> n >> m;

    For(i, 1, m){
        int x, y;
        cin >> x >> y;
        g[x].out.push_back(y);
        g[y].in++;
    }
    For(i, 1, n){
        cin >> g[i].w;
        g[i].s = g[i].w;
        if(g[i].in == 0) q.push(i);
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto i: g[now].out){
            g[i].s = max(g[i].s, g[now].s + g[i].w);
            g[i].in--;
            if(g[i].in == 0) q.push(i);
        }
    }

    int ans = 0;
    For(i, 1, n) ans = max(ans, g[i].s);
    cout << ans << endl;

    return 0;
}