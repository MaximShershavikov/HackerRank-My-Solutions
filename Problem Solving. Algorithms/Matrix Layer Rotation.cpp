#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the matrixRotation function below.

/*PROBLEM START ********************************************************************/
/*Copyright (C) 2020 Problem Solved by Maxim Shershavikov **************************/

void matrixRotation(vector<vector<int>> matrix, int r) {
    int X_size = matrix[0].size() - 1, Y_size = matrix.size() - 1;
    int X_start = 0, Y_start = 0, count_Y = 0, count_X = 0, front_X = 0, front_Y = 0;
    int m, n = 0, allsize, rr = r;
    list<int> buf;

    while (front_X < (matrix.size() / 2) && front_Y < (matrix[0].size() / 2))
    {
        allsize = (X_size - front_X + Y_size - front_Y) * 2;
        while (rr > allsize && allsize != 0) rr -= allsize;

        if (rr >= ((X_size - front_X) * 2) + (Y_size - front_Y)) {
            X_start = front_Y;
            Y_start = Y_size - (rr - (((X_size - front_X) * 2) + (Y_size - front_Y)));
            m = 3;
        }
        else if (rr >= (X_size - front_X) + (Y_size - front_Y)) {
            Y_start = Y_size;
            X_start = X_size - (rr - ((X_size - front_X) + (Y_size - front_Y)));
            m = 2;
        }
        else if (rr >= X_size - front_X) {
            X_start = X_size;
            Y_start = front_Y + (rr - (X_size - front_X));
            m = 1;
        }
        else if (rr >= 0) {
            Y_start = front_X;
            X_start = front_X + rr;
            m = 0;
        }

        for (int i = allsize; i > 0; i--)
        {
            if (buf.size() == (allsize - rr)) {
                buf.push_back(matrix[count_Y][count_X]);
                matrix[count_Y][count_X] = buf.front();
                buf.pop_front();
            }
            else {
                buf.push_back(matrix[count_Y][count_X]);
                matrix[count_Y][count_X] = matrix[Y_start][X_start];
                switch (m) {
                case 0: if (X_start < X_size) { X_start++; break; }
                      else m = 1;
                case 1: if (Y_start < Y_size) { Y_start++; break; }
                      else m = 2;
                case 2: if (X_start > front_X) { X_start--; break; }
                      else m = 3;
                case 3: if (Y_start > front_Y) { Y_start--; break; }
                      else { m = 0; X_start++; }
                }
            }

            switch (n) {
            case 0: if (count_X < X_size) { count_X++; break; }
                  else n = 1;
            case 1: if (count_Y < Y_size) { count_Y++; break; }
                  else n = 2;
            case 2: if (count_X > front_X) { count_X--; break; }
                  else n = 3;
            case 3: if (count_Y > front_Y) { count_Y--; break; }
                  else { n = 0; count_X++; }
            }
        }
        buf.clear();
        front_X++; X_size--; count_X = front_X;
        front_Y++; Y_size--; count_Y = front_Y;
        rr = r;
    }

    for (auto it_y = matrix.begin(); it_y != matrix.end(); it_y++) {
        for (auto it_x = it_y->begin(); it_x != it_y->end(); it_x++)
            cout << *it_x << " ";
        cout << endl;
    }
}

/*PROBLEM END **********************************************************************/

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

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
