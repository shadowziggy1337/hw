#include "regex.hpp"
#include <regex>

bool isValidIPv6(const std::string& ipv6) {
    const std::regex pattern(R"(^(?:[0-9A-Fa-f]{1,4}:){7}[0-9A-Fa-f]{1,4}$)");

    return std::regex_match(ipv6, pattern);
}
