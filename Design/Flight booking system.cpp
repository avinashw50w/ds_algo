class Airport {
	int id;
	string name;
	Address address;
	list<Flight> flights;
	...getters
	...setters
};

class Address {
	string pincode;
	string street;
	string city;
	string state;
	string country;
}

// an airport can have multiple flights of different airlines
class Flight {
	int id;
	string flightNo;
	string name;
	Airport source;
	Airport destination;
	list<FlightSchedule> schedules;
	list<Seat> seats;
};

// An Airline can have mulitple flights
class Airline {
	string name;
	string code;
	list<Flight> flights;
}

// each flight can have multiple schedules
// like flight A runs on Tue, Wed and Fri
// A user books a FlightSchedule not a Flight
class FlightSchedule {
	Flight flight;
	time_t departureTime;
	string gate;
	FlightStatus status;

	list<FlightSeat> seats;
};

enum FlightStatus {
	ACTIVE, SCHEDULED, DELAYED, DEPARTED
};

// each flight has multiple seats
class Seat {
	int seatNumber;
	SeatClass seatClass;
};

enum SeatClass {
	ECONOMY, BUSINESS
};

// extends the seat class to include a fair and booking status for each seat
class FlightSeat : public Seat {
	int fare;
	SeatBookingStatus bookingStatus;
};

enum SeatBookingStatus {
	BOOKED, AVAILABLE, RESERVED
};


/* Now we need to handle the booking part
1. A customer books a flight schedule - the customer chooses a flight, the date of flight,
no of seats and seat class, and the info of the age groups of the people who are travelling
*/

class Customer {
	int id;
	string name;
	string email;
	string phone;
	Gender gender;
	time_t dateOfBirth;
};

class FlightReservation {
	string reservationNo;
	FlightSchedule flight;
	map<Customer, FlightSeat> seatMap;
	time_t created_at;
	ReservationStatus status;
};

enum ReservationStatus {
	PAID, PENDING, BOOKED
};

/* Now we need to handle the Payment and Notification service */
// Notification is an abstract class which is extended by EmailNotification and
// SMSNotification or pushNotification;
class Notification {
	int id;
	string message;
	time_t created_at;
public:
	virtual bool send() = 0;
};

class EmailNotification : public Notification {
	string email;
public:
	bool send() {}
};

class SMSNotification: public Notification {
	string phone;
public:
	bool send() {}
};

// PaymentMethod is an abstract class which is extended by different payment method classes
// like Paypal, Debit, Credit, Netbanking, UPI

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