#include <bits/stdc++.h>
using namespace std;

struct Product {
    string name;
    string ProductID;
    double price;
    string Category;

    Product(string name, string ProductID, double price, string Category) {
        this->name = name;
        this->ProductID = ProductID;
        this->price = price;
        this->Category = Category;
    }

    void display() {
        cout << "Product ID: " << ProductID << ", Name: " << name << ", Price: " << price << " USD, Category: " << Category << endl;
    }
};

struct CartItem {
    Product product;
    int quantity;

    CartItem(Product product, int quantity) : product(product), quantity(quantity) {}
};

struct Database {
    vector<Product> products;

    Database() {
        products.push_back(Product("Laptop", "P001", 1000.00, "Electronics"));
        products.push_back(Product("Phone", "P002", 500.00, "Electronics"));
        products.push_back(Product("T-Shirt", "P003", 20.00, "Fashion"));
    }

    void displayProducts() {
        cout << "Initial Product Catalogue:" << endl;
        for (int i = 0; i < products.size(); i++) {
            products[i].display();
        }
    }

    Product* findProductByID(string ProductID) {
        for (auto &product : products) {
            if (product.ProductID == ProductID) {
                return &product;
            }
        }
        return nullptr;
    }
};

struct Cart {
    vector<CartItem> items;

    void addToCart(Product product, int quantity) {
        for (auto &item : items) {
            if (item.product.ProductID == product.ProductID) {
                item.quantity += quantity;
                return;
            }
        }
        items.push_back(CartItem(product, quantity));
    }

    void removeFromCart(string ProductID, int quantity) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->product.ProductID == ProductID) {
                if (quantity >= it->quantity) {
                    items.erase(it);
                } else {
                    it->quantity -= quantity;
                }
                return;
            }
        }
    }

    void viewCart() {
        double total = 0;
        cout << "Your Cart:" << endl;
        for (auto &item : items) {
            double itemTotal = item.product.price * item.quantity;
            total += itemTotal;
            cout << item.product.name << " - Quantity: " << item.quantity << ", Price: " << item.product.price << " USD, Total: " << itemTotal << " USD" << endl;
        }
        cout << "Total (before discounts): " << total << " USD" << endl;
    }

    double calculateTotal() {
        double total = 0;
        for (auto &item : items) {
            total += item.product.price * item.quantity;
        }
        return total;
    }
};

struct Discount {
    virtual double applyDiscount(Cart &cart) = 0;
};

struct BuyOneGetOneFree : public Discount {
    double applyDiscount(Cart &cart) override {
        double discount = 0;
        for (auto &item : cart.items) {
            if (item.product.Category == "Fashion" && item.quantity >= 2) {
                discount += (item.quantity / 2) * item.product.price;
            }
        }
        return discount;
    }
};

struct TenPercentOffElectronics : public Discount {
    double applyDiscount(Cart &cart) override {
        double discount = 0;
        for (auto &item : cart.items) {
            if (item.product.Category == "Electronics") {
                discount += item.product.price * item.quantity * 0.10;
            }
        }
        return discount;
    }
};

struct CurrencyConverter {
    static double convert(double amount, string currency) {
        if (currency == "EUR") {
            return amount * 0.85;
        } else if (currency == "GBP") {
            return amount * 0.75;
        }
        return amount;
    }
};

void listCommands() {
    cout << "+---------Welcome to Mini Ecommerse App---------+" << endl;
    cout << "Please select an option:" << endl;
    cout << "1. add_to_cart <ProductID> <Quantity>" << endl;
    cout << "2. remove_from_cart <ProductID> <Quantity>" << endl;
    cout << "3. view_cart" << endl;
    cout << "4. list_discounts" << endl;
    cout << "5. checkout" << endl;
    cout << "6. exit" << endl;
    cout << "+------------------------------------------------+" << endl;
}

int main() {
    Database db;
    Cart cart;
    vector<Discount*> discounts = { new BuyOneGetOneFree(), new TenPercentOffElectronics() };

    // Display initial product catalog
    db.displayProducts();
    listCommands();

    string command;
    while (true) {
        cout << "> ";
        getline(cin, command);
        stringstream ss(command);
        string action;
        ss >> action;

        if (action == "add_to_cart") {
            string ProductID;
            int quantity;
            ss >> ProductID >> quantity;
            Product* product = db.findProductByID(ProductID);
            if (product) {
                cart.addToCart(*product, quantity);
            } else {
                cout << "Product not found!" << endl;
            }
        } else if (action == "remove_from_cart") {
            string ProductID;
            int quantity;
            ss >> ProductID >> quantity;
            cart.removeFromCart(ProductID, quantity);
        } else if (action == "view_cart") {
            cart.viewCart();
        } else if (action == "list_discounts") {
            cout << "Available Discounts:" << endl;
            cout << "1. Buy 1 Get 1 Free on Fashion items" << endl;
            cout << "2. 10% 0ff on Electronics" << endl;
        } else if (action == "checkout") {
            double total = cart.calculateTotal();
            double totalDiscount = 0;
            for (auto discount : discounts) {
                totalDiscount += discount->applyDiscount(cart);
            }
            double finalPrice = total - totalDiscount;
            cout << "Applying discounts..." << endl;
            if (totalDiscount > 0) {
                cout << "Discounts applied." << endl;
            }
            cout << "Final Total in USD: " << finalPrice << " USD" << endl;

            cout << "Would you like to view it in a different currency? (yes/no): ";
            string response;
            cin >> response;
            if (response == "yes") {
                cout << "Available Currencies: EUR, GBP" << endl;
                cout << "Enter currency: ";
                string currency;
                cin >> currency;
                double convertedPrice = CurrencyConverter::convert(finalPrice, currency);
                cout << "Final Total in " << currency << ": " << convertedPrice << " " << currency << endl;
            }
            cin.ignore(); // To ignore the newline character left in the buffer
        } else if (action == "exit") {
            break;
        } else {
            cout << "Invalid command!" << endl;
            listCommands();
        }
    }

    for (auto discount : discounts) {
        delete discount;
    }

    return 0;
}