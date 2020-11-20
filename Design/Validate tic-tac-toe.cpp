/*Validity of a given Tic-Tac-Toe board configuration
A Tic-Tac-Toe board is given after some moves are played, given that X plays first.
Find out if the given board is valid, i.e., is it possible to reach this board position
 after some moves or not.
Note that every arbitrary filled grid of 9 spaces isn’t valid e.g. a grid filled with
 3 X and 6 O isn’t valid situation because each player needs to take alternate turns.

IDEA: since X plays first, so at any time the count of X should be either equal to O or
1 greater than O.
algo:
1. countX == countO or countX == countO + 1
2. if O is in win position:
	- if X is also in win position, then not valid
	- countX != countO, then not valid
3. If X is in win position
	- if countX != countO + 1, then not valid
 */
int win[8][3] = {
	{0, 1, 2},
	{3, 4, 5},
	{6, 7, 8},
	{0, 3, 6},
	{1, 4, 7},
	{2, 5, 8},
	{0, 4, 8},
	{2, 4, 6}
};

bool isWin(vector<char> board, char c) {
	for (int i = 0; i < 8; ++i) {
		if (board[win[i][0]] == c and board[win[i][1]] == c and board[win[i][2]] == c)
			return true;
	}
	return false;
}

bool isValid(vector<char> board) {
	int countX = 0, countO = 0;
	for (char c : board) {
		if (c == 'X') countX++;
		else countO++;
	}

	if (countX == countO or countX == countO + 1) {
		if (isWin(board, 'O')) {
			if (isWin(board, 'X')) return false;
			return countX == countO;
		}

		if (isWin(board, 'X') and countX != countO + 1) return false;

		return true;
	}

	return false;
}
