#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> v;
    for(int i =0 ;i<n;i++){
        ll x;cin >> x;
        v.push_back(x);
    }


    int c5 = 0;
    int c10 = 0;
    int c20 = 0;

    for(int i =0 ;i<n;i++){
        if(v[i] == 5){
            c5++;
            continue;
        }
        else if(v[i] == 10){
            c10++;
            if(c5 >= 1){
                c5--;
                continue;
            }
            else{
                cout << false << endl;
                return;
            }
        }
        else{
            c20++;
            if(c5 >= 3){
                c5-=3;
                continue;
            }
            else if(c10 >= 1 && c5 >= 1){
                c10--;
                c5--;
                continue;
            }
            else{
                cout << false << endl;
                return;
            }
        }
    }
    
    cout << true << endl;
    
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
