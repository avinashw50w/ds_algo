/*In Strategy pattern, a class behavior or its algorithm can be changed at run time. This type of design pattern comes under behavior pattern.

In Strategy pattern, we create objects which represent various strategies and a context object whose behavior varies as per its strategy object. The strategy object changes the executing algorithm of the context object.

Implementation
We are going to create a Strategy interface defining an action and concrete strategy classes implementing the Strategy interface. Context is a class which uses a Strategy.

StrategyPatternDemo, our demo class, will use Context and strategy objects to demonstrate change in Context behaviour based on strategy it deploys or uses.*/

public interface Strategy {
	public int doOperation(int a, int b);
}

public class AddOperation implements Strategy {
	@override
	public int doOperation(int a, int b) {
		return a + b;
	}
}

public class SubtractOperation implements Strategy {
	@override
	public int doOperation(int a, int b) {
		return a - b;
	}
}

public class Context {
	private Strategy strategy;

	public Context(Strategy strategy) {
		this.strategy = strategy;
	}

	public int executeStrategy(int a, int b) {
		return strategy.doOperation(a, b);
	}
}

public class Demo {
	public static void main(String args[]) {
		Context context = new Context(new AddOperation());
		System.out.println(context.executeStrategy(10, 5));

		context = new Context(new SubtractOperation());
		System.out.println(context.executeStrategy(10, 5));
	}
}

///////////////
/*
use this pattern to implement Notification and payment services,
because the way of sending notification varies in case of email, sms, whatsapp etc..
similarly there are different implementations for different payment methods like
debit, credit, upi, net_banking

eg. For notification
1. create a Notification interface - contains makePayment method
2. create EmailNotification, SMSNotification, WhatsappNotification -
implements the Notification interface and overrides the makePayment method
3. create NotificationService class - it acts as a context
 */