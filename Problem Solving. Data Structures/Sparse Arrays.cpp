#include <bits/stdc++.h>

using namespace std;

// Complete the matchingStrings function below.

/*PROBLEM START *************************************************/
/*Copyright (C) 2020 Problem Solved by Maxim Shershavikov *******/

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    int count = 0;
    vector<int> res;
    for (auto itq = queries.begin(); itq != queries.end(); itq++) {
        for (auto its = strings.begin(); its != strings.end(); its++) {
            if (*itq == *its) count++;
        }
        res.push_back(count);
        count = 0;
    }
    return res;
}

/*PROBLEM END ****************************************************/

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int strings_count;
    cin >> strings_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> strings(strings_count);

    for (int i = 0; i < strings_count; i++) {
        string strings_item;
        getline(cin, strings_item);

        strings[i] = strings_item;
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    vector<int> res = matchingStrings(strings, queries);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
