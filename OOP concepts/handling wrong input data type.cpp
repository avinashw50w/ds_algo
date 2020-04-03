/*How to handle wrong data type input
In C++, how do you handle wrong inputs? Like, if the program asks for an integer, when you type a character it
should be able to do something and then loop to repeat the input but the loop goes infinite when you input a 
character when an integer is need and vice versa.*/

/*The reason the program goes into an infinite loop is because std::cin's bad input flag is set due to the input failing. 
The thing to do is to clear that flag and discard the bad input from the input buffer.  */

//executes loop if the input fails (e.g., no characters were read)
while (cout << "Enter a number" && !(cin >> num)) {
    cin.clear(); //clear bad input flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
    cout << "Invalid input; please re-enter.\n";
}
