#include<iostream>
#include<vector>

const int v_dim=3;

std::vector<double> add(std::vector<std::vector<double> > vv){
    std::vector<double> vf;
    for(int i=0;i<v_dim;i++){
        for(int j=0;j<vv.size();j++){
            vf[i]+=vv[i][j];
        }
    }
    return vf;
}

void display(std::vector<double> v){
    std::cout<<'(';
    for(int i=0;i<v.size();i++){
        if(i!=0) std::cout<<',';
        std::cout<<v[i];
    }
    std::cout<<')';
}

int main(){
    std::vector<double> v1={1,2,3},v2={4,5,6};
    std::cout<<&v1;
    display(v1);
    display(add({v1,v2}));

    return 0;
}
