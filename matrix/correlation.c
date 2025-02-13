#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 10000

double correlation(const double data[N][2])
{
    double cov_x_y = 0;
    double mean_x = 0, mean_y = 0;
    double std_deviation_x = 0, std_deviation_y = 0;

    for (size_t i = 0; i < N; i++)
    {
        mean_x += data[i][0];
        mean_y += data[i][1];
    }
    mean_x /= N, mean_y /= N;

    for (size_t i = 0; i < N; i++)
    {
        cov_x_y += (data[i][0] - mean_x) * (data[i][1] - mean_y);
    }
    cov_x_y /= N;

    for (size_t i = 0; i < N; i++)
    {
        std_deviation_x += pow(data[i][0] - mean_x, 2);
        std_deviation_y += pow(data[i][1] - mean_y, 2);
    }
    std_deviation_x /= N, std_deviation_y /= N;

    return cov_x_y / (sqrt(std_deviation_x) * sqrt(std_deviation_y));
}

int main(void)
{
    double data[N][2];

    // Seed the random number generator
    srand((unsigned int)time(NULL) * ((unsigned int)&data));

    for (size_t i = 0; i < N; i++)
    {
        double x = ((double)rand() / RAND_MAX) * 100.0;
        double noise = (((double)rand() / RAND_MAX) * 20.0) - 10.0;
        double y = 0.5 * x + noise;
        data[i][0] = x;
        data[i][1] = y;
    }

    printf("Correlation between X and Y: %lf\n", correlation(data));

    return EXIT_SUCCESS;
}
