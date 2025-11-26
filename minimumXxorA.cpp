#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll a,b;
    cin >> a >> b;
    // find the number x such that the xor of X and A should be minimum and the also make sure the number of set bits in X should be same as B
    // our target is to completely minimize the xor of A, i.e, to make it 0, to achieve that we need to have the same number but also need to keep in mind that the number of bits need to be same as the number of bits in the B

    // to minimize we need to create a number with the avaiable set bits from B and set them accordingly to minimize the XOR of A, set those bits which are already set in the A
    
    int cnt = 0; // count of set bits in the B
    int n = b;
    while(n){
        n = n&(n-1);
        cnt++;
    }

    // now lets check which bits are set in the A accordingly we'll create X
    // keep in mind that to minimze the XOR, always set in the order of MSB, such that the maximum value bits will be removed

    int X = 0;
    for(int i = 31;i>=0;i--){
        if(cnt){
           if((a >> i)&1){
                X|=(1<<i);
                cnt--;
            }
        }
        else{
            break;
        }
    }
    // if we have more cnt we'll add from fron LSB
    // if we have enough as equal set bits in A thats fine
    // if we have less cnt that is fine

    // now need to handle only for cnt > set bits in A

    for(int i = 0;i<32;i++){
        if(cnt){
            if(((a >> i)&1) == 0){
                X|=(1 << i);
                cnt--;
            }
        }
        else{
            break;
        }
    }

    cout << X << endl;

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
