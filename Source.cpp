#include <iostream>
#include <string>

using namespace std;

class Vehicle {
public:
    virtual void ShowInfo() const = 0;  
    virtual ~Vehicle() = default;       
};

class FordExplorer : public Vehicle {
public:
    FordExplorer() {
        brand = "Ford";
        model = "Explorer";
        engine = "3.5L V6";
    }

    void ShowInfo() const override {
        cout << "Vehicle: " << brand << " " << model << "\nEngine: " << engine << endl;
    }

private:
    string brand;
    string model;
    string engine;
};

class LincolnAviator : public Vehicle {
public:
    LincolnAviator(string engineType, string color, int year)
        : engine(engineType), color(color), year(year) {
        brand = "Lincoln";
        model = "Aviator";
    }

    void ShowInfo() const override {
        cout << "Vehicle: " << brand << " " << model
            << "\nEngine: " << engine
            << "\nColor: " << color
            << "\nYear: " << year << endl;
    }

private:
    string brand;
    string model;
    string engine;
    string color;
    int year;
};

class IVehicleFactory {
public:
    virtual Vehicle* CreateVehicle() const = 0;  
    virtual ~IVehicleFactory() = default;        
};


class FordExplorerFactory : public IVehicleFactory {
public:
    Vehicle* CreateVehicle() const override {
        return new FordExplorer();  
    }
};

class LincolnAviatorFactory : public IVehicleFactory {
public:
    Vehicle* CreateVehicle() const override {
        return new LincolnAviator("3.0L V6", "Black", 2024);  
    }
};

void CreateAndShowVehicle(const IVehicleFactory& factory) {
    Vehicle* vehicle = factory.CreateVehicle();  
    vehicle->ShowInfo();  
    delete vehicle;       
}

int main() {
    FordExplorerFactory fordFactory;
    cout << "Creating Ford Explorer:\n";
    CreateAndShowVehicle(fordFactory);

    LincolnAviatorFactory lincolnFactory;
    cout << "\nCreating Lincoln Aviator:\n";
    CreateAndShowVehicle(lincolnFactory);

    return 0;
}
