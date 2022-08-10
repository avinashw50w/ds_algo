package com.workattech.splitwise.models.split;

import com.workattech.splitwise.models.User;

public class ExactSplit extends Split {

    public ExactSplit(User user, double amount) {
        super(user);
        this.amount = amount;
    }
}