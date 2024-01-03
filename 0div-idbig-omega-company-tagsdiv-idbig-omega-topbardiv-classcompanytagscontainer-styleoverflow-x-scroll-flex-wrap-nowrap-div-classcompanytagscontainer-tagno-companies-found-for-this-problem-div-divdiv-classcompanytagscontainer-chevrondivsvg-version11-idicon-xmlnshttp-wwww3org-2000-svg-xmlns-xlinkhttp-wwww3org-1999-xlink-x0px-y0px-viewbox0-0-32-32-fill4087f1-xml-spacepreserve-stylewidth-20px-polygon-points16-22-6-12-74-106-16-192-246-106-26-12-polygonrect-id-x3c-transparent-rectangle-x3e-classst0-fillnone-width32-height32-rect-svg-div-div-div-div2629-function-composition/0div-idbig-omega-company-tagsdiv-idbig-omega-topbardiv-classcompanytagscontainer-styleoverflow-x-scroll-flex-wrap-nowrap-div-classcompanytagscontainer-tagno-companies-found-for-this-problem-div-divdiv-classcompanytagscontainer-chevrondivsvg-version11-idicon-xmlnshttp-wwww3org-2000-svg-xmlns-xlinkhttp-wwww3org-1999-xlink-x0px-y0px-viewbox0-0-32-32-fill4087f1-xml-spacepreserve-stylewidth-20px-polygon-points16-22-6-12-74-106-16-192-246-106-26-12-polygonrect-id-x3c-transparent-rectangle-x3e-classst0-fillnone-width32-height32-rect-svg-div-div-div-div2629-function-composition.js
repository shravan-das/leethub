/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    
    return function(x) {
      
      var temp = x;
      var ans = 0;
      var size = functions.length;
      if(size===0){
        return temp;
      }
      for(let i = size-1 ; i>=0 ; i--){
        var fn = functions[i];
        ans = fn(temp);
        temp = ans;
        
      
      }
      
      return ans;
      
        
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */