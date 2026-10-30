package zadatak09;

import java.util.ArrayList;
import java.util.List;

class Panel{
    private String text = "";

    public void write(String text){
        this.text += text;
    }

    public String getText() {
        return text;
    }

    public Memento save(){
        return new Memento(this.text);
    }

    public void undo(Memento memento){
        this.text = memento.getText();
    }

    public static class Memento{
        private final String text;

        public Memento(String text) {
            this.text = text;
        }

        public String getText() {
            return text;
        }
    }
}

class Caretaker{
    private final Panel panel;
    private final List<Panel.Memento> states = new ArrayList<>();
    public Caretaker(Panel panel) {
        this.panel = panel;
    }

    public void save(){
        Panel.Memento memento = panel.save();
        states.add(memento);
    }

    public void undo(){
        if (states.isEmpty())
            return;

        Panel.Memento memento = states.getLast();
        states.removeLast();

        panel.undo(memento);
    }
}

interface Command{
    void execute();
}

class SaveCommand implements Command{
    private final Caretaker caretaker;

    public SaveCommand(Caretaker caretaker) {
        this.caretaker = caretaker;
    }

    @Override
    public void execute() {
        caretaker.save();
    }
}

class UndoCommand implements Command{
    private final Caretaker caretaker;

    public UndoCommand(Caretaker caretaker) {
        this.caretaker = caretaker;
    }

    @Override
    public void execute() {
        caretaker.undo();
    }
}

class Menu{
    private final UndoCommand undoCommand;
    private final SaveCommand saveCommand;

    public Menu(UndoCommand undoCommand, SaveCommand saveCommand) {
        this.undoCommand = undoCommand;
        this.saveCommand = saveCommand;
    }

    public void save(){
        saveCommand.execute();
    }

    public void undo(){
        undoCommand.execute();
    }
}

public class Solution {
    static void main() {
        Panel panel = new Panel();
        Caretaker caretaker = new Caretaker(panel);

        SaveCommand saveCommand = new SaveCommand(caretaker);
        UndoCommand undoCommand = new UndoCommand(caretaker);

        Menu menu = new Menu(undoCommand, saveCommand);

        menu.save();
        panel.write("test");
        System.out.println(panel.getText());
        menu.undo();
        System.out.println(panel.getText());
    }
}
