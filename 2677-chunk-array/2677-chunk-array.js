/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
  let ans = [];
  let l = arr.length;
  for(let i = 0 ; i<l ; i=i+size){
    let temp = arr.slice(i,i+size);
    ans.push(temp)
  }
  
  
  return ans;
  
    
};
