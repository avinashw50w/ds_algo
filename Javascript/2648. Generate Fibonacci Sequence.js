/*Write a generator function that returns a generator object which yields the fibonacci sequence.

The fibonacci sequence is defined by the relation Xn = Xn-1 + Xn-2.

The first few numbers of the series are 0, 1, 1, 2, 3, 5, 8, 13.

*/
/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    yield 0;
    yield 1;
    let a = 0, b = 1, c;
    for (let i = 0; i <= 50; ++i) {
        c = a + b;
        yield c;
        a = b;
        b = c;
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */