#include <bits\stdc++.h>
using namespace std;

set<string> unique_permutations;

void RecPermute(string soFar, string rest)
{
    if (rest.empty()) // No more characters
    {
        if (unique_permutations.find(soFar) == unique_permutations.end())
        {
            cout << soFar << endl; // Print the word
            unique_permutations.insert(soFar);
        }
    }
    else // Still more chars
        // For each remaining char
        for (int i = 0; i < rest.length(); i++)
        {
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i) + rest.substr(i + 1);
            RecPermute(next, remaining);
        }
}

// "wrapper" function

void ListPermutations(string s)
{
    sort(s.begin(), s.end());
    RecPermute("", s);
}

int main()
{
    ListPermutations("ABCA");
    return 0;
}
