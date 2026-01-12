#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


class MINSTACK{
    public:
        stack<int> s;
        int minval = INT_MAX;

        void push(int val){
            if(s.empty()){
                s.push(val);
                minval = val;
            }
            else{
                if(minval < val){
                    s.push(val);
                }
                else{
                    // if val is smaller than minval, update
                    int modval = 2*val-minval;
                    minval = val;
                    s.push(modval);
                }
                // ealier we used to store the history of minimum in the second of pairs, it would help us in maintaining the history of minumuns , it withholds the minval until its point

                // but now to optimize we removed the pairs and maintaining single val in stack.
                // and also we are maintaining the min val in the varaible, what if the minval is removed from the stack, how will we maintain the min val now , we might be thinking of maitaining the another variable like second variable and store the second min, but what even if the second variable is removed from the stack, we cant keep maintain the min order of variables

                // we apply the logic of storing the modified value which is a mixture of previous min and current min

                // 15 -> for now 15 is min
                // 15 30 -> 30 is not replacing the min i.e, 15 so we just insert it
                // 15 30 10 -> 10 is replacing the min i.e, 15 so we insert the modified value instead of 10

                // 2*current min - old min = modified value

                // when current min is popped

                // 2*currentmin - modified value = old min

                // 2*10 - 15 = 5

                // 15 30 5


                // externally we maintain a variable for min = 5 

                // top is dependent on stack top  and min val, cuz sometimes we insert the modified value so

                // if s.top() > minval -> return s.top()
                // if s.top() < minval -> return minval

                // modified value will always be smaller than actual min val

                /* proof : 
                
                currentmin < previousmin

                currentmin - previousmin < 0

                2*currentmin - previousmin < currentmin

                we know 2*currentmin - previousmin => modified value

                modifiedvalue < currentmin

                */
               // we'll do the same check when we pop and update the values accordingly
            }
        }

        void pop(){
            // instead of just popping, check whether it is modified value of normal value, so that accordingly we can update the minval

            // this is modified valuee
            if(s.top() < minval){
                minval = 2*minval - s.top();
                // this gives prev min and updates the min val 
            }
            s.pop();
        }

        void getmin(){
            cout << minval << endl;;
        }

        void top(){
            // same check

            if(s.top() < minval){
                cout << minval << endl;
            }
            else{
                cout << s.top() << endl;
            }
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
