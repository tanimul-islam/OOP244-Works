#include <cctype> // for std::tolower
#include "cstring.h"
#include "Utils.h"

using namespace sdds;

using namespace std;

namespace sdds {
    char* toLowerCase(const char* str) {
        if (str == nullptr)
            return nullptr;

        int length = strLen(str);
        char* lowercaseStr = new char[length + 1];

        for (int i = 0; i < length; i++) {
            lowercaseStr[i] = tolower(str[i]);
        }
        lowercaseStr[length] = '\0';

        return lowercaseStr;
    }
}
