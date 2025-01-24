#include <stdio.h>

const char *find(const char *str, const char *sub)
{
    if (!str || !sub)
        return NULL;
    if (sub[0] == 0)
        return str;
    for (size_t i = 0; str[i]; i++)
    {
        if (str[i] == sub[0])
        {
            size_t j = 0;
            for (size_t k = i; str[k] && sub[j]; j++, k++)
            {
                if (str[k] != sub[j])
                    break;
            }
            if (sub[j] == 0)
                return str + i;
        }
    }
    return NULL;
}

int main()
{
    const char *str = "Hello, World";
    const char *sub = "";
    const char *p1 = find(str, sub);
    printf("%s\n", (p1 ? p1 : "(null)"));
}