#include "median_finder.h"
#include <iostream>

MedianFinder::MedianFinder() {
    leftHalf_ = std::priority_queue<int>();
    rightHalf_ = std::priority_queue<int, std::vector<int>, std::greater<int>>();
}

void MedianFinder::addNumber(int number)
{
    if ((leftHalf_.size() == 0 && rightHalf_.size() == 0)
        || (leftHalf_.size() > 0 && number < leftHalf_.top()))
        leftHalf_.push(number);
    else
        rightHalf_.push(number);
    rebalance();
}

double MedianFinder::getMedian()
{
    if (leftHalf_.size() == 0 && rightHalf_.size() == 0) {
        return 0.0;
    } else if (leftHalf_.size() == rightHalf_.size()) {
        return (((double)leftHalf_.top() + rightHalf_.top()) / 2);
    } else {
        return (leftHalf_.size() > rightHalf_.size()) ? leftHalf_.top() : rightHalf_.top();
    }
}

void MedianFinder::rebalance()
{
    if (leftHalf_.size() >= rightHalf_.size() + 2) {
        rightHalf_.push(leftHalf_.top());
        leftHalf_.pop();
    } else if (rightHalf_.size() >= leftHalf_.size() + 2) {
        leftHalf_.push(rightHalf_.top());
        rightHalf_.pop();
    }
}