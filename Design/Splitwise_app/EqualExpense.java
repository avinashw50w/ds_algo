package com.workattech.splitwise.models.expense;

import com.workattech.splitwise.models.User;
import com.workattech.splitwise.models.split.EqualSplit;
import com.workattech.splitwise.models.split.Split;

import java.util.List;

public class EqualExpense extends Expense {
    public EqualExpense(double amount, User paidBy, List<Split> splits, ExpenseMetadata expenseMetadata) {
        super(amount, paidBy, splits, expenseMetadata);
    }

    @Override
    public boolean validate() {
        for (Split split : getSplits()) {
            if (!(split instanceof EqualSplit)) {
                return false;
            }
        }

        return true;
    }
}