long long f(long long x)
{
    return x * x;
    // vector<int> p;
    // return p[x]
}

int main()
{

    long long L = 0, R = 1e5;
    int x;
    while (L != R)
    {
        long long mid = (L + R) / 2;
        if (f(x) >= x)
        {
            R = mid;
        }
        else
        {
            L = mid + 1;
        }
    }
}
