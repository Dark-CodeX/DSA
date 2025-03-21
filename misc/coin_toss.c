#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ITERATION 10
#define MAX_PEOPLE 1000
#define CORRECT_FACE 0 // Heads

/*
 * 0 -> Heads
 * 1 -> Tails
 */
typedef struct person
{
    bool M_coin[MAX_ITERATION];
    int M_weight;
} person;

int comparse_persons(const void *p1, const void *p2)
{
    return ((person *)p2)->M_weight - ((person *)p1)->M_weight;
}

bool *estimate_coin(bool *a)
{
    int R = rand();
    if (R % 2 == 0)
        *a = 0;
    else
        *a = 1;
    return a;
}

int main(void)
{
    person people[MAX_PEOPLE] = {};
    srand((unsigned)time(NULL) * (unsigned)(&people));
    for (size_t i = 0; i < MAX_ITERATION; i++)
    {
        for (size_t j = 0; j < MAX_PEOPLE; j++)
        {
            estimate_coin(&people[j].M_coin[i]);
            people[j].M_weight += people[j].M_coin[i] == CORRECT_FACE ? 1 : -1;
        }
    }

    qsort(people, MAX_PEOPLE, sizeof(person), comparse_persons);

    for (size_t i = 0; i < MAX_ITERATION; i++)
    {
        printf("PERSON @ [%zu]: %s\n", i, (people[0].M_coin[i] == 0 ? "Heads" : "Tails"));
    }
    printf("PERSON WEIGHT: %d\n", people[0].M_weight);

    return EXIT_SUCCESS;
}