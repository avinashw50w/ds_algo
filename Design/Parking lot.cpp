/*
1. Multiple floors in parking lot
2. Multiple gates(entry/exits) in parking lot
3. Attendant at each gate
4. Entry gate process the parking ticket
5. Exit gate process payment on hourly basis
6. Parking facility for different types of vehicles.
7. Display board for showing available spots
 */

class ParkingLot {
	string name;
	Address address;

	vector<ParkingFloor> floors;
	vector<Entry> entries;
	vector<Exit> exits;

public:
	bool isSpotAvailableForVehicle(Vehicle vehicle);
	bool updateParkingAttendant(ParkingAttendant parkingAttendant, int gateId);
};

class Address {
	string pincode;
	string street;
	string city;
	string state;
	string country;
};

class ParkingFloor {
	int floorId;
	bool isFull;
	vector<ParkingSpot> parkingSpots;

	ParkingDisplayBoard parkingDisplayBoard;
};

class Gate {
	int gateId;
	ParkingAttendant parkingAttendant;
};

class Entry : public Gate {
public:
	ParkingTicket getParkingTicket(Vehicle vehicle);
};

class Exit : public Gate {
public:
	ParkingTicket payForParking(ParkingTicket ticket, PaymentMethod paymentMethod);
};

class ParkingSpot {
	int spotId;
	bool isAvailable;
	double costPerHour;

	Vehicle vehicle;
	ParkingSpaceType spaceType;
};

class ParkingDisplayBoard {
	map<ParkingSpaceType, int> spotAvailabilityMap;
public:
	void updateFreeSpotsAvailable(ParkingSpaceType parkingSpaceType, int spaces);
};

class Account {
	string name;
	string email;
	string empId;
	string username;
	string password;

	Address address;
};

class Admin : public Account {
public:
	bool addParkingFloor(ParkingLot parkingLot, ParkingFloor floor);
	bool addParkingSpot(ParkingFloor floor, ParkingSpot spot);
	bool addDisplayBoard(ParkingFloor floor, ParkingDisplayBoard displayBoard);
	...
};

class ParkingAttendant : public Account {
	Payment paymentService;
public:
	bool processVehicleEntry(Vehicle vehicle);
	PaymentInfo processPayment(ParkingTicket ticket, PaymentMethod paymentMethod);
};

class Vehicle {
	string licenseNumber;
	VehicleType vehicleType;
	ParkingTicket parkingTicket;
	PaymentInfo paymentInfo;
};

class ParkingTicket {
	int ticketId;
	int floorId;
	int spotId;

	string entryTimestamp;
	string exitTimestamp;

	ParkingSpaceType parkingSpaceType;
	ParkingTicketStatus ticketStatus;

	double totalCost;
public:
	void updateTotalCost();
	void updateVehicleExitTime(string exitTimestamp);
};

enum PaymentMethod {
	CASH, DEBIT, CREDIT, UPI
};

enum ParkingSpaceType {
	BIKE_PARKING, CAR_PARKING, TRUCK_PARKING
};

enum ParkingTicketStatus {
	ACTIVE, PAID
};

class Payment {
public:
	PaymentInfo makePayment(ParkingTicket ticket, PaymentMethod method);
};

class PaymentInfo {
	string txnId;
	double amount;
	string paymentDate;

	ParkingTicket ticket;
	PaymentMethod paymentMethod;
	PaymentStatus paymentStatus;
};

enum VehicleType {
	BIKE, CAR, TRUCK
};

enum PaymentStatus {
	COMPLETED, UNPAID, CANCELLED, REFUNDED, DECLINED, PENDING
};

