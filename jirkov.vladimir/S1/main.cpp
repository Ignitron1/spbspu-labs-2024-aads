#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "list.hpp"

int main() {
    jirkov::List<std::pair<std::string, std::vector<int>>> sequences;
    std::string name;
    while (std::cin >> name) {
        std::string input;
        std::getline(std::cin, input);

        std::vector<int> sequence;
        std::istringstream iss(input);
        int num;
        while (iss >> num) {
            sequence.push_back(num);
        }
        sequences.push_back({name, sequence});
    }
    std::cout << "\n";
    std::vector<int> sums;
    int maxlen = 0;
    for (const auto& pair : sequences) {
        maxlen = std::max(maxlen, static_cast<int>(pair.second.size()));
    }

    std::cout << "Объединенные последовательности:\n";
    for (int i = 0; i < maxlen; i++) {
        for (const auto& pair : sequences) {
            if (i < pair.second.size()) {
                std::cout << pair.second[i] << " ";
                if (i >= sums.size()) {
                    sums.push_back(pair.second[i]);
                } else {
                    sums[i] += pair.second[i];
                }
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Суммы элементов:\n";
    for (int sum : sums) {
        std::cout << sum << " ";
    }
    std::cout << std::endl;

    return 0;
}
