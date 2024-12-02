// SubsetsII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>

bool operator== (const std::vector<int>& a, const std::vector<int>& b)
{
    if (a.size() != b.size())
        return false;
    for (auto n : a)
    {
        bool found = false;
        for (auto m : b)
        {
            if (n == m)
            {
                found = true;
                break;
            }
        }

        if (!found)
            return false;
    }
    return true;
}

bool Find(const std::vector<std::vector<int>>& result, const std::vector<int>& r)
{
    for (auto& v : result)
    {
        if (v == r)
            return true;
    }

    return false;
}

void SubsetsHelper(const std::vector<int>& A, size_t i, std::vector<int>& r, std::vector<std::vector<int>>& result)
{
    if (i == A.size())
        return;

    r.push_back(A[i]);
    if (!Find(result, r))   // filter out duplicates
        result.push_back(r);
    SubsetsHelper(A, i + 1, r, result);
    r.pop_back();
}

// The array may not be sorted
std::vector<std::vector<int>> Subsets(const std::vector<int>& A)
{
    std::vector<std::vector<int>> result;
    std::vector<int> r;
    result.push_back(r);        // empty is one possibility
    for (size_t i = 0; i < A.size(); ++i)
    {
        SubsetsHelper(A, i, r, result);
    }

    return result;
}

int main()
{
    while (true)
    {
        std::cout << "Enter array size: ";
        int count = 0;
        std::cin >> count;
        if (count == 0)
            break;

        std::cout << "Enter array elements: ";
        std::vector<int> vec(count, 0);
        for (size_t i = 0; i < count; ++i)
        {
            std::cin >> vec[i];
        }

        std::vector<std::vector<int>> result = Subsets(vec);
        std::cout << "There are " << result.size() << " possible subsets: " << std::endl;

        for (auto& r: result)
        {
            if (r.size() != 0)
                std::cout << r[0];
            for (size_t i = 1; i < r.size(); ++i)
            {
                std::cout << "," << r[i];
            }
            std::cout << std::endl;
        }
    }
}
