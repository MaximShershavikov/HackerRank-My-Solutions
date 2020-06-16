#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */

/*PROBLEM START *************************************************/
/*Copyright (C) 2020 Problem Solved by Maxim Shershavikov *******/

int nonDivisibleSubset(int k, vector<int> s) {
    int res = 0;
    map<int, int> ss;
    map<int, int> val;
    map<int, int>::iterator iterator = ss.begin();

    for (auto it = s.begin(); it != s.end(); it++) {
        val[*it]++;
        if (val[*it] > 1)
        {
            val[*it]--;
            continue;
        }
        if ((*it % k) == 0 || ((*it % k) * 2) == k) ss[*it % k] = 1;
        else ss[*it % k]++;
    }

    for (auto it = ss.begin(); it != ss.end(); it++) {
        iterator = it;
        for (auto _it = ++iterator; _it != ss.end(); _it++) {
            if (it->first + _it->first == k && it->second <= _it->second)
            {
                it->second = 0;
                break;
            }
            if (it->first + _it->first == k && _it->second <= it->second)
            {
                _it->second = 0;
                continue;
            }
        }
        res += it->second;
    }
    return res;
}

/*PROBLEM END ****************************************************/

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    int result = nonDivisibleSubset(k, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
