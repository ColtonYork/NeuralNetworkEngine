#include "UIutils.h"



namespace UIutils{
std::string to_upper(const std::string& s) 
{
    std::string copy = s;
    std::transform(copy.begin(), copy.end(), copy.begin(),
                   [](unsigned char c){ return std::toupper(c); });
    return copy;
}

std::string ActivationFunctionToString(ActivationFunction af)
{
    switch (af)
        {
            case ActivationFunction::None:
                return "NONE";

                case ActivationFunction::Sigmoid:
                return "Sigmoid";

            case ActivationFunction::Relu:
                return "Relu";
        }

    return "error";
}

std::string LayerTypeToString(LayerType lt)
{
    switch (lt)
    {
        case LayerType::None:
            return "NONE";

        case LayerType::Dense:
            return "Dense";

        case LayerType::Recurrent:
            return "Recurrent";
    }


    return "error";
}
}