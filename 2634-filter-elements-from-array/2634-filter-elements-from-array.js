/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
  
  let ans = [];
  arr.forEach((curr,idx)=>{
    if(fn(curr,idx)){
      ans.push(curr);
    }
    
  })
  
  
  return ans;
    
};