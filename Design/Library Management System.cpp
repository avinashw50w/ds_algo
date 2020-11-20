/*
1. Any user be it any Library member or a customer should be able to search a book
	by its title, author, subject, category etc.
2. Each book will have a unique ID and a rank to uniquely identify the location of the book
3. There can be multiple copies of a single book and a library member should be able to
	check-out or reserve any copy.
4. The system should be able to retreive info about who took a book and what are the
	books checked-out a libaray member.
5. There should be a limit on how many books a member can check-out.
6. There should be a limit on how many days a customer can keep a book.
7. There should be fine if book is returned after the due date.
8. Members should be able to reserve books that are not currently available.
9. The system should be able to send notifications when a reserved book becomes available
	and when a book is not returned within the due date.
10. Each book and member card will have a unique barcode. The system should be able to read
	the barcode from the books and member's library card.
 */

class Library {
	string name;
	Address address;
	vector<BookItem> books;
};

class Address {
	string pincode;
	string street;
	string city;
	string state;
	string country;
};

class Book {
	string bookId;
	string title;
	vector<string> authors;
	BookType bookType;
};

class BookItem : public Book {
	string barcode;
	string publicationDate;
	Rack rackLocation;
	BookStatus bookStatus;
	BookFormat bookFormat;
	string issueDate;
};

enum BookType {
	SCI_FI, ACTION, ADVENTUR, DRAMA, HORROR, ROMANTIC
};

enum BookFormat {
	HARD_COVER, PAPERBACK, JOURNAL, NEWSPAPER
};

enum BookStatus {
	ISSUED, AVAILABLE, RESERVED, LOST
};

class Rack {
	int number;
	string locationId;
};

class Person {
	string firstName;
	string lastName;
};

class Author : Person {
	vector<Book> publishedBooks;
public:
	vector<Book> getPublishedBooks();
};

class SystemUser : Person {
	string email;
	string contactNumber;
	Account account;
};

class Member : SystemUser {
	int totalCheckedOutBooks;
	Search searchObj;

	BookIssueService issueService;
};

class Librarian : SystemUser {
	Search searchObj;
	BookIssueService issueService;

public:
	bool addBookItem(BookItem bookItem);
	BookItem deleteBookItem(Barcode barcode);
	BookItem editBookItem(BookItem bookItem);
};

class Account {
	int accountId;
	string username;
	string password;
};

class Search {
public:
	vector<BookItem> searchByTitle(string title);
	vector<BookItem> searchByAuthor(string author);
	vector<BookItem> searchByType(BookType bookType);
	vector<BookItem> searchByPublicationDate(string publicationDate);
};

class BookIssueService {
	FineService fineService;
public:
	BookReservationDetail getBookReservationDetail(BookItem bookItem);
	void updateBookReservationDetail(BookReservationDetail bookReservationDetail);
	BookReservationDetail reserveBook(BookItem bookItem, SystemUser user);
	BookIssueDetail issueBook(BookItem bookItem, SystemUser user);
	BookIssueDetail renewBook(BookItem bookItem, SystemUser user);
	void returnBook(BookItem bookItem, SystemUser user);
};

class BookLending {
	BookItem book;
	string startDate;
	SystemUser user;
};

class BookReservationDetail : public BookLending {
	BookReservationStatus reservationStatus;
};

class BookIssueDetail : public BookLending {
	string dueDate;
};

class Fine {
	double amount;
	string fineDate;
	SystemUser user;
	BookItem book;
};

class FineService {
public:
	Fine calculateFine(BookItem book, SystemUser user, int days);
};

