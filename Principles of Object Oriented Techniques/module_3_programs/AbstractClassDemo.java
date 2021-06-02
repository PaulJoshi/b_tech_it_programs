abstract class A {
    abstract void callme();

    void callmetoo() {
        System.out.println("This concrete method");
    }
}

class B extends A {
    void callme() {
        System.out.println("implemented inside B");
    }
}

class AbstractClassDemo {
    public static void main(String[] args) {
        B obj = new B();
        obj.callme();
        obj.callmetoo();
    }
}