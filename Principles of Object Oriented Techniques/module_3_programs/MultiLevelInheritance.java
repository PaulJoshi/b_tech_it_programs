class Box {
    private double w, h, d;
    
    Box(double a1, double a2, double a3) {
        w = a1; h = a2; d = a3;
    }

    Box() {
        w = -1; h = -1; d = -1;
    }

    double volume() {
        return w * h * d;
    }
}

class BoxWeight extends Box {
    double weight;

    BoxWeight(double b1, double b2, double b3, double b4) {
        super(b1, b2, b3);
        weight = b4;
    }

    BoxWeight() {
        super();
        weight =-1;
    }
}

class Shipment extends BoxWeight {
    double cost;

    Shipment(double c1, double c2, double c3, double c4, double c5) {
        super(c1, c2, c3, c4);
        cost = c5;
    }

    Shipment() {
        super();
        cost =- 1;
    }
}

class MultilevelInheritance {
    public static void main(String[] args) {
        Shipment ob1 = new Shipment(1, 2, 3, 4, 5);
        Shipment ob2 = new Shipment(10, 20, 30, 40, 50);

        System.out.println("Volume of Ob1 = " + ob1.volume());
        System.out.println("Weight of Ob1 = " + ob1.weight + " Cost = " + ob1.cost);
        
        System.out.println("Volume of Ob2 = " + ob2.volume());
        System.out.println("Weight of Ob2 = " + ob2.weight + " Cost = " + ob2.cost);
    }
}