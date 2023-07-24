class Solution {
public:
  long long g = 0;
  long long l = 0;
  vector<int>temp;
  int n;
  void calc_local(vector<int>nums){
    for(int i = 0 ; i<nums.size()-1;i++){
      if(nums[i]>nums[i+1]){
        l++;
      }
    }
    
  }
   
  void merge(vector<int>&nums,int low , int mid ,int high){
     temp.clear();
     long long i = low;
     long long j = mid+1;
     
     while(i<=mid && j<=high){
       if(nums[i]<=nums[j]){
         temp.push_back(nums[i]);
         i++;
       }
       else if(nums[i]>nums[j]) {
         temp.push_back(nums[j]);
         g = g+mid-i+1;
         j++;
       }
     }
     while(i<=mid){
       temp.push_back(nums[i]);
       i++;
      }
     while(j<=high){
       temp.push_back(nums[j]);
       j++;
     }
     for(int k = low ; k<=high;k++){
       nums[k] = temp[k-low];
     }
   }
   void mergesort(vector<int>&nums,int low , int high){
     if(low<high){
     long long mid = (low+high)/2;
     mergesort(nums,low,mid);
     mergesort(nums,mid+1,high);
     merge(nums,low,mid,high);
       
     }
     
   }
  
    bool isIdealPermutation(vector<int>& nums){
      int n = nums.size();
      calc_local(nums);
      mergesort(nums,0,n-1);
      cout<<g<<endl;
      cout<<l<<endl;
      if(g==l){
        return true;
      }
      return false;
        
    }
};