/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
     var temp = 1;
     var curr;
    return function(...args){
      if(temp===1){
        temp = temp+1;
        return fn(...args);
      }
      return curr;
      
      
        
    }
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
