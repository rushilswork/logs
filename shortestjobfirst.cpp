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

    sort(v.begin(),v.end());

    int currtime = 0;
    int waitingtime = 0;
    for(int i = 0;i<n;i++){
        waitingtime+=currtime;
        currtime+=v[i];
    }
    cout << "waiting time is : " << waitingtime << " " << " Average is: " << waitingtime/n << endl;
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
