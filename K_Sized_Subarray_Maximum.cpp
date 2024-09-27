vector<int> max_of_subarrays(int k, vector<int> &a) {
    // my code 
    vector<int>v;int n=a.size();
    multiset<int>s;
    int i=0,j=0;
    while(j<k){
        s.insert(a[j++]);
    }
  
    int mx=*s.rbegin();
    v.push_back(*s.rbegin());
    i++;
    while(j<n){
        if(a[i-1]==mx){
            mx=check(a,i,j+1);
            v.push_back(mx);
        }
        else {mx=max(mx,a[j]);v.push_back(mx);}
        i++;j++;
    }
    return v;
}
