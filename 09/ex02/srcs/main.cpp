#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    clock_t start_err = clock();
    if (PmergeMe::errorHandling(argc, argv))
        return -1;
    clock_t stop_err = clock();
    double interval_err = static_cast<double>(stop_err - start_err) / CLOCKS_PER_SEC * 1000000;

    clock_t start_l = clock();
    std::list<int> l;
    PmergeMe::stockNums(l, argc, argv);
//    PmergeMe::mySort(l);
    PmergeMe::mergeInsertionsort(l);
    clock_t stop_l = clock();
    double interval_l = static_cast<double>(stop_l - start_l + interval_err);

    clock_t start_d = clock();
    std::deque<int> d;
    PmergeMe::stockNums(d, argc, argv);
//    PmergeMe::mySort(d);
    PmergeMe::mergeInsertionsort(d);
    clock_t stop_d = clock();
    double interval_d = static_cast<double>(stop_d - start_d + interval_err);

    std::cout << "Before :";
    for (int i = 1; i < argc; i++)
        std::cout << " " << argv[i];
    std::cout << std::endl;
    std::cout << "After  :";
    std::list<int>::iterator it_d;
    for (it_d = l.begin(); it_d != l.end(); ++it_d)
        std::cout << " " << *it_d;
    std::cout << '\n';
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::list  : " << interval_l << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << interval_d << " us" << std::endl;

    return 0;
}
