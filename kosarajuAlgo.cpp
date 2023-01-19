#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int>graph[N];
vector<int>transpose[N];
bool vis[N];
stack<int>st;

void dfs(int source) {
    vis[source] = 1;
    
    for(auto it: graph[source]) {
        if(!vis[it]) {
            dfs(it);
        }
    }

    
    st.push(source);
}

void kosaraju(int node) {
    vis[node] = 1;
    cout<<node<<" ";
    for(auto it:transpose[node]) {
        if(!vis[it]) {
            kosaraju(it);
        }
    }
}

int main()
{
    int n, e;
    cin>>n>>e;
    while(e--) {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        transpose[v].push_back(u);
    }
    
    int source;
    cin>>source;
    dfs(source);
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    //printing the stack situation according to the finishing time
    // cout<<"Stack update below: "<<endl;
    // while(!st.empty()) {
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

    //making visited array default to 'false' for another dfs traversal.
    memset(vis, false, sizeof(vis));

    int countofscc = 0;
    while(!st.empty()) {
        int front = st.top();
        // cout<<front<<" ";
        st.pop();
        if(!vis[front]) {
            cout<<"scc "<<countofscc<<": ";
            kosaraju(front);
            countofscc++;
            cout<<endl;
        }
    }
    
    cout<<"Total Number of Strongly Connected Component is: "<<countofscc<<endl;

}