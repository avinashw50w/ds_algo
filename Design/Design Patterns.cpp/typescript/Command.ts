// Receiver
class Light {
  turnOn(): void {
    console.log('Light is on.');
  }

  turnOff(): void {
    console.log('Light is off.');
  }
}

// Command interface
interface Command {
  execute(): void;
}

// Concrete Command 1
class TurnOnCommand implements Command {
  private light: Light;

  constructor(light: Light) {
    this.light = light;
  }

  execute(): void {
    this.light.turnOn();
  }
}

// Concrete Command 2
class TurnOffCommand implements Command {
  private light: Light;

  constructor(light: Light) {
    this.light = light;
  }

  execute(): void {
    this.light.turnOff();
  }
}

// Invoker
class RemoteControl {
  private commands: Command[] = [];

  addCommand(command: Command): void {
    this.commands.push(command);
  }

  executeCommands(): void {
    for (const command of this.commands) {
      command.execute();
    }
  }
}

// Client code
const light: Light = new Light();
const turnOnCommand: Command = new TurnOnCommand(light);
const turnOffCommand: Command = new TurnOffCommand(light);

const remoteControl: RemoteControl = new RemoteControl();
remoteControl.addCommand(turnOnCommand);
remoteControl.addCommand(turnOffCommand);

remoteControl.executeCommands();


/*
The command pattern allows decoupling the sender and receiver of a command, allowing for the encapsulation of a request as an object. It enables the requester to be unaware of the receiver's implementation details and provides flexibility in adding, modifying, or reusing commands.
*/