/* validate IPV4 and IPV6 addresses
IPV4 rules:
contains 4 numbers in the range [0-255] separated by a .
leading zeroes are not allowed
eg: 47.29.111.88

use regex to solve this:
regex for a no in the range [0-255] is
[0-9] | [1-9][0-9] | 1[0-9][0-9] | 2[0-4][0-9] | 25[0-5]
0-9       10-99			100-199 	 200-249      250-255
IPV6 rules:
contains 8 hexadecimal numbers each of 8 bytes. eg: 2409:4064:a17:ac16:802e:f472:fbc5:4e4e
*/


bool checkIPV4(string IPV4) {
	regex r("(([0-9] | [1-9][0-9] | 1[0-9][0-9] | 2[0-4][0-9] | 25[0-5])\\.){3}([0-9] | [1-9][0-9] | 1[0-9][0-9] | 2[0-4][0-9] | 25[0-5])");

	return regex_match(IPV4, r);
}

bool checkIPV6(string IPV6) {
	regex r("(([0-9a-fA-F]){1-4}//:){7}(([0-9a-fA-F]){1-4})");

	return regex_match(IPV6, r);
}