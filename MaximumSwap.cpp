// You are given an integer num. You can swap two digits at most once to get the maximum valued number.
// Return the maximum valued number you can get.

// Example 1:
// Input: num = 2736
// Output: 7236
// Explanation: Swap the number 2 and the number 7.

// Example 2:
// Input: num = 9973
// Output: 9973
// Explanation: No swap.

class Solution {
public:
    int maximumSwap(int num) {
        string k=to_string(num);
        int n=k.size();
        int curr=n-1,sp=n-1;
        char mx=k[n-1];
        vector<pair<int,int>>v;
        for(int i=n-2;i>=0;i--){
            cout<<sp<<" "<<curr<<endl;
            if(k[i]>mx){
                mx=k[i];
                sp=i;
                curr=i;
            }
            else if(k[i]<mx){curr=i;v.push_back({curr,sp});}
        }
        if(v.size()>0){
            sp=v[v.size()-1].second;
            curr=v[v.size()-1].first;
        }
        swap(k[sp],k[curr]);
        num=stoi(k);
        cout<<k<<endl;
        return num;

    }
};
