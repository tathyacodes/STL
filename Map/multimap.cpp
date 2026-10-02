#include <iostream>
#include <map>
#include <string>

int main() {
    std::multimap<std::string, int> scores;

    // Inserting multiple values for the same key "Alice"
    scores.insert({"Alice", 85});
    scores.insert({"Alice", 92});
    scores.insert({"Bob", 78});

    // Retrieve all values associated with "Alice"
    auto range = scores.equal_range("Alice");
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->first << ": " << it->second << "\n";
    }

    return 0;
}