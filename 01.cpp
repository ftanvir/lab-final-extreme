#include <iostream>
#include <vector>
using namespace std;
#define mx 1000
int price[mx],weight[mx],dp[mx][mx];
vector <int> sol;
int solve(int N,int W)
{
    for(int i=0;i<=N;i++)
    {
        for(int w=0;w<=W;w++)
        {
            if(i==0||w==0) dp[i][w]=0;
            else if(weight[i]<=w) dp[i][w] = max (price[i]+dp[i-1][w-weight[i]],dp[i-1][w]);
            else dp[i][w]=dp[i-1][w];
        }
    }
    return dp[N][W];
}

int main()
{
    int N,W; // N is the number of items and W is maximum weight
    cin>>N>>W;
    for(int i=1;i<=N;i++) cin>>price[i];
    for(int i=1; i<=N; i++) cin>>weight[i];
    
    cout<<solve(N,W)<<endl;
}

// #include <iostream>
// using namespace std;
// const int N = 100;
// int v[N], w[N];

// int knapSack(int W, int n) {
//    int i, wt;
//    int K[n + 1][W + 1];
//    for (i = 0; i <= n; i++) {
//       for (wt = 0; wt <= W; wt++) {
//          if (i == 0 || wt == 0)
//          K[i][wt] = 0;
//          else if (w[i - 1] <= wt)
//             K[i][wt] = max(v[i - 1] + K[i - 1][wt - w[i - 1]], K[i - 1][wt]);
//          else
//             K[i][wt] = K[i - 1][wt];
//       }
//    }
//    return K[n][W];
// }


// int main() {

//    int n, W;
//    cin >> n;
//    // int v[n], w[n];
//    for (int i = 0; i < n; i++) {
//       cin >> v[i];
//       // cin >> w[i];
//    }
//    for (int i = 0; i < n; i++) {
//       // cin >> v[i];
//       cin >> w[i];
//    }
//    cin >> W;
//    cout << knapSack(W, n);
//    return 0;
// }



