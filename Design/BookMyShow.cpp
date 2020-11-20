/*
1. list all the cities where affiliate Theatres are located
2. Each Theatre will have multiple Auditoriums and each auditorium will run
	only one movie at a time.
3. Each movie will have multiple shows.
4. Customers are able to search a movie by title, genre, language, release date etc.
5. Once a customer selects a movie, the service should show all the Theatres
	running that movie and its available shows.
6. Ticket Booking by customer for a show at a Theatre
7. display seating arrangement of a Theatre, and select multiple seats according to
	customer preference.
8. Customer should be able to distinguish between available seats and the booked ones.
 */

class BookingService {
	vector<Theatre> theatres;
public:
	vector<Movie> getMovies(string city, string date);
	vector<Theatre> getTheatres(string city);
};

class Theatre {
	string theatreId;
	string theatreName;
	Address address;

	vector<Auditorium> audiList;
public:
	map<string, Movie> getMovies(vector<string> dateList);
	map<string, Show> getShows(vector<string> dateList);
};

class Address {
	string pincode;
	string street;
	string city;
	string state;
	string country;
};

class Auditorium {
	string auditoriumId;
	string auditoriumName;

	int totalSeats;

	vector<Show> shows;

};

class Show {
	string showId;
	Movie movie;
	string startTime;
	string endTime;

	Theatre theatrePlayedAt;
	// the price and availability of seats will vary depending on the show
	vector<Seat> seats;
};

class Seat {
	string seatId;
	SeatStatus seatStatus;
	SeatType seatType;

	double price;
};

enum SeatType {
	ECONOMY, VIP, DELUX, OTHER
};

enum SeatStatus {
	BOOKED, AVAILABLE, RESERVED
};

class Movie {
	string movieId;
	string movieName;
	int durationInMins;
	Genre genre;
	string language;
	string releaseDate;

	map<string, vector<Show>> cityShowMap;
public:
	vector<Show> getShow(string city);
};

enum Genre {
	ACTION, ADVENTURE, SCI_FI, DRAMA, FANTASY, HORROR
};

class User {
	string userId;
	Search searchObj;
};

class SystemMember {
	Account account;
	string name;
	string email;
	Address address;
};

class Account {
	string userName;
	string password;
};

class Member : public SystemMember {
public:
	Booking makeBooking(Booking booking);
	vector<Booking> getBooking();
};

class Admin : public SystemMember {
public:
	bool addMovie(Movie movie);
	bool addShow(Show show);
};

class Search {
public:
	vector<Movie> searchByTitle(string title);
	vector<Movie> searchByGenre(Genre genre);
	vector<Movie> searchByLanguage(string language);
	vector<Movie> searchByReleaseDate(string releaseDate);
};

class Booking {
	string bookingId;
	string bookingDate;
	BookingStatus bookingStatus;
	double totalAmount;

	Member member;
	Show show;
	Auditorium auditorium;

	vector<Seat> seats;

	Payment paymentObj;
public:
	bool makePayment(Payment payment);
};

enum BookingStatus {
	CONFIRMED, PENDING, REQUESTED, CANCELLED
};

class Payment {
	double amount;
	string txnId;
	string paymentDate;
	PaymentMethod paymentMethod;
	PaymentStatus paymentStatus;
};

enum PaymentMethod {
	DEBIT, CREDIT, UPI, CASH
};

enum PaymentStatus {
	COMPLETED, PENDING, UNPAID, DECLINED, CANCELLED, REFUNDED
};

