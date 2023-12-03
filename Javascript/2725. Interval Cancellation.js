/*Given a function fn, an array of arguments args, and an interval time t, return a cancel function cancelFn.

The function fn should be called with args immediately and then called again every t milliseconds until cancelFn is called at cancelT ms.

*/
/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function(fn, args, t) {
    setImmediate(() => fn(...args)); // we can also just call the func: fn(...args)

    let timer = setInterval(() => fn(...args), t);
    let cancelFn = () => clearInterval(timer);

    return cancelFn;
};

/**
 *  const result = []
 *
 *  const fn = (x) => x * 2
 *  const args = [4], t = 35, cancelT = 190
 *
 *  const start = performance.now()
 *
 *  const log = (...argsArr) => {
 *      const diff = Math.floor(performance.now() - start)
 *      result.push({"time": diff, "returned": fn(...argsArr)})
 *  }
 *       
 *  const cancel = cancellable(log, args, t);
 *
 *  setTimeout(() => {
 *     cancel()
 *  }, cancelT)
 *   
 *  setTimeout(() => {
 *    console.log(result)  // [
 *                         //      {"time":0,"returned":8},
 *                         //      {"time":35,"returned":8},
 *                         //      {"time":70,"returned":8},           
 *                         //      {"time":105,"returned":8},
 *                         //      {"time":140,"returned":8},
 *                         //      {"time":175,"returned":8}
 *                         //  ]
 *  }, cancelT + t + 15)    
 */