/*design the OOP classes for a chess game.*/

enum Color {
	WHITE, BLACK
};

enum PieceType {
	KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN
};

class Piece {
	Color color;
	PieceType type;
	bool isKilled;
public:
	Piece(Color color) {
		this->setColor(color);
		this->setKilled(false);
	}
	Color getColor() {
		return this->color;
	}
	void setColor(Color color) {
		this->color = color;
	}
	bool isKilled() {
		return this->isKilled;
	}
	void setKilled(bool killed) {
		this->isKilled = killed;
	}
	bool isSafeMove(Box start, Box end) {
		Piece a = start.getPiece();
		Piece b = end.getPiece();
		return (b.isWhite() != a.isWhite())
		       and (end.getX() >= 0 and end.getX() < 8 and end.getY() >= 0 and end.getY() < 8);
	}
	pair<int, int> getCoordinateDifference(Box start, Box end) {
		int x = abs(end.getPiece().getX() - start.getPiece().getX());
		int y = abs(end.getPiece().getY() - start.getPiece().getY());
		return { x, y };
	}

	virtual bool canMove(Board board, Box start, Box end) = 0;
	virtual PieceType getType() = 0;
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

	PieceType getType() { return KING; }
};

class Queen: public Piece {
public:
	bool canMove(Board board, Box start, Box end) {
		if (!isSafeMove(start, end)) return false;
		pair<int, int> coord = this->getCoordinateDifference(Box start, Box end);
		int x = coord.first;
		int y = coord.second;

		return ((x != 0 and y == 0) or (x == 0 and y != 0) or (x == y));
	}

	PieceType getType() { return QUEEN; }
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

	PieceType getType() { return KNIGHT; }
};

class Bishop: public Piece {
public:
	bool canMove(Board board, Box start, Box end) {
		if (!isSafeMove(start, end)) return false;
		pair<int, int> coord = this->getCoordinateDifference(Box start, Box end);
		int x = coord.first;
		int y = coord.second;
		// (x, y) : diagonal
		return x == y;
	}

	PieceType getType() { return BISHOP; }
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

	PieceType getType() { return ROOK; }
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

	PieceType getType() { return PAWN; }
};

class Player {
	Color color;
	Person person;
public:
	Player(Person person, Color color) {
		this->setColor(color);
		this->setPerson(person);
	}
	void setColor(Color color) {
		this->color = color;
	}
	Color getColor() {
		return this->color;
	}
	void setPerson(Person p) {
		this->person = p;
	}
	Person getPerson() {
		return this->person;
	}
};

enum GameStatus {
	ACTIVE, PAUSED, WHITE_WIN, BLACK_WIN
};

class Game {
	Players players[2];
	Board board;
	Player currentPlayer;
	GameStatus gameStatus;

	void changeTurn() {
		if (currentPlayer == player[0]) {
			currentPlayer = player[1];
		}
		else {
			currentPlayer = player[0];
		}
	}
	void setStatus(GameStatus status) {
		this->gameStatus = status;
	}

public:
	Game() {
		this->initialise(Player p1, Player p2) {
			if (p1.getColor() == WHITE) {
				currentPlayer = p1;
			}
			else {
				currentPlayer = p2;
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
				if (destPiece.getType() == KING) {
					if (this->currentPlayer == p1)
						this->setStatus(WHITE_WIN);
					else
						this->setStatus(BLACK_WIN);
				}
			}
			end.setPiece(sourcePiece);
			start.setPiece(NULL);

			this->changeTurn();

			return true;
		}

		return false;
	}
};
