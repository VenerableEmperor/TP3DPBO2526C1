#include <string>

using namespace std;

class SmartDevice {
    protected:
        string id;
        string name;
        string type;
    public:
        SmartDevice() {
            id = "kosong";
        }

        SmartDevice(string i, string n, string t) {
            id = i;
            name = n;
            type = t;
        }

        virtual ~SmartDevice() {}

        string getId() {
            return id;
        }
        string getName() {
            return name;
        }
        string getType() {
            return type;
        }

        void setId(string text) {
            id = text;
        }
        void setName(string text) {
            name = text;
        }
        void setType(string text) {
            type = text;
        }

        virtual int getVal() = 0;
        virtual void setVal(int val) = 0;
};

class SmartLight : public SmartDevice {
    private:
        int brightness;
    public:
        SmartLight() : SmartDevice("kosong", "kosong", "Light") {
            brightness = 0;
        }

        SmartLight(string i, string n, int b) : SmartDevice(i, n, "Light") {
            brightness = b;
        }

        int getVal() override {
            return brightness;
        }

        void setVal(int val) override {
            brightness = val;
        }
};

class SmartThermostat : public SmartDevice {
    private:
        int temperature;
    public:
        SmartThermostat() : SmartDevice("kosong", "kosong", "Thermostat") {
            temperature = 0;
        }

        SmartThermostat(string i, string n, int t) : SmartDevice(i, n, "Thermostat") {
            temperature = t;
        }

        int getVal() override {
            return temperature;
        }

        void setVal(int val) override {
            temperature = val;
        }
};

class SmartSpeaker : public SmartDevice {
    private:
        int volume;
    public:
        SmartSpeaker() : SmartDevice("kosong", "kosong", "Speaker") {
            volume = 0;
        }

        SmartSpeaker(string i, string n, int v) : SmartDevice(i, n, "Speaker") {
            volume = v;
        }

        int getVal() override {
            return volume;
        }

        void setVal(int val) override {
            volume = val;
        }
};