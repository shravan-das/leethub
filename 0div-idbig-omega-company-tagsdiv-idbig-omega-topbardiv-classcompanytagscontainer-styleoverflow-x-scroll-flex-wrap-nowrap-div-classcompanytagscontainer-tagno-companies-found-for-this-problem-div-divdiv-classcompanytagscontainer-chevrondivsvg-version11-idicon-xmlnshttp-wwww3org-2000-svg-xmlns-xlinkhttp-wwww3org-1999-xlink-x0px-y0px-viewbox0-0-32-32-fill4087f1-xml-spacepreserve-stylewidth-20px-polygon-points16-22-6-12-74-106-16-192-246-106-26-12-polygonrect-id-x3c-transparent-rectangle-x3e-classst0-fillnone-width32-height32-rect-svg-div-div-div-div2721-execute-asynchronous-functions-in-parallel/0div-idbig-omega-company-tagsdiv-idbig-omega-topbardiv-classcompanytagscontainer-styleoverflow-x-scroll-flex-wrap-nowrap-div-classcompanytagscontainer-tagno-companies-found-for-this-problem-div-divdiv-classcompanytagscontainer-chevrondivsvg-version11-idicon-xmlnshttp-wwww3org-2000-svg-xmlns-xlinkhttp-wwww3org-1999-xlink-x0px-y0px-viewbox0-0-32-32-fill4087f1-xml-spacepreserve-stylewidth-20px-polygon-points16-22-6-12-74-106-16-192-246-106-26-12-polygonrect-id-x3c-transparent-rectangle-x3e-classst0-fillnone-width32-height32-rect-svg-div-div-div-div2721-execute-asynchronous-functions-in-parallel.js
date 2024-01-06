/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    
     var size = functions.length;
     
     return new Promise((resolve,reject)=>{
       var count = 0;
       var ans = [];
       
       for(let i = 0 ; i<size ; i++){
        
         var func = functions[i];
         func().then((data)=>{
           ans[i] = data;
           count++;
           if(count===size){
             resolve(ans)

           }
           
         }).catch((error)=>{
           reject(error);
         })
          
         
       
        }
     })
     
    
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */