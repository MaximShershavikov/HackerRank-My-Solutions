#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the climbingLeaderboard function below.

/*PROBLEM START *************************************************/
/*Copyright (C) 2020 Problem Solved by Maxim Shershavikov *******/

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {

    int count = 1;
    map<int, int> rang;
    auto it = alice.begin();

    for (int i = 0; i < scores.size(); i++) {
        rang[count] = scores[i];
        if (i < (scores.size()-1) && scores[i+1] != scores[i]) count++;
    }

    scores.clear();
    while (it != alice.end()) {
        if (*it < rang[count] && count == rang.size()) {
            it++;
            scores.push_back(rang.size()+1);
            continue;
        }
        if (*it >= rang[count] && *it <= rang[count-1] && count != 1) {
            if (*it == rang[count-1]) { count--; continue; }
            it++;
            scores.push_back(count);
            continue;
        }
        if (*it >= rang[1] && count == 1) {
            it++;
            scores.push_back(count);
            continue;
        }
        count--;
    }
    return scores;
}

/*PROBLEM END ****************************************************/

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
