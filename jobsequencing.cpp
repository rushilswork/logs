#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

// the greedy logic is that we sort the pair of pairs based on the highest profit, so that we can make the max profit, while doing the placement of the jobs, we place the job as late as possible because duing the process of making max profit, we should not block other job with smaller deadlines 

// A - 1 DEADLINE 30 Profit
// B - 2 DEADLINE 80 Profit

/*
    if i place 2 as it is having max profit, first in the 1 section that is 1 unit of time, it'll block the job A from being executed as it is having deadline 1, but B is utilised though it is having second block 

    ( B1 ) JOB A --> placement 1 ( early placing )

    ( A1 B2 ) ---> placement 2 ( late placing )
*/

typedef pair<int,pair<int,int>> pp;

bool magic(pp p1, pp p2){
    if(p1.second.second > p2.second.second){
        return true;
    }
    else{
        return false;
    }
}

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<pp> v;
    for(int i =0;i<n;i++){
        ll x,y,z;
        //id, deadline, profit
        cin >> z >> x >> y;
        v.push_back({z, {x,y}});
    }

    sort(v.begin(),v.end(),magic);

    int maxdead = -1;

    for(auto x: v){
        maxdead = max(maxdead,x.second.first);
    }

    vector<int>placement(maxdead,-1);
    
    int sum=0 ;
    int jobcnt = 0;
    for(auto x: v){
        for(int i = x.second.first;i>=0;i--){
            if(placement[i - 1] == -1){
                placement[i - 1] = x.first;
                sum+=x.second.second;
                jobcnt++;
                break;
            }
        }
    }

    cout << jobcnt <<  " " << sum << endl;
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
