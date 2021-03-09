/*Design a deck of cards*/

class Card {
	int facevalue;
	Suite suite;
public:
	Card(int facevalue, Suite suite) : facevalue(facevalue), suite(suite) {}
};

enum Suite {
	HEART, DIAMOND, SPADE, CLUB
};

class Deck {
	vector<Card> cards;
public:
	Deck() {
		for (int s = 0; s < 4; ++s) {
			for (int i = 0; i < 13; ++i) {
				cards.push_back(new Card(i + 1, s));
			}
		}
	}
}