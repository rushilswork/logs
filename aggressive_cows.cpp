#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


    int howmanycows(vector<int>&v,int mid){
       int cnt = 1;
       int last = v[0];
       for(int i = 1;i<v.size();i++){
           if(v[i] - last >= mid){
               cnt++;
               last = v[i];
           }
       }
       
       return cnt;
    }
    
    int aggressiveCows(vector<int> &arr, int k) {
        vector<int> v(arr);
        
        /*
            to find the minimum distance between any two cows, we need to remember in a serial order of numbers/ checkpoint, the min ( distance between any two adjacent checkpoints ) is the min bewteen any two points, for a number in serial order, the minimum distance is always with the adjacent elements/points, if we move beyond the adjacent element the diatnce increase and we'll not get min distance



            here to achieve the problem, we're not explicitly placing the cows and figuring out the min distance to maximize it, instead we are doing reverse engineering, checking if x is answer it should make the arrangement possible

            to get x as answer, the distance between any two cows should be >= x, 

            in the sorted order, we just check the dis between adj ( last placed cow / checkpoint ) cows and if dis is >= x , consider a cow has been placed ( you may get > x ( in all comparisions ) and not exactly x ( e.g, 10 15 20 ( where mid = 3 ) all distances are 5 , we are not sticking to 3, it just says > 3 ans is possible ), that just means there is a better ans as per the objective of optimization )

            here in sorted order we only need to worry about the last adjacent cow placed and not about the cows placed way before, because the checkponts/elements beyond adjacent position just increases the distance so min is just with the last placed cow position

            e.g 3 5 8 ( k = 3 )

            lets say mid = 3, one cow at 3, now to place at 5, i'll check with the last placed cow i.e, '3'. it is not satisfying >= 3 condition so we cant place, if we place it at 5, it just violates the min distance maintaning condition, so we'll place at 8, it satisfies the condition, but we could only place 2, so mid = 3 is not the answer, 

            here being sorted helped us in checking if we can place cows with maintaining >= x ( x = 3)


            if not sorted
            e.g 8 3 5 (Mid = 3, k = 3)

            one cow at 8, now we'll check if we can place at 3, yes as >=3 condition satisfies, now to place at 5, we need to check the cow position comparision with last 2 cows placed, instead of adjacent , ( sorted guarentees that if condition with adjacent is maintained then with all it is maintianed,) here in unsorted, it doesnt guarnatee, so we need to check with all the so far cows placed, that takes much more time complexity;


            so this explains why sorting is required, and how problem is approached
        */
        sort(v.begin(),v.end());
        int low = 1;
        int high = v[v.size() - 1] - v[0];
        
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            
            int mind = howmanycows(v,mid);
            
            if(mind >= k){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return ans;
    
    }
void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> v;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }

    ll k;
    cin >> k;

    cout << aggressiveCows(v,k);
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
