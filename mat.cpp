//
//  mat.cpp
//  
//
//  Created by Hardik Darak on 05/07/19.
//

#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<std::vector<double>> matrix;
const int MATRIX_DIMENSION = 3;

bool dimensionError(matrix input_matrix_1, matrix input_matrix_2){
    if(input_matrix_1.size() == input_matrix_2.size())
        return false;
    else{
        std::cout << "Dimension error! Dimensions don't match!" << std::endl;
        return true;
    }
}
matrix scalarMultiplication(double k, matrix input_matrix){
    for(int i=0; i<input_matrix.size(); i++){
        for(int j=0; j<MATRIX_DIMENSION; j++){
            input_matrix[i][j] *= k;
        }
    }
    return input_matrix;
}
matrix addMatrices(matrix input_matrix_1, matrix input_matrix_2){
    std::cout << "Adding matrices..."<<std::endl;
    //std::cout << input_matrix_1.size() << "," << input_matrix_2.size() << std::endl;
    if(!dimensionError(input_matrix_1,input_matrix_2)){
        matrix resultant(input_matrix_1.size());//creating a matrix to store the results
        for(int i=0; i<input_matrix_1.size(); i++){
            //std::vector<double> row_result;//#2
            for(int j=0; j<MATRIX_DIMENSION; j++){
                resultant[i].push_back(input_matrix_1[i][j] + input_matrix_2[i][j]);
                //row_result.push_back(input_matrix_1[i][j] + input_matrix_2[i][j]);//#2
                //std::cout << resultant[i][j];
            }
            //            resultant[i] = row_result;//#2
        }
        return resultant;
    }
    else{
        return {{0}};
    }
}

//work in progress - matrix Multiplication
matrix matrixProduct(matrix input_matrix_1, matrix input_matrix_2){
    //if(!dimensionError(input_matrix_1,input_matrix_2)){
        for(int i=0; i<input_matrix_1.size(); i++){
            for(int j=0; j<MATRIX_DIMENSION; i++){
                for(int k=0; k<MATRIX_DIMENSION; k++){

                }
            }
        }
    return {{0}};
}

void displayMatrix(matrix input_matrix){
    std::cout << "The matrix is: \n";
    for(int i=0; i<input_matrix.size(); i++){
        for(int j=0; j<MATRIX_DIMENSION; j++){
            std::cout << input_matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main(){
    matrix mat_1 = {{1,2,3},{4,5,6},{7,8,9}};
    matrix mat_2 = {{1,0,3},{3,4,5},{2,3,4}};
    matrix identityMatrix = {{1,0,0},{0,1,0},{0,0,1}};
    //displayMatrix(identityMatrix);
    //displayMatrix(addMatrices(mat_1,mat_2));
    //displayMatrix(scalarMultiplication(-1,mat_1));

}
