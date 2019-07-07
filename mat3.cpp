//
//  mat3.cpp
//  
//
//  Created by Krish Kansara on 07/07/19.
//

#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<std::vector<double>> matrix;
typedef std::vector<std::vector<int>> int_matrix;
const int MATRIX_DIMENSION = 3;
const std::vector<int> ZERO_DIMENSION={0,0};
const matrix NULL_MATRIX={{0}};	//not same as zero matrix; used as a return value

matrix initializeMatrix(std::vector<int> dim){
matrix mat(dim[0]);
for(int i=0;i<dim[0];i++) for(int j=0;j<dim[1];j++) mat[i].push_back(0);
return mat;
}

std::vector<int> matrixDimension(matrix input_matrix){
    int row=input_matrix.size();
    int column=input_matrix[0].size();
    for(int i=1;i<row;i++){
        if(input_matrix[i].size()!=column)
            return ZERO_DIMENSION;
    }
    return {row,column};
}
//fUnCtIoN tEmPlAtE
std::vector<int> matrixDimension(int_matrix input_matrix){
    int row=input_matrix.size();
    int column=input_matrix[0].size();
    for(int i=1;i<row;i++){
        if(input_matrix[i].size()!=column)
            return ZERO_DIMENSION;
    }
    return {row,column};
}
//try adding two seperate variables for row annd column and initialize them in matrixDimension function

//matrixCheck


bool dimensionError(matrix input_matrix_1, matrix input_matrix_2){
    if(matrixDimension(input_matrix_1) !=ZERO_DIMENSION && matrixDimension(input_matrix_1) == matrixDimension(input_matrix_2))
        return false;
    else{
        std::cout << "Dimension error! Dimensions don't match!" << std::endl;
        return true;
    }
}

//think of function template
matrix vectorToMatrix(std::vector<double> v){
	return {v};
}

matrix transposeOf(matrix input_matrix){
    if(matrixDimension(input_matrix) != ZERO_DIMENSION){
        matrix transpose(input_matrix[0].size());
        for(int i=0; i<input_matrix[0].size(); i++){
            for(int j=0; j<input_matrix.size(); j++){
                transpose[i].push_back(input_matrix[j][i]);
            }
        }
        return transpose;
    }
    return {{0}};
}

matrix scalarMultiplication(double k, matrix input_matrix){
	if(matrixDimension(input_matrix)!=ZERO_DIMENSION){
	    for(int i=0; i<input_matrix.size(); i++){
		for(int j=0; j<input_matrix[0].size(); j++){
		    input_matrix[i][j] *= k;
		}
	    }
	    return input_matrix;
	}
	std::cout<<"NOT A MATRIX!";
	return NULL_MATRIX;
}

matrix addTwoMatrices(matrix input_matrix_1, matrix input_matrix_2){
    if(!dimensionError(input_matrix_1,input_matrix_2)){
        matrix resultant(input_matrix_1.size());
        for(int i=0; i<input_matrix_1.size(); i++){
            for(int j=0; j<input_matrix_1[0].size(); j++){
                resultant[i].push_back(input_matrix_1[i][j] + input_matrix_2[i][j]);
            }
        }
        return resultant;
    }
    else{
        return {{0}};
    }
}

matrix addMatrices(std::vector<matrix> vm){
if(vm.size()==1) return vm[0];
matrix temp=addTwoMatrices(vm[vm.size()-2],vm[vm.size()-1]);
vm.pop_back();
vm.pop_back();
vm.push_back(temp);
return addMatrices(vm);
}

bool matrixMultiplicable(matrix input_matrix_1,matrix input_matrix_2){
    if(matrixDimension(input_matrix_1)[1]==matrixDimension(input_matrix_2)[0])
        return true;
    return false;
}

matrix twoMatrixProduct(matrix input_matrix_1, matrix input_matrix_2){
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

matrix matrixProduct(std::vector<matrix> vm){
if(vm.size()==1) return vm[0];
matrix temp=twoMatrixProduct(vm[vm.size()-2],vm[vm.size()-1]);
vm.pop_back();
vm.pop_back();
vm.push_back(temp);
return matrixProduct(vm);
}

matrix identityMatrix(int order){
    matrix identity(order);
    for(int i=0; i<order; i++){
        for(int j=0; j<order; j++){
            if(i==j) identity[i].push_back(1);
            else identity[i].push_back(0);
        }
    }
    return identity;
}

void displayMatrix(matrix input_matrix){
    if(matrixDimension(input_matrix)!=ZERO_DIMENSION){
	    std::cout << "The matrix is: \n";
	    for(int i=0; i<input_matrix.size(); i++){
		for(int j=0; j<input_matrix[0].size(); j++){
		    std::cout << input_matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	    }
    }
    else std::cout<<"NOT A MATRIX!";
}

void displayMatrix(int_matrix input_matrix){
    if(matrixDimension(input_matrix)!=ZERO_DIMENSION){
	    std::cout << "The matrix is: \n";
	    for(int i=0; i<input_matrix.size(); i++){
		for(int j=0; j<input_matrix[0].size(); j++){
		    std::cout << input_matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	    }
    }
    else std::cout<<"NOT A MATRIX!";
}

double matrixDeterminant3D(matrix input_matrix){	//'in' is the matrix whose determinant is to be found
	std::vector<int> d=matrixDimension(input_matrix);
	if(d[0]==3 && d[1]==3) return (input_matrix[0][0]*(input_matrix[1][1]*input_matrix[2][2]-input_matrix[1][2]*input_matrix[2][1])+input_matrix[0][1]*(input_matrix[1][2]*input_matrix[2][0]-input_matrix[2][2]*input_matrix[1][0])+input_matrix[0][2]*(input_matrix[1][0]*input_matrix[2][1]-input_matrix[1][1]*input_matrix[2][0]));
	else if(d[0]==2 && d[1]==2) return input_matrix[1][1]*input_matrix[0][0]-input_matrix[1][0]*input_matrix[0][1];
	else std::cout<<"Wait for next update da!\n";
}

int main(){
    matrix mat_1 = {{1,2,3},{4,6,6},{7,7,9}};
    matrix mat_2 = {{11,12,13},{14,15,16},{17,18,19}};
    matrix mat_3={{159,19,59},{87,98,23},{12,63,5}};
    displayMatrix(matrixProduct({mat_1,mat_2,scalarMultiplication(2,identityMatrix(3)),mat_3}));
    std::cout<<(matrixDeterminant3D(mat_1))<<std::endl;
    matrix mat_4=matrixProduct({vectorToMatrix({1,2,3}),transposeOf(vectorToMatrix({1,2,3}))});
    displayMatrix(mat_4);
    displayMatrix({matrixDimension(mat_4)});
    displayMatrix(initializeMatrix({3,3}));
    //displayMatrix(identityMatrix(3));
    //displayMatrix(addMatrices(mat_1,mat_2));
    //displayMatrix(scalarMultiplication(-1,mat_1));
    //displayMatrix(addMatrices(mat_1,identityMatrix(3)));
    //std::cout << matrixMultiplicable(mat_1,identityMatrix(2));
    return 0;
}
