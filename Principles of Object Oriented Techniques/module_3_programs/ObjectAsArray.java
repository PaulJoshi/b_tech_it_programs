class Account {
    int a, b;

    Account(int c1, int c2) {
        a = c1; b = c2;
    }

    void show() {
        System.out.println("a = " + a + " b = " + b);
    }
}

class ObjectAsArray {
    public static void main(String[] args) {
        Account ob[] = new Account[3];
        ob[0] = new Account(1, 2);
        ob[1] = new Account(3, 4);
        ob[2] = new Account(5, 6);
        
        for(int i = 0; i < 3; i++) {
            ob[i].show();
        }
    }
}
