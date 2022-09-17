#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void SwapStrings(double* array1, double* array2, int size){
    for(int j = 0; j < size; j++){
        double buffer;
        buffer = array1[j];
        array1[j] = array2[j];
        array2[j] = buffer;
    }
}

double* SubtractionStrings(double* array1, double* array2, int size){
    for(int j = 0; j < size; j++){
        array1[j] = array1[j] - array2[j];
    }
    return array1;
}

double* MultiplicationStringNumber(double* array, int size, double number){
    for(size_t j = 0; j < size; j++){
        array[j] = array[j] * number;
    }
    return array;
}

size_t MaxAbsIndex(double** pdmatrix, int rows, int columnindex)
{
    int maxindex = columnindex, i, j;
    for(i = columnindex + 1; i < rows; i++){
        if(abs(pdmatrix[i][columnindex]) > abs(pdmatrix[maxindex][columnindex]))
            maxindex = i;
    }
    return maxindex;
}

double** TriangaleMatrix(double** pdmatrix, int rows, int columns)
{
    if(rows + 1 == columns)
    {
        int i = 0, j = 0, k = 0, maxrowindex = 0;
        double* BufferArray = new double[columns];
        for(j = 0; j < rows; j++){
            maxrowindex = MaxAbsIndex(pdmatrix, rows, j);
            if(maxrowindex != j) {
                SwapStrings(pdmatrix[maxrowindex], pdmatrix[j], columns);
            };
            if(double(0) != pdmatrix[j][j]){
                MultiplicationStringNumber(pdmatrix[j], columns, 1 / pdmatrix[j][j]);
                for(i = j + 1; i < rows; i++){
                    memcpy(BufferArray, pdmatrix[j], columns * sizeof(double));
                    MultiplicationStringNumber(BufferArray, columns, pdmatrix[i][j]);
                    SubtractionStrings(pdmatrix[i], BufferArray, columns);
                }
            }
        }
        delete[] BufferArray;

        for(i = 0; i < rows; ++i){
            bool zerorow = true;
            for(j = 0; j < columns - 1; j++){
                if(pdmatrix[i][j] != double(0))
                    zerorow = false;
            }
            if(zerorow && pdmatrix[i][columns - 1] != double(0)){
                cout <<"The system is incompatible \n";
                break;
            }
            else if(zerorow && pdmatrix[i][columns - 1] == double(0)){
                cout << "The system has an infinite set of solutions \n";
                break;
            }
        }
    }
    else
        cout << "Error: rows + 1 != columns \n";
    return pdmatrix;
}

double** TriangaleToDiagonalMatrix(double** pdmatrix, int rows, int columns){
    double* BufferArray = new double[columns];
    for (int j = columns-2; j > 0;j--){
        for(int i = rows - 2; i >= 0; i--){
            memcpy(BufferArray, pdmatrix[j], columns * sizeof(double));
            MultiplicationStringNumber(BufferArray, columns, pdmatrix[i][j]);
            SubtractionStrings(pdmatrix[i], BufferArray, columns);
        };
    };
    delete[] BufferArray;
    return pdmatrix;
}

int main(){
    int height;
    int width;
    cout << "Enter the number of rows and columns of the original system matrix: \n";
    cin >> height >> width;
    double **Matrix;
    Matrix = new double* [height];
    cout << "Enter the "<<height<<"x"<<width<<" matrix:"<<endl;
    for (int i = 0; i < height; i++){
        Matrix[i] = new double [width];
    };
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++)
            cin >> Matrix[i][j];
    }

    TriangaleMatrix(Matrix,height,width);
    TriangaleToDiagonalMatrix(Matrix,height,width);
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++)
            cout << setw(5) << setprecision(2) << Matrix[i][j] << "   ";
        cout << endl;
    }
    for (int i = 0; i < height; i++){
        cout << setw(3) <<"x"<<i+1<< "=" << setprecision(2) <<(-1)*Matrix[i][width-1] << "   ";
    }
    for (int i = 0; i < height; i++){
        delete[] Matrix[i];
    };
    delete [] Matrix;
}