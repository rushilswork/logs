#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> ans(n + 1 , 0);   
    for(int i = 0;i<=n;i++){
        if(i&1){
            ans[i] = ans[i/2] + 1;
        }
        else{
            ans[i] = ans[i/2];
        }
    }

    for(int i =0 ;i<=n;i++){
        cout << i << " " << ans[i] << endl;
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
