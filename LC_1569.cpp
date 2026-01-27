class Solution {
public:
int mod=1000000007;
long long ans(vector<int>& nums,vector<vector<long long>> &comb){
    if(nums.size()<=2)return 1;
    vector<int> left,right;
    for(int i=1;i<nums.size();i++){
if(nums[0]>nums[i])left.push_back(nums[i]);
else{right.push_back(nums[i]);}
    }
    long long ansi=comb[nums.size()-1][left.size()]%mod;
    ansi*=ans(left,comb);ansi%=mod;
    ansi*=ans(right,comb);ansi%=mod;
return ansi;
}
    long long numOfWays(vector<int>& nums) {vector<vector<long long>> comb(nums.size(),vector<long long>(nums.size()));
    if(nums.size()>=2)
    {comb[1][0]=1;comb[1][1]=1;}
for(int i=2;i<=nums.size()-1;i++){
    comb[i][0]=1;comb[i][i]=1;
    for(int j=1;j<i;j++){
        comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%mod;
    }
}
        return (ans(nums,comb)-1+mod)%mod;
    }
};
