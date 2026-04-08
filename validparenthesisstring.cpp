#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
/*


Since * introduces multiple possibilities, instead of deciding its value, we track the range of possiblities. If by the end we can achieve 0 open brackets, the string is valid.

*/

void TCSOLVE(){
    string s;
    cin >> s;
    
    int minp = 0;
    int maxp = 0;

    for(int i =0 ;i<s.length();i++){
        if(s[i] == '('){
            // opening bracket => +1
            minp = minp + 1;
            maxp = maxp + 1;
        }
        else if(s[i] == ')'){
            // closing brcket => -1
            minp = minp - 1;
            maxp = maxp - 1;
        }
        else{
            /*
                '*' can be anything '(' or ' ', ')'

                we need to make sure not to start with ')' i.e, -1, so if so far maxp and inp count is 0, make sure not to start with ')' so that the value should not be -1, as for closing bracket there is not validity can be achieved


                for a val x ( minp or maxp )    least value can be x - 1 and max can be x + 1

                choosing the extremes to cover all possibiities
            */

            minp = minp - 1;
            maxp = maxp + 1;
        }

        if(minp < 0 ){
           minp = 0;
        }
    }
// **(*(((*((******
    cout << minp << " " << maxp << endl;
    if(minp == 0){
        cout << "Valid" << endl;
    }
    else{
        cout << "Not valid" << endl;
    }
}
int main(){
    ll n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    n = 1;
    while(n--){
        TCSOLVE();
    }
}
