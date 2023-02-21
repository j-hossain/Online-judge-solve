#include<iostream>
#include<set>
#include<map>
#include<utility>
#include<vector>
using namespace std;

class Product{
    protected:
    // Since this class is be inherited by cartItem these properties are set to protected
    
    string Name;
    double Price;
    string Description;
    
    public:
    
    Product(string name, double price, string description){
        this->Name = name;
        this->Price = price;
        this->Description= description;
    }
    
    Product(){
        this->Name = "";
        this->Price = 0.0;
        this->Description = "";
    }

    string getterName()const{return Name;}
    double getterPrice()const{return Price;}
    string getterDescription()const{return Description;}
    
    // since I don't want to make any changed to the product after it is selected
    // There shouldn't be any setter function for them
    // void setterName(string name){this->Name = name;}
    // void setterPrice(double price){this->Price = price;}
    // void setterDescription(string description){this->Description = description;}
    
    // Prints the details of the product
    void show()const{
        cout<<"Product Name\t: "<<this->Name<<"\n";
        cout<<"Unit Price\t: "<<this->Price<<"\n";
        cout<<"Description\t: "<<this->Description<<"\n";
    }
    
    // operator overloaded for using its object in stl
    bool operator< (const Product p)const{
        return this->Name<p.Name;
    }
};

class cartItem: public Product{
    protected:
    
    int quantity;
    
    public:
    
    // cart e ekta product r quantity dicchi, o etakei nie or parent class e pathay dicche
    cartItem(Product p, int quantity):Product(p.getterName(),p.getterPrice(),p.getterDescription()){
        this->quantity = quantity;
    }
    
    cartItem():Product(){
        this->quantity = 0;
    }

    int getterQuantity() const{return quantity;}
    void setterQuantity(int newQuantity) {this->quantity = max(0,newQuantity);}

    void show() const{
        // product er show method ta call korbe
        Product::show();
        // Then nijer quantity tao print korbe
        cout<<"Quanity\t\t: "<<quantity<<"\n";
    }
    
    bool operator< (const cartItem item)const{
        return this->Name<item.Name;
    }
};

class orderDetails:public cartItem{
    private:

    double orderCost;
    
    public:
    
    orderDetails(cartItem item):cartItem({item.getterName(),item.getterPrice(),item.getterDescription()},item.getterQuantity()){
        orderCost = Price*quantity;
    }
    
    double getterCost()const{return orderCost;}
    
    // since I do not want anyone to change the quantity in the order
    //  I will make the setterquantity to blank, which will not change anything
    void setterQuantity(int newQuantity){cerr<<"you cannot change the quantity once it is out of the cart\n";}
    
    void show(){
        cartItem::show();
        cout<<"\t\t\t\tProduct Cost\t: "<<orderCost<<"\n";
    }
};

class Order{
    private:
    
    // Keeping the orderlist dynamic
    vector<orderDetails> orderList;
    double totalCost;
    
    public:
    
    Order(){
        orderList.clear();
        totalCost = 0.0;
    }
    
    void addItem(orderDetails orderItem){
        orderList.push_back(orderItem);
        // increasing the total cost while adding an orderItem to the list
        totalCost+=orderItem.getterCost();
    }

    void confirmOrder(){
        cout<<"........................................................\n";
        cout<<"........................................................\n";
        cout<<"\t\tYour Final Order...\n";
        cout<<"........................................................\n";
        for(auto orderItem:orderList){
            orderItem.show();
        cout<<"........................................................\n";
        }
        cout<<"........................................................\n";
        cout<<"\t\t\t\tTotal order Cost: "<<totalCost<<"\n";
        cout<<"........................................................\n";
        cout<<"........................................................\n";
    }
};

class shoppingCart{
    protected:
    
    // using set to maintain a list that contains unique elements only once
    set<cartItem> items;
    double totalCost;
    
    private:
    
