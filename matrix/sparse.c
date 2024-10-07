#include <stdio.h>

int main(void)
{
    int sparse_matrix[4][5] =
        {
            {0, 0, 6, 0, 9},
            {0, 0, 4, 6, 0},
            {0, 0, 0, 0, 0},
            {0, 1, 2, 0, 0}};

    size_t s = 0;
    for (size_t i = 0; i < sizeof(sparse_matrix) / sizeof(*sparse_matrix); i++)
    {
        for (size_t j = 0; j < sizeof(*sparse_matrix) / sizeof(**sparse_matrix); j++)
        {
            if (sparse_matrix[i][j] != 0)
                s++;
        }
    }
    int res[3][s], k = 0;
    for (size_t i = 0; i < sizeof(sparse_matrix) / sizeof(*sparse_matrix); i++)
    {
        for (size_t j = 0; j < sizeof(*sparse_matrix) / sizeof(**sparse_matrix); j++)
        {
            if (sparse_matrix[i][j] != 0)
            {
                res[0][k] = i;
                res[1][k] = j;
                res[2][k] = sparse_matrix[i][j];
                k++;
            }
        }
    }

    for (size_t j = 0; j < k; j++)
    {
        printf("[i: %zu, j: %zu, val: %d]\n", res[0][j], res[1][j], res[2][j]);
    }

    return 0;
}