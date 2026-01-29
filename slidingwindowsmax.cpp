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

    int k;
    cin >> k;

    deque<int> dq;

    /*

        k = 3
        0 1 2 3 4
    
    */

    for(int i =0 ;i<n;i++){
        // check if the front index is out of bounds of current windows starting index
        if(!dq.empty() && dq.front() < i - k + 1){
            dq.pop_front();
        }

        while(!dq.empty() && v[dq.back()] < v[i]){
            dq.pop_back();
        }
        
        dq.push_back(i);    
        
        //  end index for first window starts from k - 1
        if(i >= k - 1){
            cout << v[dq.front()] << " ";
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

/*  
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

    int k;
    cin >> k;

    for(int i =0 ;i<n - k + 1;i++){
        int maxans = INT_MIN;
        for(int j =i ;j<=i +k - 1;j++){
            maxans = max(maxans,v[j]);
        }
        cout << maxans << " ";
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
*/