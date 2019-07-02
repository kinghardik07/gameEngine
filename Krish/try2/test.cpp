#include<iostream>
#include<vector>
#include<cmath>

const int VECTOR_DIMENSION = 3;

void initailizeVector(std::vector<double> &input_vector){
    for(int i=0;i<VECTOR_DIMENSION;i++)
        input_vector[i]=0;
}

double magnitudeOfVector(std::vector<double> input_vector){
    double magnitude = 0;
    for(int i=0;i<VECTOR_DIMENSION;i++){
        magnitude += pow(input_vector[i],2);
    }
    magnitude = sqrt(magnitude);
    return magnitude;
}

void displayVector(std::vector<double> input_vector){
    std::cout << "The vector is ";
    std::cout<<"(";
    for(int i=0;i<input_vector.size();i++){
        if(i!=0) std::cout<<",";
        std::cout<<input_vector[i];
    }
    std::cout<<")"<<std::endl;
}

void scalarMultiplication(double k, std::vector<double> &input_vector){
    for(int i=0;i<VECTOR_DIMENSION;i++)
        input_vector[i] *= k;
}

double innerProduct(std::vector<double> vector_1,std::vector<double> vector_2){
    double dot_product=0;
    for(int i=0;i<VECTOR_DIMENSION;i++)
        dot_product+=vector_1[i]*vector_2[i];
    return dot_product;
}

std::vector<double> crossProduct(std::vector<double> vector_1,std::vector<double> vector_2){
    return {vector_1[1]*vector_2[2]-vector_1[2]*vector_2[1],vector_1[2]*vector_2[0]-vector_1[0]*vector_2[2],vector_1[0]*vector_2[1]-vector_1[1]*vector_2[0]};
}

std::vector<double> addVector(std::vector<std::vector<double>> vector_vector){
    std::vector<double> resultant_vector (VECTOR_DIMENSION);
    std::cout << "In addVector\nSize of vector_vector: " << vector_vector.size() <<std::endl;
    for(int i=0;i<VECTOR_DIMENSION;i++){
        for(int j=0;j<vector_vector.size();j++){
            resultant_vector[i]+=vector_vector[j][i];
            //std::cout<<resultant_vector[i]<<std::endl;
        }
    }
    return resultant_vector;
}

std::vector<double> unitVectorOf(std::vector<double> input_vector){
    scalarMultiplication((1/magnitudeOfVector(input_vector)),input_vector);
    return input_vector;
}

int main(){
    std::vector<double> vector_1 = {3,4,0},vector_2 = {0,0,1};
    //std::cout<<&vector_1<<std::endl;
    displayVector(addVector({vector_1,vector_2}));
    scalarMultiplication(9,vector_1);
    displayVector(vector_1);
    std::cout << "The value of dot product is: " << innerProduct(vector_1,vector_2) << std::endl;
    displayVector(crossProduct(vector_1,vector_2));
    std::cout << "Magnitude of vector is: " << magnitudeOfVector(vector_1)<<std::endl;
    displayVector(unitVectorOf(vector_1));
    return 0;
}
