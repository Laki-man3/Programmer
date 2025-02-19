#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    if (s.length() == 3 && s.find('R') != string::npos && s.find('S') != string::npos && s.find('M') != string::npos) {
        size_t inR = s.find('R');
        size_t inM = s.find('M');

        if (inR < inM) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    else {
        cout << "Err" << endl;
    }
    return 0;
}
