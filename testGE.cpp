//
//  testGE.cpp
//  
//
//  Created by Hardik Darak on 25/06/19.
//
#include <iostream>

class Vector{
private:
    double arr[];
public:
    Vector(){
        std::cout<<"This is the constructor\n";
    }
    double add(double v1[], double v2[]);
    void subtract(double v1[], double v2[]);
    void dotProduct(double v1[], double v2[]);
    void crossProduct(double v1[], double v2[]);
};

double Vector :: add(double v1[], double v2[]){
    return v1;
}

int main(){
    int abcdefgh = 10;
    std::cout<<"Hello World: "<<abcdefgh;
    Vector obj = new Vector();
    double a1[] = {1.3,2,4};
    double a2[] = {2,5,6.2};
    std::cout<<(obj.add(a1,a2));
}
