#include <bits/stdc++.h>

using namespace std;

// Complete the formingMagicSquare function below.

/*PROBLEM START *************************************************/
/*Copyright (C) 2020 Problem Solved by Maxim Shershavikov *******/

const int MAJIC_CUBE[24][3] = {
{ 2,7,6 }, { 9,5,1 }, { 4,3,8 },
{ 4,9,2 }, { 3,5,7 }, { 8,1,6 },
{ 8,3,4 }, { 1,5,9 }, { 6,7,2 },
{ 6,1,8 }, { 7,5,3 }, { 2,9,4 },
{ 6,7,2 }, { 1,5,9 }, { 8,3,4 },
{ 8,1,6 }, { 3,5,7 }, { 4,9,2 },
{ 4,3,8 }, { 9,5,1 }, { 2,7,6 },
{ 2,9,4 }, { 7,5,3 }, { 6,1,8 }};

int formingMagicSquare(vector<vector<int>> s)
{
    int res[8] = { 0 };
    int result = 10000;

    for (int i = 0; i < 8; i++) {
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (MAJIC_CUBE[x+(i*3)][y] == s[x][y]) continue;
                if (MAJIC_CUBE[x+(i*3)][y] > s[x][y])
                    res[i] += MAJIC_CUBE[x+(i*3)][y] - s[x][y];
                if (MAJIC_CUBE[x+(i*3)][y] < s[x][y])
                    res[i] += s[x][y] - MAJIC_CUBE[x+(i*3)][y];
            }
        }
        if (res[i] < result) result = res[i];
    }

    return result;
}

/*PROBLEM END ****************************************************/

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int count = 0;

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
