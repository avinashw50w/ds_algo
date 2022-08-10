/*
requirements:
- vending machine should keep track of the product inventory
- a person should be able to choose an item and insert cash into the machine
- the machine should confirm the inserted cash with the price of the product
- the machine must display error in case of insufficient cash
- the machine should dispence the change(if any), and then the product
 */

/* Use State design pattern
 States as follows: 
 Ready state -> collect cash -> dispense change -> dispense item  
   |
trx cancelled
*/

public interface State {
    public void makeReady();
    public void collectCash(int cash);
    public void dispenseChange(String productId);
    public void dispenseItem(String productId);
    public void cancelTrx();
}

public class VendingMachine {
    private int totalCollectedCash;
    private int collectedCash;
    private State state;
    private Map<String, Set<String>> productItemMap;
    private Map<String, Integer> productPriceMap;

    VendingMachine() {
        this.totalCollectedCash = 0;
        this.setState(new ReadyState(this));
    }

    public State getState() {
        return this.state;
    }

    public VendingMachine setState(State state) {
        this.state = state;
        return this;
    }

    public int calculateChange(String productId) {
        return this.collectedCash - getProductPrice(productId);
    }

    public int getProductPrice(String productId) {
        return productPriceMap.get(productId);
    }

    public int getCollectedCash() {
        return this.collectedCash;
    }

    public void addCash(int cash) {
        this.collectedCash += cash;
        this.totalCollectedCash += this.collectedCash;
    }
    public void minusCash(int cash) {
        this.collectedCash -= cash;
        this.totalCollectedCash -= this.collectedCash;
    }

    public void setCollectedCash(int cash) {
        this.collectedCash = cash;
    }

    public void setTotalCollectedCash(int cash) {
        this.totalCollectedCash = cash;
    }

    public void addProduct(String productId, int price) {}
    public void removeProduct(String productId) {}
}

public class ReadyState implements State {
    private VendingMachine vendingMachine;

    ReadyState(VendingMachine vendingMachine) {
        this.vendingMachine = vendingMachine;
    }

    @Override
    public void makeReady() {
        throw new RuntimeException("Already in Ready state");
    }

    @Override
    public void collectCash(int cash) {
        this.vendingMachine.addCash(cash);
        this.vendingMachine.setState(new CashCollectedState(this.vendingMachine));
    }

    @Override
    public void dispenseChange(String productId) {
        throw new RuntimeException("Transaction not initiated. Cannot dispense change");
    }

    @Override
    public void dispenseItem(String productId) {
        throw new RuntimeException("Transaction not initiated. Cannot dispense item");
    }

    @Override
    public void cancelTrx() {
        throw new RuntimeException("Transaction not initiated. Cannot cancel transaction");
        // this.vendingMachine.setState(new TrxCancelled(this.vendingMachine));
        // this.vendingMachine.cancelTrx();
    }
}

public class CashCollectedState implements State {
    private VendingMachine vendingMachine;

    CashCollectedState(VendingMachine vendingMachine) {
        this.vendingMachine = vendingMachine;
    }

    @Override
    public void makeReady() {
        throw new RuntimeException("Transaction initiated. Cannot go to ready state now.");
    }

    @Override
    public void collectCash(int cash) {
        throw new RuntimeException("Transaction initiated. Cannot collect cash");
    }

    @Override
    public void dispenseChange(String productId) {
        int change = this.vendingMachine.calculateChange(productId);
        if (change < 0) {
            throw new IllegalArgumentException("Insufficient cash");
        }
        System.out.println("Change of " + change + " returned");
        this.vendingMachine.setState(new ChangeDispensedState(this.vendingMachine));
    }

    @Override
    public void dispenseItem(String productId) {
        throw new RuntimeException("Transaction initiated. Cannot dispense item");
    }

    @Override
    public void cancelTrx() {
        System.out.println("returning collected cash: " + this.vendingMachine.getCollectedCash());
        this.vendingMachine.minusCash(this.vendingMachine.getProductPrice(productId));

        this.vendingMachine.setState(new TrxCancelledState(this.vendingMachine));
    }
}

public class ChangeDispensedState implements State {
    private VendingMachine vendingMachine;

    ChangeDispensedState(VendingMachine vendingMachine) {
        this.vendingMachine = vendingMachine;
    }

    @Override
    public void makeReady() {
        throw new RuntimeException("Transaction initiated. Cannot go to ready state now.");
    }

    @Override
    public void collectCash(int cash) {
        throw new RuntimeException("Unable to collect cash");
    }

    @Override
    public void dispenseChange(String productId) {
        throw new RuntimeException("Change already dispensed.");
    }

    @Override
    public void dispenseItem(String productId) {
        System.out.println("Dispensing item: " + productId);
        this.vendingMachine.setState(new ItemDispensedState(this.vendingMachine));
    }

    @Override
    public void cancelTrx() {
        throw new RuntimeException("Unable to cancel trx");
    }
}

public class ItemDispensedState implements State {
    private VendingMachine vendingMachine;

    ItemDispensedState(VendingMachine vendingMachine) {
        this.vendingMachine = vendingMachine;
    }

    @Override
    public void makeReady() {
        this.vendingMachine.setCollectedCash(0);
        this.vendingMachine.setState(new ReadyState(this.vendingMachine));
    }

    @Override
    public void collectCash(int cash) {
        throw new RuntimeException("Unable to collect cash");
    }

    @Override
    public void dispenseChange(String productId) {
        throw new RuntimeException("Unable to dispense change");
    }

    @Override
    public void dispenseItem(String productId) {
        throw new RuntimeException("Item already dispensed");
    }

    @Override
    public void cancelTrx() {
        throw new RuntimeException("Item already dispensed. Unable to cancel trx");
    }
}

public class TrxCancelledState implements State {
    private VendingMachine vendingMachine;

    TrxCancelledState(VendingMachine vendingMachine) {
        this.vendingMachine = vendingMachine;
    }

    @Override
    public void makeReady() {
        this.vendingMachine.setCollectedCash(0);
        this.vendingMachine.setState(new ReadyState(this.vendingMachine));
    }

    @Override
    public void collectCash(int cash) {
        throw new RuntimeException("Unable to collect cash in cancelled transaction state");
    }

    @Override
    public void dispenseChange(String productId) {
        throw new RuntimeException("Unable to collect cash in cancelled transaction state");
    }

    @Override
    public void dispenseItem(String productId) {
        throw new RuntimeException("Unable to collect cash in cancelled transaction state");
    }

    @Override
    public void cancelTrx() {
        throw new RuntimeException("Transaction already cancelled");
    }
}

public class Demo {
    public static void main(String[] args) {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.getState().collectCash();
        vendingMachine.getState().dispenseChange();
        vendingMachine.getState().cancelTrx();
        vendingMachine.getState().dispenseItem();
        vendingMachine.getState().makeReady();
    }
}