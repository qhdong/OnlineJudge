#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_loopword(const string& a, const string& b) {
    auto aa = a + a;
    return aa.find(b) != string::npos;
}

void get_words(istream& in, vector<string>& words, int n) {
    string word;
    while (n-- > 0 && in >> word) {
        words.push_back(word);
    }
}

int count_loopwords(vector<string>& words) {
    auto it = words.begin();
    while (it != words.end()) {
        string curr_word = *it;
        words.erase(remove_if(it + 1, words.end(), [&curr_word](string& w) {
                bool remove = is_loopword(curr_word, w);
                return remove;
        }));
        it = words.begin() + 1;
    }
    return words.size();
}

int main() {
    int n;
    while (cin >> n) {
        vector<string> words;
        get_words(cin, words, n);
        cout << count_loopwords(words) << endl;
    }

    return 0;
}
