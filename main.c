#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STRING 502

/* simple bubble sort */
void sort(int arr[], size_t n)
{
    int i, j;

    for(i = 0; i < n; ++ i) {
        for(j = 0; j < n - 1; ++j) {

            if(arr[j] < arr[j + 1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/*  Each character is valued by rank. The character that appears the most is ranked 26, and
    second most repeated 25 and so on. We can simply assign each letter to an array index.
    We can then sort that index and use it to calculate the value of the string
*/
int calc(char *str)
{
    int i = 0, r = 0, n;

    int arr[26] = {0};

    while (str[i] != '\n' && str[i]) {
        if(isalpha(str[i])) {
            char temp = tolower(str[i]) - 97; // get index of the letter, a = 0, b = 2 etc.
            arr[temp] += 1;
        }
        ++i;
    }

    sort(arr, 26);

    for (i = 0, n = 26; arr[i] != 0 && i < 26; ++i) {
        r += arr[i] * n--;
    }

    return r;
}

int main(int argc, char **argv)
{
    int i = 0;
    if (argc < 2) {
        printf("usage: main <filename>\n");
        return -1;
    }

    FILE *file = fopen(argv[1], "r");
    if(!file) {
        printf("Unable to open %s", argv[1]);
        return -1;
    }

    char  line[502];

    while(fgets(line, MAX_STRING, file)) {
        printf("Case #%d: %d\n", ++i, calc(line));

    }

    return 0;
}
