#include <iostream>
#include <string>
#include <vector>

class Product {
    public:
        Product() { }
        // TODO: Constructor
        Product(std::string _name, int _price){
            name = _name;
            price = _price;
        }
        // TODO: setTaxRatio function
        static void setTaxRatio(float rt){
            taxRatio = rt;
        }
        void setName(std::string newName) {
            name = newName;
        }
        void setPrice(int newPrice) {
            price = newPrice;
        }
        // TODO: getName function
        std::string getName() const{
            return name;
        }
        // TODO: getPrice function
        int getPrice() const{
            return price * (1+taxRatio);
        }
    private:
        std::string name;
        int price;
        static float taxRatio;
};
// TODO: Initialize taxRatio to 0.1
float Product::taxRatio = 0.1;

class OrderItem {
    public:
        // TODO: Constructor
        OrderItem(const Product &_product, int _count) : product(_product), count(_count) {};
        // TODO: getProduct function
        const Product& getProduct() const{
            return product;
        }
        // TODO: getCount function
        int getCount() const{
            return count;
        }
        // TODO: getPrice function
        int getPrice() const{
            return product.getPrice() * count;
        }
    private:
        const Product& product;
        int count;
};

class Order {
    public:
        // TODO add function
        void add(OrderItem oi){
            orderItems.emplace_back(oi);
        }
        // TODO: getOrderItems
        const std::vector<OrderItem> &getOrderItems() const{
            return orderItems;
        }

        void output() const {
            int totalPrice = 0;
            std::cout << "Items: " << std::endl;
            for (int i = 0; i < orderItems.size(); i++) {
                std::cout << orderItems[i].getProduct().getName() << "(" << orderItems[i].getProduct().getPrice() << ")" << " * " << orderItems[i].getCount() << " = " << orderItems[i].getPrice() << std::endl;
                totalPrice += orderItems[i].getPrice();
            }
            std::cout << "Total Price with Taxes: " << totalPrice << std::endl;
        }
        // TODO: Override operator +
        

    private:
        std::vector<OrderItem> orderItems;
};

const Order operator+(const Order& o1, const Order& o2){
    Order tmp;
    std::vector<OrderItem> v1 = o1.getOrderItems(), v2 = o2.getOrderItems();
    int sv1 = v1.size(), sv2 = v2.size();
    for(int i = 0; i < sv1; i ++){
        int flg = 0;
        for(int j = 0; j < sv2; j ++){
            if(&v1[i].getProduct() == &v2[j].getProduct()){
                flg = 1;
                
                tmp.add(OrderItem(v1[i].getProduct(), OrderItem(v1[i]).getCount() + OrderItem(v2[j]).getCount()));
            }
        }
        if(!flg){
            tmp.add(OrderItem(v1[i].getProduct(), OrderItem(v1[i]).getCount()));
        }
    }
    for(int j = 0; j < sv2; j ++){
        int flg = 0;
        for(int i = 0; i < sv1; i ++){
            if(&v1[i].getProduct() == &v2[j].getProduct()){
                flg = 1;
            }
        }
        if(!flg){
            tmp.add(OrderItem(v2[j].getProduct(), OrderItem(v2[j]).getCount()));
        }
    }
    return tmp;
}

int main(void) {
	int productCount;
	std::cin >> productCount;
	std::vector<Product> products;
	for (int i = 0; i < productCount; i++) {
		std::string name;
		int price;
		std::cin >> name >> price;
		products.push_back(Product(name, price));
	}

	Order order1;
	int orderItemCountForOrder1;
	std::cin >> orderItemCountForOrder1;
	for (int i = 0; i < orderItemCountForOrder1; i++) {
		int productIndex;
		int count;
		std::cin >> productIndex >> count;
		order1.add(OrderItem(products[productIndex], count));
	}

	Order order2;
	int orderItemCountForOrder2;
	std::cin >> orderItemCountForOrder2;
	for (int i = 0; i < orderItemCountForOrder2; i++) {
		int productIndex;
		int count;
		std::cin >> productIndex >> count;
		order2.add(OrderItem(products[productIndex], count));
	}

	std::cout << "Order1: " << std::endl;
	order1.output();
	std::cout << std::endl;

	std::cout << "Order2: " << std::endl;
	order2.output();
	std::cout << std::endl;

	Order combinedOrder = order1 + order2;
	std::cout << "Combined Order: " << std::endl;
	combinedOrder.output();
	std::cout << std::endl;

	Product::setTaxRatio(0.2);
	std::cout << "Combined Order: " << std::endl;
	combinedOrder.output();
	std::cout << std::endl;

	// Don't worry about this. We will make sure that the number of products exceeds 2.
	products[0].setName("Invalid Product");
	products[1].setPrice(100);
	std::cout << "Combined Order: " << std::endl;
	combinedOrder.output();
	std::cout << std::endl;
}