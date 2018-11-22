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
#define MX 1005
#define mod 1000000007
#define INF 10000000000000
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

bool marked[MX],vis[1000005];

const ll K = 70;

struct Vertex {
    ll next[K];
    bool leaf = false;
    ll p = -1;
    char pch;
    ll link = -1;
    ll go[K];
    vll pos;

    Vertex(ll p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s, ll pos) {
    ll v = 0;
    for (char ch : s) {
        ll c = ch - 'A';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].pos.pb(pos);
    t[v].leaf = true;
}

ll go(ll v, char ch);

ll get_link(ll v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

ll go(ll v, char ch) {
    ll c = ch - 'A';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }

    return t[v].go[c];
}

ll find_text(ll v, char ch)
{
    ll c=ch-'A';

    ll u=v;
    if(t[v].link!=-1){
        /*u=t[v].link;
        if(ch=='c')
            cout<< v << endl;
        if(t[u].leaf){
            for(ll i=0;i<t[u].pos.size();i++)
                marked[t[u].pos[i]]=true;
        }*/
        while(u>0){
            if(vis[u])
                break;
            vis[u]=true;
            //cout<< u << ' ' << ch << endl;
            u=t[u].link;
            if(t[u].go[c]!=-1 and t[t[u].go[c]].leaf){
                for(ll i=0;i<t[t[u].go[c]].pos.size();i++)
                    marked[t[t[u].go[c]].pos[i]]=true;
            }
        }
    }
    v=go(v,ch);
    if(t[v].leaf)
        for(ll i=0;i<t[v].pos.size();i++)
            marked[t[v].pos[i]]=true;
    return v;
}

int main()
{

    fast_io;
    ll n,m,i,j,k,a,b,c,cs=1;
    //freopen(input.txt, r, stdin);
    //freopen(output.txt, w, stdout);
    string str;
    cin>> str >> n;

    for(i=1;i<=n;i++){
        string s;
        cin>> s;
        add_string(s,i);
    }

    for(i=0;i<t.size();i++)
        get_link(i);

    ll v=0;
    for(i=0;i<str.size();i++)
        v=find_text(v,str[i]);

    for(i=1;i<=n;i++){
        if(marked[i])
            cout<< "Y\n";
        else
            cout<< "N\n";
    }
    return 0;
}