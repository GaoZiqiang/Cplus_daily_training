#include "strategy.h"

class SalesOrder {
private:
    TaxStrategy* strategy;

public:
    SalesOrder(StrategyFactory* strategyFactory) {
        this->strategy = strategyFactory->newStrategy();// 利用工厂模式
    }

    ~SalesOrder() {
        delete this->strategy;
    }

public:
    double calculateTax() {
        // ...
        Context context;
        // 策略选择
        strategy->calculate(context);
        // ...
    }

};