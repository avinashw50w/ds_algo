// Component interface
interface Car {
  assemble(): string;
}

// Concrete component
class BasicCar implements Car {
  assemble(): string {
    return 'Basic car';
  }
}

// Decorator base class
class CarDecorator implements Car {
  protected car: Car;

  constructor(car: Car) {
    this.car = car;
  }

  assemble(): string {
    return this.car.assemble();
  }
}

// Concrete decorators
class SportsCar extends CarDecorator {
  assemble(): string {
    return `${super.assemble()} with sports car features`;
  }
}

class LuxuryCar extends CarDecorator {
  assemble(): string {
    return `${super.assemble()} with luxury car features`;
  }
}

// Client code
const basicCar: Car = new BasicCar();
console.log(basicCar.assemble()); // Output: Basic car

const sportsCar: Car = new SportsCar(basicCar);
console.log(sportsCar.assemble()); // Output: Basic car with sports car features

const luxuryCar: Car = new LuxuryCar(basicCar);
console.log(luxuryCar.assemble()); // Output: Basic car with luxury car features

const sportsLuxuryCar: Car = new LuxuryCar(new SportsCar(basicCar));
console.log(sportsLuxuryCar.assemble()); // Output: Basic car with sports car features with luxury car features
