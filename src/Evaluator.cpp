#include "Evaluator.h"
#include <random>


double Evaluator::random(const Node& node)
{
    // this is a stub. do nothing with node just return random percentage
    // https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution

    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);

    return dis(gen);
}


double Evaluator::random()
{
    Node node;
    return Evaluator::random(node);
    
}