#pragma once
#include <set>
#include <iostream>

class Node
{
private:
    
    std::set<int> _featureSet;
    double _accuracy;

public:
    Node();
    Node(std::set<int> s);
    Node(const Node& node);
    ~Node();

    bool insert(int n);

    double accuracy();

    
    // OPERATOR OVERLOADS
    friend std::ostream& operator<<(std::ostream& os, const Node& rhs);

};

