#include <iostream>
#include "ValidAnagram.h" 
#include "../common/testlib.h"

using namespace std;

int main()
{
    Solution solution;
    ASSERT_TRUE(solution.isAnagram("", ""));
    ASSERT_TRUE(solution.isAnagram("anagram", "nagaram"));
    ASSERT_FALSE(solution.isAnagram("rat", "car"));
    ASSERT_FALSE(solution.isAnagram("hello", "helloh"));
    ASSERT_FALSE(solution.isAnagram("hellohh", "hellooh"));
    
    return 0;
}

