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
#define MX 10000005
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

vll sort_cyclic_shifts(string const& s)
{
    ll n=s.size();
    const ll alp=256;
    
    vll p(n),c(n),cnt(max(alp,n),0);
    ll i,j,k,h;
    for(i=0;i<n;i++)
        cnt[s[i]]++;
    for(i=1;i<alp;i++)
        cnt[i]+=cnt[i-1];
    for(i=0;i<n;i++)
        p[--cnt[s[i]]]=i;
    
    ll classes=1;
    c[p[0]]=0;
    for(i=1;i<n;i++){
        if(s[p[i]]!=s[p[i-1]])
            classes++;
        c[p[i]]=classes-1;
    }

    vll pn(n),cn(n);
    for(h=0;(1<<h)<n;h++){
        for(i=0;i<n;i++){
            pn[i]=p[i]-(1<<h);
            if(pn[i]<0)
                pn[i]+=n;
        }

        fill(cnt.begin(),cnt.begin()+classes,0);
        for(i=0;i<n;i++)
            cnt[c[pn[i]]]++;
        for (i=1;i<classes;i++)
            cnt[i]+=cnt[i-1];
        for (i=n-1;i>=0;i--)
            p[--cnt[c[pn[i]]]]=pn[i];
        
        cn[p[0]]=0;
        classes=1;
        for(i=1;i<n;i++){
            pll cur={c[p[i]],c[(p[i]+(1<<h))%n]};
            pll prev={c[p[i-1]],c[(p[i-1]+(1<<h))%n]};

            if(cur!=prev)
                classes++;
            cn[p[i]]=classes-1;
        }

        c.swap(cn);
    }

    return p;
}

vll build_suffix_array(string s)
{
    s+='$';
    vll res=sort_cyclic_shifts(s);
    res.erase(res.begin());
    return res;
}

vll lcp_construction(string const& s, vll const& p) {
    ll n = s.size();
    vll rank(n, 0);
    for (ll i = 0; i < n; i++)
        rank[p[i]] = i;

    ll k = 0;
    vll lcp(n-1, 0);
    for (ll i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        ll j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}


int main()
{

    fast_io;
    ll n,m,t,i,j,k,a,b,c,cs=1;
    //freopen(input.txt, r, stdin);
    //freopen(output.txt, w, stdout);
    string str;

    cin>> str;

    vll res=build_suffix_array(str);
    for(i=0;i<res.size();i++)
        cout<< res[i] << ' ';
    cout<< endl;
    
    return 0;
}
