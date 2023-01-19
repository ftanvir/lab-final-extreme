#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int INF = 1e9+10;

vector<pair<int,int>>g[N];
vector<int>dis(N, INF);
vector<int>vis(N, 0);

void dijsktra(int source)
{

    set<pair<int,int>>st; //{weight, node}

    st.insert({0, source});
    dis[source] = 0;

    while(st.size()>0) {
        auto node = *st.begin();
        int v = node.second;
        int dist = node.first;
        st.erase(st.begin());//pop the minimum pair

        if(vis[v]) continue;
        vis[v] = 1;

        for(auto child:g[v]) {
            int child_v = child.first;
            int wt = child.second;

            if(dis[v]+wt < dis[child_v]) {
                dis[child_v] = dis[v]+wt;
                st.insert({dis[child_v], child_v});
            }
        }
    }
}

int main()
{
    int n, e;
    cin>>n>>e;
    while(e--) {
        int u, v, wt;
        cin>>u>>v>>wt;
        g[u].push_back({v, wt});
    }
    int source;
    cin>>source;
    dijsktra(source);

    for(int i=1; i<=n; i++) {
        cout<<i<<" -> "<<dis[i]<<endl;
    }
    return 0;
}