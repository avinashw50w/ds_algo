// Elevator State Interface
interface ElevatorState {
  openDoors(): void;
  closeDoors(): void;
  moveUp(): void;
  moveDown(): void;
  stop(): void;
}

enum Direction {
  UP = "UP",
  DOWN = "DOWN"
}

// Concrete State: Elevator is Stopped
class StoppedState implements ElevatorState {
  openDoors() {
    console.log('Opening doors...');
  }

  closeDoors() {
    console.log('Closing doors...');
  }

  moveUp() {
    console.log('Moving up...');
  }

  moveDown() {
    console.log('Moving down...');
  }

  stop() {
    console.log('Elevator is already stopped.');
  }
}

// Concrete State: Elevator is Moving
class MovingState implements ElevatorState {

  constructor(private direction: Direction) {}

  openDoors() {
    console.log('Cannot open doors while moving.');
  }

  closeDoors() {
    console.log('Cannot close doors while moving.');
  }

  moveUp() {
    console.log('Continuing to move up...');
  }

  moveDown() {
    console.log('Continuing to move down...');
  }

  stop() {
    console.log('Stopping elevator...');
  }
}

// Context: Elevator
class Elevator {
  private state: ElevatorState = new StoppedState();
  private currentFloor: number = 1;
  private destinationFloors: number[] = [];

  setState(state: ElevatorState) {
    this.state = state;
  }

  openDoors() {
    this.state.openDoors();
  }

  closeDoors() {
    this.state.closeDoors();
  }

  moveUp() {
    this.state.moveUp();
  }

  moveDown() {
    this.state.moveDown();
  }

  stop() {
    this.state.stop();
  }

  requestFloor(floor: number) {
    if (floor === this.currentFloor) {
      console.log(`Already on floor ${floor}.`);
    } else {
      this.destinationFloors.push(floor);
      this.moveElevator();
    }
  }

  private moveElevator() {
    if (this.destinationFloors.length === 0) {
      this.setState(new StoppedState());
      console.log('Elevator is now idle.');
      return;
    }

    const nextFloor = this.destinationFloors.shift()!;

    if (nextFloor > this.currentFloor) {
      this.setState(new MovingState(Direction.UP));
      console.log(`Moving up to floor ${nextFloor}...`);
    } else {
      this.setState(new MovingState(Direction.DOWN));
      console.log(`Moving down to floor ${nextFloor}...`);
    }

    setTimeout(() => {
      this.currentFloor = nextFloor;
      this.setState(new StoppedState());
      console.log(`Arrived at floor ${this.currentFloor}.`);
      this.moveElevator(); // Continue to the next floor
    }, 2000);
  }
}

// Usage
const elevator = new Elevator();

elevator.requestFloor(5); // Outputs: Moving up to floor 5...
elevator.requestFloor(3); // Outputs: Moving down to floor 3...
elevator.requestFloor(5); // Outputs: Moving up to floor 5...
elevator.requestFloor(2); // Outputs: Moving down to floor 2...
