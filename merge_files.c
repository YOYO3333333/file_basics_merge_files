#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int merge_files(const char *file_1, const char *file_2)
{
    FILE *fp4 = fopen(file_1, "r");
    FILE *fp2 = fopen(file_2, "r");
    char c;
    if (fp4 == NULL || fp2 == NULL)
        return -1;
    fclose(fp4);
    FILE *fp1 = fopen(file_1, "a");
    while ((c = fgetc(fp2)) != EOF)
        fputc(c, fp1);
    fclose(fp2);
    fclose(fp1);
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int cmpt = 0;
    FILE *fp3 = fopen(file_1, "r");
    while ((read = getline(&line, &len, fp3)) != -1)
        cmpt++;
    if (cmpt == 0)
        cmpt++;
    if (line)
        free(line);
    fclose(fp3);
    return cmpt;
}
