#include <vector>
#include <string>

// Definition for a Pair
class Pair
{
public:
    int key;
    std::string value;

    Pair(int key, std::string value) : key(key), value(value) {}
};

class Solution
{
public:
    std::vector<std::vector<Pair>> insertionSort(std::vector<Pair> &pairs)
    {
        if (pairs.size() < 1)
        {
            return {};
        }

        std::vector<std::vector<Pair>> steps;
        steps.push_back(pairs);

        for (size_t i = 1; i < pairs.size(); i++)
        {
            int j = i - 1;
            Pair temp = pairs[i]; // get key value for sorting

            while (temp.key < pairs[j].key && j >= 0) // while the key is less than previous keys in range
            {
                pairs[j + 1] = pairs[j]; // swap pairs
                j--;
            }
            pairs[j + 1] = temp;

            steps.push_back(pairs);
        }

        return steps;
    }
};
