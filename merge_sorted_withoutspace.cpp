#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n,m;
    cin >> n >> m;
    vector<int> v1;
    vector<int> v2;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        v1.push_back(x);
    }

    for(int i =0 ;i<m;i++){
        ll x;
        cin >> x;
        v2.push_back(x);
    }


    int gap = ceil(float(n + m)/2);
    while(gap > 0){
        int l = 0;
        int r = gap;
        while(l < r && r < n + m){
            if(l < n && r < n){
                if(v1[l] > v1[r]){
                    swap(v1[l],v1[r]);
                }
            }
            else if(l >= n && r < n + m){
                if(v2[l-n] > v2[r-n]){
                    swap(v2[l-n],v2[r-n]);
                }
            }
            else{
                if(v1[l] > v2[r-n]){
                    swap(v1[l],v2[r-n]);
                }
            }
            l++;
            r++;
        }      
        if(gap == 1){
            break;
        }
        gap = ceil(float(gap)/2);
    }


    for(auto x: v1){
        cout << x << " ";
    }
    for(auto x: v2){
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
