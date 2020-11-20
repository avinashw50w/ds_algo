/*
Types of user: Guest, Receptionist, Admin, HouseKeeping
1. receptionist is able to search rooms, check room availability, book rooms
2. Admin should be able to add, udpate and remove rooms
3. The system should send notification when a room becomes available.
 */

class Hotel {
	string hotelId;
	string name;
	Address location;
	vector<Room> rooms;
};

class Address {
	string pincode;
	string street;
	string city;
	string state;
	string country;
};

class Room {
	string roomNumber;
	string floor;
	RoomType roomType;
	RoomStatus roomStatus;
	vector<RoomKey> roomKeys;
	vector<HouseKeepingLog> houseKeepingLogs;
};

enum RoomType {
	STANDARD, DELUX, SUITE
};

enum RoomStatus {
	BOOKED, RESERVED, CANCELLED, AVAILABLE, PENDING
};

class RoomKey {
	string keyId;
	string barcode;
	string issuedAt;
	bool isActive;
	bool isMaster;
public:
	void assignRoom(Room room);
};

class HouseKeepingLog {
	HouseKeeper houseKeeper;
	string description;
	string startDate;
	int durationInMins;
public:
	void addRoom(Room room);
};

class Person {
	string name;
	string phoneNumber;
	Account account;
};

class Account {
	string username;
	string password;

	AccountStatus status;
};

enum AccountStatus {
	ACTIVE, INACTIVE, CLOSED, BLOCKED
};

class HouseKeeper : public Person {
public:
	vector<Room> getRoomsServiced(string date);
};

class Guest : public Person {
	Search searchObj;
	Booking bookingObj;

public:
	vector<Room> getAllRoomBookings();
};

class Receptionist : public Person {
	Search searchObj;
	Booking bookingObj;
public:
	void checkInGuest(Guest guest, RoomBooking bookingInfo);
	void checkOutGuest(Guest guest, RoomBooking bookingInfo);
};

class Admin : public Person {
public:
	void addRoom(Room room);
	void deleteRoom(Room room);
	void editRoom(Room room);
};

class Search {
public:
	vector<Room> getAvailableRooms(RoomType roomType, string startDate, int duration);
	vector<Room> getBookedRooms();
};

class Booking {
public:
	RoomBooking createBooking(Guest guest);
	RoomBooking cancelBooking(Guest guest);
};

class RoomBooking {
	string bookingId;
	string startDate;
	int durationInDays;

	BookingStatus bookingStatus;
	vector<Guest> guests;
	vector<Room> rooms;

	BaseRoomCharge totalRoomCharges;
};

// Decorator patterm is used here to decorate the prices here
// interface
class BaseRoomCharge {
	virtual double getCost() = 0;
	virtual void setCost() = 0;
};

class RoomCharge : public BaseRoomCharge {
	double cost;
public:
	double getCost() {
		return cost;
	}
	void setCost(double cost) {
		this->cost = cost;
	}
};

class RoomServiceCharge : public BaseRoomCharge {
	double cost;
	BaseRoomCharge baseRoomCharge;
public:
	double getCost() {
		baseRoomCharge.setCost(baseRoomCharge.getCost() + cost);
		return baseRoomCharge.getCost();
	}
};

class InRoomPurchaseCharge : public BaseRoomCharge {
	double cost;
	BaseRoomCharge baseRoomCharge;
public:
	double getCost() {
		baseRoomCharge.setCost(baseRoomCharge.getCost + cost);
		return baseRoomCharge.getCost();
	}
};

