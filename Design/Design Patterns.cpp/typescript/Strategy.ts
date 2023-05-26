// Strategy interface
interface PaymentStrategy {
  pay(amount: number): void;
}

// Concrete Strategy 1
class CreditCardPaymentStrategy implements PaymentStrategy {
  private cardNumber: string;
  private cardExpiration: string;
  private cardCVV: string;

  constructor(cardNumber: string, cardExpiration: string, cardCVV: string) {
    this.cardNumber = cardNumber;
    this.cardExpiration = cardExpiration;
    this.cardCVV = cardCVV;
  }

  pay(amount: number): void {
    console.log(`Paying $${amount} with credit card (${this.cardNumber})`);
    // Additional logic for credit card payment
  }
}

// Concrete Strategy 2
class PayPalPaymentStrategy implements PaymentStrategy {
  private email: string;
  private password: string;

  constructor(email: string, password: string) {
    this.email = email;
    this.password = password;
  }

  pay(amount: number): void {
    console.log(`Paying $${amount} with PayPal account (${this.email})`);
    // Additional logic for PayPal payment
  }
}

// Context
class ShoppingCart {
  private paymentStrategy: PaymentStrategy | null = null;

  setPaymentStrategy(paymentStrategy: PaymentStrategy): void {
    this.paymentStrategy = paymentStrategy;
  }

  checkout(amount: number): void {
    if (this.paymentStrategy) {
      this.paymentStrategy.pay(amount);
    } else {
      console.log('Please set a payment strategy before checking out.');
    }
  }
}

// Client code
const shoppingCart: ShoppingCart = new ShoppingCart();

// Setting credit card payment strategy
const creditCardStrategy: PaymentStrategy = new CreditCardPaymentStrategy(
  '1234567890123456',
  '12/2024',
  '123'
);
shoppingCart.setPaymentStrategy(creditCardStrategy);
shoppingCart.checkout(100.50);

// Setting PayPal payment strategy
const paypalStrategy: PaymentStrategy = new PayPalPaymentStrategy(
  'example@example.com',
  'password'
);
shoppingCart.setPaymentStrategy(paypalStrategy);
shoppingCart.checkout(75.20);

/*
The chosen payment strategy is used to perform the payment by calling the pay() method on the selected strategy. Each strategy can implement its own logic for payment processing.

The strategy pattern allows for dynamic selection and interchangeability of different algorithms or strategies at runtime. It enables the context object to work with different strategies without being tightly coupled to their specific implementations.
*/
