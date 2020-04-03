/* Write a method to replacee all spaces in a string with '%20'. You may assume that
 * the string has sufficient space at the end of the string to hold the additional
 * characters, and that you are given the "true" length of the string. (Note: if
 * implementing in Java, please use a character array so that you can perform this
 * operation in place).
 * EXAMPLE
 * Input:  "Mr John Smith"
 * Output: "Mr%20John%20Smith"
 *
 * Source: Cracking the Coding Interview, page 73, question 1.4
 */

char *solve(char *str) {
	if(str == NULL) return NULL;

	int new_len = 0, i;

	for(i = 0; str[i]; ++i) 
		if(str[i] == ' ') new_len += 3;
		else new_len++;

	if(new_len == 0 or new_len == i) 
		return str;

	str[new_len] = '\0';
	int j = new_len-1;

	for(--i; i > 0; --i) {
		if(str[i] == ' ') {
			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '%';
		}
		else
			str[j--] = str[i];
	}

	if(str[i] == ' ') {
		str[j--] = '0';
		str[j--] = '2';
		str[j--] = '%';
	}
	else
		str[j--] = str[i];


	return str;
}

