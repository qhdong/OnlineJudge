#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

int main() {
    vector<string> words{"abc", "bca", "cab"};
    words.erase(remove_if(words.begin(), words.end(), [](string& w) {
            return w == "bca";
            }));
    copy(words.begin(), words.end(), ostream_iterator<string>(cout, " "));
    cout << endl;

    return 0;
}
