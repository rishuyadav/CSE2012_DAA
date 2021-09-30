#include <iostream>
#include <vector>

using namespace std;

#define last ((int)v.size() - 1)

bool grtr(vector<int> a, vector<int> b)
{
    bool flag = false;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < b[i])
            return false;
        else if (a[i] > b[i])
            flag = true;
    }

    return flag;
}

bool smlr(vector<int> a, vector<int> b)
{
    bool flag = false;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > b[i])
            return false;
        else if (a[i] < b[i])
            flag = true;
    }

    return flag;
}

void fn(vector<vector<int>> &v, int k, vector<vector<vector<int>>> &ans)
{
    while (v.size())
    {
        vector<vector<int>> non_comp, current;
        for (int i = 0; i < (int)v.size() - 1; i++)
        {
            if (grtr(v[i], v[last]))
                swap(v[i], v[last]);
            else if (!smlr(v[i], v[last]))
            {
                non_comp.push_back(v[i]);
                v.erase(v.begin() + i);
                i--;
            }
        }
        current.push_back(v[last]);
        v.erase(v.begin() + last);
        for (int i = 0; i < non_comp.size(); i++)
        {
            if (grtr(current[0], non_comp[i]))
            {
                v.push_back(non_comp[i]);
                non_comp.erase(non_comp.begin() + i);
                i--;
            }
        }
        for (int i = 0; i < non_comp.size(); i++)
        {
            bool flag = true;
            for (int j = 0; j < v.size(); j++)
            {
                if (smlr(non_comp[i], v[j]) || !grtr(non_comp[i], v[j]))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                current.push_back(non_comp[i]);
        }
        if (!current.empty())
            ans.push_back(current);
    }
}

int main()
{
    int n, k;
    cout << "[*] Enter the number of points: ";
    cin >> n;
    cout << "[*] Enter the dimensions: ";
    cin >> k;
    cout << "[*] Enter the points in sequential order: " << endl;
    vector<vector<int>> v(n, vector<int>(k));
    for (auto &x : v)
    {
        for (auto &y : x)
            cin >> y;
    }
    vector<vector<vector<int>>> ans;
    fn(v, k, ans);
    int i = 1;
    cout << endl;
    for (auto const &x : ans)
    {
        cout << "[*] Set " << i++ << ':' << endl;
        for (auto const &y : x)
        {
            for (auto const &z : y)
            {
                cout << z << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
