#include <random>

#include "../include/utilities.hpp"

int random(int begin_range, int end_range)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(begin_range, end_range);
    return distrib(gen);
}