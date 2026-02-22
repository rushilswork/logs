#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    string s;
    cin >> s;
    int n;
    cin >> n;


    map<char,int> m;
    priority_queue<pair<int,char>> pq;

    int time = 0;


    for(auto x: s){
        m[x]++;
    }

    for(auto x: m){
        pq.push({x.second,x.first});
    }

    vector<char> v;

    /*
        Between every two identical tasks there need to be a cooling time of n, that means we can execute n + 1 different tasks and that stands for 1 cycle until same tasks can be process.

        we start with high freq/occurance tasks, the reason is, if we start with low freq/occurance tasks, the high freq ones at the end will take up more time, as the tasks will be having idle time, so spaces will be left out between high freq tasks


        so if we start with high freq tasks first such that the spaces/idle time can be covered with other tasks, instead of keeping them idle like the low freq first approach mentioned above


        this way we can cover the tasks in min time

    */
    while(!m.empty()){
        v.clear();
        // run this for one cycle n + 1
        int cnt = n + 1;
        while(!pq.empty() && cnt){
            auto x = pq.top();
            pq.pop();
            m[x.second]--;
            if(m[x.second] == 0){
                m.erase(x.second);
            }
            else{
                v.push_back(x.second);
            }
            cnt--;
        }
        for(auto x: v){
            pq.push({m[x],x});
        }
        time+=n+1;
        if(v.empty()){
            // when no elements are left out to process, remove the empty spaces ( idle time ) from the time counter in the last cycle, where by default we'll consider the complete cycle so remove the spaces from the last cycle
            time-=cnt;
        }
    }
 
    cout << time << endl;
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
