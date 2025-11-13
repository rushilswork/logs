#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n;
    cin >> n;
    int xorn = 0;
/*
    for(int i =1;i<=n;i++){
        xorn^=i;
    }

    this is the bruteforce way to do xor in the range of 1 - n 


    if we observer there is a pattern when we do xor in the range of 1 - n    
    n
    1 -> 1
    2 - > 3
    3 - > 0
    4 - > 4

    5 - 1
    6 - 7
    7 - 0
    8 - 8

    for every n from 1 - 10 if we observe there is this pattern

    1 - n%4 = 1;
    n + 1 - n%4 = 2;
    0 - n%4 = 3;
    n - n%4 = 0;

*/


    int modofn = n%4;

    if(modofn == 0){
        cout << n << endl;
    }
    else if(modofn == 1){
        cout << 1 << endl;
    }
    else if(modofn == 2){
        cout << n + 1 << endl;
    }
    else if(modofn == 3){
        cout << 0 << endl;
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
