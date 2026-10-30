package zadatak06;

import java.util.HashMap;

interface Texture{
    void draw();
}

interface WaterTexture extends Texture{
    void draw();
}

interface LandTexture extends Texture{
    void draw();
}

class MarsWaterTexture implements WaterTexture{
    @Override
    public void draw() {
        System.out.println("Drawing water on Mars");
    }
}

class MarsLandTexture implements LandTexture{
    @Override
    public void draw() {
        System.out.println("Drawing land on Mars");
    }
}

class EarthWaterTexture implements WaterTexture{
    @Override
    public void draw() {
        System.out.println("Drawing water on Earth");
    }
}

class EarthLandTexture implements LandTexture{
    @Override
    public void draw() {
        System.out.println("Drawing land of Earth");
    }
}

interface TextureFactory{
    WaterTexture createWater();
    LandTexture createLand();
}

class EarthFactory implements TextureFactory{
    @Override
    public WaterTexture createWater() {
        return new EarthWaterTexture();
    }

    @Override
    public LandTexture createLand() {
        return new EarthLandTexture();
    }
}

class MarsFactory implements TextureFactory{
    @Override
    public WaterTexture createWater() {
        return new MarsWaterTexture();
    }

    @Override
    public LandTexture createLand() {
        return new MarsLandTexture();
    }
}

class Gallery {
    private TextureFactory factory;
    private final HashMap<String, Texture> textures = new HashMap<>();
    public Gallery(TextureFactory factory){
        this.factory = factory;
    }

    public void drawLand(){
        String key = factory.getClass() + "land";
        if (!textures.containsKey(key)){
            textures.put(key, factory.createLand());
        }

        textures.get(key).draw();
    }

    public void drawWater(){
        String key = factory.getClass() + "water";
        if (!textures.containsKey(key)){
            textures.put(key, factory.createWater());
        }

        textures.get(key).draw();
    }

    public void setFactory(TextureFactory factory){
        this.factory = factory;
        textures.clear();
    }
}
public class Solution {
    static void main() {
        Gallery gallery = new Gallery(new EarthFactory());
        gallery.drawLand();
        gallery.drawWater();

        gallery.setFactory(new MarsFactory());
        gallery.drawWater();
        gallery.drawLand();
    }
}
