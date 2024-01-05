/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
    
    return async function(...args) {
      
      const promise1 = new Promise((resolve,reject)=>{
        const res = fn(...args);
        resolve(res);
      })
      
      const promise2 = new Promise((resolve,reject)=>{
        setTimeout(()=>{
          reject("Time Limit Exceeded")
        },t);
      })
      
      const temp = await Promise.race([promise1,promise2]);
      return temp;
      
      
        
    }
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */