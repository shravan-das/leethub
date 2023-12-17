class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxarea = 0;
        int currarea = 0;
        int i = 0;
        int j = height.size() - 1;
        while(i<j){
            currarea = (j-i)*(min(height[i] ,height[j]));
            if(currarea>maxarea)
                maxarea = currarea;
                height[i]<height[j] ? i++ : j--;       
             }
        return maxarea;
        
        
    }
};