int minEatingSpeed(vector<int>& piles, int h) {
    int l=1,n=piles.size(),r=*max_element(piles.begin(),piles.end());
    int res=r;
    while(l<=r){
        int m=(l+r)/2;
        // cout<<m<<endl;
        double totalH=0;
        for(auto i:piles){
            totalH+=ceil((double)i/(double)m);
        }
        cout<<totalH<<endl;
         if(totalH<=h){
            res=m;
            r=m-1;
            
        }else{
            l=m+1;
        }
    }return res;
}