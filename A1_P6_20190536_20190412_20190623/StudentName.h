#ifndef PROBLEM_6_STUDENTNAME_H
#define PROBLEM_6_STUDENTNAME_H

#include <bits\stdc++.h>
using namespace std;

class StudentName {
private:
    string name;
    vector<string> single_names;
    void editName();

public:
    StudentName(string name);
    void print() const;
    bool replace(int i, int j);
};

StudentName::StudentName(string name)
{
    stringstream ss(name);
    string word;
    while (ss >> word)
        single_names.emplace_back(word);
    while (single_names.size() < 3)
        single_names.emplace_back(word);
    editName();
}

void StudentName::editName()
{
    name = "";
    for (auto& word : single_names)
        name += word + " ";
    name.pop_back();
}

void StudentName::print() const
{
    puts("detailed parts of the name are: ");
    for (int i = 0; i < single_names.size(); i++)
        cout << "(" << i + 1 << ") " << single_names[i] << endl;
}

bool StudentName::replace(int i, int j)
{
    if (min(i, j) < 1 || max(i, j) > single_names.size())
        return false;
    swap(single_names[i - 1], single_names[j - 1]);
    editName();
    return true;
}

#endif //PROBLEM_6_STUDENTNAME_H
