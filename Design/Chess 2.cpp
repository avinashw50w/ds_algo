class Chess {
	Board board;
	Player players[2];
	Player currentPlayer;
	GameStatus gameStatus;
	vector<Move> moveList;

	void changeTurn();

public:
	bool playerMove(CellPosition from, CellPosition to, Piece piece);
	bool endGame();
};

class Player {
	Account account;
	Color color;
	Time timeLeft;
};

class Account {
	string name;
	string email;
	string username;
	string password;
};

enum Color {
	WHITE, BLACK
};

class Time {
	int mins;
	int secs;
};

enum GameStatus {
	WHITE_WIN, BLACK_WIN, ACTIVE, PAUSED
};

class Board {
	vector<vector<Cell>> board;
public:
	Board(int N) {
		board = vector<vector<Cell>> (N, vector<Cell> (N));
		this->initializeBoard();
	}
	void initializeBoard();
	void updateBoard(Move move);
};

class Cell {
	Color color;
	CellPosition position;
	Piece piece;
};

class CellPosition {
	int x;
	int y;
};

class Move {
	Player player;
	Piece piece;
	Piece killedPiece;
	CellPosition startPosition;
	CellPosition endPosition;
};

class Piece {
	Color color;
public:
	virtual bool move(CellPosition from, CellPosition to) = 0;
	vector<Move> possibleMoves(CellPosition from);
	bool validateMove(CellPosition from, CellPosition to);
};

class King : public Piece {
public:
	bool move(CellPosition from, CellPosition to) {
		int x = abs(to.x - from.x);
		int y = abs(to.y - from.y);
		return x + y == 1 or x + y == 2;
	}
};

class Queen : public Piece {
public:
	bool move(CellPosition from, CellPosition to) {
		int x = abs(to.x - from.x);
		int y = abs(to.y - from.y);
		return ((x and y == 0) or (y and x == 0) or (x == y));
	}
};
class Bishop : public Piece {
public:
	bool move(CellPosition from, CellPosition to) {
		int x = abs(to.x - from.x);
		int y = abs(to.y - from.y);
		return x == y;
	}
};
class Knight : public Piece {
public:
	bool move(CellPosition from, CellPosition to) {
		int x = abs(to.x - from.x);
		int y = abs(to.y - from.y);
		return x * y == 2;
	}
};
class Rook : public Piece {
public:
	bool move(CellPosition from, CellPosition to) {
		int x = abs(to.x - from.x);
		int y = abs(to.y - from.y);
		return (x and y == 0) or (y and x == 0);
	}
};
class Pawn : public Piece {
public:
	bool move(CellPosition from, CellPosition to) {
		int x = abs(to.x - from.x);
		int y = abs(to.y - from.y);
		return x + y == 1 or x + y == 2;
	}
};