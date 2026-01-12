#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


class MINSTACK{
    public:
        stack<pair<int,int>> s;

        void push(int val){
            if(s.empty()){
                s.push({val,val});
            }
            else{
                s.push({val,min(val,s.top().second)});
            }
        }

        void pop(){
            s.pop();
        }

        void getmin(){
            cout << s.top().second << endl;
        }
};

void TCSOLVE(){
    MINSTACK s;
    s.push(12);
    s.push(10);
    s.push(20);
    s.push(100);
    s.push(1);

    s.getmin();

    s.pop();

    s.getmin();
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
