long long mod=1e9+7;
long long BE(int n,long long p){
    long long ans=1;
    while(p){
        if(p&1){
            p--;
            ans=((ans%mod)*(n%mod))%mod;
        }
        else{
            n=((n%mod)*(n%mod))%mod;
            p/=2;
        }
    }
    return ans%mod;
}
long long solve(vector<int> a) {
    long long c1=0,c2=0;
    for(int i=0;i<a.size();i++){
        if(a[i]&1) c1++;
        else c2++;
    }
    long long ans=0,res=0;
    if(c2!=0){
        ans=BE(2,c2)%mod;
        ans--;
    }
    if(c1!=0){
        res=BE(2,c1-1)%mod;
        res--;
    }
    return ((ans%mod)+(res%mod)+(((ans%mod)*(res%mod))%mod))%mod;
}
