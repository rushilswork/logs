#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


int kthsmallest(vector<int>&v,int k){
    priority_queue<int> pq;
    for(auto x: v){
        pq.push(x);
        if(pq.size() > k){
            pq.pop();
        }
    }

    return pq.top();
}


void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> v;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }    

    int k1,k2;
    cin >> k1 >> k2;

    if(k1 > k2){
        swap(k1,k2);
    }

    int x = kthsmallest(v,k1);
    int y = kthsmallest(v,k2);



    int sum = 0;
    for(auto z: v){
        if(z > x && z < y){
            sum+=z;
        }
    }

    cout << sum << endl; 
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
