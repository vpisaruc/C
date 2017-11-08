#define OK                           0
#define ERROR_FILE_NOT_EXISTS       -1
#define ERROR_FILE_DATA_STRUCTURE   -2
#define ERROR_FILE_EMPTY            -3
#define COMMAND_LINE_ERROR          -4
#define ERROR_FILE_OPEN_WRITE       -10


unsigned long long tick(void);


int countFileData(FILE *file, int *cntElem);

int loadFileData(FILE *file, int *arrInp);


int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);


void printArray(int typeHead, int *arrPrint, int *lastPrintElem);

int compareFunc(const void *a, const void *b);

void mySort(void *arrSort, size_t cntElem, size_t sizeElem, int(* compareFunc) (const void *, const void *));