    // This method can increase or decrease the quantity of a product in the cart
    // If the quantity is to be decreased, simply pass the negative form of the quantity you want to reduce
    void changeQuantity(_Rb_tree_const_iterator<cartItem> itemIT, cartItem changedItem){
        
        int prevQuantity = itemIT->getterQuantity(); // fetching the previous quantity of the product
        totalCost-=(changedItem.getterPrice()*prevQuantity); // removing the cost for that quantity
        
        //changing the quantity, if the changed item quantity is negative, 
        // if the previous quantity will be reduced
        int newQuantity = prevQuantity+changedItem.getterQuantity(); 
        
        changedItem.setterQuantity(newQuantity);
        
        // removing the previous item record
        items.erase(itemIT);
        
        // If the product quantity is not a positive integer greater than zero,
        //  then it should not be in the cart
        if(changedItem.getterQuantity()){
            totalCost+=(changedItem.getterPrice()*newQuantity); // calculating the new cost
            items.insert(changedItem);
        }
        
        // cartItem.show();
        // (*itemIT).setterQuantity((*itemIT).getterQuantity()+changedQuantity);
        // if((*itemIT).getterQuantity()==0) items.erase(itemIT);
    }
    
    public:
    
    shoppingCart(){
        totalCost = 0.0;
        items.clear();
    }
    
    void addItem(Product addedProduct, int addedQuantity){
        cartItem item(addedProduct, addedQuantity);
        auto itemIT = items.find(item);
    
        // If the product is not currently present in the set of cart,
        if(itemIT==items.end()){
            //  just insert it
            items.insert(item);
            totalCost+=(item.getterPrice()*addedQuantity);
        }
        else{
            // If some quantity of a product is already present in the cart
            //  this process only increases the quantity,
            //  without creating a new instance of the same product in the cart
            changeQuantity(itemIT,item);
        }
    }
    
    void reduceQuantity(Product targetProduct, int reducedQuantity){
        // converting the reducable quantity to negative,
        //  to use the same quantity changer function twice
        cartItem targetItem(targetProduct,-reducedQuantity);
        
        auto itemIT = items.find(targetItem);
        
        // handling the case where a product not currently present in the cart 
        //  is attempted to reduce,this makes no damage to the cart list
        if(itemIT!=items.end()){
            changeQuantity(itemIT,targetItem);
        }
        // otherwise show an error
        else{
            cerr<<"This Product is not present in the cart\n";
        }
    }
    
    void removeProduct(Product removedProduct){
        cartItem toRemove(removedProduct,0);
        
        auto itemIT = items.find(toRemove);
        
        // handling the case where a product not present in the cart
        //  is attempted to remove
        if(itemIT!=items.end()){
            // updating the total cost caused by removing the product
            totalCost-=(itemIT->getterPrice()*itemIT->getterQuantity());
            items.erase(itemIT);
        }
        // otherwise show an error
        else{
            cerr<<"This product is not present in the cart\n";
        }
    }
    
    // simply viewing the cart while showing each of the cart item
    void viewCart(){
        cout<<"\nViewing The Cart"<<"\n\n";
        for(auto item:items){
            item.show();
            cout<<"\n";
        }
        cout<<"Total Cost in Cart: "<<totalCost<<"\n\n\n";
    }

    double getterTotalCost()const{return totalCost;}

    void clearCart(){
        // deletes all cart items from the set
        items.clear();
        // reseting the total cost of the cart
        totalCost = 0.0;
    }

    // After checking out you get order in return
    Order checkout(){
        Order newOrder;
    
        for(auto item:items){
            // converting each cart item to an order item
            orderDetails orderItem(item);
            // adding the order item to the complete order list
            // cost and others will be handling in the order class
            newOrder.addItem(orderItem);
        }
    
        // Since the order has been created the cart is then cleared
        clearCart();
    
        return newOrder;
    }
};


int main(){
    Product watch("Watch",2000,"The watch description...");
    Product shirt("Shirt",4000,"The shirt description...");
    Product shoe("Shoe",3000,"The shoe description...");
    
    shoppingCart theCart;
    
    // checking add methods
    theCart.addItem(watch,1);
    theCart.addItem(shirt,2);
    theCart.addItem(shoe,1);
    theCart.viewCart();
    
    // Checking add for existing products
    theCart.addItem(watch,1);
    theCart.viewCart();
    
    // Testing the reduce methods
    theCart.reduceQuantity(watch,1);
    theCart.reduceQuantity(shirt,1);
    
    // Checking reducing to null
    theCart.reduceQuantity(shirt,1);
    theCart.viewCart();
    
    // Checking the removal of a product completely
    theCart.removeProduct(watch);
    theCart.viewCart();
    
    // Adding more than 1 quantity
    theCart.addItem(watch,3);
    theCart.viewCart();
    
    // Testing checkout
    Order newOrder = theCart.checkout();
    newOrder.confirmOrder();

    return 0;
}
