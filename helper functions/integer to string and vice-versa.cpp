typedef uint64_t ll;

ll toInteger(string &s) {
    ll v;  
    stringstream str(s);
    str >> v;
    return v;
}

string toString(ll v) {
    stringstream str;
    str << v;
    return str.str();
}