#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int minsteps(vector<int>&v,int idx, int steps){
    
    if(idx >= v.size() - 1){
        return steps;
    }

    int minjumps = INT_MAX;
    for(int i = idx + 1;i<=idx + v[idx];i++){
        minjumps = min(minjumps,minsteps(v,i,steps+1));
    }
    return minjumps;
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
     
    int ans = minsteps(v,0,0);
    if(ans !=INT_MAX){
        cout << ans << endl;
    }
    else{
        cout << -1 << endl;
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
