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

#### Functional Requirements:

##### Product Management:
Each product will have the following attributes:
- **Product ID (string)**: Unique identifier for each product.
- **Name (string)**: The name of the product.
- **Price (float)**: Price stored in the base currency (USD).
- **Category (string)**: The category of the product (e.g., electronics, fashion).

Pre-populate a product catalogue with at least 3 products, which users can add to their cart.

**Example Product Catalog:**
1. **Product ID**: P001, **Name**: Laptop, **Price**: 1000.00 USD, **Category**: Electronics
2. **Product ID**: P002, **Name**: Phone, **Price**: 500.00 USD, **Category**: Electronics
3. **Product ID**: P003, **Name**: T-Shirt, **Price**: 20.00 USD, **Category**: Fashion

##### Cart Operations:
1. **Add to Cart**:
   - Allow users to add products to their cart.
   - Multiple quantities of the same item should be supported.
2. **Remove from Cart**:
   - Users can remove items entirely or reduce the quantity of an item already in the cart.
3. **View Cart**:
   - Show a detailed view of the cart, including:
     - Product name
     - Price per item
     - Quantity
     - Total cost per product
     - Total cart cost before discounts.

##### Discount System:
1. **List Available Discounts**:
   - The system should have a command to list all currently available discounts.
   - Users can query the system to see which discounts can be applied before checkout.
2. **Discount Examples**:
   - Buy 1 Get 1 Free: Available for Fashion category items.
   - 10% Off on Electronics: Available for all Electronics items.
3. **Apply Discounts**:
   - Discounts should be applied automatically during checkout based on the items in the cart.
   - Discounts should be modular and easy to extend for future additions.

#### Usage:

```bash
# Display initial product catalog
Initial Product Catalogue:
1. Product ID: P001, Name: Laptop, Price: 1000.00 USD, Category: Electronics
2. Product ID: P002, Name: Phone, Price: 500.00 USD, Category: Electronics
3. Product ID: P003, Name: T-Shirt, Price: 20.00 USD, Category: Fashion

# Add items to the cart
> add_to_cart P001 1
> add_to_cart P003 2

# View the cart
> view_cart
Your Cart:
1. Laptop - Quantity: 1, Price: 1000.00 USD, Total: 1000.00 USD
2. T-Shirt - Quantity: 2, Price: 20.00 USD, Total: 40.00 USD
Total (before discounts): 1040.00 USD

# List available discounts
> list_discounts
Available Discounts:
1. Buy 1 Get 1 Free on Fashion items
2. 10% Off on Electronics

# Apply discount at checkout
> checkout
Applying discounts...
Buy 1 Get 1 Free on T-Shirt applied.
Final Total in USD: 1020.00

# Convert total to EUR
Would you like to view it in a different currency? (yes/no): yes
Available Currencies: EUR, GBP
Enter currency: EUR
Final Total in EUR: 867.00