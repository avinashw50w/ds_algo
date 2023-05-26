interface ICar {};

class Car implements ICar { 
	constructor() {
		this.make = '';
		this.model = '';
		this.year = '';
		this.color = '';
	}
}

class CarBuilder {
  private car: ICar;
  
  constructor() {
    this.car = new Car();
  }

  setMake(make) {
    this.car.make = make;
    return this;
  }

  setModel(model) {
    this.car.model = model;
    return this;
  }

  setYear(year) {
    this.car.year = year;
    return this;
  }

  setColor(color) {
    this.car.color = color;
    return this;
  }

  build() {
    return this.car;
  }
}

// Usage example
const car = new CarBuilder()
  .setMake('Toyota')
  .setModel('Camry')
  .setYear('2022')
  .setColor('Blue')
  .build();

console.log(car);