// Subject interface
interface Subject {
  registerObserver(observer: Observer): void;
  removeObserver(observer: Observer): void;
  notifyObservers(): void;
}

// Observer interface
interface Observer {
  update(message: string): void;
}

// Concrete Subject class
class WeatherStation implements Subject {
  private observers: Observer[] = [];
  private temperature: number = 0;

  registerObserver(observer: Observer): void {
    this.observers.push(observer);
  }

  removeObserver(observer: Observer): void {
    const index = this.observers.indexOf(observer);
    if (index !== -1) {
      this.observers.splice(index, 1);
    }
  }

  notifyObservers(): void {
    for (const observer of this.observers) {
      observer.update(`Temperature is ${this.temperature} degrees.`);
    }
  }

  setTemperature(temperature: number): void {
    this.temperature = temperature;
    this.notifyObservers();
  }
}

// Concrete Observer class
class User implements Observer {
  private name: string;

  constructor(name: string) {
    this.name = name;
  }

  update(message: string): void {
    console.log(`${this.name} received an update: ${message}`);
  }
}

// Client code
const weatherStation: WeatherStation = new WeatherStation();

const user1: Observer = new User('User 1');
const user2: Observer = new User('User 2');
const user3: Observer = new User('User 3');

weatherStation.registerObserver(user1);
weatherStation.registerObserver(user2);
weatherStation.registerObserver(user3);

weatherStation.setTemperature(25);

weatherStation.removeObserver(user2);

weatherStation.setTemperature(30);


/*
The observers receive the update message and can perform actions based on the received information.

Note that in this example, the observers simply log the received message, but in a real-world scenario, they could perform any relevant actions based on the update, such as updating a user interface, triggering further operations, or processing the data in some way.

The observer pattern facilitates the loose coupling between the subject and observers, allowing multiple observers to receive updates and react independently to changes in the subject.
*/