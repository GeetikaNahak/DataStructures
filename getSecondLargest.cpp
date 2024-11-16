// Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.
// Note: The second largest element should not be equal to the largest element.

int getSecondLargest(vector<int> &arr) {
        // Code Here
        set<int>s;
        for(auto i:arr)s.insert(i);
        if(s.size()<2)return -1;
        int k=0;int res=0;
        for(auto i:s){
            res=i;
            k++;
            if(k==s.size()-1)break;
        }return res;
    }
