#include <iostream>
#include <algorithm>

typedef struct __item__
{
    int profit;
    int weight;
    double ratio;
} item;

bool cmp(item a, item b)
{
    return a.ratio > b.ratio;
}

double max_profit(item *x, size_t len, int max_weight)
{
    std::sort(x, x + len, cmp);
    double res = 0;
    size_t i = 0;
    for (; i < len; i++)
    {
        if (max_weight > 0 && x[i].weight <= max_weight)
        {
            max_weight -= x[i].weight;
            res += x[i].profit;
        }
        else
            break;
    }
    if (max_weight > 0)
    {
        res += max_weight * x[i].ratio;
    }
    return res;
}

int main()
{
    item x[4] = {{25, 18, 25.0 / 18.0}, {24, 15, 24.0 / 15.0}, {15, 10, 15.0 / 10.0}};
    printf("Max Profit: %lf\n", max_profit(x, sizeof(x) / sizeof(*x), 20));

    return 0;
}