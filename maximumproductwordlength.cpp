#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<string> s;
    for(int i =0 ;i<n;i++){
        string x;
        cin >> x;
        s.push_back(x);
    }


    vector<int>state(n,0);

/*
        for(int i = 0;i<n;i++){
        for(auto x: s[i]){
            state[i]|=(1 << x-'a');
        }
    }

    int ans = INT_MIN;
    for(int i =0 ;i<n;i++){
        for(int j = i;j<n;j++){
            if(!(state[i]&state[j])){
                ans = max(ans,(signed)s[i].length()*(signed)s[j].length());
            }
        }
    }

*/

    // the other way to solve this problem is considering the extra loop in the logic itself
    // its more like i will iterate forward and j will iterate backward
    // usually we do both iterations forward for pairs
    int ans = INT_MIN;
    for(int i =0;i<n;i++){
        for(auto x: s[i]){
            state[i] |= (1 << x - 'a');
        }
        for(int j=0;j<i;j++){
            if(!(state[i]&state[j])){
                ans = max(ans,(signed)s[i].length()*(signed)s[j].length());
            }
        }   
    }

    cout << ans << endl;
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
