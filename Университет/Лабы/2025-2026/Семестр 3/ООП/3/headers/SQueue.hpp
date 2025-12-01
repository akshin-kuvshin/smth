// author: Danila "akshin_" Axyonov

#ifndef SQUEUE__
#define SQUEUE__

#include "SBase.hpp"
#include <queue>
#include <initializer_list>

namespace Lab3
{


class SQueue : public SBase {
private:
    std::queue<int> q_;

public:
    SQueue(int n = 0, int min = 0, int max = 0);
    SQueue(const std::queue<int>& q) : q_(q) {}
    SQueue(const std::initializer_list<int>& l);
    void assign_rand(int n = 0, int min = 0, int max = 0);
    void operator=(const std::queue<int>& q);
    void operator=(const std::initializer_list<int>& l);
    int get() override;
};


}

#endif
