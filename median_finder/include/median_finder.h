#ifndef MEDIAN_FINDER_H_
#define MEDIAN_FINDER_H_

#include <queue>
#include <vector>

class MedianFinder
{
private:
    /* 
    * These two heaps, the first one being a max heap, while the second - a min heap,
    * represent the split in data where the left half contains only numbers, whose maximum
    * is less than (or equal) to the minimum of the right half. Hence, we get an ascending
    * ordering of all the numbers, so we can easily find the median.
    * */
    std::priority_queue<int> leftHalf_;
    std::priority_queue<int, std::vector<int>, std::greater<int>> rightHalf_;

    /* 
    * This function makes sure that the difference in size between the two halves is at most 1
    * and if it is not, it rebalances them by transferring the top of the larger heap to the other
    * */
    void rebalance();
public:
    MedianFinder();
    /* 
    * This function adds the passed number to one of the halves depending on the comparison with
    * the tops of the two heaps after making sure the corresponding sizes are at least 1
    * */
    void addNumber(int number);
    /* 
    * This function calculates the median by comparing the sizes of the two halves and either
    * returning the top of the bigger heap in case their sizes differ, or the average between
    * the two heap tops if their sizes are the same
    * */
    double getMedian();
};

#endif /* MEDIAN_FINDER_H_ */