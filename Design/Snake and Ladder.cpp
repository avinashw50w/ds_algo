/*
Entities: Game, Board, DiceService, Player, ScoreBoard, Snake, Ladder, Bonus, Danger
 */

class DiceService {
	int facevalue;
public:
	DiceService() : facevalue(0) {}
	static int roll() {
		srand(time(NULL));
		facevalue = 1 + rand() % 6;
		return facevalue;
	}
	int getFacevalue() { return facevalue; }
};

class Snake {
	int start;
	int end;
public:
	Snake(int s, int e) : start(s), end(e) {}
	int getStart() { return start; }
	int getEnd() { return end; }
};

class Ladder {
	int start;
	int end;
public:
	Ladder(int s, int e) : start(s), end(e) {}
	int getStart() { return start; }
	int getEnd() { return end; }
};

class Player {
	string id;
	string name;
public:
	Player(string name) {
		id = to_string(uuid);
		this->name = name;
	}
	string getId() { return id; }
	string getName() { return name; }
};

class Board {
	vector<Snake> snakes;
	vector<Ladder> ladders;
	int boardSize;
	map<string, int> playerPositions;

public:
	Board(int N) {
		boardSize = N;
	}
	int getSize() { return boardSize; }
	vector<Snake> getSnakes() { return snakes; }
	vector<Ladder> getLadder() { return ladders; }
	void setSnakes(vector<Snake> snakes) {
		this->snakes = snakes;
	}
	void setLadders(vector<Ladder> ladders) {
		this->ladders = ladders;
	}

	map<string, int> getPlayerPositions() { return playerPositions; }

	void setPlayerPositions(map<string, int> playerPositions) {
		this->playerPositions = playerPositions;
	}

	void updatePlayerPosition(Player player, int pos) {
		playerPosition[player->getId()] = pos;
	}

	void removePlayerPosition(Player player) {
		playerPosition.erase(player->getId());
	}
};

class SnakeAndLadder {
	Board board;
	int numberOfPlayers;
	queue<Player> players;
	bool isGameCompleted;

	int numberOfDices;
	bool shouldGameContinueTillLastPlayer;
	bool shouldAllowMultipleDiceRollsOnSix;

	static const int DEFAULT_BOARD_SIZE = 100;
	static const int DEFAULT_NO_OF_DICES = 1;
public:
	SnakeAndLadder(int boardSize) {
		board = new Board(boardSize);
		numberOfDices = DEFAULT_NO_OF_DICES;
	}
	void setNumberOfDices(int n) {
		numberOfDices = n;
	}
	void setShouldGameContinueTillLastPlayer(bool flag) {
		shouldGameContinueTillLastPlayer = flag;
	}
	void shouldAllowMultipleDiceRollsOnSix(bool flag) {
		shouldAllowMultipleDiceRollsOnSix = flag;
	}

	void setPlayers(vector<Player> players) {
		numberOfPlayers = players.size();
		map<string, int> playerPositions;
		for (Player p : players) {
			this->players.push(p);
			playerPositions[p.getId()] = 0;
		}
		board.setPlayerPositions(playerPositions);
	}

	void setSnakes(vector<Snake> snakes) {
		board.setSnakes(snakes);
	}

	void setLadders(vector<Ladder> ladders) {
		board.setLadders(ladders);
	}

	int getNewPositionIfSnakeOrLadder(int currPosition) {
		int prevPosition;
		vector<array<int,2>> allPositions;
		for (Snake s: board.getSnakes()) {
			allPositions.push_back({s.getStart(), s.getEnd()});
		}
		for (Ladder l: board.getLadders()) {
			allPositions.push_back({l.getStart(), l.getEnd()});
		}

		sort(allPositions.begin(), allPositions.end());
		for (int i = 0; i < allPositions.size(); i++) {
			if (currPostion == allPositions[i][0]) {
				currPostion = allPositions[i][1];
			}
		}

		return currPosition;
	}

	void movePlayer(Player player, int diceValue) {
		int oldPosition = board.getPlayerPositions()[player->getId()];
		int newPosition = oldPosition + diceValue;

		if (newPosition > board.getSize())
			newPosition = oldPosition;
		else
			newPosition = getNewPositionIfSnakeOrLadder(newPosition);

		board.updatePlayerPosition(player, newPosition);

		cout << player.getName() << " rolled a " << diceValue << " and moved from "
		     << oldPosition << " to " << newPosition << endl;
	}

	int getTotalValueAfterDiceRolls() {
		// Can use noOfDices and setShouldAllowMultipleDiceRollOnSix here to get
		// total value (Optional requirements)
		return DiceService.roll();
	}

	bool hasPlayerWon(Player player) {
		// Can change the logic a bit to handle special cases when there are more
		// than one dice (Optional requirements)
		int pos = board.getPlayerPositions()[player->getId()];
		return pos == board.getSize();
	}

	bool isGameCompleted() {
		// Can use shouldGameContinueTillLastPlayer to change the logic of
		// determining if game is completed (Optional requirements)
		// for that use players.size() == 0
		return players.size() < numberOfPlayers;
	}

	void startGame() {
		while (!isGameCompleted()) {
			int diceValue = getTotalValueAfterDiceRolls();
			Player currPlayer = players.top(); player.pop();

			movePlayer(currPlayer, diceValue);

			if (hasPlayerWon(currPlayer)) {
				cout << "Player " << currPlayer->getName() << " wins..." << endl;
				board.removePlayerPosition(currPlayer);
			}
			else {
				players.push(currPlayer);
			}
		}
	}
}