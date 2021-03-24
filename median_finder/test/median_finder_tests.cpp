#include "median_finder.h"
#include <gtest/gtest.h>

struct MedianFinderTests
    : public ::testing::Test
{
    MedianFinder medFinder;

    virtual void SetUp() override {
        MedianFinder medFinder = MedianFinder();
    }
};

TEST_F(MedianFinderTests, TestEmpty) {
    EXPECT_EQ(medFinder.getMedian(), 0);
}

TEST_F(MedianFinderTests, TestSingleNumber) {
    medFinder.addNumber(5);
    EXPECT_EQ(medFinder.getMedian(), 5.0);
}

TEST_F(MedianFinderTests, TestEvenSize) {
    medFinder.addNumber(5);
    medFinder.addNumber(10);
    EXPECT_EQ(medFinder.getMedian(), 7.5);

    medFinder.addNumber(30);
    medFinder.addNumber(20);
    EXPECT_EQ(medFinder.getMedian(), 15.0);
}

TEST_F(MedianFinderTests, TestOddSize) {
    medFinder.addNumber(5);
    medFinder.addNumber(3);
    medFinder.addNumber(10);
    EXPECT_EQ(medFinder.getMedian(), 5.0);

    medFinder.addNumber(20);
    medFinder.addNumber(1);
    EXPECT_EQ(medFinder.getMedian(), 5.0);

    medFinder.addNumber(6);
    medFinder.addNumber(7);
    EXPECT_EQ(medFinder.getMedian(), 6.0);
}