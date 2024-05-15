const sum = (a, b) => a + b;

function memoize(fn) {
    let res;
    return (...args) => {
        if (res) return res;
        res = fn.apply(this, args);
        return res;
    };
}

let cached = memoize(sum);
cached(2, 4);
