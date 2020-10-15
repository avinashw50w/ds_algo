/*design the OOP classes for a chess game.*/

class Piece {
	bool isWhite;
	bool isKilled;
public:
	Piece(bool white) {
		this->setWhite(white);
		this->setKilled(false);
	}
	bool isWhite() {
		return this->isWhite;
	}
	void setWhite(bool white) {
		this->isWhite = white;
	}
	bool isKilled() {
		return this->isKilled;
	}
	void setKilled(bool killed) {
		this->isKilled = killed;
	}
	bool isSafeMove(Piece start, Piece end) {
		Piece a = start.getPiece();
		Piece b = end.getPiece();
		return (b.isWhite() != a.isWhite())
		       and (b.getX() >= 0 and b.getX() < 8 and b.getY() >= 0 and b.getY() < 8);
	}
	pair<int, int> getCoordinateDifference(Box start, Box end) {
		int x = abs(end.getPiece().getX() - start.getPiece().getX());
		int y = abs(end.getPiece().getY() - start.getPiece().getY());
		return { x, y };
	}

	virtual bool canMove(Board board, Box start, Box end) = 0;
	virtual string getType() = 0;
};

class Box {
	Piece piece;
	int x;
	int y;

public:
	Box(int x, int y, Piece piece) {
		this->setX(x);
		this->setY(y);
		this->setPiece(piece);
	}

	void setX(int x) {
		this->x = x;
	}
	int getX() {
		return this->x;
	}
	void setY(int y) {
		this->y = y;
	}
	void getY() {
		return this->y;
	}
	void setPiece(Piece piece) {
		this->piece = piece;
	}
	void getPiece() {
		return this->piece ? this->piece : NULL;
	}
};

class Board {
	vector<vector<Box>> board;
public:
	Board() {
		this->initialiseBoard();
	}

	void initialiseBoard() {
		board = vector<vector<Box>> (8, vector<Box> (8));
		board[0][0] = new Box(0, 0, new Rook(true));
		board[0][1] = new Box(0, 1, new Knight(true));
		board[0][2] = new Box(0, 2, new Bishop(true));
		board[0][3] = new Box(0, 3, new King(true));
		board[0][4] = new Box(0, 4, new Queen(true));
		board[0][5] = new Box(0, 5, new Bishop(true));
		board[0][6] = new Box(0, 6, new Knight(true));
		board[0][7] = new Box(0, 7, new Rook(true));

		for (int i = 0; i < 8; ++i) {
			board[1][i] = new Box(0, i, new Pawn(true));
		}

		board[7][0] = new Box(7, 0, new Rook(false));
		board[7][1] = new Box(7, 1, new Knight(false));
		board[7][2] = new Box(7, 2, new Bishop(false));
		board[7][4] = new Box(7, 3, new Queen(false));
		board[7][3] = new Box(7, 4, new King(false));
		board[7][5] = new Box(7, 5, new Bishop(false));
		board[7][6] = new Box(7, 6, new Knight(false));
		board[7][7] = new Box(7, 7, new Rook(false));

		for (int i = 0; i < 8; ++i) {
			board[6][i] = new Box(6, i, new Pawn(false));
		}
	}
};

class King: public Piece {
public:
	bool canMove(Board board, Box start, Box end) {
		if (!isSafeMove(start, end)) return false;
		pair<int, int> coord = this->getCoordinateDifference(Box start, Box end);
		int x = coord.first;
		int y = coord.second;

		return (x + y == 1 or x + y == 2);
	}

	string getType() { return "KING"; }
};

class Queen: public Piece {
public:
	bool canMove(Board board, Box start, Box end) {
		if (!isSafeMove(start, end)) return false;
		pair<int, int> coord = this->getCoordinateDifference(Box start, Box end);
		int x = coord.first;
		int y = coord.second;

		return ((x != 0 and y == 0) or (x == 0 and y != 0) or abs(x - y) == 0);
	}

	string getType() { return "QUEEN"; }
};

class Knight: public Piece {
public:
	bool canMove(Board board, Box start, Box end) {
		if (!isSafeMove(start, end)) return false;
		pair<int, int> coord = this->getCoordinateDifference(Box start, Box end);
		int x = coord.first;
		int y = coord.second;
		// (x, y) : (1, 2), (2, 1)
		return x * y == 2;
	}

	string getType() { return "KNIGHT"; }
};

class Bishop: public Piece {
	bool canMove(Board board, Box start, Box end) {
		if (!isSafeMove(start, end)) return false;
		pair<int, int> coord = this->getCoordinateDifference(Box start, Box end);
		int x = coord.first;
		int y = coord.second;
		// (x, y) : diagonal
		return x == y;
	}

	string getType() { return "BISHOP"; }
};

class Rook: public Piece {
	bool canMove(Board board, Box start, Box end) {
		if (!isSafeMove(start, end)) return false;
		pair<int, int> coord = this->getCoordinateDifference(Box start, Box end);
		int x = coord.first;
		int y = coord.second;
		// (x, y) : horizontal / vertical
		return (x != 0 and y == 0) or (x  == 0 and y != 0);
	}

	string getType() { return "ROOK"; }
};

class Pawn: Public Piece {
	bool canMove(Board board, Box start, Box end) {
		if (!isSafeMove(start, end)) return false;
		pair<int, int> coord = this->getCoordinateDifference(Box start, Box end);
		int x = coord.first;
		int y = coord.second;
		// (x, y) : forward/ diagonal left and right
		return (x + y == 1 or x + y == 2);
	}

	string getType() { return "PAWN"; }
};

class Player {
	bool whiteSide;
	Person person;
public:
	Player(Person person, bool whiteSide) {
		this->setWhiteSide(whiteSide);
		this->setPerson(person);
	}
	void setWhite(bool whiteSide) {
		this->whiteSide = whiteSide;
	}
	bool isWhiteSide() {
		return this->whiteSide;
	}
	void setPerson(Person p) {
		this->person = p;
	}
	Person getPerson() {
		return this->person;
	}
};

class Game {
	Players players[2];
	Board board;
	Player currentTurn;
	GameStatus gameStatus;

public:
	Game() {
		this->initialise(Player p1, Player p2) {
			if (p1.isWhiteSide()) {
				currentTurn = p1;
			}
			else {
				currentTurn = p2;
			}
		}
	}

	bool playerMove(int startX, int startY, int endX, int endY) {
		Box start = board[startX][startY];
		Box end = board[endX][endY];

		Piece sourcePiece = start.getPiece();
		Piece destPiece = end.getPiece();

		if (sourcePiece.canMove(board, start, end)) {
			if (destPiece) {
				destPiece.setKilled(true);
				if (destPiece.getType == "KING") {
					gameStatus.setStatus("WINNER");
				}
			}
			end.setPiece(sourcePiece);
			start.setPiece(NULL);

			if (currentTurn == player[0]) {
				currentTurn = player[1];
			}
			else {
				currentTurn = player[0];
			}

			return true;
		}

		return false;
	}
};
