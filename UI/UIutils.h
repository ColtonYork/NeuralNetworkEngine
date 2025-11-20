#include <string>
#include <algorithm>
#include "../core/enums/enums.h"


namespace UIutils
{
    std::string to_upper(const std::string& s);

    std::string ActivationFunctionToString(ActivationFunction af);

    std::string LayerTypeToString(LayerType lt);
}