#include <iostream>

using namespace std;

// Baian W. Kernighan
class Solution{
public:
    int hammingDistance(int x, int y) {
        int z = x^y;
        int distance = 0;
        while(z){
            ++distance;
            z = z&(z-1);
        }
        return distance;
    }
};
