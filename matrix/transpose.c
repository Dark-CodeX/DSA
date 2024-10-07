#include <stdio.h>

int main(void)
{
    int m1[2][2] = {
        {1, 2},
        {3, 4}};

    int m2[2][2];

    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            m2[i][j] = m1[j][i];
        }
    }

    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            printf("%d\t", m2[i][j]);
        }
        puts("");
    }
    return 0;
}