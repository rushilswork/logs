#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> v;
    for(int i =0;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }


    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    for(int i =0 ;i<n;i++){
        pq.push({v[i],i});
    }

    vector<int> ans(n,0);

    int k =0 ;
    int lastupdated = -1;
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        if(x.first != lastupdated){
            k++;
        }
        ans[x.second] = k;
        lastupdated = x.first;
    }

    for(auto x: ans){
        cout << x << " ";
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
