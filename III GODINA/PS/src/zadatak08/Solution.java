package zadatak08;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Wizard{
    private int x, y;
    private int health;

    public Wizard(int y, int x, int health) {
        this.y = y;
        this.x = x;
        this.health = health;
    }

    void moveOne(){
        this.x += 10;
        this.y += 10;
    }

    void teleport(int x, int y){
        this.x = x;
        this.y = y;
    }

    void addHealth(int heal){
        health += heal;
    }

    void loseHealth(int damage){
        health -= Math.abs(damage);
    }

    void interact(MagicMushroom mushroom){
        mushroom.applyEffect();
    }
}

interface MagicEffectComponent{
    void apply();
}

class MagicMushroom{
    private final MagicEffectComponent effect;

    public MagicMushroom(MagicEffectComponent effect) {
        this.effect = effect;
    }

    public void applyEffect(){
        effect.apply();
    }
}

abstract class Effect implements MagicEffectComponent{
    protected final Wizard wizard;

    public Effect(Wizard wizard){
        this.wizard = wizard;
    }
    public abstract void apply();
}

class TeleportEffect extends Effect{
    public TeleportEffect(Wizard wizard){
        super(wizard);
    }

    @Override
    public void apply() {
        Random random = new Random();
        int x = random.nextInt(-1000, 1000);
        int y = random.nextInt(-1000, 1000);

        wizard.teleport(x, y);
    }
}

class LoseHealthEffect extends Effect{
    public LoseHealthEffect(Wizard wizard) {
        super(wizard);
    }

    @Override
    public void apply() {
        wizard.loseHealth(40);
    }
}

class AddHealthEffect extends Effect{
    public AddHealthEffect(Wizard wizard) {
        super(wizard);
    }

    @Override
    public void apply() {
        wizard.addHealth(20);
    }
}

class Spell implements MagicEffectComponent{
    private final List<MagicEffectComponent> effects = new ArrayList<>();

    @Override
    public void apply() {
        for (MagicEffectComponent e : effects)
            e.apply();
    }

    public void addEffect(MagicEffectComponent component){
        effects.add(component);
    }
}

public class Solution {
    static void main() {
        Wizard wizard1 = new Wizard(10, 20, 100);
        Wizard wizard2 = new Wizard(10, 20, 100);
        Wizard wizard3 = new Wizard(10, 20, 100);

        MagicMushroom mushroom1 = new MagicMushroom(new AddHealthEffect(wizard1));
        Spell spell = new Spell();

        spell.addEffect(new TeleportEffect(wizard2));
        spell.addEffect(new LoseHealthEffect(wizard2));

        mushroom1.applyEffect();
        MagicMushroom mushroom2 = new MagicMushroom(spell);
        mushroom2.applyEffect();
    }
}
