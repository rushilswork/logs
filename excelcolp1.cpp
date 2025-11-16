#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n;
    cin >> n;
    string s="";
    while(n){
        int mod26 = n%26;
        if(mod26 == 0){
            s+='Z';
            n/=26;
            n--;
        }
        else{
            s+=mod26+'A'-1;
            n/=26;
        } 
    }

    reverse(s.begin(),s.end());
    cout << s << endl;
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
