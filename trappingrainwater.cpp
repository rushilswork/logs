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

    int leftmax = v[0];
    int rightmax = v[n - 1];

    int left = 0;
    int right = n - 1;
    int ans = 0;

    // usually on the both sides in the better approach we are looking at the smaller one, because the smaller block is limiting the capacity to store water, we start with both the pointers, either of the side once the limiting block is decided, on the side of limiting block we move forward and calculate stored water capacity on that side, because we already know the limiting block ( smaller block )
    /*
        example: 2 0 3
        the edge blocks 2 and 3 cant store any water because there is no support from either sides
        but we have 2 blocks 2 and 3 in which the smaller one is the limiting one
        we move forward, for the next element 0, we can see the limiting block is 2 so 2 - 0 = 2 capacity it stores
    */
    while(left <= right){
        leftmax = max(leftmax,v[left]);
        rightmax = max(rightmax,v[right]);

        if(leftmax < rightmax){
            ans+=leftmax-v[left];
            left++;
        }
        else{
            ans+=rightmax - v[right];
            right--;
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


/*
TC  - o(3n), SC - O(2n)
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

    vector<int> prefmax(n,INT_MIN);
    vector<int> suffmax(n,INT_MIN);
    prefmax[0] = v[0];
    for(int i=1;i<n;i++){
        prefmax[i] = max(v[i],prefmax[i - 1]);
    }

    suffmax[n - 1] = v[n - 1];
    for(int i = n - 2;i>=0;i--){
        suffmax[i] = max(v[i],suffmax[i + 1]);
    }

    int total = 0;
    for(int i =0 ;i<n;i++){
        total+=min(prefmax[i],suffmax[i]) - v[i];
    }

    cout << total << endl;
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