#include <iostream>
bool is_palindrome(const std::string& str) {
    int left = 0;
    int right = str.length() - 1;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
        
        
        }
    
    return true;
}
std::cout << is_palindrome("madam") << std::endl;
std::cout << is_palindrome("hello") << std::endl;