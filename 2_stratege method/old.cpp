#include <iostream>
using namespace std;

enum TaxBase {
    CN_tax,
    US_tax,
    DE_tax
};

class SalesOrder {
    TaxBase tax;
public:
    SalesOrder(TaxBase _tax): tax(_tax) {}
    void calculateTax() {
        if (tax == CN_tax) {
            cout << "i am CN_tax" << endl;
        }
        else if (tax == US_tax) {
            cout << "i am US_tax" << endl;
        }
        else if (tax == DE_tax) {
            cout << "i am DE_tax" << endl;
        }
        else {
            cout << "invalid TaxBase" << endl;
        }
    }
};

int main() {
    SalesOrder* order = new SalesOrder(CN_tax);
    order->calculateTax();

    return 0;
}