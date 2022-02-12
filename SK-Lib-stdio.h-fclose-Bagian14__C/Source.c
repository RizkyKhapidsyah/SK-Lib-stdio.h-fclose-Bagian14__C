#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
    Source by Programiz
    Modified For Learn by RK
    I.D.E : VS2019
*/

int main(void) {
    int is_ok = EXIT_FAILURE;
    const char* fname = "/tmp/unique_name.txt";
    FILE* fp = fopen(fname, "w+");

    if (!fp) {
        perror("File opening failed");
        return is_ok;
    }
    
    fputs("Hello, world!\n", fp);
    rewind(fp);

    int c;
    while ((c = fgetc(fp)) != EOF) { 
        putchar(c);
    }

    if (ferror(fp)) {
        puts("I/O error when reading");
    } else if (feof(fp)) {
        puts("End of file reached successfully");
        is_ok = EXIT_SUCCESS;
    }

    fclose(fp);
    remove(fname);

    _getch();
    return is_ok;
}