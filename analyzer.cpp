#include <iostream>
#include <list>
#include "StringData.h"
int linearSearch(std::vector<std::string> container, std::string element);
int binarySearch(std::vector<std::string> container, std::string element);

// The main method
int main() {
    std::vector<std::string> container = getStringData();
    long long before;
    long long after;

    std::string test1 = "not_here";
    std::cout << "\nLinear Search for 'not_here':";
    before = systemTimeNanoseconds();
    std::cout << "\nThe index is:" << linearSearch(container, test1);
    after = systemTimeNanoseconds();
    std::cout << "\nThe time taken is: " << (after - before);
    std::cout << "\nBinary Search for 'not_here':";
    before = systemTimeNanoseconds();
    std::cout << "\nThe index is: " << binarySearch(container, test1);
    after = systemTimeNanoseconds();
    std::cout << "\nThe time taken is: " << (after - before);

    std::string test2 = "mzzzz";
    std::cout << "\n\nLinear Search for 'mzzzz':";
    before = systemTimeNanoseconds();
    std::cout << "\nThe index is:" << linearSearch(container, test2);
    after = systemTimeNanoseconds();
    std::cout << "\nThe time taken is: " << (after - before);
    std::cout << "\nBinary Search for 'mzzzz':";
    before = systemTimeNanoseconds();
    std::cout << "\nThe index is: " << binarySearch(container, test2);
    after = systemTimeNanoseconds();
    std::cout << "\nThe time taken is: " << (after - before);

    std::string test3 = "aaaaa";
    std::cout << "\n\nLinear Search for 'aaaaa':";
    before = systemTimeNanoseconds();
    std::cout << "\nThe index is:" << linearSearch(container, test3);
    after = systemTimeNanoseconds();
    std::cout << "\nThe time taken is: " << (after - before);
    std::cout << "\nBinary Search for 'aaaaa':";
    before = systemTimeNanoseconds();
    std::cout << "\nThe index is: " << binarySearch(container, test3);
    after = systemTimeNanoseconds();
    std::cout << "\nThe time taken is: " << (after - before);

    return 0;
}

// Function definition
int linearSearch(std::vector<std::string> container, std::string element) {
    for (int i = 0; i<= container.size(); i++) {
        if (element == container[i]) {
            return i;
        }
    }
    return -1;
}

int binarySearch(std::vector<std::string> container, std::string element) {
    int high = container.size() - 1;
    int low = 0;
    while (low <= high) {
        int mid = ((low + high)/2);
        if (element <container[mid]) {
            high = mid - 1;
        }
        else if (element > container[mid]) {
            low = mid + 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}