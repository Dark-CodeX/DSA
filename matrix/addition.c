#include <stdio.h>

int main(void)
{
    int m1[2][2] = {{1, 2}, {3, 4}};
    int m2[2][2] = {{1, 2}, {3, 4}};
    int m3[2][2];

    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }

    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            printf("%d\t", m3[i][j]);
        }
        printf("\n");
    }

    return 0;
}