// https://chatgpt.com/share/6ab7a41b-c78c-83e9-9f30-cc35c102f00c

// if the string contains only numbers, string s = "12345";  int x = stoi(s); converts it into integer
// long long x = stoll(s);

// for a single character, char c = '7';  int x = c - '0';

// manual way:
// string s = "12345";
// int x = 0;
// for (char c : s) {
//     x = x * 10 + (c - '0');
// }

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {

    // =========================================================
    // 1. CREATING STRINGS
    // =========================================================

    string s = "hello";
    string t("world");

    // n copies of a character
    string a(5, 'x');       // "xxxxx"

    cout << "s = " << s << endl;
    cout << "t = " << t << endl;
    cout << "a = " << a << endl;


    // =========================================================
    // 2. SIZE / LENGTH
    // =========================================================

    cout << "\n--- Size ---\n";

    cout << s.size() << endl;       // 5
    cout << s.length() << endl;     // 5

    // size() and length() do the same thing for string


    // =========================================================
    // 3. ACCESSING CHARACTERS
    // =========================================================

    cout << "\n--- Character Access ---\n";

    cout << s[0] << endl;            // h
    cout << s.at(1) << endl;         // e

    // front() = first character
    // back()  = last character

    cout << s.front() << endl;       // h
    cout << s.back() << endl;        // o


    // Modifying a character
    s[0] = 'H';

    cout << s << endl;               // Hello


    // =========================================================
    // 4. EMPTY
    // =========================================================

    cout << "\n--- Empty ---\n";

    cout << s.empty() << endl;       // 0 (false)

    string emptyString;

    cout << emptyString.empty() << endl;  // 1 (true)


    // =========================================================
    // 5. PUSH_BACK
    // =========================================================

    cout << "\n--- push_back ---\n";

    string p = "abc";

    p.push_back('d');

    cout << p << endl;               // abcd


    // =========================================================
    // 6. POP_BACK
    // =========================================================

    cout << "\n--- pop_back ---\n";

    p.pop_back();

    cout << p << endl;               // abc


    // =========================================================
    // 7. STRING CONCATENATION
    // =========================================================

    cout << "\n--- Concatenation ---\n";

    string x = "Hello";
    string y = "World";

    string z = x + " " + y;

    cout << z << endl;               // Hello World

    x += " World";

    cout << x << endl;               // Hello World


    // =========================================================
    // 8. SUBSTR
    // =========================================================

    cout << "\n--- substr ---\n";

    string str = "abcdef";

    // substr(starting_index, number_of_characters)

    cout << str.substr(2, 3) << endl;    // cde

    // If length is not specified,
    // everything from that index to the end is taken

    cout << str.substr(2) << endl;       // cdef


    // =========================================================
    // 9. FIND
    // =========================================================

    cout << "\n--- find ---\n";

    string word = "hello world";

    cout << word.find("world") << endl;  // 6
    cout << word.find('o') << endl;      // 4

    // If not found:
    if (word.find("xyz") == string::npos) {
        cout << "xyz not found\n";
    }

    // string::npos means "not found"


    // =========================================================
    // 10. RFIND
    // =========================================================

    cout << "\n--- rfind ---\n";

    string banana = "banana";

    cout << banana.rfind('a') << endl;   // 5

    // find()  -> first occurrence
    // rfind() -> last occurrence


    // =========================================================
    // 11. ERASE
    // =========================================================

    cout << "\n--- erase ---\n";

    string e = "abcdef";

    // erase(starting_index, number_of_characters)

    e.erase(2, 2);

    cout << e << endl;                   // abef

    // Erase everything from index 2 onward

    e.erase(2);

    cout << e << endl;                   // ab


    // =========================================================
    // 12. INSERT
    // =========================================================

    cout << "\n--- insert ---\n";

    string ins = "helo";

    // Insert "l" at index 3

    ins.insert(3, "l");

    cout << ins << endl;                 // hello


    // =========================================================
    // 13. REPLACE
    // =========================================================

    cout << "\n--- replace ---\n";

    string rep = "abcdef";

    // replace(start, length, new_string)

    rep.replace(2, 2, "XYZ");

    cout << rep << endl;                 // abXYZef


    // =========================================================
    // 14. RESIZE
    // =========================================================

    cout << "\n--- resize ---\n";

    string r = "hello";

    r.resize(3);

    cout << r << endl;                   // hel

    r.resize(6, 'x');

    cout << r << endl;                   // helxxx


    // =========================================================
    // 15. STRING COMPARISON
    // =========================================================

    cout << "\n--- Comparison ---\n";

    string s1 = "apple";
    string s2 = "banana";

    if (s1 == s2)
        cout << "Equal\n";
    else
        cout << "Not equal\n";


    if (s1 < s2)
        cout << "apple comes before banana\n";


    // compare()

    cout << s1.compare(s2) << endl;

    // < 0  -> s1 comes before s2
    //   0  -> equal
    // > 0  -> s1 comes after s2


    // =========================================================
    // 16. ITERATORS
    // =========================================================

    cout << "\n--- Iterators ---\n";

    string it = "hello";

    for (auto i = it.begin(); i != it.end(); i++) {
        cout << *i << " ";
    }

    cout << endl;

    // Reverse iterators

    for (auto i = it.rbegin(); i != it.rend(); i++) {
        cout << *i << " ";
    }

    cout << endl;


    // =========================================================
    // 17. RANGE-BASED FOR LOOP
    // =========================================================

    cout << "\n--- Range Based Loop ---\n";

    for (char c : it) {
        cout << c << " ";
    }

    cout << endl;


    // =========================================================
    // 18. REVERSE
    // =========================================================

    cout << "\n--- reverse ---\n";

    string rev = "hello";

    reverse(rev.begin(), rev.end());

    cout << rev << endl;                 // olleh


    // =========================================================
    // 19. SORT
    // =========================================================

    cout << "\n--- sort ---\n";

    string sorted = "dcba";

    sort(sorted.begin(), sorted.end());

    cout << sorted << endl;              // abcd


    // =========================================================
    // 20. COUNT
    // =========================================================

    cout << "\n--- count ---\n";

    string countString = "banana";

    int numberOfA =
        count(countString.begin(), countString.end(), 'a');

    cout << numberOfA << endl;            // 3


    // =========================================================
    // 21. CHARACTER FUNCTIONS
    // =========================================================

    cout << "\n--- Character Functions ---\n";

    char c = 'A';

    cout << char(tolower(c)) << endl;     // a
    cout << char(toupper('b')) << endl;   // B

    cout << isalpha('A') << endl;         // 1
    cout << isdigit('5') << endl;         // 1
    cout << isalnum('5') << endl;         // 1
    cout << isspace(' ') << endl;         // 1


    // =========================================================
    // 22. STRING -> NUMBER
    // =========================================================

    cout << "\n--- String to Number ---\n";

    string numString = "12345";

    int num = stoi(numString);

    cout << num << endl;                  // 12345


    // long long
    string bigNumber = "123456789";

    long long big = stoll(bigNumber);

    cout << big << endl;


    // =========================================================
    // 23. NUMBER -> STRING
    // =========================================================

    cout << "\n--- Number to String ---\n";

    int number = 123;

    string numberString = to_string(number);

    cout << numberString << endl;         // "123"


    // =========================================================
    // 24. CLEAR
    // =========================================================

    cout << "\n--- clear ---\n";

    string clearString = "hello";

    clearString.clear();

    cout << clearString << endl;          // empty

    cout << clearString.empty() << endl;  // 1


    // =========================================================
    // 25. FIND USING STL find()
    // =========================================================

    cout << "\n--- STL find ---\n";

    string findString = "hello";

    auto it2 = find(findString.begin(),
                    findString.end(),
                    'e');

    if (it2 != findString.end()) {
        cout << "Character found\n";
    }


    return 0;
}