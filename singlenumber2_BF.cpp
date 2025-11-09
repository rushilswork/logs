#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int>v;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }

    int ans = 0;

    // logic is if the same number if appearing thrice and one number is apprearing once,it creates an imbalance in the count of its possition count of bit
    /*
    suppose 1 1 1 2 3 3 3
    1 - 0 0 1
    2 - 0 1 0
    3 - 0 1 1
    4 - 1 0 0
    as we see 0th bit of 1 is 1 and 2 is 0 and 3 is 1, so total of 6 setbits at position 0 and count of unset bit is 1 for 2, as count of 0 created a imbalance

    similarly we can think of 
    1 1 1 2 4 4 4

    count of setbits at position 0 is 3 and count of 0's is 4, desired number that is 2 is mingled with 4 now, it can either be a part of 1 or 0 depends but which everthat'll be the part of that will create the imbalance

    so where ever the imbalance that is the bit for the position
    */
    // check for 32 bits
    for(int bitno = 0;bitno<32;bitno++){
        int cnt = 0;
        for(int i =0 ;i<n;i++){
            // checking only the count of setbits as we have to explicitly set 1 in ans, where suppose if 0 is not divisible by 3 we dont have to explciitly set it by default it is already present
            if((v[i] >> bitno)&1){
                cnt++;
            }
        }
        if(cnt % 3){
           ans|=(1 << bitno);
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
