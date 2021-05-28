class Box {
	private double w, h, d;

	Box(double a, double b, double c) {
	    w = a; h = b; d = c;
	}

	double volume() {
	    return w * h * d;
	}

}
class BoxWeight extends Box {
	double weight;
    
	BoxWeight(double a1, double a2, double a3, double a4) {
		super(a1, a2, a3);
		weight = a4;
	}
}
class DemoSuper {
	public static void main(String args[]) {
		BoxWeight ob = new BoxWeight(10, 20, 30, 40);
		double volume = ob.volume();
		System.out.println("Volume  = " + volume);
		System.out.println("Weight = " + ob.weight);
		//System.out.println("Width=  " + ob.w + "Height = " + ob.h + "depth= " + ob.d);
	}
}