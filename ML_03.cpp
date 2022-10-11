#include <iostream>
#include <fstream>
#include <Eigen/dense>

using namespace std;

int main() {

 
  int ns = 108288;  //ns = Number of samples;
  int nif =3;       //Number of input features   (FU, FV, FW)
  int nof =6;      //Number of output features   TAUij
  int phl1 =40;     //Number of perceptrons @ hidden layer 1
  int phl2 =40;     //Number of perceptrons @ hidden layer 2
  
  
  double MSE;
  
  
    //                        +++++++ Arrays definition +++++++++
    
  Eigen::MatrixXd w_in(nif,phl1), w_h1(phl1,phl2), w_out(phl2,nof);               //Weights @ each layer
  Eigen::VectorXd  b_in(phl1), b_h1(phl2), b_out(nof);               //Warning Amin!! Biases are VECRORS not Matrices Warning again!!!!!!!!!!!! //// Biases @ each layer
  Eigen::MatrixXd X_input(ns,nif), Y_output(ns,nof);               // X_input must be standardized >>>>>  X_iput_stzd = (X-Xmin)/(Xmax-Xmin)
  Eigen::MatrixXd y, yp, y_act, z2, z2p, z2_act, p, p_act ;    // Loop variables
  Eigen::MatrixXd AA,BB;                                          //MSE   
  
  
  //====================Read and declare w_in===================================
  
  ifstream myfile;
  myfile.open ("w_in.txt");
   
  for (int i = 0; i < nif; i++) {
    for (int j = 0; j < phl1; j++) {
      myfile >> w_in(i,j);
    }
  }
  
  myfile.close();

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
  

  cout<<"********************************************"<<endl;
  cout<<w_h1(1,5);
  cout<<"********************************************"<<endl;
  cout<<"w_h1 rows= "<<w_h1.rows()<<'\t'<<"w_h1 columns= "<<w_h1.cols()<<'\n'<<"w_h1 size="<<w_h1.size()<<'\n';
    cout<<"*****************************************************************************************************"<<'\n';
   //====================Read and declare w_out===================================
  ifstream myfile3;
  myfile3.open ("w_out.txt");
   
  for (int i = 0; i < phl2; i++) {
    for (int j = 0; j < nof; j++) {
      myfile3 >> w_out(i,j);
    }
  }
  
  myfile3.close();
  

  cout<<"********************************************"<<endl;
  cout<<w_out(1,5);
  cout<<"********************************************"<<endl;
  cout<<"w_out rows= "<<w_out.rows()<<'\t'<<"w_out columns= "<<w_out.cols()<<'\n'<<"w_out size="<<w_out.size()<<'\n';
    cout<<"*****************************************************************************************************"<<'\n';   
   
   
   //==========================================Read The Biases================================================================================================\\
      //====================Read b_in===================================
  ifstream myfile4;
  myfile4.open ("b_in.txt");
   
  for (int j = 0; j < phl1; j++) {
  	myfile4 >> b_in(j);
  }
  
  myfile4.close();
  

  cout<<"********************************************"<<endl;
  cout<<b_in(5);
  cout<<"********************************************"<<endl;
  cout<<"b_in rows= "<<b_in.rows()<<'\t'<<"b_in columns= "<<b_in.cols()<<'\n'<<"b_in size="<<b_in.size()<<'\n';
    cout<<"*****************************************************************************************************"<<'\n';
   
   //====================Read b_h1===================================
  ifstream myfile5;
  myfile5.open ("b_h1.txt");
   
  for (int j = 0; j < phl2; j++) {
  	myfile5 >> b_h1(j);
  }
  
  myfile5.close();
  

  cout<<"********************************************"<<endl;
  cout<<b_h1(5);
  cout<<"********************************************"<<endl;
  cout<<"b_h1 rows= "<<b_h1.rows()<<'\t'<<"b_h1 columns= "<<b_h1.cols()<<'\n'<<"b_h1 size="<<b_h1.size()<<'\n';
    cout<<"*****************************************************************************************************"<<'\n';
   
    //====================Read b_out===================================
  ifstream myfile6;
  myfile6.open ("b_out.txt");
   
  for (int j = 0; j < nof; j++) {
  	myfile6 >> b_out(j);
  }
  
  myfile6.close();
  

  cout<<"********************************************"<<endl;
  cout<<b_out(5);
  cout<<"********************************************"<<endl;
  cout<<"b_out rows= "<<b_out.rows()<<'\t'<<"b_out columns= "<<b_out.cols()<<'\n'<<"b_out size="<<b_out.size()<<'\n';
    cout<<"*****************************************************************************************************"<<'\n';  
   
   /////////////////////////////////////////////////////////////READ THE INPUT DATA\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ 
   //////////////////////////////X_input
  ifstream myfile7;
  myfile7.open ("X_input_stzd038.txt");
   
  for (int i = 0; i < ns; i++) {
    for (int j = 0; j < nif; j++) {
      myfile7 >> X_input(i,j);
    }
  }
  
  myfile7.close();
  

  cout<<"********************************************"<<endl;
  cout<<X_input(1,2);
  cout<<"********************************************"<<endl;
  cout<<"X_input rows= "<<X_input.rows()<<'\t'<<"X_input columns= "<<X_input.cols()<<'\n'<<"X_input size="<<X_input.size()<<'\n';
  cout<<"*****************************************************************************************************"<<'\n';    
  /////////////////////////////////////////////////////////////READ THE INPUT DATA\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ 
  //////////////////////////////Youtput
  ifstream myfile8;
  myfile8.open ("Y_output038.txt");
   
  for (int i = 0; i < ns; i++) {
    for (int j = 0; j < nof; j++) {
      myfile8 >> Y_output(i,j);
    }
  }
  
  myfile8.close();
  

  cout<<"********************************************"<<endl;
  cout<<Y_output(1,2);
  cout<<"********************************************"<<endl;
  cout<<"Y_output rows= "<<Y_output.rows()<<'\t'<<"Y_output columns= "<<Y_output.cols()<<'\n'<<"Y_output size="<<Y_output.size()<<'\n';
  cout<<"*****************************************************************************************************"<<'\n';  
   
   
     
   
   //--------------------------INPUT LAYER---------------------------------
  cout<< "----------------------> Hidden 1 <------------------------------"<<'\n';
    // X_input @ w_in 
  yp = X_input*w_in;
  y = yp;
  cout << "y rows = "<<y.rows()<<'\t'<<"y columns = "<<y.cols()<<'\n';
  
    // X_input @ w_in + b_in
   
  for (int i = 0; i < ns; i++) {
    for (int j = 0; j < phl1; j++) {
      y(i,j) = yp(i,j) + b_in(j);
    }
  }
     
    
    //!!!!!!!!!!!!!!!!!!!!!!Relu!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    y_act = y;
  for (int i = 0; i < ns; i++) {
    for (int j = 0; j < phl1; j++) {
    	if (y(i,j)<0){
    		y_act(i,j) = 0;
    	}
    		else{
    			y_act(i,j)=y(i,j);
			}
		}
      
    }


  cout<< "----------------------> Hidden 2 <------------------------------"<<'\n';
    // X_input @ w_in
  z2p = y_act*w_h1;
  z2 = z2p;
  cout << "z2p rows = "<<z2p.rows()<<'\t'<<"z2p columns = "<<z2p.cols()<<'\n';
  
    // X_input @ w_in + b_in
   
  for (int i = 0; i < ns; i++) {
    for (int j = 0; j < phl2; j++) {
      z2(i,j) = z2p(i,j) + b_h1(j);
    }
  }
     
    
    //!!!!!!!!!!!!!!!!!!!!!!Relu!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    z2_act = z2;
  for (int i = 0; i < ns; i++) {
    for (int j = 0; j < phl2; j++) {
    	if (z2(i,j)<0){
    		z2_act(i,j) = 0;
    	}
    		else{
    			z2_act(i,j)=z2(i,j);
			}
		}
      
    }

  cout<< "----------------------> Output layer <------------------------------"<<'\n';
    // X_input @ w_in
  p = z2_act*w_out;
  p_act = p;
  cout << "p rows = "<<p.rows()<<'\t'<<"p columns = "<<p.cols()<<'\n';
  
    // X_input @ w_in + b_in
   
  for (int i = 0; i < ns; i++) {
    for (int j = 0; j < nof; j++) {
      p_act(i,j) = p(i,j) + b_out(j);
    }
  }
  
    ////////////////////////////////////////////////////////////////////MSE Calculation
    cout<< "------------------> MSE <------------------------------"<<'\n';
    AA =  p_act - Y_output;
    BB=AA.array().pow(2);
    MSE = BB.sum()/AA.size();
    cout<< "MSE "<< MSE<<'\n';
    
    cout<<p_act(4,3)<<'\n';
    cout<<AA.size()<<'\n';
    cout<<AA(0,0)<<'\n';
    cout<<Y_output(20,5);
    ////////////////////////////////////////////////////////////////////////////////////
  ofstream myfile100;
  myfile100.open ("FT_ij_predicted_Cpp.txt");
  myfile100<< p_act;
  myfile100.close();

  
  
  
     
     
    return 0;
}