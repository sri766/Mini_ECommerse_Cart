### Mini E-commerce Cart System (Command-Line Application)

#### Objective:
Design and implement a command-line based Mini E-commerce Cart System where users can add items to a cart, calculate total costs, manage discounts dynamically, and handle cart items.

#### Problem Statement:
You need to create a command-line application where users can:
- Add items to the cart.
- Remove items from the cart.
- View current items in the cart.
- Calculate the total price, with support for multiple currencies.
- Apply discounts dynamically (discounts available in the system should be queryable).
- Checkout to see the final price.


### How to Run the Code
```bash

g++ mini-Ecart.cpp - 0 mini_Ecart
./mini-Ecart

```

#### Implementation:
- Product Struct: Represents a product with attributes such as ProductID, name, price, and category.
- Database Struct: Contains a collection of products and provides functionality to display the available products.
- CartItem Struct: Represents an item in the cart, holding the product details and the quantity of the item.
- Cart Struct: Manages cart operations such as adding items, removing items, viewing the cart, and calculating the total price.
- Discount System: Defines a base Discount struct and two specific discount types, BuyOneGetOneFree for fashion items and TenPercentOffElectronics for electronics, each implementing their own discount logic.
- Currency Conversion: Supports converting the total cost to different currencies with fixed conversion rates.
