package zadatak03;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

interface ShowStrategy{
    void show(List<String> questions);
}
class ChatBot{
    private final List<String> questions = new ArrayList<>(){
        {
            add("What is 2+2?");
            add("What is 3*3?");
            add("What is 9/3?");
            add("How are you?");
        }
    };

    private ShowStrategy strategy;

    public ChatBot(ShowStrategy strategy){
        this.strategy = strategy;
    }

    public void setStrategy(ShowStrategy strategy){
        this.strategy = strategy;
    }

    public void show(){
        strategy.show(questions);
    }
}

class DefaultStrategy implements ShowStrategy{
    @Override
    public void show(List<String> questions) {
        for (String q : questions)
            System.out.println(q);
    }
}

class RandomStrategy implements ShowStrategy{
    @Override
    public void show(List<String> questions) {
        Random random = new Random();

        while (!questions.isEmpty()){
            int index = random.nextInt(0, questions.size());
            System.out.println(questions.get(index));
            questions.remove(index);
        }
    }
}
public class Solution {
    static void main() {
        ChatBot chatBot = new ChatBot(new DefaultStrategy());
        chatBot.show();

        System.out.println("-------------");

        chatBot.setStrategy(new RandomStrategy());
        chatBot.show();
    }
}
