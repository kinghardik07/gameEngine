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
const std::vector<int> ZERO_DIMENSION={0,0};

std::vector<int> matrixDimension(matrix input_matrix){
    int row=input_matrix.size();
    int column=input_matrix[0].size();
    for(int i=1;i<row;i++){
        if(input_matrix[i].size()!=column)
            return {0,0};
    }
    return {row,column};
}
//try adding two seperate variables for row annd column and initialize them in matrixDimension function

//matrixCheck


bool dimensionError(matrix input_matrix_1, matrix input_matrix_2){
    if(matrixDimension(input_matrix_1) == matrixDimension(input_matrix_2))
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
bool matrixMultiplicable(matrix input_matrix_1,matrix input_matrix_2){
    if(matrixDimension(input_matrix_1)[1]==matrixDimension(input_matrix_2)[0])
        return true;
    return false;
}
//work in progress - matrix Multiplication

/*matrix initialiseMatrix(int r,int c){

}*/

matrix matrixProduct(matrix input_matrix_1, matrix input_matrix_2){
	if(matrixDimension(input_matrix_1)!=ZERO_DIMENSION && matrixDimension(input_matrix_2)!=ZERO_DIMENSION && matrixMultiplicable(input_matrix_1,input_matrix_2)){
		matrix output_matrix(input_matrix_1.size());
		for(int i=0; i<input_matrix_1.size(); i++){
			for(int j=0; j<input_matrix_2[0].size(); j++){
				output_matrix[i].push_back(0);
				for(int k=0; k<input_matrix_2.size(); k++){
					output_matrix[i][j]+=input_matrix_1[i][k]*input_matrix_2[k][j];//
				}
			}
		}
		return output_matrix;
	}
	return {{0}};
}

matrix identityMatrix(int order){
    matrix identity(order);
    for(int i=0; i<order; i++){
//        identity[i](order);
        for(int j=0; j<order; j++){
            if(i==j){
                identity[i].push_back(1);
                continue;
            }
            identity[i].push_back(0);
        }
    }
    return identity;
}
void displayMatrix(matrix input_matrix){
    std::cout << "The matrix is(assuming it IS a matrix): \n";
    for(int i=0; i<input_matrix.size(); i++){
        for(int j=0; j<input_matrix[0].size(); j++){
            std::cout << input_matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main(){
    matrix mat_1 = {{1,2,3},{4,5,6},{7,8,9}};
    matrix mat_2 = {{11,12,13},{14,15,16},{17,18,19}};
    displayMatrix(matrixProduct(mat_1,identityMatrix));
    //displayMatrix(identityMatrix);
    //displayMatrix(addMatrices(mat_1,mat_2));
    //displayMatrix(scalarMultiplication(-1,mat_1));
    //displayMatrix(addMatrices(mat_1,identityMatrix(3)));
    //std::cout << matrixMultiplicable(mat_1,identityMatrix(2));
}
