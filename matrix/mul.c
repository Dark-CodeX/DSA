#include <stdio.h>

int main(void)
{
    int m1[2][2] = {
        {1, 2},
        {3, 4}};

    int m2[2][2] = {
        {5, 6},
        {7, 8}};

    int m3[2][2];

    for (size_t i = 0; i < sizeof(m1) / sizeof(*m1); i++)
    {
        for (size_t j = 0; j < sizeof(*m1) / sizeof(**m1); j++)
        {
            int sum = 0;
            for (size_t k = 0; k < sizeof(*m1) / sizeof(**m1); k++)
            {
                sum += m1[i][k] * m2[k][j];
            }
            m3[i][j] = sum;
        }
    }

    for (size_t i = 0; i < sizeof(m3) / sizeof(*m3); i++)
    {
        for (size_t j = 0; j < sizeof(*m3) / sizeof(**m3); j++)
        {
            printf("%d\t", m3[i][j]);
        }
        puts("");
    }
    return 0;
}