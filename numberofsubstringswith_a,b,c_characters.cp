#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    string s;
    cin >> s;
    int a = -1;
    int b = -1;
    int c = -1;
    int r = 0;
    int n = s.length();

    int cnt = 0;

    while(r < n){
        if(s[r] == 'a'){
            a = r;
        }
        else if(s[r] == 'b'){
            b = r;
        }
        else if(s[r] == 'c'){
            c = r;
        }
        
        // update these indexes , at every update check 


        // the substring with min(indexes of a,b,c) to r will be the valid window, anything extension to this valid window will also be valid
        if(a != -1 && b != -1 && c != -1){
            int minindex = min(a,min(b,c));
            // int maxindex = max(a,max(b,c)); not required would definately be 'r'

            // r - minindex + 1, would be the size of subarray with a , b and c
            // join the prefix characters to this to form new subarray so , number of prefixes = number of subarrays, based on this logic add cnt
            cnt+=(minindex + 1);
        }
        r++;
    }

    cout << cnt << endl;
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
