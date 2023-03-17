#include <bits/stdc++.h>

using namespace std;

void print_multiline_text(string input, int max_length) {
    vector<string> lines;
    istringstream iss(input);
    string word, line;

    while (iss >> word) {
        if (line.length() + word.length() <= max_length) {
            line += word + " ";
        } else {
            lines.push_back(line);
            line = word + " ";
        }
    }
    lines.push_back(line);

    for (string l : lines) {
        cout << l << endl;
    }
}

int main() {
    string input;
    int max_length;
    cin >> max_length;
    cin>>input;
    print_multiline_text(input, max_length);
    return 0;
}
