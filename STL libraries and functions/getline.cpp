/*By default, leading whitespace (carriage returns, tabs, spaces) is ignored by cin.

Given:
int i;
float fl;
std::cin >> fl;
std::cin >> i;
And you type: 3.14<return>42<return>
3.14 is read into fl . The carriage return (newline) following the 3.14 is still sitting on the input buffer.
Since std::cin ignores whitespace, the first return is "eaten" by std::cin >> i . Then the integer 42 is read into i and the second return is left on the input buffer.
std::cin.getline() can run into problems when used with std::cin >> var.

getline can be provided a third argument--a "stop" character. This character ends getline's input. The character is eaten and the string is terminated. Example:
std::cin.getline(str, 100, '|')
If std::cin.getline() is not provided a "stop" character as a third argument, it will stop when it reaches a newline.
Given:
  float fl;
  std::cin >> fl;
  char str[101]
  std::cin.getline(str, 101);
And you type: 3.14<return>
3.14 is read into fl . The newline following the 3.14 is still sitting on the input buffer.
std::cin.getline(str, 101) immediately processes the newline that is still on the input buffer. str becomes an empty string.
The illusion is that the application "skipped" the std::cin.getline() statement.
The solution is to add std::cin.ignore(); immediately after the first std::cin statement. This will grab a character off of the input buffer (in this case, newline) and discard it.

std::cin.ignore() can be called three different ways:

No arguments: A single character is taken from the input buffer and discarded:
std::cin.ignore(); //discard 1 character
One argument: The number of characters specified are taken from the input buffer and discarded:
std::cin.ignore(33); //discard 33 characters
Two arguments: discard the number of characters specified, or discard characters up to and including the specified delimiter (whichever comes first):
std::cin.ignore(26, '\n'); //ignore 26 characters or to a newline, whichever comes first*/

int main() {
	int a;
	float b;
	string s;
	cin>>a;
	cin>>b;
	cin.ignore();
	getline(cin,s);

	cout <<a<<endl;
	cout <<b<<endl;
	cout << s;

	return 0;
}