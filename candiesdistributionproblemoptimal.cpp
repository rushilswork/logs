#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> v;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }

    /*
        this is optimal approach for candy problem using slope approach

        in better approach we try to do left comparision and right comparision individually and take the max on each to satisfity the condition



        in the optimal approach we try to do both at the same time


        1 2 3 4 -> in this case we keep checking left as it is upstream, increasing so the assignment goes like 1 2 3 4 and there is no downstream

        1 3 2 1 -> in this case there are both upstream and downstream

        till 3 there is upstream 1 3 -> the assignment goes like 1 2 ( based on left compariosion as it is upstream ), Now 2 1 is downstream ( after 3 ) in better approach we still do the left comparision and assign 1 on each on downstream then later we do right comparision and take the max on the both, But here in the optimal approach we try to do all at once, as it is a down stream we should have started from the bottom point ( lowest point ) but all we care of summation, we do not care of how many getting assignment to whom, so it doesnt matter where we start from until and unless we have the correct assignments, 
            so instead of starting from bottom by figuring out the bottom we instead proceed from the same point i.e, after 3 -> ( 2 1 ) if we would have followed right conmparision separately 2 , 1 -> 2, 1 ( this would be the assignment ), now in optimal approach we do 2,1 -> 1, 2 ( same but order is different, we dont care about order ) in this way we are already getting the max on each. In upstream ( left < right ) , In downstream ( left > right )

            so if we observe the pattern before peak and after peak 

            in left comparision , after peak we assign 1's if it is downstream , we take the max from right comparision
            in right comparision . before peak we assign 1's if it is upstream, we take max from left comparision


            so with the optimal approach we get the upstream and downstream max values correctly, except the peak, 

            if upstream < downstream ( in terms of length ) the peak needs to change based on the length of downstream, as we need to take the max on each

            if upstream > downstream , the peak need not be changed, as it is already having max val, so peak need to be max
    */

    int sum = 1;

    int i = 1;
    while(i < n){

        while(i < n && v[i] == v[i - 1]){
            sum++;
            i++;
        }

        int peak = 1;
        /*
            for the 0th index element the peak is 1 ( basically for the starting element peak should be 1 so initialized to 1 and also for the same reason sum = 1)

            if we are starting from the second element peak should be peak + 1 i.e, 2, i.e, sum==2(peak)
        */
        while(i < n && v[i] > v[i - 1]){ // upstream
            peak++;
            sum+=peak;
            i++;
        }

        int down = 1;
        /*
            when there is a drop, the down should be 1, for the reason we init to 1 and for the sum , + 1 should be added

            if you do this: 
            down++;
            sum+=down;

                you'll never add 1 , instead you'll add 2, due to which sometimes you get ans + 1, insetad of ans

            so change to:
            sum+=down;
            down++;
           
            eg;
            1 5 1 2 3 4
            app1 -> 1 2 2(down = 1 should be added but down++ is added) 2(peak picks up) 3 4
            app2 -> 1 2 1 2 3 4
  

            eg:
            3 2 1
            1 2 3

            app1 works fine for starting downstreams but not for intermediate downstreams ( reason explain above )
            app2 works fine for both

            3 2 1 with app2
            1 1 2 -> start from 2nd index and d = 1, sum += d, d++;
            d = 1, s = 1    d = 1, s = 1            d = 2, s = 2
            d = 1, s = 1    d = 1, s = 2, d = 2     d = 2, s = 4,d = 3

            this case:
                if(peak < down){
                  sum+=(down - peak);
                }

                bring backs the ans

                s = 4 + (down(3) - peak(1))
                s = 6

        */
        while(i < n && v[i] < v[i - 1]){ // downstream
            sum+=down;
            down++;
            i++;
        }

        // once one up and down is done correc the peak
        if(peak < down){
            sum+=(down - peak);
        }
    }


    cout << sum << endl;
}


/*
    1 0 5
    1 1 2
    2 1 1

    2 1 2


    p = 1
    d = 1

    d = 2
    s = 3


    p - 1
    d = 1

*/
int main(){
    ll n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    n = 1;
    while(n--){
        TCSOLVE();
    }
}
