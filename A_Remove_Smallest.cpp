#include<bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define nl "\n"
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define rrep(i, a, b) for(int i = (a); i >= (b); i--)

typedef long long ll;
typedef vector <int> vi;
typedef vector <double> vd;
typedef vector <ll> vll;

void solve()
{
    int n;
    cin >> n;

    int arr[n];

    rep(i,0,n)
        cin >> arr[i];

    sort(arr, arr+n);

    bool has = false;

    rep(i,1,n)
    {
        int b = arr[i]; 
        int a = arr[i-1]; 
        if(!(a == b || a+1 == b))
            has = true;
    }
    
    if(has)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main ()
{
    optimize();
              
    int t = 1;
    cin >> t;

    while(t--)
        solve();
        
    return 0;
}