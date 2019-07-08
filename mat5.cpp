//
//  mat4.cpp
//  
//
//  Created by Krish Kansara on 08/07/19.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

typedef std::vector<std::vector<double>> matrix;
typedef std::vector<std::vector<int>> int_matrix;
const int MATRIX_DIMENSION = 3;
const std::vector<int> ZERO_DIMENSION={0,0};
const matrix NULL_MATRIX={{0}};	//not same as zero matrix; used as a return value

//LOOK INTO ERROR MESSAGES AND stderr

void raiseError(int error_code,bool exit_program){	//or create another raiseErrorAndExit
	std::cerr<<"Error: ";
	switch(error_code){
		case 0:std::cerr<<"Not a matrix";break;
		case 1:std::cerr<<"Matrix dimensions don't match";break;
		case 2:std::cerr<<"Matrices are not multiplicable";break;
		case 3:std::cerr<<"Not a square matrix";break;
		case 4:std::cerr<<"Matrix is singular";break;
		default:std::cerr<<"Unknown error code";break;
	}
	std::cerr<<std::endl;
	if(exit_program) exit(0);	//or _Exit()?
}

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
    std::vector<int> dim=matrixDimension(input_matrix_1);
    if(dim !=ZERO_DIMENSION){
    	if(matrixDimension(input_matrix_2)==dim)
        	return false;
    	else{
        	raiseError(1,false);
        	return true;
    	}
    }
    raiseError(0,true);
}

bool isSquareMatrix(matrix input_matrix){
	std::vector<int> dim=matrixDimension(input_matrix);
	if(dim!=ZERO_DIMENSION){
		if(dim[0]==dim[1]) return true;
		return false;
	}
	raiseError(0,true);
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
    raiseError(0,true);
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
	raiseError(0,true);
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
        raiseError(1,true);
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
	if(matrixDimension(input_matrix_1)!=ZERO_DIMENSION && matrixDimension(input_matrix_2)!=ZERO_DIMENSION){
		if(matrixMultiplicable(input_matrix_1,input_matrix_2)){
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
		raiseError(2,true);
	}
	raiseError(0,true);
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
    else raiseError(0,true);
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
    else raiseError(0,true);
}

matrix minorMatrix(matrix input_matrix,std::vector<int> index_position){
	if(matrixDimension(input_matrix)!=ZERO_DIMENSION){
		matrix minor_matrix(input_matrix.size()-1);
		int skip=0;
		for(int i=0;i<input_matrix.size();i++){
			if(i==index_position[0]) {skip=1;continue;}
			for(int j=0;j<input_matrix[0].size();j++){
				if(j==index_position[1]) continue;
				minor_matrix[i-skip].push_back(input_matrix[i][j]);
			}
		}
		return minor_matrix;
	}
	raiseError(0,true);
}

/*Note: don't use the following 2 functions for normal code; use determinantOf()*/
double matrixDeterminant2D(matrix input_matrix){	//'in' is the matrix whose determinant is to be found
	return input_matrix[1][1]*input_matrix[0][0]-input_matrix[1][0]*input_matrix[0][1];
}

double matrixDeterminant3D(matrix input_matrix){	//'in' is the matrix whose determinant is to be found
	return (input_matrix[0][0]*(input_matrix[1][1]*input_matrix[2][2]-input_matrix[1][2]*input_matrix[2][1])+input_matrix[0][1]*(input_matrix[1][2]*input_matrix[2][0]-input_matrix[2][2]*input_matrix[1][0])+input_matrix[0][2]*(input_matrix[1][0]*input_matrix[2][1]-input_matrix[1][1]*input_matrix[2][0]));
}

//using adjugate method
double determinantOfSquareMatrix(matrix input_matrix){
	if(matrixDimension(input_matrix)[0]==3) return matrixDeterminant3D(input_matrix);
	if(matrixDimension(input_matrix)[0]==2) return matrixDeterminant2D(input_matrix);
	if(matrixDimension(input_matrix)[0]==1) return input_matrix[0][0];
	double det=0;
	for(int i=0;i<input_matrix[0].size();i++){
		det+=pow(-1,i)*input_matrix[0][i]*determinantOfSquareMatrix(minorMatrix(input_matrix,{0,i}));
	}
	return det;
}

double determinantOf(matrix input_matrix){
	if(matrixDimension(input_matrix)!=ZERO_DIMENSION){
		if(isSquareMatrix(input_matrix)) return determinantOfSquareMatrix(input_matrix);
		raiseError(3,true);
	}
	raiseError(0,true);
}

matrix inverseOf(matrix input_matrix){
	if(matrixDimension(input_matrix)!=ZERO_DIMENSION){
		if(isSquareMatrix(input_matrix)){
			matrix adjugate(input_matrix.size());
			double det=0;
			
			for(int j=0;j<input_matrix[0].size();j++){
					adjugate[0].push_back(pow(-1,j)*determinantOf(minorMatrix(input_matrix,{0,j})));
					det+=input_matrix[0][j]*adjugate[0][j];
				}
			if(det==0) raiseError(4,true);
			
			for(int i=1;i<input_matrix.size();i++){
				for(int j=0;j<input_matrix[0].size();j++){
					adjugate[i].push_back(pow(-1,i+j)*determinantOf(minorMatrix(input_matrix,{i,j})));
				}
			}
			return scalarMultiplication(1.0/det,transposeOf(adjugate));
		}
		raiseError(3,true);
	}
	raiseError(0,true);
}

int main(){
    std::cout<<"Hi\n";
    matrix mat_1 = {{1,2,3},{4,6,6},{7,7,9}};
    matrix mat_2 = {{11,12,13},{14,15,16},{17,18,19}};
    matrix mat_3={{159,19,59},{87,98,23},{12,63,5}};
    displayMatrix(matrixProduct({mat_1,mat_2,scalarMultiplication(2,identityMatrix(3)),mat_3}));
    std::cout<<matrixDeterminant3D(mat_2)<<'\t'<<determinantOf(mat_3)<<std::endl;
    matrix mat_4=matrixProduct({vectorToMatrix({1,2,3}),transposeOf(vectorToMatrix({1,2,3}))});
    displayMatrix(mat_4);
    std::cout<<determinantOf({{1,2,3}});
    displayMatrix({matrixDimension(mat_4)});
    displayMatrix(initializeMatrix({3,3}));
    matrix mat_5={{1,3},{3,4}};
    matrix mat_6={{1,2,3,4},{5,5,6,7},{8,9,9,11},{10,12,13,14}};
    std::cout<<determinantOf(mat_6)<<std::endl;
    displayMatrix(inverseOf(mat_1));
    displayMatrix(matrixProduct({mat_1,inverseOf(mat_1)}));
    //displayMatrix(cofactorMatrix(mat_1,{2,1}));
    //displayMatrix(identityMatrix(3));
    //displayMatrix(addMatrices(mat_1,mat_2));
    //displayMatrix(scalarMultiplication(-1,mat_1));
    //displayMatrix(addMatrices(mat_1,identityMatrix(3)));
    //std::cout << matrixMultiplicable(mat_1,identityMatrix(2));
    return 0;
}
