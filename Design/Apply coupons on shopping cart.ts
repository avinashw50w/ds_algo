/*
Given a shopping cart with products. We have to apply the below coupons on each of the product
in the order they are given. Calculate the net price after applying coupons on all the products
1. N % of for all producs
2. P% off on next item
3. D% off for product of a type T


Sol: we can use decorator pattern to decorate product with coupons 
 */

enum ProductType {
    ELECTRONICS,
    GARMENTS,
    FURNITURE,
};

abstract class Product {
    name: string;
    type: ProductType;
    price: number;

    constructor(type: ProductType, name: string, price: number) {
        this.name = name;
        this.type = type;
        this.price = price;
    }

    abstract getPrice(): number;

    getType(): ProductType { return this.type; }
}

class Garment extends Product {
    constructor(name: string, price: number) {
        super(ProductType.GARMENTS, name, price );
    }
    getPrice(): number {
        return this.price;
    }
}

abstract class CouponDecorator extends Product {

    constructor(product: Product) {
        super(product.type, product.name, product.price);
    }
}

class PercentageCouponDecorator extends CouponDecorator {
    discountPercentage: number;
    product: Product;

    constructor(discountPercentage: number, product: Product) {
        super(product);
        this.discountPercentage = discountPercentage;
    }

    getPrice(): number {
        const price = this.product.getPrice();
        return price - (price * this.discountPercentage)/100;
    }
}


class TypeCouponDecorator extends CouponDecorator {
    discountPercentage: number;
    type: ProductType;
    product: Product;

    static readonly eligibleProductTypes: ProductType[] = [ProductType.GARMENTS, ProductType.ELECTRONICS];

    constructor(discountPercentage: number, product: Product) {
        super(product);
        this.discountPercentage = discountPercentage;
    }

    getPrice(): number {
        const productType = this.product.getType();
        const price = this.product.getPrice();
        if (! TypeCouponDecorator.eligibleProductTypes.includes(productType)) {
            return price;
        }
        return price - (price * this.discountPercentage)/100;
    }
}

class ShoppingCart {
    products: Product[];

    constructor() {}

    addToCart(product: Product) {
        const productAfterPercentageCouponApply = new PercentageCouponDecorator(30, product);
        let productAfterNextItemCouponApply = productAfterPercentageCouponApply;
        
        if (this.products.length) {
            productAfterNextItemCouponApply = new PercentageCouponDecorator(
                20,
                productAfterPercentageCouponApply
            );
        }

        const productAfterTypeCouponApply = new TypeCouponDecorator(10, productAfterNextItemCouponApply);

        this.products.push(productAfterTypeCouponApply);
    }

    removeFromCart(product: Product) {
        this.products.splice(this.products.indexOf(product), 1);
    }

    getTotal() {
        const total = this.products.reduce((price, product: Product) => {
            price += product.getPrice();
            return price;
        }, 0);

        return total;
    }
}
