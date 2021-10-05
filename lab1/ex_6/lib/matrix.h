typedef struct __Matrix Matrix;

typedef struct __Matrix{
    int column;
    int row;
    double** data;
}Matrix;


Matrix* newMatrix(int column, int row);
void initMatrixByConsole(Matrix* matrix);
void printMatrix(Matrix* matrix);
int getColumn(Matrix* matrix);
int getRol(Matrix* matrix);
double get(Matrix* matrix, int columnIndex, int rowIndex);
void set(Matrix* matrix, int columnIndex, int rowIndex, double item);
void clearMatrix(Matrix* matrix);
void resizeMatrix(Matrix* matrix, int column, int row);
Matrix* sum(Matrix* o1, Matrix* o2);
Matrix* multiplication(Matrix* o1, Matrix* o2);
Matrix* multiplicatioByNumber(Matrix* matrix, double val);
Matrix* subtraction(Matrix* o1, Matrix* o2);
void saveMatrixInFile(Matrix* matrix,char* path);
Matrix* readMatrixFromTheFile(char* path);

