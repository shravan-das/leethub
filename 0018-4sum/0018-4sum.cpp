class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
vector<vector<int>> ans;
if(nums.empty())return ans;
int n=nums.size();
sort(nums.begin(),nums.end());
for(int i=0;i<n;i++){
for(int j=i+1;j<n;j++){
long long target2= target - (long long int)nums[i]-(long long int)nums[j];
long long left=j+1;
long long right=n-1;
while(left<right ){
if((nums[left]+nums[right])<target2){
left++;
}
else if((nums[left]+nums[right])>target2){
right--;
}
else{
vector res(4,0);
res[0]=nums[i];
res[1]=nums[j];
res[2]=nums[left];
res[3]=nums[right];
ans.push_back(res);
while(left<right && nums[left]==res[2])++left;
while(left<right && nums[right]==res[3])--right;
}

            }
            while(j+1<n && nums[j+1]==nums[j])++j;
        }
        while(i+1<n && nums[i+1]==nums[i])++i;
    }
    return ans;
        
    }
};