#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::endl;

#include "unittests.h"

int main(){
  RooUnfoldGenerate();
  auto u = BuildRooUnfoldBayes();
  int n = u.GetNrows();

  std::vector<float> r;
  std::ifstream ref("../ref/bayes.ref");
  if (ref.is_open()){
    std::string line;
    while (getline(ref,line)){
      r.push_back(std::stof(line));
    }
  ref.close();
  }
  bool error = false;

  for (int i=0; i<n; i++){
    if (fabs(u[i]-r[i]>5)){
	cout<<"bin "<<i<<", difference of:"<<u[i]-r[i]<<endl;
	error = true;
      }
  }
  if (error == false)
    return 0;
  else
    return -1;
}

