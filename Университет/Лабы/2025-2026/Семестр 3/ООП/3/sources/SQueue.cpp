// author: Danila "akshin_" Axyonov

#include "SQueue.hpp"
#include <cstdlib>
#include <queue>
#include <initializer_list>
#include <stdexcept>

namespace Lab3
{


SQueue::SQueue(int n, int min, int max) {
    if (n < 0)
        throw std::domain_error("Length of randomly generated queue can't be a negative number.");
    if (min > max)
        throw std::domain_error("Minimum value of numbers in queue can't be greater than the similar maximum one.");
    
    while (n--)
        q_.push(min + rand() % (max - min + 1));
}

SQueue::SQueue(const std::initializer_list<int>& l) {
    for (auto l_i : l)
        q_.push(l_i);
}

void SQueue::assign_rand(int n, int min, int max) {
    if (n < 0)
        throw std::domain_error("Length of randomly generated queue can't be a negative number.");
    if (min > max)
        throw std::domain_error("Minimum value of numbers in queue can't be greater than the similar maximum one.");
    
    q_ = std::queue<int>();
    while (n--)
        q_.push(min + rand() % (max - min + 1));
}

void SQueue::operator=(const std::initializer_list<int>& l) {
    q_ = std::queue<int>();
    for (auto l_i : l)
        q_.push(l_i);
}

int SQueue::get() {
    if (q_.empty())
        return EOF;
    int x = q_.front();
    q_.pop();
    return x;
}


}
