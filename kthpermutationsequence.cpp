#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


void kthfactorial(vector<int>&v, int n, int k){

    vector<int> ans;
    int chunk = 1;
    for(int i =1;i<n;i++){
        chunk*=i;
    }

    k--;
    while(1){
        // where does k falls
        // k/chunk
        int index = k/chunk;
        ans.push_back(v[index]);
        v.erase(v.begin() + index);
        k%=chunk;
        if(!v.size()){
            break;
        }
        chunk/=v.size();
    }

    for(auto x: ans){
        cout << x << " ";
    }
}

void TCSOLVE(){
    ll n,k;
    cin >> n >> k;

    vector<int> v;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }

    kthfactorial(v,n,k);
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
