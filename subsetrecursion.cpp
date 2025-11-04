#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void subsets(vector<int>&v,int i, vector<pair<int,int>> &store){
    if(i == v.size()){
        for(auto x: store){
            cout << x.first << " ";
        }
        cout << endl;
        return;
    }

    if(store.empty() || abs(store.back().second - i) == 1){
        store.push_back({v[i], i});
        subsets(v,i + 1, store);
        store.pop_back();
    }
    subsets(v,i + 1,store);
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

    vector<pair<int,int>> store;
    subsets(v,0,store);
}
int main(){
    ll n;
    ios_base::sync_with_stdio(false);
    n = 1;
    while(n--){
        TCSOLVE();
    }
}
