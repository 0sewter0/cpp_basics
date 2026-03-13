#include <iostream>
#include <string>
#include <cctype>

std::string sanitize_string(const std::string& input) {
    std::string cleaned;
    for (char c : input) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            cleaned += std::tolower(static_cast<unsigned char>(c));
        }
    }
    return cleaned;
}

bool is_palindrome(const std::string& str) {
    std::string cleaned = sanitize_string(str);
    if (cleaned.empty()) {
        return false;  // No letters = not a palindrome
    }
    int left = 0;
    int right = static_cast<int>(cleaned.length()) - 1;
    while (left < right) {
        if (cleaned[left] != cleaned[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    std::string input;
    char continue_choice;
    
    std::cout << "Advanced Palindrome Checker (case-insensitive, ignores non-letters)" << std::endl << std::endl;
    
    do {
        std::cout << "Enter a string to check: ";
        std::getline(std::cin, input);
        
        if (input.empty()) {
            std::cout << "No input provided. Skipping." << std::endl << std::endl;
            continue;
        }
        
        std::string cleaned = sanitize_string(input);
        bool result = is_palindrome(input);
        std::cout << "  \"" << input << "\" ";
        if (result) {
            std::cout << "IS ";
        } else {
            std::cout << "is NOT ";
        }
        std::cout << "a palindrome.";
        if (cleaned.empty()) {
            std::cout << " (no letters found)";
        }
        std::cout << std::endl << std::endl;
        
        std::cout << "Check another? (y/n): ";
        std::cin >> continue_choice;
        std::cin.ignore(1000, '\n');  // Clear input buffer
    } while (std::tolower(continue_choice) == 'y' || continue_choice == 'Y');
    
    std::cout << "Thanks for using Palindrome Checker!" << std::endl;
    return 0;
}
