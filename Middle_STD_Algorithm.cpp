#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <array>

std::map<std::string, int> m_StrMap;
std::unordered_map<std::string, int> m_StrUnorderedMap;
std::set<int> m_IntSet{ 10, 20, 30, 40, 50 };
std::array<int, 10> m_IntArray = { 0 };
std::array<int, 10> m_IntArrayCopy;


// return std::pair from std::map with the specified key
std::pair<const std::string, int> GetMapStr(const std::string& ss)
{
    auto ddd = m_StrMap.find(ss);
    if (ddd != m_StrMap.end())
    {
        // if map contains key
        return std::pair<const std::string, int>(ss, m_StrMap[ss]);
    }
    else
    {
        // if map does not contains key
        // return inccorrect std::pair, so as not to create a new key in map
        return std::pair<const std::string, int>(ss, 0);
    }
}

int main()
{
    // Homework 4.4 and 5.4
    // find for std::map 
    // find the iterator with the specified key and display values from result to end of map 
    m_StrMap["Unreal"] = 100;
    m_StrMap["Unity"] = 200;
    m_StrMap["Crytek"] = 300;

    auto m_FindResult = std::find(m_StrMap.cbegin(), m_StrMap.cend(), GetMapStr("Unity"));
    if (m_FindResult == m_StrMap.end())
    {
        std::cout << "std::find could not find the key \n";
    }
    else
    {
        std::cout << "std::find result: \n";
        std::for_each(m_FindResult, m_StrMap.cend(), [](std::pair<const std::string, int>n) { std::cout << n.first << " : " << n.second << "\n"; });
    }
    std::cout << "\n";


    // Homework 4.4
    // count_if for std::unordered_map
    // count the number of values more than 15 
    m_StrUnorderedMap["Unreal"] = 10;
    m_StrUnorderedMap["Unity"] = 20;
    m_StrUnorderedMap["Crytek"] = 30;

    auto Cost15 = [](std::pair<const std::string, int> n) {return n.second > 15; };
    int m_Count = std::count_if(m_StrUnorderedMap.cbegin(), m_StrUnorderedMap.cend(), Cost15);
    std::cout << "count_if result: " << m_Count << "\n";
    std::cout << "\n";
 

    // Homework 4.4
    // for_each for std::set
    // display values more than 25 
    auto More25 = [](int n) { if (n >= 25) std::cout << n << "\n"; };
    std::cout << "for_each result: \n";
    std::for_each(m_IntSet.cbegin(), m_IntSet.cend(), More25);
    std::cout << "\n";


    // Homework 5.4
    // fill for std::array
    // fill the array with 3 
    std::cout << "fill result: \n";
    std::cout << "before fill: \n";
    std::for_each(m_IntArray.cbegin(), m_IntArray.cend(), [](int n) { std::cout << n << " "; });
    std::cout << "\n";

    std::fill(m_IntArray.begin(), m_IntArray.end(), 3);

    std::cout << "after fill: \n";
    std::for_each(m_IntArray.cbegin(), m_IntArray.cend(), [](int n) { std::cout << n << " "; });
    std::cout << "\n\n";


    // Homework 5.4
    // copy
    // copy values from m_IntArray to m_IntArrayCopy
    std::copy(m_IntArray.cbegin(), m_IntArray.cend(), m_IntArrayCopy.begin());
    std::cout << "m_IntArrayCopy after copy: \n";
    std::for_each(m_IntArrayCopy.cbegin(), m_IntArrayCopy.cend(), [](int n) { std::cout << n << " "; });
    std::cout << "\n\n\n";


    //////////////////////////////////////////////////////////////////////////////////
    // Homework 6.4
    // generate

    std::cout << "-------  Homework 6.4 ------- \n\n";

    srand(time(0));
    std::vector<int> m_GenerateVector(10);

    // generate int from 0 to 99 
    std::generate(m_GenerateVector.begin(), m_GenerateVector.end(), []() {return rand() % 100; });

    std::cout << "generate result: \n";
    std::for_each(m_GenerateVector.cbegin(), m_GenerateVector.cend(), [](int n) { std::cout << n << " "; });
    std::cout << "\n\n";

    // Homework 6.4
    // transform

    // multiply the values in m_GenerateVector by 2 
    std::transform(m_GenerateVector.cbegin(), m_GenerateVector.cend(), m_GenerateVector.begin(), [](int n) { return n * 2; });

    std::cout << "transform result: \n";
    std::for_each(m_GenerateVector.cbegin(), m_GenerateVector.cend(), [](int n) { std::cout << n << " "; });
    std::cout << "\n\n";


    // Homework 6.4
    // remove_if

    std::vector<int> m_RemoveVector(10);

    // generate int from 0 to 9 
    std::generate(m_RemoveVector.begin(), m_RemoveVector.end(), []() {return rand() % 10; });

    std::cout << " before remove_if: \n";
    std::for_each(m_RemoveVector.cbegin(), m_RemoveVector.cend(), [](int n) { std::cout << n << " "; });
    std::cout << "\n\n";

    // remove all values in m_RemoveVector less than 3
    m_RemoveVector.erase(std::remove_if(m_RemoveVector.begin(), m_RemoveVector.end(), [](int n) { return n < 3; }), m_RemoveVector.end());

    std::cout << "remove_if result: \n";
    std::for_each(m_RemoveVector.cbegin(), m_RemoveVector.cend(), [](int n) { std::cout << n << " "; });
    std::cout << "\n\n";

}
