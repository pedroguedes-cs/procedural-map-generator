#include <random>

#include "../include/utilities.hpp"

int random(int begin_range, int end_range)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(begin_range, end_range);
    return distrib(gen);
}


int next_valid_size(int biggest_dimension)
{
    return (int) pow(2, ceil(log2(biggest_dimension - 1))) + 1;
}