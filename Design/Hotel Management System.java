/*
Types of user: Guest, Receptionist, Admin, HouseKeeping
1. receptionist is able to search rooms, check room availability, book rooms
2. Admin should be able to add, udpate and remove rooms
3. The system should send notification when a room becomes available.
 */

public enum RoomStyle {
  STANDARD, DELUXE, FAMILY_SUITE, BUSINESS_SUITE
}

public enum RoomStatus {
  AVAILABLE, RESERVED, OCCUPIED, NOT_AVAILABLE, BEING_SERVICED, OTHER
}

public enum BookingStatus {
  REQUESTED, PENDING, CONFIRMED, CHECKED_IN, CHECKED_OUT, CANCELLED, ABANDONED
}

public enum AccountStatus {
  ACTIVE, CLOSED, CANCELED, BLACKLISTED, BLOCKED
}

public enum AccountType {
  MEMBER, GUEST, MANAGER, RECEPTIONIST
}

public enum PaymentStatus {
  UNPAID, PENDING, COMPLETED, FILLED, DECLINED, CANCELLED, ABANDONED, SETTLING, SETTLED, REFUNDED
}

public class Address {
  private String streetAddress;
  private String city;
  private String state;
  private String zipCode;
  private String country;
}

// For simplicity, we are not defining getter and setter functions. The reader can
// assume that all class attributes are private and accessed through their respective
// public getter method and modified only through their public setter method.

public class Account {
  private String id;
  private String password;
  private AccountStatus status;

  public boolean resetPassword();
}

public abstract class Person {
  private String name;
  private Address address;
  private String email;
  private String phone;

  private Account account;
}


public class Guest extends Person {
  private int totalRoomsCheckedIn;

  public List<RoomBooking> getBookings();
}

public class Receptionist extends Person {
  public List<Member> searchMember(String name);
  public boolean createBooking();
}

public class Server extends Person {
  public boolean addRoomCharge(Room room, RoomCharge roomCharge);
}

public class HotelLocation {
  private String name;
  private Address location;

  public Address getRooms();
}

public class Hotel {
  private String name;
  private List<HotelLocation> locations;

  public boolean addLocation(HotelLocation location);
}

public interface Search {
  public static List<Room> search(RoomStyle style, Date startDate, int duration);
}

public class Room implements Search {
  private String roomNumber;
  private RoomStyle style;
  private RoomStatus status;
  private double bookingPrice;
  private boolean isSmoking;

  private List<RoomKey> keys;
  private List<RoomHouseKeeping> houseKeepingLog;

  public boolean isRoomAvailable();
  public boolean checkIn();
  public boolean checkOut();

  public static List<Room> search(RoomStyle style, Date startDate, int duration) {
    // return all rooms with the given style and availability
  }
}

public class RoomKey {
  private String keyId;
  private String barcode;
  private Date issuedAt;
  private boolean active;
  private boolean isMaster;

  public boolean assignRoom(Room room);
  public boolean isActive();
}

public class RoomHouseKeeping
 {
  private String description;
  private Date startDatetime;
  private int duration;
  private HouseKeeper houseKeeper;

  public boolean addHouseKeeping(Room room);
}

public class RoomBooking {
  private String reservationNumber;
  private Date startDate;
  private int durationInDays;
  private BookingStatus status;
  private Date checkin;
  private Date checkout;

  private int guestID;
  private Room room;
  private Invoice invoice;
  private List<Notification> notifications;

  public static RoomBooking fectchDetails(String reservationNumber);
}

public abstract class RoomCharge {
  public Date issueAt;
  public boolean addInvoiceItem(Invoice invoice);
}

public class Amenity extends RoomCharge {
  public String name;
  public String description;
}

public class RoomService extends RoomCharge {
  public boolean isChargeable;
  public Date requestTime;
}

public class KitchenService extends RoomCharge {
  public String description;
}

////////////////////////////////////////////////////////////////
public class Hotel {
	private String hotelId;
	private String name;
	private Address location;
	private List<Room> rooms;
};

public class Address {
	private String pincode;
	private String street;
	private String city;
	private String state;
	private String country;
};

public class Room {
	private String roomNumber;
	private String floor;
	private RoomType roomType;
	private RoomStatus roomStatus;
	private List<RoomKey> roomKeys;
	private List<HouseKeepingLog> houseKeepingLogs;

	public boolean isRoomAvailable();
};

enum RoomType {
	STANDARD, DELUX, SUITE
};

enum RoomStatus {
	BOOKED, RESERVED, CANCELLED, AVAILABLE, PENDING
};

public class RoomKey {
	private String keyId;
	private String barcode;
	private string issuedAt;
	private boolean isActive;
	private boolean isMaster;
	public void assignRoom(Room room);
};

public class HouseKeepingLog {
	private HouseKeeper houseKeeper;
	private String description;
	private String startDate;
	private int durationInMins;

	public void addRoom(Room room);
};

public class Person {
	private String name;
	private String phoneNumber;
	private Account account;
};

public class Account {
	private String username;
	private String password;
	private AccountStatus status;

	public boolean resetPassword();
};

enum AccountStatus {
	ACTIVE, INACTIVE, CLOSED, BLOCKED
};

public class HouseKeeper extends Person {
	public List<Room> getRoomsServiced(String date);
};

public class Guest extends Person {
	private Search searchObj;
	private Booking bookingObj;

	public List<RoomBooking> getBookings();
};

public class Receptionist extends Person {
	private Search searchObj;
	private Booking bookingObj;

	public void checkInGuest(Guest guest, RoomBooking bookingInfo);
	public void checkOutGuest(Guest guest, RoomBooking bookingInfo);
};

public class Admin extends public Person {
	public void addRoom(Room room);
	public void deleteRoom(Room room);
	public void editRoom(Room room);
};

public class Search {
	private List<Room> getAvailableRooms(RoomType roomType, String startDate, int duration);
	private List<Room> getBookedRooms();
};

public class Booking {
	public RoomBooking createBooking(Guest guest);
	public RoomBooking cancelBooking(Guest guest);
};

public class RoomBooking {
	private String bookingId;
	private String startDate;
	private int durationInDays;

	private BookingStatus bookingStatus;
	private List<Guest> guests;
	private List<Room> rooms;

	private BaseRoomCharge totalRoomCharges;
};

// Decorator patterm is used here to decorate the prices here
// interface
public interface BaseRoomCharge {
	private double getCost();
	private void setCost();
};

class RoomCharge implements BaseRoomCharge {
	private double cost;
	
	public double getCost() {
		return cost;
	}
	public void setCost(double cost) {
		this.cost = cost;
	}
};

class RoomServiceCharge implements BaseRoomCharge {
	private double cost;
	private BaseRoomCharge baseRoomCharge;

	public double getCost() {
		baseRoomCharge.setCost(baseRoomCharge.getCost() + cost);
		return baseRoomCharge.getCost();
	}
};

class InRoomPurchaseCharge implements BaseRoomCharge {
	private double cost;
	private BaseRoomCharge baseRoomCharge;
	
	public double getCost() {
		baseRoomCharge.setCost(baseRoomCharge.getCost + cost);
		return baseRoomCharge.getCost();
	}
};

