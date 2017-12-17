#include <stdio.h>
#include <string.h>
#include <malloc.h>


#include "functions.h"


int main(int argc, char **argv)
{
    FILE *file, *file_out;
    char *strSearch, *strReplace, *strOut;
    size_t retStrLength;
    char str[80], sym[80];
    int lengthStrNew, functionsType;

    printf("\nIf you want to run functions my_strcspn and my_strndup write 1\n");
    printf("\nIf you want to run functions my_getline and my_str_replace write 0\n");
    scanf("%d", &functionsType);

    switch(functionsType)
    {
        case 0:
        {
            // Test for my_strcspn function
            // ������������� �������� � ��������� ������
            strSearch = "truct";
            strReplace = "<!TRUCT!>";

            char **lineptr = (char**)malloc(sizeof(char));

            // �������� �������� ��������� �����
            file = fopen(argv[1], "r");
            if (file == NULL)
            {
                printf("Error: File  not exists");
                return ERROR_FILE_NOT_EXISTS;
            }
            // ������ ������ ����������� � ����
            file_out = fopen(argv[2], "w");
            if (file_out == NULL)
            {
                printf("Error: Can't open file  for write");
                

                fclose(file);
                return ERROR_FILE_OPEN_WRITE;
            }

            // ������ �����
            while (my_getline(lineptr, &retStrLength, file) != FGETS_EOF)
            {
                // ������ ��������
                *lineptr = my_str_replace(*lineptr, strSearch, strReplace);
                // ����� � ����
                fprintf(file_out,"%s",*lineptr);
            }

            fclose(file);
            fclose(file_out);

            printf("Ok. Input any key for Exit");
            break;
        }
        case 1:
        {
            // �������� ��������� �����
            file = fopen(argv[1], "r");
            if (file == NULL)
            {
                printf("Error: File  not exists");
                

                return ERROR_FILE_NOT_EXISTS;
            }
            // read 1 string
            if (fgets(str, sizeof(str), file) == NULL)
            {
                printf("Error: Wrong file structure");
                

                fclose(file);

                return ERROR_FILE_DATA_STRUCTURE;
            }
            // read 2 string
            if (fgets(sym, sizeof(sym), file) == NULL)
            {
                printf("Error: Wrong file structure");
                

                fclose(file);

                return ERROR_FILE_DATA_STRUCTURE;
            }
            fclose(file);


            // ������ ������ ����������� � ����
            file = fopen(argv[2], "w");
            if (file == NULL)
            {
                printf("Error: Can't open file  for write");
                

                return ERROR_FILE_OPEN_WRITE;
            }

            // My function
            size_t retVal = my_strcspn(str, sym);
            fprintf(file, "my_strcspn retVal = %d\n", (int)retVal);
            // standard function
            retVal = strcspn(str, sym);
            fprintf(file, "strcspn retVal = %d\n", (int)retVal);
            fclose(file);

            // Test for my_strndup function
            // ������������� �������� � ��������� ������

            // �������� ��������� �����
            file = fopen(argv[3], "r");
            if (file == NULL)
            {
                printf("Error: File not exists");
                

                return ERROR_FILE_NOT_EXISTS;
            }
            // read 1 string
            if (fgets(str, sizeof(str), file) == NULL)
            {
                printf("Error: Wrong file structure ");
                

                fclose(file);

                return ERROR_FILE_DATA_STRUCTURE;
            }

            // read 2 string
            retVal = fscanf(file, "%d", &lengthStrNew);
            if (retVal == 0)
            {
                printf("Error: Wrong file structure ");
                

                fclose(file);

                return ERROR_FILE_DATA_STRUCTURE;
            }
            fclose(file);


            // ������ ������ ����������� � ����
            file = fopen(argv[4], "w");
            if (file == NULL)
            {
                printf("Error: Can't open file  for write");
                

                return ERROR_FILE_OPEN_WRITE;
            }

            // My function
            strOut = my_strndup(str, lengthStrNew);
            fprintf(file, "my_strndup out String = <%s>\n", strOut);
            fclose(file);

            printf("Ok. Input any key for Exit");

            break;
        }
    }

    

    return OK;
}

