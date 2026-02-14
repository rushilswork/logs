#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> v;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }

    int k;
    cin >> k;

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    map<int,int> m;
    for(int i =0 ;i<n;i++){
        m[v[i]]++;
        pq.push({m[v[i]],v[i]});
        if(pq.size() > k){
            pq.pop();
        }
    }

    while(!pq.empty()){
        cout << pq.top().second << " ";
        pq.pop();
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
