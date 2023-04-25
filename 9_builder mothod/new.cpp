#include <iostream>
using namespace std;

class House {
    // 不能使用构造函数，因为C++为静态绑定
};

class HouseBuilder {
public:
    House *GetResult() {
        return pHouse;
    }
    virtual ~HouseBuilder(){}

protected:
    House *pHouse;
    virtual void BuildPart1()=0;
    virtual void BuildPart2()=0;
    virtual bool BuildPart3()=0;
    virtual void BuildPart4()=0;
    virtual void BuildPart5()=0;
};

class HouseDirector {
public:
    HouseBuilder *pHouseBuilder;
    HouseDirector(HouseBuilder *pHouseBuilder) {
        this->pHouseBuilder = pHouseBuilder;
    }

    void Construct() {
        pHouseBuilder->BuildPart1();

        for (int i = 0; i < 4; i++) {
            pHouseBuilder->BuildPart2();
        }

        bool flag = pHouseBuilder->BuildPart3();

        if (flag) {
            pHouseBuilder->BuildPart4();
        }

        pHouseBuilder->BuildPart5();
    }
};

// 具体类
class StoneHouseBuilder: public HouseBuilder {
public:
    virtual void BuildPart1() {
        // 具体实现
    }
    virtual void BuildPart2() {
        
    }
    virtual bool BuildPart3() {
        
    }
    virtual void BuildPart4() {
        
    }
    virtual void BuildPart5() {
        
    }
};

void main() {
    StoneHouseBuilder *pStoneHouseBuilder = new StoneHouseBuilder;
    HouseDirector *pHouseDirector = new HouseDirector(HouseBuilder *pStoneHouseBuilder);
    pHouseDirector->Construct();

    // 操作
}