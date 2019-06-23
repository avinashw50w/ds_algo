/* Assume you have a method isSubstring which checks if one word is a
 * substring of another. Given two strings, s1 and s2, write code to check if s2 is
 * a rotation of s1 using only one call to isSubstring (e.g. "waterbottle" is a
 * rotation of "erbottlewat").
 *
 * Source: Cracking the Coding Interview, page 74, question 1.8
 */

#include <iostream>
#include <cstring>

int is_substring(string haystack, string needle) {
	return haystack.find(needle);
}

bool solve(string s1, string s2) {

	string S = s1 + s1;

	return is_substring(S, s2);
}