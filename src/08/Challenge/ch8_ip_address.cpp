// C++ Code Challenges, LinkedIn Learning

// Challenge #8: IP Address Validation
// Write an application that reads a string from the terminal and responds with a message indicating whether the string is a valid IP address or not.
// Assume decimal IP addresses.
// 158.25.0.33
// All numbers between 0 and 255.

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

void test_is_valid_ip();
void assert_and_print(std::string &ip, bool expected);

// is_valid_ip()
// Summary: This function validates an IP address.
// Arguments:
//           ip: The string to analyze with a potential ip address.
// Returns: A boolean value. True for valid ip addresses, false otherwise.
bool is_valid_ip(std::string ip){

    std::vector<std::string> octets;
    std::string temp;
    size_t pos = 0;
    
    // Validate for 4 parts separated by dots

    // Split the string into octets
    while ((pos = ip.find('.')) != std::string::npos) {
        temp = ip.substr(0, pos);
        octets.push_back(temp);
        ip.erase(0, pos + 1);
    }
    octets.push_back(ip); // Add the last octet after the last dot
    
    // Check if we have exactly 4 octets
    if (octets.size() != 4) return false;
    
    // Validate each octet
    for (const auto& octet : octets) {
        // Check if octet is empty
        if (octet.empty()) return false;
        
        // Check if octet contains only digits
        for (char c : octet) {
            if (!isdigit(c)) return false;
        }

        // Convert octet to integer and check range
        int value = std::stoi(octet);
        if (value < 0 || value > 255) return false;
    }

    // All checks passed, it's a valid IP address
    return true;
}

// Main function
int main(){
    std::string s;

    test_is_valid_ip();
    
    std::cout << std::endl << "Enter an IP address in decimal: " << std::flush;
    std::getline(std::cin,s);
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";
    return 0;
}

void test_is_valid_ip(){
    std::string valid_ip1 = "158.25.2.33";
    assert_and_print(valid_ip1, true);
    
    std::string valid_ip2 = "192.168.0.1";
    assert_and_print(valid_ip2, true);

    std::string invalid_ip1 = "300.25.2.33"; // number out of range
    assert_and_print(invalid_ip1, false);
    
    std::string invalid_ip2 = "158.25.2";    // missing number
    assert_and_print(invalid_ip2, false);
    
    std::string invalid_ip3 = "12.B5-33 FF"; // invalid characters
    assert_and_print(invalid_ip3, false);

    std::string invalid_ip4 = "..."; // empty octets
    assert_and_print(invalid_ip4, false);
}

void assert_and_print(std::string &ip, bool expected){
    bool is_valid;
    is_valid = is_valid_ip(ip);
    assert(is_valid == expected);
    std::cout << "is_valid_ip(\"" << ip << "\") -> " << (is_valid ? "true" : "false") << std::endl;
}