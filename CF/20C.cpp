#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define eb emplace_back
#define pb push_back
#define FOR(i,a,n) for(int i = a; i < n; i++)
#define f0r(i,n) for(int i = 0; i < n; i++)
#define in(a) int a; cin>>a
#define in2(a,b) in(a); in(b)
#define in3(a,b,c) in2(a,b); in(c);
#define out(a) cout<<a<<'\n'
#define out2(a,b) out(a<<' '<<b)
#define out3(a,b,c) out2(a,b<<' '<<c)
#define dout(a) cout<<a<<' '<<#a<<'\n'
#define dout2(a,b) cout<<a<<' '<<#a<<' '<<b<<' '<<#b<<endl
#define vout(v) cout<<#v<<": "; for(auto x : v)cout<<x<<' '; cout<<endl
#define vin(v,n) vi a(n); f0r(i,n)cin>>a[i]
using namespace std;
const signed mxn = 1e5 + 5;
int n, m; vector<pii>adj[mxn]; int par[mxn], dis[mxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m; f0r(i,m){in3(u,v,w); adj[u].eb(v,w); adj[v].eb(u,w);}
    f0r(i,n+1)dis[i] = (int)1e18, par[i] = i;
    priority_queue<pii>q; q.emplace(0,1);
    while(!q.empty()){
        auto [carry,node] = q.top(); q.pop(); carry = -carry; //dout2(carry,node);
        for(auto [u,w] : adj[node])if(dis[u] > carry + w){
            dis[u] = carry + w;
            par[u] = node;
            q.emplace(-dis[u],u);
        }
    } if(dis[n] == (int)1e18){out(-1); return 0;}
    // FOR(i,1,n+1)dout2(dis[i],par[i]);
    vi ans; int cur = n;
    while(cur != 1){
        ans.pb(cur);
        cur = par[cur];
        // dout(cur);
    } ans.pb(1); //vout(ans);
    reverse(ans.begin(),ans.end());
    f0r(i,ans.size())cout<<ans[i]<<' ';
    cout<<'\n';
}
