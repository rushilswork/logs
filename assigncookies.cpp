#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n,m;
    cin >> n >> m;
    vector<int> student;
    vector<int> cookie;
    for(int i = 0;i<n;i++){
        ll x;
        cin >> x;
        student.push_back(x);
    }

    for(int i =0 ;i<m;i++){
        ll x;
        cin >> x;
        cookie.push_back(x);
    }

    sort(student.begin(),student.end());
    sort(cookie.begin(),cookie.end());

    int i = 0;
    int j = 0;
    // int cnt =0 ;
    while(i < n && j < m){
        if(student[i] <= cookie[j]){
            // cnt++;
            i++;
            j++;
        }
        else if(student[i] > cookie[j]){
            j++;
        }
    }

    // you can just print number of students satisfied i.e 'i' instead of 'cnt' we try to satisfy every student but based on the cookie we have we might or might not satisfy everyone so you can return 'i'
    cout << i << endl;
    // cout << cnt << endl;
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
