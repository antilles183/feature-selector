#pragma once
#include <set>
#include <iostream>

class Node
{
private:
    
    std::set<int> _featureSet;
    double _accuracy;

public:
    Node(double acc = -1);
    Node(std::set<int> s);
    Node(const Node& node);
    ~Node();

    bool insert(int n);

    double accuracy() const;
    void setAccuracy(double acc);

    
    // OPERATOR OVERLOADS
    friend std::ostream& operator<<(std::ostream& os, const Node& rhs);
    bool operator<(const Node& rhs) const;
    bool operator>(const Node& rhs) const;

};

