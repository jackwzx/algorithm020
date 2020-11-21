//
//  main.cpp
//  plusOne
//
//  Created by jackwangliang on 2020/11/21.
//  Copyright © 2020 jackwangliang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        for (int i= (int)digits.size()-1; i>=0; i--) {
            
            if (digits[i] != 9) {
                digits[i]++;
                return digits;
            }
            else {
                digits[i] = 0;
            }
            
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
