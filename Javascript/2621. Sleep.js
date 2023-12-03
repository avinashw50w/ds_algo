/*Given a positive integer millis, write an asynchronous function that sleeps for millis milliseconds. It can resolve any value.*/
/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    return new Promise(res => setTimeout(res, millis));
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */