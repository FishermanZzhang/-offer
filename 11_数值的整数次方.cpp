double Power(double base, int exponent){
	function<double(double,int)> mypower = [&mypower](double base, int x){
		if (x == 0) return 1.0;
		if (x == 1) return base;
		double r = mypower(base, x / 2);
		return r * r * ((x & 1) ? base : 1.0);
	};
	if(base == 0.0) return .0;
	if (exponent < 0) return mypower(1.0 /base, -exponent);
	return mypower(base, exponent);
}
