/*
1. Users should be able to add new products to sell
2. search by product name and category
3. users should be able to search and view products, but need to be a registered
	member to buy it.
4. user is able to add/remove/modify products in their shopping cart
5. users can check-out and buy items in the shopping cart
6. users can give rating and reviews for a product
7. users should receive notifications whenever there is a change in the order
	or shipping status
 */

class Customer {
	int customerId;

	ShoppingCart cart;
	Search searchObj;

public:
	ShoppingCart getShoppingCart();
	void addItemsInShoppingCart(Item item);
	void updateItemInShoppingCart(Item item);
	void removeItemFormShoppingCart(Item item);
};

class Guest : public Customer {
public:
	Account createNewAccount();
};

class User : public Customer {
	Account account;
};

class Seller : public Customer {
public:
	void addProduct(Product product);
	void updateProduct(Product product);
	void removeProduct(Product product);
};

class Buyer : public Customer {
	Order orderObj;
public:
	OrderStatus placeOrder(ShoppingCart cart);
	void addReview(ProductReview review);
};

class Account {
	string name;
	string email;
	string phoneNumber;
	string username;
	string password;

	list<Address> shippingAddresses;

	AccountStatus accountStatus;
};

class Address {
	string pincode;
	string street;
	string city;
	string state;
	string country;
};

enum AccountStatus {
	ACTIVE, INACTIVE, BLOCKED
};

class ShoppingCart {
	list<Item> items;
	double cartValue;
public:
	void addItem(Item item);
	void updateItem(Item item);
	void removeItem(Item item);
	list<Item> getItems();
	double getCartValue();
	void checkOut();
};

class Item {
	Product product;
	int quantity;
};

class Product {
	int productId;
	string name;
	string description;
	double price;
	ProductCategory category;
	Seller seller;

	list<ProductReview> reviews;
};

enum ProductCategory {
	GROCERY, ELECTRONICS, CLOTHING, FURNITURE
};

class ProductReview {
	string review;
	Buyer reviewer;
	double rating;
	string createdAt;
};

class Search {
public:
	list<Product> searchByName(string productName);
	list<Product> searchByCategory(ProductCategory category);
};

class Order {
	string orderId;
	list<Item> items;
	double orderValue;
	string orderDate;
	Buyer buyer;
	Address shippingAddress;

	list<OrderLog> orderLogs;

	NotificationService notificationService;

public:
	OrderStatus placeOrder();
	OrderStatus trackOrder();
	void addOrderLog(OrderLog orderLog);

	PaymentStatus makePayment(PaymentMethod paymentMethod) {
		PaymentService paymentService = new PaymentService();
		PaymentInfo paymentInfo = paymentServie.makePayment(this->getOrderValue, paymentMethod);
		return paymentInfo.paymentStatus;
	}
};

enum OrderStatus {
	PACKED, SHIPPED, OUT_FOR_DELIVERY, DELIVERED, CANCELLED
};

enum PaymentStatus {
	PAID, UNPAID, REFUNDED, CANCELLED, ERROR
};

enum PaymentMethod {
	DEBIT, CREDIT, COD, UPI, NET_BANKING
};

class OrderLog {
	string details;
	string createdAt;
	OrderStatus orderStatus;
};

class NotificationService {
	Notification notificationObj;
	Message message;

public:
	/**
	 * the notificationDomain contains info about the notification type
	 * and the user to whom the notification is to be sent
	 */
	bool sendNotification(NotificationDomain notificationDomain) {
		switch (notificationDomain.getNotificationType()) {
		case EMAIL:
			notificationObj = new EmailNotification();
			message = new Message("no-reply@e-commerce.com", notificationDomain.getUser().getAccount().getEmail(), "Order details to send");
			break;

		case WHATSAPP:
			notificationObj = new WhatsappNotification();
			message = new Message("9457386748", notificationDomain.getUser().getAccount().getPhoneNumber(), "Order details to send");
			break;

		case SMS:
			notificationObj = new SMSNotificationObj();
			message = new Message("ECOMR", notificationDomain.getUser().getAccount().getPhoneNumber(), "Order details to send");
			break;
		}

		notificationObj.sentNotification(message);
	}
};

class NotificationDomain {
	int notificationId;
	NotificationType notificationType;
	User user;
};

class Message {
	string to;
	string from;
	string message;
};

class Notification {
public:
	virtual bool sendNotification(Message message) = 0;
};

class EmailNotification : public Notification {
public:
	bool sendNotification(Message message);
};

class WhatsappNotification : public Notification {
public:
	bool sendNotification(Message message);
};

class SMSNotification : public Notification {
public:
	bool sendNotification(Message message);
};

class PaymentService {
	Payment paymentObj;
public:
	PaymentInfo makePayment(double amount, PaymentMethod paymentMethod) {
		switch (paymentMethod) {
		case DEBIT:
			paymentObj = new DebitCardPayment(); break;
		case CREDIT:
			paymentObj = new CreditCardPayment(); break;
		case UPI:
			paymentObj = new UPIPayment(); break;
		}

		paymentObj.makePayment(amount);
	}
};

class Payment {
public:
	virtual PaymentInfo makePayment(double amount) = 0;
};

class DebitCardPayment : public Payment {
	CardInfo cardInfo;
public:
	PaymentInfo makePayment(double amount);
};

class CreditCardPayment : public Payment {
	CardInfo cardInfo;
public:
	PaymentInfo makePayment(double amount);
};

class UPIPayment : public Payment {
	string UPI_ID;
public:
	PaymentInfo makePayment(double amount);
};

class CardInfo {
	string cardNumber;
	string expirationDate;
	string cvv;
	string cardHolderName;
	CardType cardType;
};

enum CardType {
	DEBIT_CARD, CREDIT_CARD
};