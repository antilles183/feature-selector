#pragma once
#include <vector>
#include "Node.h"
#include "Classifier.h"
#include "defs.h"
#include "Stopwatch.h"


class Validator
{

private:

    Stopwatch m_stopwatch;

public:

    // static double evaluate(const Node& node);
    static double evaluate(const FeatureSet& featureSet,
                           const DataSet& dataSet,
                           Classifier& classifier);


    static double random(const Node& node);
    static double random();

};

