#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * count the number of bits.
 */
int countBitSet(long val)
{
    int ret = 0;
    while (val)
    {
        if (val & 1)
        {
            ret++;
        }
        val = val >> 1;
    }
    return ret;
}

int calculate(int subset, const vector<long> &d)
{
    vector<long> valSubset;
    int pos = 0;
    while (subset)
    {
        if (subset & 1)
        {
            valSubset.push_back(d[pos]);
        }

        pos++;
        subset = subset >> 1;
    }

    // Merge if connection exists.
    int valSubsetSize = valSubset.size();
    for (int i = 0; i < valSubsetSize; ++i)
    {
        for (int j = 0; j < valSubsetSize; ++j)
        {
            if (i != j)
            {
                if (valSubset[i] & valSubset[j])
                {
                    valSubset[i] |= valSubset[j];
                    valSubset[j] = 0;
                }
            }
        }
    }

    int ret = 64;
    for (int i = 0; i < valSubsetSize; ++i)
    {
        if (valSubset[i] != 0)
        {
            ret -= countBitSet(valSubset[i]);
            ret += 1;
        }
    }

    return ret;
}

int findConnectedComponents(vector<long> d)
{
    int ret = 0;
    int dSize = d.size();
    int dSet = (1 << dSize) - 1;
    ret += calculate(0, d);
    for (int subset = dSet; subset; subset = ((subset - 1) & dSet))
    {
        ret += calculate(subset, d);
    }

    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string d_count_temp;
    getline(cin, d_count_temp);

    int d_count = stoi(ltrim(rtrim(d_count_temp)));

    string d_temp_temp;
    getline(cin, d_temp_temp);

    vector<string> d_temp = split(rtrim(d_temp_temp));

    vector<long> d(d_count);

    for (int i = 0; i < d_count; i++)
    {
        long d_item = stol(d_temp[i]);

        d[i] = d_item;
    }

    int components = findConnectedComponents(d);

    fout << components << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
