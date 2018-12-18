#include <iostream>
#include "Trie.h"
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    Trie t;
    t.put("cat", "feline animal");
    t.put("rat", "eaten by cat");

    cout << t.get("rat") << endl;
    cout << t.get("cow") << endl;

    t.put("rat", "a rodent");

    cout << t.get("rat") << endl;

    return 0;
}