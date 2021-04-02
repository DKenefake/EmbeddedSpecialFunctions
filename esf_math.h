
#naming convention function_datatype_approximationtype_accuracy

# example exp_fp32_poly_5 -> exponential function with float data type using an optimal polynomial approximation with 5 digits of accuracy

double ESF_E = 2.71828182845904523536028747135;
double ESF_PI = 3.1415926553308963775634765625;

float exp_fp32_poly_3 (float x){
  // for x in [0,1]
  float a_0 = 0.9994552135467529f;
  float a_1 = 1.0166022777557373f;
  float a_2 = 0.4217030107975006f;
  float a_3 = 0.279976487159729f;
  return a_0+x*(a_1 +x*(a_2 +x*a_3));
}

float exp_fp32_poly_7 (float x){
  // for x in [0,1]
  float a_0 = 0.9999999987424468f;
  float a_1 = 1.0000001587890517f;
  float a_2 = 0.4999967126130278f;
  float a_3 = 0.1666925406662895f;
  float a_4 = 0.04156707212926572f;
  float a_5 = 0.008539872630710326f;
  float a_6 = 0.0011554938997961866f;
  float a_7 = 0.0003299777309039571f;
  return a_0+x*(a_1 +x*(a_2 +x*(a_3 +x*(a_4 +x*(a_5 +x*(a_6 +x*a_7))))));
}

double exp_fp64_poly_16 (double x){
  // for x in [0,1]
	double a_0 = 1.0;
	double a_1 = 0.9999999999999973;
	double a_2 = 0.5000000000001484;
	double a_3 = 0.16666666666341987;
	double a_4 = 0.041666666703539176;
	double a_5 = 0.008333333084382588;
	double a_6 = 0.001388889966183505;
	double a_7 = 0.0001984095813033984;
	double a_8 = 2.4807740937379906e-05;
	double a_9 = 2.747433155793177e-06;
	double a_10 = 2.830652297263044e-07;
	double a_11 = 2.076098037816143e-08;
	double a_12 = 3.459767640813932e-09;
	return a_0+x*(a_1 +x*(a_2 +x*(a_3 +x*(a_4 +x*(a_5 +x*(a_6 +x*(a_7 +x*(a_8 +x*(a_9 +x*(a_10 +x*(a_11 +x*a_12)))))))))));
}

// raise a floating poing number to a integral power
double ipow(double x, int n){
  if(n == 0)
    return 1.0;
  if(n &1 == 0)
    return ipow(x*x, n/2); 
  else{
   if (n > 1)
      return x*ipow(x*x, n/2);
   else
      return x;
  }
}

double exp(double x){
  //example implementation of a full range exp based on exp_fp64_poly_16
  
  bool flip_flag = x < 0.0;
  x = fabs(x);
  
  // we are going to segment x into the integral and floating point components
  // x = x_f + x_int
  int x_int = int(x);
  double x_f = x - x_int;
  
  // e^x = e^x_f * e^x_int
  double f_int = ipow(ESF_E, x_int);
  double f_f = exp_fp64_poly_16(x_f);
  
  double f = f_f * f_int;
  
  // e^(-x) = 1/e^x 
  if(flip_flag){
   f = 1.0/f; 
  }
  
  return f;
}

