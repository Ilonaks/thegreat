#include <iostream>
#include <vector>
#include <algorithm>

int maximumProduct(std::vector<int>& num) {

    std::sort(num.begin(), num.end());

    int n = num.size();
    int maxProduct = std::max(num[n - 1] * num[n - 2] * num[n - 3],
        num[0] * num[1] * num[n - 1]);

    return maxProduct;
}

int main () {
    std::vector<int> num1 = {1, 2, 3, -1, -2};
    std::vector<int> num2 = {-10, -10, 5, 2};
    std::vector<int> num3 = {-1, -2, 0, 3, 4, 5};

    std::cout << "Output 1:" <<maximumProduct(num1) << std::endl;
    std::cout << "Output 2:" <<maximumProduct(num2) << std::endl;
    std::cout << "Output 3:" <<maximumProduct(num3) << std::endl;

    return 0;
}