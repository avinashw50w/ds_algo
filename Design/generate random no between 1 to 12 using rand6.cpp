/*Given a random no generator A which generates a # between 1 to 6 with equal prob. Use this 
generator to generate # between 1 to 12 with equal prob.

IDEA: (A() - 1) * 6 + A()

let's break it into expressions: x = (A() - 1) * 6
y = A()

when A() = 0, then x = 0, and y can be between [1...6]. So when x = 0, all nos btw [1...6]
is generated with equal probability.
when A() = 1, then x = 6, and y can be between [1...6]. So when x = 1, all nos btw [7...12]
is generated with equal probability.
when A() = 2, then x = 12, and y can be between [1...6]. So when x = 1, all nos btw [13...18]
is generated with equal probability.
... and so on

*/

while (true) {
    int x = (A() - 1) * 6;
    int y = A();

    int res = x + y;
    if (res > 12) continue;
    return res;
}