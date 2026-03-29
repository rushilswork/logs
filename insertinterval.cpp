#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> p;

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<p> v;
    for(int i =0 ;i<n;i++){
        ll x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }

    p ip;
    int x,y;
    cin >> x >> y;
    ip.first = x;
    ip.second = y;

    vector<pair<int,int>> ans;

    int i =1;
    ans.push_back(v[0]);
    // merge all the intervals < ip
    while(i < n && (v[i].second <= ip.first || v[i].first <= ip.first)){
        if(ans.back().second >= v[i].first){
            ans.back().second = max(ans.back().second,v[i].second);
        }
        else{
            ans.push_back(v[i]);
        }
        i++;
    }

    // check for ip interval merge
    if(ans.back().second >= ip.first){
        ans.back().second = max(ans.back().second,ip.second);
        ans.back().first = min(ans.back().first,ip.first);
    }
    else{
        ans.push_back(ip);
    }


    while(i < n){
        if(ans.back().second >= v[i].first){
            ans.back().second = max(ans.back().second,v[i].second);
        }
        else{
            ans.push_back(v[i]);
        }
        i++;
    }

    for(auto x: ans){
        cout << x.first << "," << x.second << " , ";
    }
}
int main(){
    ll n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    n = 1;
    while(n--){
        TCSOLVE();
    }
}
