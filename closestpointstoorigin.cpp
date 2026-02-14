#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

typedef pair<int,int> p;

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i =0 ;i<n;i++){
        ll x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }

    priority_queue<pair<float,p>,vector<pair<float,p>>,greater<pair<int,p>>> pq;

    for(auto x: v){
        float hypo = sqrt(pow(x.first,2) + pow(x.second,2));
        pq.push({hypo,x});
    }

    cout << endl;
    while(!pq.empty()){
        cout << pq.top().second.first << " " << pq.top().second.second << endl;
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
