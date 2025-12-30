#include "UI/Menu.h"
#include "core/Math/Math.h"
#include "App.h"
#include <iostream>
#include <vector>

int main(const int argc, const char *argv[])
{
    // App app;
    // app.run();
            
    // return 0;

    std::vector<float> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    for(const auto& vecs : vec)
        {std::cout << vecs << '\n';}

    std::cout << "\n\n\n";
    Math::addArray(vec, 1, true);

    for(const auto& vecs : vec)
        {std::cout << vecs << '\n';}
    

}