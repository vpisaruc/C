#define OK                           0
#define ERROR_FILE_NOT_EXISTS       -1
#define ERROR_FILE_DATA_STRUCTURE   -2
#define ERROR_FILE_EMPTY            -3
#define COMMAND_LINE_ERROR          -4
#define ERROR_FILE_OPEN_WRITE       -10
#define BUFFER_ERROR                -5
#define INCORRECT_PARAM              -6
#define MEMMORY_ERROR               -7
#define NONE_ELEMENTS               -8

// ���������� �������

//����� �������
unsigned long long tick(void);

// ���������� ��������� � �����
int countFileData(FILE *file, int *cntElem);

// �������� ������
int loadFileData(FILE *file, int *arrInp, int *cntElem);


// ����� ������ ����������(�� �������) 
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);


// ������ ������� ������
void printArray(const char *headString, int *arrPrint, int *lastPrintElem);

// ������� ���������
int compareFunc(const void *a, const void *b);

// ������� ���������� �������
void mysort(void *arrSort, size_t cntElem, size_t sizeElem, int(*compareFunc)(const void *, const void *));

void write_file(FILE *file, int *arrWork, int *lastPrintElem);