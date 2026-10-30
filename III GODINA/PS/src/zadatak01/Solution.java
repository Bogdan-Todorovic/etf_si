package zadatak01;

interface Coffee{
    int getPrice();
    String getDescription();
}

class SingleOrigin implements Coffee{
    private final int price = 120;
    private final String description = "Single Origin coffee";

    @Override
    public int getPrice() {
        return price;
    }

    @Override
    public String getDescription() {
        return description;
    }
}

class Blend implements Coffee{
    private final int price = 60;
    private final String description = "Blend coffee";

    @Override
    public int getPrice() {
        return price;
    }

    @Override
    public String getDescription() {
        return description;
    }
}

abstract class CoffeeDecorator implements Coffee{
    protected Coffee baseCoffee;

    protected CoffeeDecorator(Coffee baseCoffee){
        this.baseCoffee = baseCoffee;
    }
}

class MilkDecorator extends CoffeeDecorator{
    public MilkDecorator(Coffee baseCoffee) {
        super(baseCoffee);
    }

    @Override
    public int getPrice() {
        return baseCoffee.getPrice() + 30;
    }

    @Override
    public String getDescription() {
        return baseCoffee.getDescription() + " + milk";
    }
}

class SugarDecorator extends CoffeeDecorator{
    public SugarDecorator(Coffee baseCoffee) {
        super(baseCoffee);
    }

    @Override
    public int getPrice() {
        return baseCoffee.getPrice() + 10;
    }

    @Override
    public String getDescription() {
        return baseCoffee.getDescription() + " + sugar";
    }
}

class CaramelDecorator extends CoffeeDecorator{
    public CaramelDecorator(Coffee baseCoffee) {
        super(baseCoffee);
    }

    @Override
    public int getPrice() {
        return baseCoffee.getPrice() + 60;
    }

    @Override
    public String getDescription() {
        return baseCoffee.getDescription() + " + caramel";
    }
}


public class Solution {
    static void main() {
        Coffee singleOriginCoffee = new SingleOrigin();
        Coffee blendCoffee = new Blend();

        System.out.println(singleOriginCoffee.getDescription() + " " + singleOriginCoffee.getPrice());
        System.out.println(blendCoffee.getDescription() + " " + blendCoffee.getPrice());

        singleOriginCoffee = new CaramelDecorator(singleOriginCoffee);
        singleOriginCoffee = new MilkDecorator(singleOriginCoffee);

        blendCoffee = new SugarDecorator(blendCoffee);

        System.out.println(singleOriginCoffee.getDescription() + " " + singleOriginCoffee.getPrice());
        System.out.println(blendCoffee.getDescription() + " " + blendCoffee.getPrice());
    }
}
