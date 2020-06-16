#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

/*PROBLEM START *************************************************/
/*Copyright (C) 2020 Problem Solved by Maxim Shershavikov *******/

int pickingNumbers(vector<int> a)
{
    vector < vector<int> > val(2);
    int res_a = 0, res_b = 0;

    for (int i = 0; i < a.size(); i++) {
        val[0].push_back(a[i]);
        for (int j = 0; j < a.size(); j++)
            if (val[0].back() == a[j]) res_a++;
        val[1].push_back(res_a);
        for (int k = 0; k < val[0].size() - 1; k++)
            if (val[0].back() == val[0][k]) {
                val[0].pop_back();
                val[1].pop_back();
                break;
            }
        res_a = 0;
    }
    for (int i = 0; i < val[0].size(); i++) {
        res_b = val[1][i];
        for (int j = 0; j < val[0].size(); j++)
            if (abs(val[0][i] - val[0][j]) == 1) {
                res_b += val[1][j];
                break;
            }
        if (res_a < res_b) res_a = res_b;
        res_b = 0;
    }

    return res_a;
}

/*PROBLEM END ****************************************************/

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = pickingNumbers(a);

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
