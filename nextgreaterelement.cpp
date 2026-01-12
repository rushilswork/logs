
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

    vector<int> ans(n,-1);
    stack<int> s;
    for(int i = n - 1;i>=0;i--){
        while(!s.empty() && v[i] > s.top()){
            s.pop();
        }
        if(!s.empty()){
            ans[i] = s.top();
        }
        s.push(v[i]);
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
