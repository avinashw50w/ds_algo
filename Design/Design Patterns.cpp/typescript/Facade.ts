// Subsystem 1
class Engine {
  start(): void {
    console.log('Engine started.');
  }

  stop(): void {
    console.log('Engine stopped.');
  }
}

// Subsystem 2
class FuelSystem {
  fillFuel(): void {
    console.log('Fuel tank filled.');
  }

  drainFuel(): void {
    console.log('Fuel drained from tank.');
  }
}

// Subsystem 3
class IgnitionSystem {
  ignite(): void {
    console.log('Ignition system activated.');
  }

  turnOff(): void {
    console.log('Ignition system turned off.');
  }
}

// Facade class
class CarFacade {
  private engine: Engine;
  private fuelSystem: FuelSystem;
  private ignitionSystem: IgnitionSystem;

  constructor() {
    this.engine = new Engine();
    this.fuelSystem = new FuelSystem();
    this.ignitionSystem = new IgnitionSystem();
  }

  startCar(): void {
    this.fuelSystem.fillFuel();
    this.ignitionSystem.ignite();
    this.engine.start();
    console.log('Car started.');
  }

  stopCar(): void {
    this.engine.stop();
    this.ignitionSystem.turnOff();
    this.fuelSystem.drainFuel();
    console.log('Car stopped.');
  }
}

// Client code
const carFacade = new CarFacade();

// Starting the car using the facade
carFacade.startCar();

// Stopping the car using the facade
carFacade.stopCar();


/*
The facade pattern helps to simplify the usage of complex subsystems by providing a high-level interface, hiding the details of the subsystems, and coordinating their interactions.
*/