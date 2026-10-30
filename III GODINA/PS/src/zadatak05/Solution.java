package zadatak05;

interface Adapter {
    void setSpeed(int num);
}

class SpeedAdapter implements Adapter{
    @Override
    public void setSpeed(int num) {
        HAL hal = HAL.getInstance();
        byte[] packet = convert(num);

        hal.setSpeed(packet);
    }

    byte[] convert(int num){
        System.out.println("Converting...");
        return null;
    }
}

class HAL{
    private EngineDriver engineDriver;
    private DCdriver dCdriver;
    private RevCounterDriver revCounterDriver;

    public static HAL instance = null;

    private HAL(EngineDriver engineDriver, DCdriver dCdriver, RevCounterDriver revCounterDriver){
        this.engineDriver = engineDriver;
        this.dCdriver = dCdriver;
        this.revCounterDriver = revCounterDriver;
    }

    public static HAL getInstance(){
        if (instance == null)
            instance = new HAL(new EngineDriver(), new DCdriver(), new RevCounterDriver());

        return instance;
    }

    public void setSpeed(byte[] packet){
        dCdriver.write(packet);
        revCounterDriver.reset();
        engineDriver.start();
    }
}

class EngineDriver{
    public void start(){
        System.out.println("Starting...");
    }
}

class DCdriver{
    public void write(byte[] packet){
        System.out.println("Writing...");
    }
}

class RevCounterDriver{
    public void reset(){
        System.out.println("Resetting...");
    }
}
public class Solution {
    static void main() {
        SpeedAdapter adapter = new SpeedAdapter();
        adapter.setSpeed(200);
    }
}
