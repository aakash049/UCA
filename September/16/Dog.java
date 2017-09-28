public class Dog extends Animal{
    public String Gender;
    public Dog(String name) {
        super(name);
        Gender = "Male";
    }
    public static void main(String[] args) {
        Dog d = new Dog("Tommy");
        System.out.println(d.name);
        System.out.println(d.Gender);
    }    
}
