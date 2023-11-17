#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    if (s.size() < 11)
        return false;
    for (auto i : s)
        if (!('0' <= i and i <= '9'))
            return false;
    return true;
}

string getTable(string numbers, int rowCap)
{
    vector<string> arr;
    string cur;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == ' ')
        {
            if (isValid(cur))
                arr.push_back(cur);
            cur.clear();
        }
        else
            cur.push_back(numbers[i]);
    }
    if (isValid(cur))
        arr.push_back(cur);

    string table = "<table>\n";
    table += "<tr>\n";
    for (int i = 0; i < arr.size(); i++)
    {
        table += "<td>" + arr[i] + "<\\td>\n";
        if (i % rowCap == rowCap - 1)
        {
            table += "<\\tr>\n";
        }
    }
    if (arr.size() % rowCap != 0)
    {
        table += "<\\tr>\n";
    }
    table += "<\\table>\n";
    return table;
}

int main()
{
    string number = "abcd 1234567801 12345678901 12345678901 12345678901 12345678901 12345678901 12345678901";
    cout << getTable(number, 3);
}