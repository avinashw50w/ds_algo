/*Given a multi-dimensional array of integers, return a generator object which yields integers in the same order as inorder traversal.

A multi-dimensional array is a recursive data structure that contains both integers and other multi-dimensional arrays.

inorder traversal iterates over each array from left to right, yielding any integers it encounters or applying inorder traversal to any arrays it encounters.

Example 1:

Input: arr = [[[6]],[1,3],[]]
Output: [6,1,3]
Explanation:
const generator = inorderTraversal(arr);
generator.next().value; // 6
generator.next().value; // 1
generator.next().value; // 3
generator.next().done; // true
Example 2:

Input: arr = []
Output: []
 * @param {Array} arr
 * @return {Generator}
 */

const flat = (a) => {
    return a.reduce((acc, cur) => {
        if (Array.isArray(cur)) acc.push(...cur);
        else acc.push(cur);
        return acc;
    }, []);
};
var inorderTraversal = function*(arr) {
    function* itr(a) {
        if (Array.isArray(a)) {
            for (let e of a) {
                yield* itr(e);
            }
        } else {
            yield a;
        }
    }

    yield* itr(arr);
};

/**
 * const gen = inorderTraversal([1, [2, 3]]);
 * gen.next().value; // 1
 * gen.next().value; // 2
 * gen.next().value; // 3
 */
