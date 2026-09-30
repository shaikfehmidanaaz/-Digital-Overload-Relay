#include <iostream>
using namespace std;

class DigitalOverloadRelay {
private:
    double current;
    double overloadLimit;
    bool relayStatus;

public:
    DigitalOverloadRelay(double limit) {
        overloadLimit = limit;
        relayStatus = true;
    }

    void setCurrent(double value) {
        current = value;
    }

    void checkOverload() {
        cout << "\nMeasured Current: " << current << " A" << endl;
        cout << "Overload Limit: " << overloadLimit << " A" << endl;

        if (current > overloadLimit) {
            relayStatus = false;

            cout << "Status: OVERLOAD DETECTED" << endl;
            cout << "Relay: TRIPPED" << endl;
            cout << "Load: DISCONNECTED" << endl;
        }
        else {
            relayStatus = true;

            cout << "Status: NORMAL" << endl;
            cout << "Relay: ON" << endl;
            cout << "Load: CONNECTED" << endl;
        }
    }

    void displayRelayStatus() {
        cout << "\n----- RELAY STATUS -----" << endl;

        if (relayStatus)
            cout << "Relay Status: ON" << endl;
        else
            cout << "Relay Status: TRIPPED" << endl;
    }
};

int main() {
    double limit;
    double measuredCurrent;

    cout << "===== DIGITAL OVERLOAD RELAY =====" << endl;

    cout << "Enter overload current limit (A): ";
    cin >> limit;

    cout << "Enter measured load current (A): ";
    cin >> measuredCurrent;

    DigitalOverloadRelay relay(limit);

    relay.setCurrent(measuredCurrent);
    relay.checkOverload();
    relay.displayRelayStatus();

    return 0;
}
