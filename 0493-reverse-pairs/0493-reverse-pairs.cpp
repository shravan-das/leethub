class Solution {
public:
  
  int res = 0;
  
  
  void count_inversions(vector<int>&nums , int low , int mid , int high){
    int ans = 0;
    int right = mid+1;
    for(int i = low ; i<=mid ; i++){
      while(right<=high && nums[i]>(long long)2*nums[right]){
        right++;
      }
      ans = ans + (right-(mid+1));
    }
    res = res+ans;
  }
  
  void merge(vector<int>&nums,int low , int mid , int high){
    int left = low;
    int right = mid+1;
    vector<int>temp;
    while(left<=mid && right<=high){
      if(nums[left]<nums[right]){
        temp.push_back(nums[left]);
        left++;
      }
      else {
        temp.push_back(nums[right]);
        right++;
      }
    }
    
    while(left<=mid){
      temp.push_back(nums[left]);
      left++;
    }
    while(right<=high){
      temp.push_back(nums[right]);
      right++;
    }
    for(int i = low ; i<=high ; i++){
      nums[i] = temp[i-low];
    }    
  }
  void mergesort(vector<int>&nums , int low , int high){
      if(low<high){
      int mid=low+(high-low)/2;
      mergesort(nums,low,mid);
      mergesort(nums,mid+1,high);
      count_inversions(nums,low,mid,high);
      merge(nums,low,mid,high);
        
      }  
      
    
  }  
    int reversePairs(vector<int>& nums) {
      int n =  nums.size();
      mergesort(nums,0,n-1);
      return res;
        
    }
};