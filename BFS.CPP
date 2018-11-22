#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define fast_io ios_base::sync_with_stdio(0); //cin.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define loop(i,n) for(i=1;i<=n;i++)
#define loon(i,n) for(i=n;i>0;i--)
#define pii pair< int,int > 
#define pll pair< ll,ll > 
#define vii vector< int > 
#define vll vector< ll > 
#define vss vector< string > 
#define vdd vector< double > 
#define vpi vector< pii > 
#define vpl vector< pll > 
#define vvi vector< vii > 
#define vvl vector< vll > 
#define PQ priority_queue
#define MX 1000005
#define mod 1000000007
#define INF 10000000000000000
#define EPS 1e-12

/* Special functions:
        find_by_order(k) --> returns iterator to the kth largest element counting from 0
        order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/

typedef tree<
pii(ll,ll),					// type long long
null_type,
less<pii(ll,ll)>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

struct compare{
    bool operator() (ll a, ll b)
    {
        return a>b;
    }
};

ll par[MX],dis[MX];
vll edge[MX];

void BFS(ll s, ll d, ll n)
{
    bool vis[n];
    memset(vis, false, sizeof vis);

    queue<ll>Q;
    Q.push(s);
    par[s]=-1;
    vis[s]=true;
    dis[s]=0;

    while(!Q.empty()){
        ll u=Q.front();
        Q.pop();

        for(auto v:edge[u]){
            if(vis[v])
                continue;
            par[v]=u;
            vis[v]=true;
            Q.push(v);
            dis[v]=dis[u]+1;
        }
    }

    if(!vis[d]){
        cout<< "No Path\n";
        return;
    }
    else{
        vll path;
        for(ll v=d;v!=-1;v=par[v])
            path.pb(v);
        reverse(path.begin(),path.end());

        cout<< "Path: ";
        for(auto v:path)
            cout<< v+1 << ' ';
        cout<< "\n";
    }
}

int main()
{
    fast_io;
    ll n,m,t,i,j,k,a,b,c,cs=1;
    //freopen(input.txt, r, stdin);
    //freopen(output.txt, w, stdout);
    string s;

    cin>> n >> m;

    for(i=0;i<m;i++){
        cin>> a >> b;
        a--,b--;

        edge[a].pb(b);
        edge[b].pb(a);
    }
    BFS(0,n-1,n);

    for(i=0;i<n;i++)
        cout<< dis[i] << ' ';

    return 0;
}
