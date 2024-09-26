#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>

// Function to convert a string from any base to an integer
long long decodeY(const std::string& value, int base) {
    return std::stoll(value, nullptr, base);
}

// Lagrange interpolation to solve for the constant term (c)
double lagrangeInterpolation(const std::vector<std::pair<int, long long>>& points) {
    double c = 0.0;
    int k = points.size();

    for (int i = 0; i < k; i++) {
        double term = points[i].second;  // Y value
        for (int j = 0; j < k; j++) {
            if (i != j) {
                term *= (0 - points[j].first) / double(points[i].first - points[j].first);
            }
        }
        c += term;
    }
    return c;
}

int main() {
    // Simplified test case input
    std::map<int, std::pair<int, std::string>> input = {
        {1, {10, "4"}},  // x = 1, base = 10, y = 4
        {2, {2, "111"}},  // x = 2, base = 2, y = 111 in base 2 (7)
        {3, {10, "12"}},  // x = 3, base = 10, y = 12
        {6, {4, "213"}}   // x = 6, base = 4, y = 213 in base 4
    };

    int n = 4;  // Number of points
    int k = 3;  // Degree of the polynomial + 1

    std::vector<std::pair<int, long long>> points;

    // Read and decode all the points
    for (const auto& entry : input) {
        int x = entry.first;  // X value
        int base = entry.second.first;  // Base value
        std::string value = entry.second.second;  // Encoded Y value
        long long y = decodeY(value, base);  // Decode Y value
        points.push_back({x, y});
    }

    // Calculate the constant term using Lagrange interpolation
    double c = lagrangeInterpolation(points);

    std::cout << "Constant term (c) = " << c << std::endl;

    return 0;
}
