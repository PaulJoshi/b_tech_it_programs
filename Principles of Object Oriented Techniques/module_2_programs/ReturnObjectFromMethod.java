class ReturnTestOb {
    int a;

    ReturnTestOb(int a) {
        this.a = a;
    }

    ReturnTestOb incrByTen() {
        ReturnTestOb temp = new ReturnTestOb(a + 10);
        return temp;
    }
}

public class ReturnObjectFromMethod {
    public static void main(String args[]) {
        ReturnTestOb ob1 = new ReturnTestOb(2);        
        ReturnTestOb ob2;        
        ob2 = ob1.incrByTen();
    }
}
