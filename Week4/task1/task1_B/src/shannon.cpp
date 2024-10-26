#include <cmath>
#include "shannon.hpp"

double calculateShannonEntropy(const std::string& input) {
    int charCount[256] = {0};

    // Подсчет количества каждого символа
    for (char c : input) {
        charCount[static_cast<unsigned char>(c)]++;
    }

    double entropy = 0.0;
    double totalChars = input.length();

    // Расчет энтропии
    for (int count : charCount) {
        if (count > 0) {
            double probability = static_cast<double>(count) / totalChars;
            entropy -= probability * log2(probability);  // Формула Шеннона
        }
    }

    return entropy;  // Возврат рассчитанной энтропии
}
