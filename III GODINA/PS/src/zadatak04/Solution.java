package zadatak04;

interface Product1{
    Product1 clone();
}

interface Product2{
    Product2 clone();
}

class Product1A implements Product1{
    private int a;
    public Product1A(int a){
        this.a = a;
    }

    @Override
    public Product1 clone() {
        return new Product1A(this.a);
    }
}
class Product1B implements Product1{
    private int b;
    public Product1B(int b){
        this.b = b;
    }

    @Override
    public Product1 clone() {
        return new Product1B(this.b);
    }
}

class Product2A implements Product2{
    private int a;
    public Product2A(int a){
        this.a = a;
    }

    @Override
    public Product2 clone() {
        return new Product2A(this.a);
    }
}
class Product2B implements Product2{
    private int b;
    public Product2B(int b){
        this.b = b;
    }

    @Override
    public Product2 clone() {
        return new Product2B(this.b);
    }
}

abstract class AbstractFactory{
    protected Product1 product1;
    protected Product2 product2;

    public AbstractFactory(Product1 product1, Product2 product2){
        this.product1 = product1;
        this.product2 = product2;
    }

    abstract public Product1 createProduct1();
    abstract public Product2 createProduct2();
}

class FactoryA extends AbstractFactory{
    public FactoryA(Product1A product1, Product2A product2){
        super(product1, product2);
    }

    @Override
    public Product1 createProduct1() {
        return product1.clone();
    }

    @Override
    public Product2 createProduct2() {
        return product2.clone();
    }
}

class FactoryB extends AbstractFactory{
    public FactoryB(Product1B product1, Product2B product2){
        super(product1, product2);
    }

    @Override
    public Product1 createProduct1() {
        return product1.clone();
    }

    @Override
    public Product2 createProduct2() {
        return product2.clone();
    }
}

public class Solution {
    static void main() {

        AbstractFactory factory1 = new FactoryA(new Product1A(4), new Product2A(10));

        Product1 product5 = factory1.createProduct1();
        Product2 product6 = factory1.createProduct2();
    }
}
