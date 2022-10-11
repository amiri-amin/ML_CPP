#include <iostream>
#include <fstream>
#include <Eigen/dense>

using namespace std;

int main() {

  int n=3, m=40;
  int ns = 108288;  //ns = Number of samples;
  int nif =3;       //Number of input features   (FU, FV, FW)
  int nof =6;      //Number of output features   TAUij
  int phl1 =40;     //Number of perceptrons @ hidden layer 1
  int phl2 =40;     //Number of perceptrons @ hidden layer 2
  
  
    //                        +++++++ Arrays definition +++++++++
    
  Eigen::MatrixXf w_in(nif,phl1), w_h1(phl1,phl2), w_out(phl2,nof);               //Weights @ each layer
  Eigen::MatrixXf b_in(1,phl1), b_h1(1,phl2), b_out(1,nof);               //Biases @ each layer
  Eigen::MatrixXf X_input(ns,nif), Y_output(ns,nof);               // X_input must be standardized >>>>>  X_iput_stzd = (X-Xmin)/(Xmax-Xmin)
  Eigen::MatrixXf y, yp, y_act, z2, z2p, z2_act, p, p_act ;    // Loop variables
  Eigen::MatrixXf AA;                                          //MSE   
  
  
  //====================Read and declare w_in===================================
  
  ifstream myfile;
  myfile.open ("w_in.txt");
   
  for (int i = 0; i < nif; i++) {
    for (int j = 0; j < phl1; j++) {
      myfile >> w_in(i,j);
    }
  }
  
  myfile.close();
  
  for (int i = 0; i < nif; i++) {
    for (int j = 0; j < phl1; j++) {
      cout << w_in(i,j);
    }
    cout << endl;
  }
  cout<<"********************************************"<<endl;
  cout<<w_in(1,5);
  cout<<"********************************************"<<endl;
  cout<<"w_in rows= "<<w_in.rows()<<'\t'<<"w_in columns= "<<w_in.cols()<<'\n'<<"w_in size="<<w_in.size()<<'\n';
  cout<<"*****************************************************************************************************"<<'\n';
  
    
    //====================Read and declare w_h1===================================
  ifstream myfile2;
  myfile2.open ("w_h1.txt");
   
  for (int i = 0; i < phl1; i++) {
    for (int j = 0; j < phl2; j++) {
      myfile2 >> w_h1(i,j);
    }
  }
  
  myfile2.close();
  
  for (int i = 0; i < phl1; i++) {
    for (int j = 0; j < phl2; j++) {
      cout << w_h1(i,j);
    }
    cout << endl;
  }
  cout<<"********************************************"<<endl;
  cout<<w_h1(1,5);
  cout<<"********************************************"<<endl;
  cout<<"w_h1 rows= "<<w_h1.rows()<<'\t'<<"w_h1 columns= "<<w_h1.cols()<<'\n'<<"w_h1 size="<<w_h1.size();
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}