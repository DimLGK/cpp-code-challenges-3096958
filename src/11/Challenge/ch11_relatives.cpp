// C++ Code Challenges, LinkedIn Learning

// Challenge #11: Finding Relatives
// Write an application that reads a list of people's names in a CSV file and outputs the first pair of people it finds to be possibly related based on their family names.
// Assume that all entries have one name and one family name.
// Entries are separated by commas.
// Names and family names are separated by spaces.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// Finding Relatives, main()
// Summary: This application displays the first pair of possible relatives from a list of names in a CSV file.
int main(){
    std::fstream file ("names.csv", std::ios::in);
    std::vector<std::string> names;

    // Read the CSV file.
    if(file.is_open()){

        std::string line;
        
        while(getline(file,line)){
            std::stringstream  lineStream(line);
            std::string cell;
            while(getline(lineStream,cell,',')){
                names.push_back(cell);
            }
        }

        std::cout << "\nNames loaded from CSV file:\n\n" << std::flush;
        for(size_t i=0; i<names.size(); i++){
            std::cout << names[i] << "\n" << std::flush;
        }
        std::cout << "\n" << std::flush;
    
        file.close();
    }
    else{
        std::cout << "Something went wrong\n" << std::flush;
        return 1;
    }

    // Write your code here
    for(size_t i=0; i<names.size(); i++){
        std::string first_name1, last_name1;
        std::stringstream nameStream1(names[i]);
        nameStream1 >> first_name1 >> last_name1;

        for(size_t j=i+1; j<names.size(); j++){
            std::string first_name2, last_name2;
            std::stringstream nameStream2(names[j]);
            nameStream2 >> first_name2 >> last_name2;

            if(last_name1 == last_name2){
                std::cout << "Possible relatives found: " << names[i] << " and " << names[j] << "\n\n" << std::flush;    
                return 0;
            }
        }
    }

    std::cout << "No relatives found.\n\n" << std::flush;    
    return 0;
}
 