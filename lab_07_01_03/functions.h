#define OK                           0
#define ERROR_FILE_NOT_EXISTS       -1
#define ERROR_FILE_DATA_STRUCTURE   -2
#define ERROR_FILE_EMPTY            -3
#define COMMAND_LINE_ERROR          -4
#define ERROR_FILE_OPEN_WRITE       -10

// Объявление функций

//Замер времени
unsigned long long tick(void);

// Количество элементов в файле
int countFileData(FILE *file, int *cntElem);

// Загрузка данных
int loadFileData(FILE *file, int *arrInp);


// Новая версия фильтрации(из задания) 
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);


// Печать массива данных
void printArray(int typeHead, int *arrPrint, int *lastPrintElem);

// Функция сравнения
int compareFunc(const void *a, const void *b);

// функция сортировки массива
void mySort(void * arrSort, size_t cntElem, size_t sizeElem, int(* compareFunc) (const void *, const void *));
