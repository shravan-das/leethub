/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
  let arr = this;
  let ans = arr.reduce((acc,curr)=>{
    let id = fn(curr);
    if(acc[id]){
      acc[id].push(curr);
    }
    else if(!acc[id]){
      let newarr = [];
      newarr.push(curr);
      acc[id] = newarr;
    }
    return acc;
    
  },{});
  
  
  return ans;
  
    
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */