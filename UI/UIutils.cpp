#include "UIutils.h"


std::string to_upper(const std::string& s) 
{
    std::string copy = s;
    std::transform(copy.begin(), copy.end(), copy.begin(),
                   [](unsigned char c){ return std::toupper(c); });
    return copy;
}