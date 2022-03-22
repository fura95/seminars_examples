#include <iostream>
#include <map>
#include <string>
#include <iterator>


int main()
{
    std::multimap<std::string, int> mapOfWords;
    // Inserting data in std::map
    mapOfWords.insert(std::make_pair("earth", 3));
    mapOfWords.insert(std::make_pair("earth", 0));
    mapOfWords.insert(std::make_pair("earth", 2));

    // Searching element in std::map by key.
    int count = 0;
    mapOfWords.erase("earth");
    for(auto it = mapOfWords.begin(); it != mapOfWords.end(); it++) {
        if(it->second == 3)
            it->second = 5;
        std::cout << it->first << " " << it->second << "\n";
    }
        

    return 0;
}