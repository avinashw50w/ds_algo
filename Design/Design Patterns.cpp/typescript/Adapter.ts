// Existing Adaptee class
class EuropeanCar {
  drive(): void {
    console.log('Driving on the right side of the road.');
  }
}

// Target interface expected by the client
interface AmericanCar {
  driveOnLeftSide(): void;
}

// Adapter class
class EuropeanToAmericanAdapter implements AmericanCar {
  private europeanCar: EuropeanCar;

  constructor(europeanCar: EuropeanCar) {
    this.europeanCar = europeanCar;
  }

  driveOnLeftSide(): void {
    console.log('Driving on the left side of the road.');
    this.europeanCar.drive();
  }
}

// Client code
function testDrive(car: AmericanCar): void {
  car.driveOnLeftSide();
}

// Usage example
const europeanCar = new EuropeanCar();
const americanCar = new EuropeanToAmericanAdapter(europeanCar);

testDrive(americanCar);