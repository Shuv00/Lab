#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
bool cmp(pair<ll , ll> x , pair<ll , ll> y){
    double v1 = (double)x.first/x.second;
     double v2 = (double)y.first/y.second;
     return v1 >  v2;

}
int main(){
    fast;
    ll n; cin >> n;
    vector<pair<ll , ll> >a(n);
    for( ll i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }
    ll w ;
    cin >> w;
    sort(a.begin(), a.end(), cmp);
    ll ans =0;
    for(int i=0;i<n;i++){
        if(w >=a[i].second){
            ans+= a[i].first;
            w-=a[i].second;
        }
        else {
        cout << "its working" << endl;
        double vw =  (double) a[i].first/a[i].second;
        cout << "vw" << endl;
        ans = ans + (vw * w);
        w=0;
        break;
        }

    }
    cout << ans << endl;
// 5 10 4 15 6 6 3 8 4 4 2 12

}

