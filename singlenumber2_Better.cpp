#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> v;
    for(int i =0;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(),v.end());
    int low = 0;
    int high = 0;

    if(v[0] != v[1]){
        cout << v[low] << endl;
        return;
    }
    else if(v[n - 1] != v[n - 2]){
        cout << v[n - 1] << endl;
        return;
    }
    else{
        /*
            while(high < n){
                if(v[low] == v[high]){
                    high++;
                }
                else{
                    break;
                }

                if(high - low == 3){
                    low = high;
                }
            }
        */

    // the other way to implement this is starting from the center of chunks and jumping to the center of other chunk, the reason for starting from the center of the chunk is that we can check the either side at once by standing at the center we check the right and left at the same time and jump on to another, if there is any difference we return that answer

    
        for(int i =1 ;i<n;i+=3){
            if(v[i] != v[i - 1] || v[i] != v[i + 1]){
                cout << v[i - 1] << endl;
                break;
            }
        }
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
