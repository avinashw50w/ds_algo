interface VendingMachineState {
  insertMoney(amount: number): void;
  selectProduct(code: string): void;
  dispenseProduct(): void;
  ejectMoney(): void;
}

class IdleState implements VendingMachineState {
  private vendingMachine: VendingMachine;

  constructor(vendingMachine: VendingMachine) {
    this.vendingMachine = vendingMachine;
  }

  insertMoney(amount: number): void {
    this.vendingMachine.addMoney(amount);
    this.vendingMachine.changeState(new HasMoneyState(this.vendingMachine));
  }

  selectProduct(code: string): void {
    this.vendingMachine.showMessage("Please insert money first.");
  }

  dispenseProduct(): void {
    this.vendingMachine.showMessage(
      "Please insert money and select a product.",
    );
  }

  ejectMoney(): void {
    this.vendingMachine.showMessage("No money to eject.");
  }
}

class HasMoneyState implements VendingMachineState {
  private vendingMachine: VendingMachine;

  constructor(vendingMachine: VendingMachine) {
    this.vendingMachine = vendingMachine;
  }

  insertMoney(amount: number): void {
    this.vendingMachine.addMoney(amount);
  }

  selectProduct(code: string): void {
    const item = this.vendingMachine.getItemByCode(code);
    if (!item) {
      this.vendingMachine.showMessage("Invalid product code.");
      return;
    }

    if (!this.vendingMachine.hasEnoughMoney(item.price)) {
      this.vendingMachine.showMessage("Insufficient funds for selected item.");
      return;
    }

    this.vendingMachine.setSelectedItem(item);
    this.vendingMachine.changeState(
      new ProductSelectedState(this.vendingMachine),
    );
  }

  dispenseProduct(): void {
    this.vendingMachine.showMessage("Please select a product first.");
  }

  ejectMoney(): void {
    this.vendingMachine.returnMoney();
    this.vendingMachine.changeState(new IdleState(this.vendingMachine));
  }
}

class ProductSelectedState implements VendingMachineState {
  private vendingMachine: VendingMachine;

  constructor(vendingMachine: VendingMachine) {
    this.vendingMachine = vendingMachine;
  }

  insertMoney(amount: number): void {
    this.vendingMachine.addMoney(amount);
  }

  selectProduct(code: string): void {
    this.vendingMachine.showMessage("Product already selected.");
  }

  dispenseProduct(): void {
    const selectedItem = this.vendingMachine.getSelectedItem();
    if (!selectedItem) {
      this.vendingMachine.showMessage("No product selected.");
      return;
    }

    if (!this.vendingMachine.hasEnoughMoney(selectedItem.price)) {
      this.vendingMachine.showMessage("Insufficient funds for selected item.");
      return;
    }

    this.vendingMachine.dispenseProduct();
    this.vendingMachine.changeState(new DispenseState(this.vendingMachine));
  }

  ejectMoney(): void {
    this.vendingMachine.returnMoney();
    this.vendingMachine.changeState(new IdleState(this.vendingMachine));
  }
}

class DispenseState implements VendingMachineState {
  private vendingMachine: VendingMachine;

  constructor(vendingMachine: VendingMachine) {
    this.vendingMachine = vendingMachine;
  }

  insertMoney(amount: number): void {
    this.vendingMachine.addMoney(amount);
  }

  selectProduct(code: string): void {
    this.vendingMachine.showMessage("Product already selected.");
  }

  dispenseProduct(): void {
    this.vendingMachine.showMessage("Product already dispensed.");
  }

  ejectMoney(): void {
    this.vendingMachine.returnMoney();
    this.vendingMachine.changeState(new IdleState(this.vendingMachine));
  }
}

type Item = { code: string; price: number };

class VendingMachine {
  private state: VendingMachineState;
  private items: { code: string; price: number }[];
  private moneyInserted: number;
  private selectedItem: Item;

  constructor(items: Item[]) {
    this.state = new IdleState(this);
    this.items = items;
    this.moneyInserted = 0;
    this.selectedItem = null;
  }

  private changeState(newState: VendingMachineState): void {
    this.state = newState;
  }

  private showMessage(message: string): void {
    console.log(message);
  }

  private addMoney(amount: number): void {
    this.moneyInserted += amount;
    this.showMessage(`Inserted money: ${amount}`);
  }

  public getItemByCode(code: string): Item | undefined {
    return this.items.find((item) => item.code === code);
  }

  private removeItem(item: Item): boolean {
    return this.items.splice(this.items.indexOf(item.code), 1);
  }

  private hasEnoughMoney(price: number): boolean {
    return this.moneyInserted >= price;
  }

  private setSelectedItem(item: Item): void {
    this.selectedItem = item;
  }

  public getSelectedItem(): Item | null {
    return this.selectedItem;
  }

  private dispenseProduct(): void {
    if (this.selectedItem) {
      this.showMessage(`Dispensing ${this.selectedItem.code}...`);
      this.moneyInserted -= this.selectedItem.price;
      this.removeItem(this.selectedItem);
      this.selectedItem = null;
    }
  }

  private returnMoney(): void {
    this.showMessage(`Returning money: ${this.moneyInserted}`);
    this.moneyInserted = 0;
  }

  public insertMoney(amount: number): void {
    this.state.insertMoney(amount);
  }

  public selectProduct(code: string): void {
    this.state.selectProduct(code);
  }

  public dispenseProduct(): void {
    this.state.dispenseProduct();
  }

  public ejectMoney(): void {
    this.state.ejectMoney();
  }
}

// Example usage:

const items: { code: string; price: number }[] = [
  { code: "A1", price: 1.5 },
  { code: "A2", price: 2.0 },
  { code: "B1", price: 1.0 },
  { code: "B2", price: 3.0 },
];

const vendingMachine = new VendingMachine(items);

// Simulated user interaction
vendingMachine.insertMoney(2);
vendingMachine.selectProduct("A1");
vendingMachine.dispenseProduct();
vendingMachine.ejectMoney();
