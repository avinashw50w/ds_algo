/*Write a function that checks if a given value is an instance of a given class or superclass. 
For this problem, an object is considered an instance of a given class if that object has access to that class's methods.

There are no constraints on the data types that can be passed to the function. For example, the value or the class could be undefined.

eg1: () => checkIfInstanceOf(new Date(), Date)
true
eg2. () => { class Animal {}; class Dog extends Animal {}; return checkIfInstanceOf(new Dog(), Animal); }
true
eg3.() => checkIfInstanceOf(Date, Date)
false
eg4. () => checkIfInstanceOf(5, Number)
true
eg5. () => checkIfInstanceOf(Number.NaN, Number)
true
eg6. () => checkIfInstanceOf(undefined, Object)
false
*/
/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    return obj != null && typeof classFunction === 'function' && Object(obj) instanceof classFunction;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */