#include "vector.hpp"

std::vector<double> addVector(std::vector<std::vector<double>> vv){
	std::vector<double> vf;
	for(int i=0;i<v_dim;i++){
		for(int j=0;j<vv.size();j++){
			vf[i]+=vv[j][i];
		}
	}
	return vf;
}

void displayVector(std::vector<double> v){
	std::cout<<"(";
	for(int i=0;i<v.size();i++){
		if(i>0) std::cout<<",";
		std::cout<<v[i];
	}
	std::cout<<")";
}
