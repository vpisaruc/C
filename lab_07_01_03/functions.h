#define OK                           0
#define ERROR_FILE_NOT_EXISTS       -1
#define ERROR_FILE_DATA_STRUCTURE   -2
#define ERROR_FILE_EMPTY            -3

#define ERROR_FILE_OPEN_WRITE       -10

// ���������� �������

// ���������� ��������� � �����
int countFileData(FILE *file, int *cntElem);

// �������� ������
int loadFileData(FILE *file, int *arrInp);

// ���������� � ���������� ������ � ������� ������
void filterData(int *arrInp, int *afterLastElem, int *arrWork, int *cntWorkElem);

// ������ ������� ������
void printArray(int typeHead, int *arrPrint, int *lastPrintElem);

// ������� ���������
int compareFunc(const void *a, const void *b);

// ������� ���������� �������
void sortArray(void * arrSort, size_t cntElem, size_t sizeElem, int(* compareFunc) (const void *, const void *));
