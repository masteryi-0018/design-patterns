#include <iostream>
using namespace std;

class Command {
public:
    virtual void execute() = 0;
};

// 具体命令对象
class ConcreteCommand1: public Command {
    string arg;
public:
    ConcreteCommand1(const string& a): arg(a) {

    }
    void execute() override {
        cout << "#1 process..." << arg << endl;
    }
};

class ConcreteCommand2: public Command {
    string arg;
public:
    ConcreteCommand2(const string& a): arg(a) {

    }
    void execute() override {
        cout << "#2 process..." << arg << endl;
    }
};

// 宏
class MacroCommand: public Command {
    vector<Command*> commands;
public:
    void addCommand(Command* c) {
        commands.push_back(c);
    }
    void execute() override {
        for (auto& c: commands) {
            c->execute();
        }
    }
};

int main() {
    ConcreteCommand1 command1("Arg ###");
    ConcreteCommand2 command2("Arg $$$");

    MacroCommand macro;
    macro.addCommand(&command1);
    macro.addCommand(&command2);

    macro.execute();
}
