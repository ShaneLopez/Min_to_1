#include <iostream>
#include <vector>

using namespace std;

int minto1(long n, vector<int>& memo)
{
    if(n == 1)
        return 0;

    if(memo[n - 1] != -1)
        return memo[n - 1];

    int min = 999;
    int tempmin;

    tempmin = 1 + minto1(n - 1,memo);

    if(tempmin < min)
        min = tempmin;

    if(n % 2 == 0)
    {
        tempmin = 1 + minto1(n / 2,memo);

        if(tempmin < min)
            min = tempmin;
    }

    if(n % 3 == 0)
    {
        tempmin = 1 + minto1(n / 3,memo);

        if(tempmin < min)
            min = tempmin;
    }
    memo[n - 1] = min;
    return memo[n - 1];
}

int main()
{
    vector<int> memo(12345, -1);
    cout << minto1(12345,memo) << endl;
    return 0;
}
