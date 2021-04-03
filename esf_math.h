// naming convention function_datatype_approximationtype_accuracy
// example exp_fp32_poly_5->exponential function with float data type using an optimal polynomial approximation with 5 digits of accuracy

double ESF_E = 2.71828182845904523536028747135;
double ESF_PI = 3.1415926553308963775634765625;

float fabs_esf(float x){
	return 	x < 0.0f ? -x : x;
}

double fabs_esf(double x){
	return 	x < 0.0f ? -x : x;
}

float exp_fp32_poly_3(float x) {
	// for x in [0,1]
	float a_0 = 0.9994552135467529f;
	float a_1 = 1.0166022777557373f;
	float a_2 = 0.4217030107975006f;
	float a_3 = 0.279976487159729f;
	return a_0 + x * (a_1 + x * (a_2 + x * a_3));
}

float exp_fp32_poly_7(float x) {
	// for x in [0,1]
	float a_0 = 0.9999999987424468f;
	float a_1 = 1.0000001587890517f;
	float a_2 = 0.4999967126130278f;
	float a_3 = 0.1666925406662895f;
	float a_4 = 0.04156707212926572f;
	float a_5 = 0.008539872630710326f;
	float a_6 = 0.0011554938997961866f;
	float a_7 = 0.0003299777309039571f;
	return a_0 + x * (a_1 + x * (a_2 + x * (a_3 + x * (a_4 + x * (a_5 + x * (a_6 + x * a_7))))));
}

double exp_fp64_poly_16(double x) {
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
	return a_0 + x * (a_1 + x * (a_2 + x * (a_3 + x * (a_4 + x * (a_5 + x * (a_6 + x * (a_7 + x * (a_8 + x * (a_9 + x * (a_10 + x * (a_11 + x * a_12)))))))))));
}

// raise a floating poing number to a integral power
double ipow(double x, int n) {
	if (n < 0) {
		x = 1.0 / x;
		n = -n;
	}

	double product = 1.0;
	double partial = x;

	while (n >= 1) {
		double flag = double(n % 2 != 0);
		product *= 1.0 - flag + flag * partial;
		partial *= partial;
		n >>= 1;
	}

	return product;
}

double exp__(double x) {
	//example implementation of a full range exp based on exp_fp64_poly_16

	bool flip_flag = x < 0.0;
	x = fabs_esf(x);

	// we are going to segment x into the integral and floating point components
	// x = x_f + x_int
	int x_int = int(x);
	double x_f = x - x_int;

	// e^x = e^x_f * e^x_int
	double f_int = ipow(ESF_E, x_int);
	double f_f = exp_fp64_poly_16(x_f);

	double f = f_f * f_int;

	// e^(-x) = 1/e^x 
	if (flip_flag) {
		f = 1.0 / f;
	}

	return f;
}

float sin_fp32_poly_3(float x) {
	// x in [0, 0.5*pi] 

	float a_0 = 0.00010772378300316632;
	float a_1 = 0.9964213967323303;
	float a_2 = 0.019080841913819313;
	float a_3 = -0.202665776014328;
	float a_4 = 0.028419241309165955;

	return a_0 + x * (a_1 + x * (a_2 + x * (a_3 + x * a_4)));
}

float sin_fp32_poly_7(float x) {
	// x in [0, 0.5*pi] 

	float a_0 = -1.953677397636966e-08;
	float a_1 = 1.0000015497207642;
	float a_2 = -2.022928310907446e-05;
	float a_3 = -0.16656678915023804;
	float a_4 = -0.00023970396432559937;
	float a_5 = 0.008639206178486347;
	float a_6 = -0.00020570005290210247;
	float a_7 = -0.0001373232080368325;

	return a_0 + x * (a_1 + x * (a_2 + x * (a_3 + x * (a_4 + x * (a_5 + x * (a_6 + x * a_7))))));
}


double sin_fp64_poly_16(double x) {
	// x in [0, 0.5*pi] 

	double a_0 = 3.3325480822228105e-17;
	double a_1 = 0.9999999999999918;
	double a_2 = 3.3858844847093896e-13;
	double a_3 = -0.1666666666721373;
	double a_4 = 4.608238316017612e-11;
	double a_5 = 0.008333333101125396;
	double a_6 = 7.565121749902032e-10;
	double a_7 = -0.00019841436640046875;
	double a_8 = 2.5515814884108134e-09;
	double a_9 = 2.753001299354405e-06;
	double a_10 = 2.02661079804195e-09;
	double a_11 = -2.606226621297559e-08;
	double a_12 = 3.1293079674057407e-10;
	double a_13 = 1.1222774696232966e-10;

	return a_0 + x * (a_1 + x * (a_2 + x * (a_3 + x * (a_4 + x * (a_5 + x * (a_6 + x * (a_7 + x * (a_8 + x * (a_9 + x * (a_10 + x * (a_11 + x * (a_12 + x * a_13))))))))))));
}

float cos_fp32_poly_4(float x) {
	// x in [0, 0.5*pi] 

	float a_0 = 0.9998922944068909;
	float a_1 = 0.0032202100846916437;
	float a_2 = -0.5152291059494019;
	float a_3 = 0.02410241961479187;
	float a_4 = 0.028419241309165955;

	return a_0 + x * (a_1 + x * (a_2 + x * (a_3 + x * a_4)));
}

float cos_fp32_poly_7(float x) {
	// x in [0, 0.5*pi] 

	float a_0 = 1.0;
	float a_1 = 1.6226621255555074e-06;
	float a_2 = -0.5000221133232117;
	float a_3 = 0.00011517452367115766;
	float a_4 = 0.04137105867266655;
	float a_5 = 0.00041493194294162095;
	float a_6 = -0.0017156476387754083;
	float a_7 = 0.0001373232080368325;

	return a_0 + x * (a_1 + x * (a_2 + x * (a_3 + x * (a_4 + x * (a_5 + x * (a_6 + x * a_7))))));
}

double cos_fp64_poly_16(double x) {
	// x in [0, 0.5*pi] 

	double a_0 = 1.0;
	double a_1 = -2.483312936899274e-16;
	double a_2 = -0.4999999999999883;
	double a_3 = -2.1822946266852489e-13;
	double a_4 = 0.04166666666879297;
	double a_5 = -1.2461996573742913e-11;
	double a_6 = -0.0013888888412970804;
	double a_7 = -1.243327293042927e-10;
	double a_8 = 2.4801816038635867e-05;
	double a_9 = -3.00643391207725e-10;
	double a_10 = -2.752905011819677e-07;
	double a_11 = -1.8760267979388781e-10;
	double a_12 = 2.1724707129204808e-09;
	double a_13 = -2.409389140074968e-11;
	double a_14 = -8.022898608569874e-12;

	return a_0 + x * (a_1 + x * (a_2 + x * (a_3 + x * (a_4 + x * (a_5 + x * (a_6 + x * (a_7 + x * (a_8 + x * (a_9 + x * (a_10 + x * (a_11 + x * (a_12 + x * (a_13 + x * a_14)))))))))))));
}
