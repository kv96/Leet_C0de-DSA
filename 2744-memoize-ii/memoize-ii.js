/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const RESULT = Symbol("result");
    const root = new Map();

    return function (...args) {
        let node = root;

        for (const arg of args) {
            if (!node.has(arg)) {
                node.set(arg, new Map());
            }
            node = node.get(arg);
        }

        if (node.has(RESULT)) {
            return node.get(RESULT);
        }

        const value = fn(...args);
        node.set(RESULT, value);

        return value;
    };
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */