package zadatak10;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

interface Client{
    void updatePrice(Stock stock, int delta);
}

class Stock{
    private int price;
    private final String name;

    public Stock(String name, int price) {
        this.name = name;
        this.price = price;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public String getName() {
        return name;
    }
}

class StockService{
    private static StockService instance;
    private final HashMap<Stock, Integer> stocks = new HashMap<>();
    private final List<Client> clients = new ArrayList<>();

    public static StockService getInstance(){
        if (instance == null)
            instance = new StockService();

        return instance;
    }
    public void subscribe(Client client){
        clients.add(client);
    }

    public void unsubscribe(Client client){
        clients.remove(client);
    }

    public void buyStocks(Stock stock, int count){
        if (stocks.containsKey(stock) && stocks.get(stock) >= count)
            stocks.put(stock, stocks.get(stock) - count);
    }

    public void sellStocks(Stock stock, int count){
        if (stocks.containsKey(stock))
            stocks.put(stock, stocks.get(stock) + count);
    }

    private void stockChange(Stock stock, int delta){
        for (Client c : clients){
            c.updatePrice(stock, delta);
        }
    }

    public void newPrice(Stock stock, int newPrice){
        int delta = newPrice - stock.getPrice();
        stock.setPrice(newPrice);

        stockChange(stock, delta);
    }

    public void addStock(Stock stock, int startingCount){
        stocks.put(stock, startingCount);
    }
}

class User implements Client{
    private final HashMap<Stock, Integer> ownedStocks = new HashMap<>();

    @Override
    public void updatePrice(Stock stock, int delta) {
        if (delta < 0){
            StockService.getInstance().buyStocks(stock, 2);
            ownedStocks.put(stock, ownedStocks.getOrDefault(stock, 0) + 2);
        } else if (delta > 0 && ownedStocks.getOrDefault(stock, 0) > 0){
            StockService.getInstance().sellStocks(stock, ownedStocks.get(stock));
            ownedStocks.put(stock, 0);
        }
    }
}

class Company implements Client{
    private final HashMap<Stock, Integer> ownedStocks = new HashMap<>();
    private static final int threshold = 100;
    @Override
    public void updatePrice(Stock stock, int delta) {
        if (delta < 0 && stock.getPrice() < threshold){
            StockService.getInstance().buyStocks(stock, 5);
            ownedStocks.put(stock, ownedStocks.getOrDefault(stock, 0) + 5);
        } else if (delta > 0 && ownedStocks.getOrDefault(stock, 0) > 0){
            StockService.getInstance().sellStocks(stock, ownedStocks.get(stock));
            ownedStocks.put(stock, 0);
        }
    }
}

public class Solution {
}
