#include <iostream>
#include <vector>
using namespace std;

class House;
class Factory;
class Bank;

class InsuranceAgentVisitor {
public:
    virtual void visit(House* house) = 0;
    virtual void visit(Factory* factory) = 0;
    virtual void visit(Bank* bank) = 0;
    virtual ~InsuranceAgentVisitor() {}
};

class Visitable {
public:
    virtual void accept(InsuranceAgentVisitor* visitor) = 0;
    virtual ~Visitable() {}
};

class House : public Visitable {
public:
    void accept(InsuranceAgentVisitor* visitor) override {
        visitor->visit(this);
    }
};

class Factory : public Visitable {
public:
    void accept(InsuranceAgentVisitor* visitor) override {
        visitor->visit(this);
    }
};

class Bank : public Visitable {
public:
    void accept(InsuranceAgentVisitor* visitor) override {
        visitor->visit(this);
    }
};

class InsuranceAgent : public InsuranceAgentVisitor {
public:
    void visit(House* house) override {
        cout << "Страховий агент пропонує медичну страховку для сім’ї." << endl;
    }

    void visit(Factory* factory) override {
        cout << "Страховий агент пропонує страховку від пожежі та повені для фабрики." << endl;
    }

    void visit(Bank* bank) override {
        cout << "Страховий агент пропонує страховку від пограбування для банку." << endl;
    }
};

int main() {
    vector<Visitable*> locations = { new House(), new Factory(), new Bank() };
    InsuranceAgent agent;

    for (Visitable* place : locations) {
        place->accept(&agent);
    }

    for (Visitable* place : locations) {
        delete place;
    }

    return 0;
}
