/*Used to instantiate only a single instance of the class.
eg. creating instance of db driver or the whole app instance
*/

class Singleton {
	private static Singleton instance;
	// private constructor to force use of the getInstance method
	// to create a single object
	private Singleton() {}

	public static Singleton getInstance() {
		if (instance == null) instance = new Singleton();
		return instance;
	}
}
// but the above implementation is not thread safe, coz two threads running at the same time
// will create two instances

// Method 2: make getInstance() synchronized
class Singleton {
	private static Singleton instance;

	private Singleton() {}

	public static syncronized Singleton getInstance() {
		if (instance == null) instance = new Singleton();
		return instance;
	}
}
/*Here using synchronized makes sure that only one thread at a time can execute getInstance().
The main disadvantage of this is method is that using synchronized every time while
creating the singleton object is expensive and may decrease the performance of your
program. However if performance of getInstance() is not critical for your application
this method provides a clean and simple solution.*/

// Method 3: eager instantiation
/*Here we have created instance of singleton in static initializer.
JVM executes static initializer when the class is loaded and hence this is guaranteed
to be thread safe. Use this method only when your singleton class is light and
is used throughout the execution of your program.
*/
class Singleton {
	private static Singleton instance = new Singleton();

	private Singleton() {}

	public static Singleton getInstance() {
		return instance;
	}
}

/*Method 4 (Best): Use “Double Checked Locking”
If you notice carefully once an object is created synchronization is no longer useful because now obj will not be null and any sequence of operations will lead to consistent results.
So we will only acquire lock on the getInstance() once, when the obj is null. This way we only synchronize the first way through, just what we want.*/

class Singleton {
	private volatile static Singleton obj;

	private Singleton() {}

	public static Singleton getInstance() {
		if (obj == null) {
			// To make thread safe
			synchronized (Singleton.class) {
				// check again as multiple threads
				// can reach above step
				if (obj == null)
					obj = new Singleton();
			}
		}
		return obj;
	}
}
/*We have declared the obj volatile which ensures that multiple threads offer the
obj variable correctly when it is being initialized to Singleton instance.
This method drastically reduces the overhead of calling the synchronized method every time.*/
