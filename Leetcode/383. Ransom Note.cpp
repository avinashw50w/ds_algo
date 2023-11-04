/*Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.
Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false

Example 3:
Input: ransomNote = "aa", magazine = "aab"
Output: true*/

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> f;
    for (char c : magazine) f[c]++;

    for (char c : ransomNote) {
        if (!f[c]) return false;
        f[c]--;
    }

    return true;
}