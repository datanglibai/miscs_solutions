#pragma once
#include "iostream";
#include <vector>;

using namespace std; 

class zigZag {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;
        vector<string> rows(numRows);
        int step = 2 * (numRows - 1);
        for (int i = 0; i < s.size(); i++) {
            if (i % step == 0)
            {
                rows[0] += s[i];
                continue;
            }

            if (i%step == step / 2)
            {
                rows[numRows - 1] += s[i];
                continue;
            }
            int r = step / 2 - abs(step / 2 - i%step);
            rows[r] += s[i];
        }

        string result("");
        for (int i = 0; i< numRows; i++)
            result += rows[i];

        return result;
    };

    void testItself()
    {
        string result = convert("ABCDE", 4);
        //cout<<result<<endl;
    }
};
