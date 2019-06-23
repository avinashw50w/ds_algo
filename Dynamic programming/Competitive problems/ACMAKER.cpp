/*The sadists who design problems for ACM programming contests often like to include the abbre- viation “ACM” somewhere 
in their problem descriptions. Thus, in years past, the World Finals has had problems involving “Apartment Construction 
Management,” the “Atheneum of Culture and Movies,” the “Association of Cover Manufacturers,” “ACM Airlines,” the 
“Association for Computa- tional Marinelife,” and even an insect named “Amelia Cheese Mite.” However, the number of 
word combinations beginning with A, C, and M that make sense is finite and the problem writers are starting to run 
out of ideas (it’s hard to think of problems about “Antidisestablishmentarianistic Chthonian Metalinguistics”). 
Fortunately, modern culture allows more flexibility in designing abbreviations — consider, for example:

GDB — Gnu DeBugger
LINUX — either “LINus’s UniX” or “LINUs’s miniX” or “Linux Is Not UniX”
SNOBOL — StriNg Oriented symBOlic Language
SPITBOL — SPeedy ImplemenTation of snoBOL
The rules used in these examples seem to be:

Insignificant words (such as “of”, “a”, “the”, etc.) are ignored.
The letters of the abbreviation must appear, in the correct order, as an ordered sublist of the letters in the 
significant words of the phrase to be abbreviated.
At least one letter of the abbreviation must come from every significant word 
(multiple occurrences of a letter are, of course, treated as distinct).
Of course these rules are often broken in real life. For instance, RADAR is an abbreviation for 
“RAdio Detecting And Ranging”. Under our rules (assuming that “and” is an insignificant word), 
this would not be a valid abbreviation (however, RADR or RADRAN or DODGING would be valid). 
You have been asked to take a list of insignificant words and a list of abbreviations and 
phrases and to determine in how many ways each abbreviation can be formed from the corresponding 
phrase according to the rules above.

Input
The input file consists of multiple scenarios. Each scenario begins with an integer 100 >= n >= 1 
followed by n insignificant words, all in lower case, one per line with no extra white space. 
(A line containing 0 indicates end of input.) Following this are one or more test cases for this 
scenario, one per line, followed by a line containing the phrase “LAST CASE”. Each line containing 
a test case begins with an abbreviation (uppercase letters only) followed by a phrase 
(lowercase letters and spaces only). The abbreviation has length at least 1 and the phrase 
contains at least one significant word. No input line (including abbreviation, phrase, and spaces) 
will contain more than 150 characters. Within these limits, however, abbreviations and phrase words may be any length.

Output
For each test case, output the abbreviation followed by either

is not a valid abbreviation

or

can be formed in i ways

where i is the number of different ways in which the letters of the abbreviation may be assigned to the 
letters in the phrase according to the rules above. The value of i will not exceed the range of a 32-bit signed integer.

Example
Input:
2
and
of
ACM academy of computer makers
RADAR radio detection and ranging
LAST CASE
2
a
an
APPLY an apple a day
LAST CASE
0

Output:
ACM can be formed in 2 ways
RADAR is not a valid abbreviation
APPLY can be formed in 1 ways*/

int main() {
    for (;;) {
        int n; cin >> n; if (n == 0) return 0;
        set<string> insignificant;
        for (int i = 0; i < n; i++) {
            string s; cin >> s; insignificant.insert(s);
        }
        for (;;) {
            string acro; cin >> acro; cin.ignore();
            string phrase; getline(cin, phrase);
            if (phrase == "CASE") break;
            istringstream iss(phrase);
            vector<string> words;
            for (;;) {
                string word; iss >> word;
                if (word == "") break;
                if (insignificant.find(word) == insignificant.end()) {
                    words.push_back(word);
                }
            }
            // dp[i][j] is the number of ways to use the first i words and the
            // first j letters of the acronym
            int dp[151][151]; memset(dp, 0, sizeof(dp));
            dp[0][0] = 1;
            int dp2[151][151];
            for (int i = 0; i < words.size(); i++) {
                for (int j = 0; j < acro.length(); j++) {
                    // How many letters of this acronym do we want to use for word[i] ?
                    int mx = min(acro.length() - j, words[i].length());
                    for (int k = 0; k <= words[i].length(); k++) {
                        dp2[k][0] = 1;
                    }
                    for (int k = 1; k <= mx; k++) {
                        dp2[0][k] = 0;
                    }
                    for (int k = 0; k < words[i].length(); k++) {
                        for (int m = 0; m < mx; m++) {
                            dp2[k+1][m+1] = dp2[k][m+1]; // not taking the (j+m)th letter of acronym
                            if (words[i][k] == tolower(acro[j+m])) {
                                dp2[k+1][m+1] += dp2[k][m];
                            }
                        }
                    }
                    for (int k = 1; k <= mx; k++) {
                        dp[i+1][j+k] += dp[i][j] * dp2[words[i].length()][k];
                    }
                }
            }
            if (dp[words.size()][acro.length()] == 0) {
                cout << acro << " is not a valid abbreviation" << endl;
            } else {
                cout << acro << " can be formed in "
                     << dp[words.size()][acro.length()] << " ways" << endl;
            }
        }
    }
}

/*Given a line that starts with acronym and has bunch of insignificant words. How many ways the acronym can be formed using 
significant (not insignificant) words so that each word has at least one char contributing to the acronym.

E.g. If insignificant words = {"and", "of"}
and line = "ACM academy of computer makers"
Then ACM is the acronym and after removing the insignificant word, we are left with

words[] = {“academy”, “computer”, “makers”}

Here we can form the acronym in 2 ways. Because there are two a’s in academy and thus ACM could mean 
“Academy of Computer Makers” or “acAdemy of Computer Makers”.

Since we have to make sure we include each word, it will be wise to use dp that counts number of ways 
i words can be used to form the acronym when j chars of the acronym are used.

Since we are limited to words, we will need an additional block to keep track of number of ways the characters 
from each word can contribute to the overall acronym. Also, we need to be careful that we don’t use more letters 
from the word then size of acronym – number of remaining words.

One more observation that we can make is that each character in a word will multiply the ways the acronym can be 
used for that i,j pair.*/