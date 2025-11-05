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

    int subsets = 1 << n;

    vector<vector<int>> subsetslist;
    for(int i = 0;i<subsets;i++){
        vector<int>subset;
        // for every ith subsets we are representing 'i' in binary form which mapps to index of vcetors and helps in selection of subset elements
        for(int j = 0;j<n;j++){
            if((i >> j) & 1 == 1){
                subset.push_back(v[j]);
            }
        }

        subsetslist.push_back(subset);
    }   

    for(auto x: subsetslist){
        for(auto y: x){
            cout << y << " ";
        }
        cout << endl;
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
