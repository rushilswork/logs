#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
/*
We are not specifically determining the exact point where the jump should be made. Instead, we identify the entire range of positions that can be reached with the current jump. From all positions in this range, we calculate the farthest possible position that could be reached in the next step, regardless of where the jump is made within the range. To achieve the minimum number of jumps, we therefore move from one range to the next, and the number of such ranges determines the answer.

*/
void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> v;
    
    for(int i =0;i<n;i++){
        ll x;
        cin >>x;
        v.push_back(x);
    }
    int ranges = 0;


    int currentrangeend = 0; // this helps in knowing if the extreme range we thought is done or not iterating, once done, one range will be completed
    int farthestend = 0;
    for(int i =0 ;i<n;i++){
        if(farthestend >= n - 1){
            cout << ranges + 1 << endl;
            break;
        }
        // updates extreme end
        farthestend = max(farthestend,i + v[i]);
        if(i == currentrangeend){
            currentrangeend = farthestend;// this should be updated when all the elements in one range are covered, if you update it right away eventually you'll get only one range
            ranges++;
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
