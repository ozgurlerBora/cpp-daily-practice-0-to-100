//
// Created by böo on 30/08/2026.
//
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <memory>
#include <fstream>
class Matrix {
private:
    int rows;
    int cols;
    std::vector <std::vector<double>> data;
public:
    Matrix(int r,int c) {
        rows=r;
        cols=c;
        data=std::vector<std::vector<double>>(rows,std::vector<double>(cols,0.0));
    }
    void setValue(int r,int c, double val) {
        data[r-1][c-1]=val;
    }
    void display() {
        for (int i=0;i<rows;i++) {
            for (int k=0;k<cols;k++) {
                std::cout<<data[i][k]<<" ";
            }
            std::cout<<std::endl;
        }
    }
    Matrix operator+(const Matrix& other) {
        Matrix result(rows,cols);
        for (int i =0;i<rows;i++) {
            for (int k=0;k<cols;k++) {
                result.data[i][k]=this->data[i][k]+other.data[i][k];
            }
        }
        return result;
    }
    Matrix operator-(const Matrix& other) {
        Matrix result (rows,cols);
        for (int i =0;i<rows;i++){
        for (int k =0;k<cols;k++) {
             result.data[i][k]=this->data[i][k]-other.data[i][k];
        }
        }
        return result;
    }
    Matrix operator*(const Matrix& other) {
        if (this->cols !=other.rows) {
            throw std::invalid_argument("Math Error: First Matrix columns must be equal to Second Matrix rows.");
        }
        Matrix result (rows,other.cols);
        for (int i =0;i<rows;i++) {
            for (int k=0;k<other.cols;k++) {
                for (int j =0;j<cols;j++) {
                    result.data[i][k]+=this->data[i][j]* other.data[j][k];
                }
            }
        }
        return result;

    }
    Matrix transpose() {
        Matrix result(this->cols,this->rows);
        for (int i=0;i<rows;i++) {
            for (int k=0;k<cols;k++) {
                result.data[k][i]=this->data[i][k];
            }
        }
        return result;
    }
    Matrix operator*(double scalar) {
        Matrix result(rows,cols);
        for (int i=0;i<rows;i++) {
            for (int k=0;k<cols;k++) {
                result.data[i][k]=this->data[i][k]*scalar;
            }
        }
        return result;
    }
};
int main() {
  /*  Matrix matrix1(2,2);
    Matrix matrix2(2,2);
    matrix1.setValue(1,1,1.5);
    matrix1.setValue(1,2,4.5);
    matrix1.setValue(2,2,3.5);
    matrix1.setValue(2,1,2.5);
    matrix2.setValue(1,1,2);
    matrix2.setValue(1,2,3);
    matrix2.setValue(2,2,5);
    matrix2.setValue(2,1,1);
    Matrix matrix3 = matrix1+matrix2;
    Matrix matrix4 =matrix1-matrix2;
    Matrix matrix5= matrix1*matrix2;
    matrix5.display();*/
    Matrix A (2,3);
    for (int i = 1; i<=2;i++) {
        for (int k=1; k<=3;k++) {
            A.setValue(i,k,3+i+k);
        }
    }
    Matrix B(3,2);
    for (int i = 1; i<=3;i++) {
        for (int k=1; k<=2;k++) {
            B.setValue(i,k,6-i+k);
        }
    }
    Matrix C =A*B;
    C.display();
    // Crash Test
    try {
        Matrix D=A*A;
        D.display();
    }
    catch (const std::invalid_argument& error) {
        std::cout <<"ENGINE WARNING "<<error.what()<<std::endl;
    }
    Matrix At=A.transpose();
    A.display();
    std::cout<<"********* Matrix A Transposed!!!!**********"<<std::endl;
    At.display();
    Matrix E=A*5.0;
    std::cout<<"***** Matrix A*5.0"""<<std::endl;
    E.display();
    std::cout <<"Program survived and still running!"<<std::endl;








    return 0;

}
