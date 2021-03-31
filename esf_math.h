
#naming convention function_datatype_approximationtype_accuracy

# example exp_fp32_poly_5 -> exponential function with float data type using an optimal polynomial approximation with 5 digits of accuracy

float exp_fp32_poly_6(float x){
  // x in [0,1]
  float a_0 = 0.9999988704458271;
  float a_1 = 1.0000794560363868;
  float a_2 = 0.49909610298799373;
  float a_3 = 0.17040196411362313;
  float a_4 = 0.03480057985302988;
  float a_5 = 0.013903725468011486;
  
  return a_0 + x*(a_1 + x*(a_2 + x*(a_3 + x*(a_4 + a_5*x))));
}
