/** Adapter pattern works as a bridge between two incompatible interfaces. 
This type of design pattern comes under structural pattern as this pattern combines the capability 
of two independent interfaces.

Used when we want some component having extra features than the current component, but the current one
is incompatible with the new one.
*/

public interface Movable {
    // returns speed in MPH 
    double getSpeed();
}

public class BugattiVeyron implements Movable {
 
    @Override
    public double getSpeed() {
        return 268;
    }
}

public interface AdvancedMovable {
    // returns speed in KM/H 
    double getSpeed();
}

public class MovableAdapter implements AdvancedMovable {
    private Movable luxuryCars;
    
    // standard constructors

    @Override
    public double getSpeed() {
        return convertMPHtoKMPH(luxuryCars.getSpeed());
    }
    
    private double convertMPHtoKMPH(double mph) {
        return mph * 1.60934;
    }
}

@Test
public void whenConvertingMPHToKMPH_thenSuccessfullyConverted() {
    Movable bugattiVeyron = new BugattiVeyron();
    AdvancedMovable bugattiVeyronAdapter = new MovableAdapter(bugattiVeyron);
 
    assertEquals(bugattiVeyronAdapter.getSpeed(), 431.30312, 0.00001);
}