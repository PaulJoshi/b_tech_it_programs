class Shape {
    int length;
    int breadth;
    int width;

    Shape(int length, int breadth, int width) {
        this.length = length;
        this.breadth = breadth;
        this.width = width;
    }

    int[] read() {
        int dim[] = {length, breadth, width};
        return dim;
    }

    int calculateArea() {
        return length * breadth;
    }

    int calculateVolume() {
        return length * breadth * width;
    }
}