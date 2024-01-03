/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
  var prev = n;
  var nex = n+1;
  var temp;
    return function() {
      temp = prev;
      prev = nex;
      nex = nex+1;
      return temp;
      
      
      
      
      
      
        
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */