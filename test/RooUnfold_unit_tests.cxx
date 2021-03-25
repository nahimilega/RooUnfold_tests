#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::endl;

#include "unittests.h"

bool TestBayes(){
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
  return error;
}

bool TestSVD(){
  auto u = BuildRooUnfoldSVD();
  int n = u.GetNrows();

  std::vector<float> r;
  std::ifstream ref("../ref/svd.ref");
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
  return error;
}

bool TestTUnfold(){
  auto u = BuildRooUnfoldTUnfold();
  int n = u.GetNrows();

  std::vector<float> r;
  std::ifstream ref("../ref/tunfold.ref");
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
  return error;
}

bool TestInvert(){
  auto u = BuildRooUnfoldInvert();
  int n = u.GetNrows();

  std::vector<float> r;
  std::ifstream ref("../ref/invert.ref");
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
  return error;
}

bool TestBinByBin(){
  auto u = BuildRooUnfoldBinByBin();
  int n = u.GetNrows();

  std::vector<float> r;
  std::ifstream ref("../ref/bbb.ref");
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
  return error;
}



int main(){
  RooUnfoldGenerate();
  bool error_bayes = TestBayes();
  bool error_svd = TestSVD();
  //  bool error_tunfold = TestTUnfold();
  bool error_invert = TestInvert();
  bool error_bbb = TestBinByBin();

  bool error = error_bayes & error_svd & error_invert & error_bbb;
  if (error == false)
    return 0;
  else
    return -1;
}

