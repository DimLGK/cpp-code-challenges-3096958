// C++ Code Challenges, LinkedIn Learning

// Challenge #12: Age in Days Calculator
// Write an application that asks the user's birth date and responds with the user's age in days. 
// If the user claims to be over 120 years old, output a message calling the bluff.

#include <iostream>
#include <string>
#include <ctime>

bool is_leap_year(int year){
    if(year % 4 != 0)
        return false;
    else if(year % 100 != 0)
        return true;
    else if(year % 400 != 0)
        return false;
    else
        return true;
}

// Age in Days, main()
// Summary: This application asks the user's birth date and prints their age in days.
int main(){
    int birth_y, birth_m, birth_d, today_y, today_m, today_d, age;

    std::cout << "Enter your birth date's month as a number: " << std::flush;
    std::cin >> birth_m;
    std::cout << "Enter your birth date's day: " << std::flush;
    std::cin >> birth_d;
    std::cout << "Enter your birth date's year: " << std::flush;
    std::cin >> birth_y;
    
    if(birth_m < 1)
        birth_m = 1;
    if(birth_m > 12)
        birth_m = 12;

    if(birth_d < 1)
        birth_d = 1;
    if(birth_d > 31)
        birth_d = 31;


    // Get today's date
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    today_y = now->tm_year + 1900;
    today_m = now->tm_mon + 1;
    today_d = now->tm_mday;

    // Calculate age in days
    age = 0;
    // Check full years
    for (int year = birth_y; year < today_y; ++year){
        if(is_leap_year(year))
            age += 366;
        else
            age += 365;
    }

    // Check months in current year
    for (int month = 1; month < today_m; ++month){
        if(month == 2){
            if(is_leap_year(today_y))
                age += 29;
            else
                age += 28;
        }
        else if(month == 4 || month == 6 || month == 9 || month == 11)
            age += 30;
        else
            age += 31;
    }
    // Add days in current month
    age += (today_d - birth_d);

    std::cout << "\nYou were born on " << birth_d << "/" << birth_m << "/" << birth_y << ".\n";

    if(age < 43830)
        std::cout << "You are " << age << " days old.";
    else
        std::cout << "Come on. You can't be " << age << " days old!";
    std::cout << "\n\n" << std::flush;
}
