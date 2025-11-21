#include <vector>


class Layer
{
    public:
    virtual void forward(const std::vector<float>& input, std::vector<float>& output) const = 0;

    virtual void backward(const std::vector<float>& input, std::vector<float>& output) const = 0;

    protected:
    std::vector<float> weights;
    std::vector<float> biases;
    int input_size;
    int output_size;


};