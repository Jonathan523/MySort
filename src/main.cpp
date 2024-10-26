#include "MySort/TestPattern/DataConfig.hpp"
#include "MySort/TestPattern/TestPatterns.hpp"

// Change this function if your container has a specific way to construct
// with a vector.
testPatterns::CONTAINER_TYPE testPatterns::constructContainer(
    const std::vector<testPatterns::ELEMENT_TYPE>& vec)
{
    return testPatterns::CONTAINER_TYPE(vec.begin(), vec.end());
}

int main()
{
    testPatterns::generateData();
    testPatterns::MergeSort().test();
    testPatterns::MergeSort_Natural().test();
    testPatterns::QuickSort_Lomuto().test();
    testPatterns::QuickSort_Lomuto_TailRecOpt().test();
    testPatterns::QuickSort_Lomuto_Rand().test();
    testPatterns::QuickSort_Lomuto_Rand_Duplicated().test();
    testPatterns::QuickSort_Lomuto_Rand_Duplicated_Insertion().test();
    testPatterns::QuickSort_Hoare().test();
    testPatterns::QuickSort_Hoare_rand().test();
    testPatterns::QuickSort_Hoare_insertion().test();
    testPatterns::HeapSort().test();
    testPatterns::BubbleSort().test();
    testPatterns::BubbleSort_Stop().test();
    testPatterns::BubbleSort_NarrowBoundary().test();
    testPatterns::InsertionSort().test();
    testPatterns::SelectionSort().test();
    ////system("pause");
}