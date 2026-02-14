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

    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i =0 ;i<n;i++){
        pq.push(v[i]);
        if(pq.size() > k){
            cout << pq.top() << " ";
            pq.pop();
        }
    }

    while(!pq.empty()){
        cout << pq.top() << " ";
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
