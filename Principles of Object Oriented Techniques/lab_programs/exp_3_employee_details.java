// Construct a Java class to store some employee details and provide methods to set and get values.

class EmployeeDetails{
    int emp_id, salary;
    String name, address, email;

    void setDetails(int id, int sal, String nm, String adrs, String eml) {
        emp_id = id;
        salary = sal;
        name = nm;
        address = adrs;
        email = eml;
    }

    void getDetails() {
        System.out.println("\nName     :  " + name + "\nID       :  " + emp_id + "\nSalary   :  " + salary + "\nAddress  :  " + address + "\nEmail    :  " + email);
    }
}

class Employee{
    public static void main(String args[]) {
        EmployeeDetails obj1 = new EmployeeDetails();
        obj1.setDetails(12, 210000, "Tessa Young", "Emory, Atlanta", "tessayoung@abc.co");
        obj1.getDetails();
    }
}