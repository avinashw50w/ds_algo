// Elevator State Interface
interface ElevatorState {
  openDoor(): void;
  closeDoor(): void;
  requestFloor(floor: number): void;
  stop(): void;
}

enum Direction {
  UP = "UP",
  DOWN = "DOWN"
}

// Concrete State: Elevator is Stopped
class StoppedState implements ElevatorState {

  constructor(private elevator: Elevator) {}

  openDoor() {
    console.log('Opening doors...');
  }

  closeDoor() {
    console.log('Closing doors...');
  }

  requestFloor(floor: number) {
    this.elevator.addDestinationFloor(floor);
    this.elevator.setState(new MovingState(this.elevator));
    this.elevator.serverRequestedFloors();
  }

  stop() {
    console.log('Elevator is already stopped.');
  }
}

// Concrete State: Elevator is Moving
class MovingState implements ElevatorState {

  constructor(private elevator: Elevator) {}

  openDoor() {
    console.log('Cannot open doors while moving.');
  }

  closeDoor() {
    console.log('Cannot close doors while moving.');
  }

  requestFloor(floor: number) {
    this.elevator.addDestinationFloor(floor);
  }

  stop() {
    console.log('Stopping elevator...');
    this.elevator.setState(new StoppedState(this.elevator));
  }
}

// Context: Elevator
class Elevator {
  private state: ElevatorState;
  private currentFloor: number = 1;
  private requestedFloors: number[] = [];

  constructor() {
    this.state = new StoppedState(this);
  }

  setState(state: ElevatorState) {
    this.state = state;
  }

  openDoor() {
    this.state.openDoor();
  }

  closeDoor() {
    this.state.closeDoor();
  }

  requestFloor(floor: number) {
    this.state.requestFloor(floor);
  }

  stop() {
    this.state.stop();
  }

  // requestFloor(floor: number) {
  //   if (floor === this.currentFloor) {
  //     console.log(`Already on floor ${floor}.`);
  //   } else {
  //     this.requestedFloors.push(floor);
  //     this.moveElevator();
  //   }
  // }

  private addDestinationFloor(floor: number) {
    if (this.requestedFloors.indexOf(floor) !== -1) {
      console.log('Floor already requested.');
    }
    this.requestedFloors.push(floor);

  }

  private moveElevator(direction: Direction) {
  }

  private serverRequestedFloors() {
    if (this.requestedFloors.length === 0) {
      this.setState(new StoppedState());
      console.log('Elevator is now idle.');
      return;
    }

    const nextFloor = this.requestedFloors.shift()!;

    if (nextFloor > this.currentFloor) {
      while (nextFloor > this.currentFloor) {
        console.log(`Moving up to floor ${this.currentFloor + 1}...`);
        this.moveElevator(Direction.UP);
        this.currentFloor += 1;
      }
    } else {
      while (nextFloor < this.currentFloor) {
        console.log(`Moving down to floor ${this.currentFloor - 1}...`);
        this.moveElevator(Direction.DOWN);
        this.currentFloor -= 1;
      }
    }

    this.stop();
    this.openDoor();
    delay(10000);
    this.closeDoor();
    this.serverRequestedFloors();
  }
}

// Usage
const elevator = new Elevator();

elevator.requestFloor(5); // Outputs: Moving up to floor 5...
elevator.requestFloor(3); // Outputs: Moving down to floor 3...
elevator.requestFloor(5); // Outputs: Moving up to floor 5...
elevator.requestFloor(2); // Outputs: Moving down to floor 2...
