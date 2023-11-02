// list of all actions that a user can perform
interface VendingMachineState {
  insertCash(amount: number): void;
  selectItem(code: string): void;
  dispenceItem(): void;
  cancelTxn(): void;
}

// These are the states of the vending machine
class IdleState implements VendingMachineState {
  private vendingMachine: VendingMachine;

  constructor(vendingMachine: VendingMachine) {
    this.vendingMachine = vendingMachine;
  }

  insertCash(amount: number): void {
    this.vendingMachine.addMoney(amount);
    this.vendingMachine.changeState(new HasMoneyState(this.vendingMachine));
  }

  selectItem(code: string): void {
    this.vendingMachine.showMessage("Please insert money first.");
  }

  dispenceItem(): void {
    this.vendingMachine.showMessage(
      "Please insert money and select a product.",
    );
  }

  cancelTxn(): void {
    this.vendingMachine.showMessage("No Txn to cancel.");
  }
}

class HasMoneyState implements VendingMachineState {
  private vendingMachine: VendingMachine;

  constructor(vendingMachine: VendingMachine) {
    this.vendingMachine = vendingMachine;
  }

  insertCash(amount: number): void {
    this.vendingMachine.addMoney(amount);
  }

  selectItem(code: string): void {
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

  dispenceItem(): void {
    this.vendingMachine.showMessage("Please select a product first.");
  }

  cancelTxn(): void {
    this.vendingMachine.abortTxn();
    this.vendingMachine.changeState(new IdleState(this.vendingMachine));
  }
}

class ProductSelectedState implements VendingMachineState {
  private vendingMachine: VendingMachine;

  constructor(vendingMachine: VendingMachine) {
    this.vendingMachine = vendingMachine;
  }

  insertCash(amount: number): void {
    this.vendingMachine.addMoney(amount);
  }

  selectItem(code: string): void {
    this.vendingMachine.showMessage("Product already selected.");
  }

  dispenceItem(): void {
    const selectedItem = this.vendingMachine.getSelectedItem();
    if (!selectedItem) {
      this.vendingMachine.showMessage("No product selected.");
      return;
    }

    if (!this.vendingMachine.hasEnoughMoney(selectedItem.price)) {
      this.vendingMachine.showMessage("Insufficient funds for selected item.");
      return;
    }

    this.vendingMachine.dispenceItem();
    this.vendingMachine.changeState(new ItemDispensedState(this.vendingMachine));
  }

  cancelTxn(): void {
    this.vendingMachine.abortTxn();
    this.vendingMachine.changeState(new IdleState(this.vendingMachine));
  }
}

class ItemDispensedState implements VendingMachineState {
  private vendingMachine: VendingMachine;

  constructor(vendingMachine: VendingMachine) {
    this.vendingMachine = vendingMachine;
  }

  insertCash(amount: number): void {
    this.vendingMachine.addMoney(amount);
  }

  selectItem(code: string): void {
    this.vendingMachine.showMessage("Product already selected.");
  }

  dispenceItem(): void {
    this.vendingMachine.showMessage("Product already dispensed.");
  }

  cancelTxn(): void {
    this.vendingMachine.showMessage('Item has been dispached. Cannot cancel Txn.');
  }
}

type Item = { code: string; price: number };

class VendingMachine {
  private state: VendingMachineState;
  private items: { code: string; price: number }[];
  private totalCashCollected: number;
  private cashCollected: number;
  private selectedItem: Item;

  constructor(items: Item[]) {
    this.state = new IdleState(this);
    this.items = items;
    totalCashCollected = 0;
    this.cashCollected = 0;
    this.selectedItem = null;
  }

  private changeState(newState: VendingMachineState): void {
    this.state = newState;
  }

  private showMessage(message: string): void {
    console.log(message);
  }

  private addMoney(amount: number): void {
    this.totalCashCollected += amount;
    this.cashCollected += amount;
    this.showMessage(`Inserted money: ${amount}`);
  }

  private getItemByCode(code: string): Item | undefined {
    return this.items.find((item) => item.code === code);
  }

  private removeItem(item: Item): boolean {
    return this.items.splice(this.items.indexOf(item.code), 1);
  }

  private hasEnoughMoney(price: number): boolean {
    return this.cashCollected >= price;
  }

  private setSelectedItem(item: Item | null): void {
    this.selectedItem = item;
  }

  private getSelectedItem(): Item | null {
    return this.selectedItem;
  }

  private dispenceItem(): void {
    if (this.selectedItem) {
      this.showMessage(`Dispensing ${this.selectedItem.code}...`);
      this.returnChange();
      this.removeItem(this.selectedItem);
      this.setSelectedItem(null);
    }
  }

  private returnChange(): void {
    const change = this.cashCollected - this.selectedItem.price;
    this.showMessage(`Returning money: ${change}`);
    this.cashCollected = 0;
  }

  private returnMoney(): void {
    this.showMessage(`Returning money: ${this.cashCollected}`);
    this.cashCollected = 0;
  }

  private abortTxn(): void {
    this.showMessage(`Aborting txn...\nReturning money: ${this.cashCollected}`);
    this.returnMoney();
    this.setSelectedItem(null);
  }

  // only the actions performed by the user are made public

  public insertCash(amount: number): void {
    this.state.insertCash(amount);
  }

  public selectItem(code: string): void {
    this.state.selectItem(code);
  }

  public dispenceItem(): void {
    this.state.dispenceItem();
  }

  public cancelTxn(): void {
    this.state.cancelTxn();
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
vendingMachine.insertCash(2);
vendingMachine.selectItem("A1");
vendingMachine.dispenceItem();
// vendingMachine.cancelTxn();
