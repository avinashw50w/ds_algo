class Dice {
    static roll() {
        const facevalue = 1 + (Math.floor(Math.random() * 10) % 6);
        return facevalue;
    }
}

class Player {
    constructor(id, name) {
        this.id = id;
        this.name = name;
    }
    getId() {
        return this.id;
    }
    getName() {
        return this.name;
    }
}

class Snake {
    constructor(start, end) {
        this.start = start;
        this.end = end;
    }
    getStart() {
        return this.start;
    }
    getEnd() {
        return this.end;
    }
}

class Ladder {
    constructor(start, end) {
        this.start = start;
        this.end = end;
    }
    getStart() {
        return this.start;
    }
    getEnd() {
        return this.end;
    }
}

class Player {
    constructor(name) {
        this.id = uuid();
        this.name = name;
    }
    getId() {
        return this.id;
    }
    getName() {
        return this.name;
    }
}

class Board {
    constructor(boardSize) {
        this.boardSize = boardSize;
        this.players = [];
        this.snakes = [];
        this.ladders = [];
        this.playerPositions = {}; // {player id, board position}
    }
    setPlayers(players) {
        this.players = players;
    }
    setSnakes(snakes) {
        this.snakes = snakes;
    }
    setLadders(ladders) {
        this.ladders = ladders;
    }
    setPlayerPositions(playerPositions) {
        this.playerPositions = playerPositions;
    }
    getPlayerPosition(player) {
        return this.playerPositions[player.getId()];
    }
    updatePlayerPostion(player, newPostion) {
        return (this.playerPositions[player.getId()] = newPosition);
    }
    removePlayerPosition(player) {
        this.playerPositions.delete(player.getId());
    }
}

class SnakeAndLadder {
    board;
    players; // queue of players

    constructor(boardSize) {
        this.board = new Board(boardSize);
    }
    setSnakes(snakes) {
        this.board.setSnakes(snakes);
    }
    setLadders(ladders) {
        this.board.setLadders(ladders);
    }
    setPlayers() {
        this.players = new Queue(players);
    }
    getNewPositionIfSnakeOrLadder(currentPosition) {
        const allPostions = [];
        this.board.getSnakes.every((snake) =>
            allPostions.push([snake.getStart(), snake.getEnd()]),
        );
        this.board.getLadders.every((ladder) =>
            allPostions.push([ladder.getStart(), ladder.getEnd()]),
        );

        sort(allPostions, (a, b) => a[0] - b[0]);

        let newPosition = currentPosition;
        for (let i = 0; i < allPostions.length; i++) {
            if (newPosition === allPostions[i][0]) {
                newPosition = allPostions[i][1];
            }
        }
        return newPosition;
    }

    movePlayer(player, diceValue) {
        const currPosition = this.board.getPlayerPosition(player);
        let newPosition = currentPosition + diceValue;
        if (newPostion > this.board.getSize()) {
            newPosition = currPosition;
        } else {
            newPosition = getNewPositionIfSnakeOrLadder(newPosition);
        }

        this.board.updatePlayerPosition(player, newPosition);
    }

    hasPlayerWon(player) {
        return this.board.getPlayerPosition(player) === this.board.getSize();
    }

    isGameCompleted() {
        return this.players.size() === 0;
    }

    startGame() {
        while (!isGameCompleted()) {
            const player = this.players.front();
            this.players.pop();
            const diceValue = Dice.roll();

            movePlayer(player, diceValue);

            if (hasPlayerWon(player)) {
                console.log(`player ${player.getName()} has won`);
                this.board.removePlayerPosition(player);
            } else {
                this.players.push(player);
            }
        }
    }
}
