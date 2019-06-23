
vector<string> split(string s, char delimiter) {
	stringstream ss(s);
	vector<string> res;
	string token;

	while(getline(ss, token, delimiter)) res.push_back(token);

	return res;
}

//////////////////////////////////////////
// if the delimiter is a space, then u can also use this


vector<string> split(string s, char delimiter) {
	stringstream ss(s);
	vector<string> res;
	string token;

	while(ss >> token) res.push_back(token);

	return res;
}