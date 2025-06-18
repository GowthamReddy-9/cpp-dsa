#include <iostream>
#include <string>
using namespace std;

int main() {
    // 1. Declaring and Initializing Strings
    string s1 = "Hello";
    string s2("World");
    string s3;
    cout << "s1: " << s1 << ", s2: " << s2 << endl;

    // 2. Taking Input with spaces
    cout << "Enter a sentence: ";
    getline(cin, s3);
    cout << "You entered: " << s3 << endl;

    // 3. Concatenation
    string combined = s1 + " " + s2;
    cout << "Combined: " << combined << endl;

    // 4. String Length
    cout << "Length of s3: " << s3.length() << endl;

    // 5. Accessing Characters
    cout << "First character of s3: " << s3[0] << endl;

    // 6. Modifying Characters
    s3[0] = 'X';
    cout << "Modified s3: " << s3 << endl;

    // 7. Substring
    string sub = s3.substr(0, 5); // first 5 chars
    cout << "Substring of s3: " << sub << endl;

    // 8. Searching in a String
    size_t found = s3.find("lo");
    if (found != string::npos) {
        cout << "'lo' found at index: " << found << endl;
    } else {
        cout << "'lo' not found." << endl;
    }

    // 9. Erase Part of String
    s3.erase(0, 2); // remove first 2 chars
    cout << "After erase: " << s3 << endl;

    // 10. Append
    s3.append(" is fun!");
    cout << "After append: " << s3 << endl;

    //11.Begin 
    cout<<"first char: "<<*s3.begin()<<endl;  //.begin() Actually returns a pointer pointing to first char in string.
	cout<<"last char: "<<*(s3.end()-1)<<endl; //but .end() returns a pointer pointing to the next char of last char in string.
    return 0;
}

