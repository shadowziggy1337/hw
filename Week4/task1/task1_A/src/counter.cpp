#include "counter.hpp"

int countSubstring(const std::string& str, const std::string& sub) {
    if (sub.length() == 0) return 0;
    
    int count = 0;
    size_t subLength = sub.length();

    // Проходим по строке и проверяем вхождения подстроки
    for (size_t i = 0; i <= str.length() - subLength; ++i) {
        if (str.substr(i, subLength) == sub) {
            count++;
        }
    }
    
    return count; // Возвращаем общее количество вхождений
}
