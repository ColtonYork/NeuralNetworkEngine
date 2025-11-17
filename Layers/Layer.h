#include <vector>


class Layer
{
    public:
    virtual void forward(const std::vector<float>& input, std::vector<float>& output) = 0;

    virtual void backward(const std::vector<float>& input, std::vector<float>& output) = 0;



};