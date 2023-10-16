#include <iostream>
#include <vector>
#include <string>
#include <chrono>

inline long long systemTimeNanoseconds() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::time_point_cast<std::chrono::milliseconds>(
                    std::chrono::system_clock::now()
            ).time_since_epoch()
    ).count();
}

inline std::vector<std::string>& getStringData() {
    static std::vector<std::string> stringDataSet;
    if (stringDataSet.size() == 0) {
        char tempSet[6] = " ";
        for (tempSet[0] = 'a'; tempSet[0] <= 'z'; tempSet[0]++)
            for (tempSet[1] = 'a'; tempSet[1] <= 'z'; tempSet[1]++)
                for (tempSet[2] = 'a'; tempSet[2] <= 'z'; tempSet[2]++)
                    for (tempSet[3] = 'a'; tempSet[3] <= 'z'; tempSet[3]++)
                        for (tempSet[4] = 'a'; tempSet[4] <= 'z'; tempSet[4]++)
                            stringDataSet.push_back(std::string(tempSet));
    }
    return stringDataSet;
}

int binary_search(std::vector<std::string> bob, std::string element);
int linear_search(std::vector<std::string> bob, std::string element);

int main() {
    std::vector<std::string> string_data = getStringData();
    long long time_a = systemTimeNanoseconds();
    linear_search(string_data, "not_here");
    long long time_b = systemTimeNanoseconds();
    std::cout << "Time for linear search of not_here: " << time_b - time_a << "\n";
    std::cout << "Position of not_here from linear search: " << linear_search(string_data, "not_here") << "\n";
    time_a = systemTimeNanoseconds();
    binary_search(string_data, "not_here");
    time_b = systemTimeNanoseconds();
    std::cout << "Time for binary search of not_here " << time_b - time_a << "\n";
    std::cout << "Position of not_here from binary search: " << binary_search(string_data, "not_here") << "\n";
    time_a = systemTimeNanoseconds();
    linear_search(string_data, "mzzzz");
    time_b = systemTimeNanoseconds();
    std::cout << "Time for linear search of mzzzz: " << time_b - time_a << "\n";
    std::cout << "Position of mzzzz from linear search: " << linear_search(string_data, "mzzzz") << "\n";
    time_a = systemTimeNanoseconds();
    binary_search(string_data, "mzzzz");
    time_b = systemTimeNanoseconds();
    std::cout << "Time for binary search of mzzzz " << time_b - time_a << "\n";
    std::cout << "Position of mzzzz from binary search: " << binary_search(string_data, "mzzzz") << "\n";
    time_a = systemTimeNanoseconds();
    linear_search(string_data, "aaaaa");
    time_b = systemTimeNanoseconds();
    std::cout << "Time for linear search of aaaaa: " << time_b - time_a << "\n";
    std::cout << "Position of aaaaa from linear search: " << linear_search(string_data, "aaaaa") << "\n";
    time_a = systemTimeNanoseconds();
    binary_search(string_data, "aaaaa");
    time_b = systemTimeNanoseconds();
    std::cout << "Time for binary search of aaaaa " << time_b - time_a << "\n";
    std::cout << "Position of aaaaa from binary search: " << binary_search(string_data, "aaaaa") << "\n";
}

int binary_search(std::vector<std::string> bob, std::string element) {
    int low = 0;
    int high = bob.size() - 1;
    int mid = 0;
    while (low <= high) {
        mid = (high+low) / 2;
        if (bob.at(mid) < element) {
            low = mid + 1;
        }
        else if (bob.at(mid) > element) {
            high = mid - 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

int linear_search(std::vector<std::string> bob, std::string element) {
    for(int i=0; i<bob.size(); i++) {
        if (bob.at(i) == element) {
            return i;
        }
    }
    return -1;
}