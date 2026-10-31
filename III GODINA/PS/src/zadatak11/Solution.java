package zadatak11;

import javax.print.event.PrintJobEvent;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Hero{
    private final int startingPower;
    private int coins = 0;
    private final List<Item> inventory = new ArrayList<>();

    public Hero(int power) {
        this.startingPower = power;
    }

    public int getPower() {
        int totalPower = this.startingPower;
        for (Item i : inventory)
            totalPower += i.getPower();

        return totalPower;
    }

    public int getCoins() {
        return coins;
    }

    public void sellItem(Item item){
        if (inventory.remove(item))
            this.coins += item.getValue();
    }

    public void receiveItem(Item item){
        inventory.add(item);
    }

    public void fight(Enemy enemy){
        if (getPower() > enemy.getPower())
            receiveItem(enemy.makeReward());
    }
}

abstract class Enemy{
    private final int power;

    public Enemy(int power) {
        this.power = power;
    }

    public int getPower() {
        return power;
    }

    abstract Item makeReward();
}

class Elf extends Enemy{
    public Elf(int power) {
        super(power);
    }

    @Override
    Item makeReward() {
        return new Jewelry();
    }
}

class Goblin extends Enemy{
    public Goblin(int power) {
        super(power);
    }

    @Override
    Item makeReward() {
        return new Weapon();
    }
}

class Giant extends Enemy{
    public Giant(int power) {
        super(power);
    }

    @Override
    Item makeReward() {
        Bag bag = new Bag();
        Random random = new Random();

        for (int i = 0; i < 5; i++){
            int newItem = random.nextInt(0, 3);
            switch (newItem){
                case 0:
                    bag.addItem(new Jewelry());
                    break;
                case 1:
                    bag.addItem(new Weapon());
                    break;
                case 2:
                    bag.addItem(new Bag());
                    break;
            }
        }

        return bag;
    }
}

interface Item{
    int getPower();
    int getValue();
}

class Jewelry implements Item{
    private final int value = 1000;
    private final int power = 0;

    @Override
    public int getPower() {
        return power;
    }

    @Override
    public int getValue() {
        return value;
    }
}

class Weapon implements Item{
    private final int value = 50;
    private final int power = 5000;

    @Override
    public int getValue() {
        return value;
    }

    @Override
    public int getPower() {
        return power;
    }
}

class Bag implements Item{
    private final List<Item> items = new ArrayList<>();

    @Override
    public int getPower() {
        int totalPower = 0;
        for (Item i : items)
            totalPower += i.getPower();

        return totalPower;
    }

    @Override
    public int getValue() {
        int totalValue = 0;
        for (Item i : items)
            totalValue += i.getValue();

        return totalValue;
    }

    Bag addItem(Item item){
        items.add(item);
        return this;
    }
}

public class Solution {
}
