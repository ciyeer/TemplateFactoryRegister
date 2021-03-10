#ifndef PRODUCTREGISTER_H
#define PRODUCTREGISTER_H
#include <iostream>
#include "iproductregister.h"
#include "ifactory.h"

template <class ProductType_t, class ProductImpl_t>
class ProductRegister : public IProductRegister<ProductType_t>
{
public:
    // 构造函数,用于注册产品到工厂,只能显示调用
    explicit ProductRegister(std::string name)
    {
        // 通过工厂单例把产品注册到工厂
        IFactory<ProductType_t>::getInstance().RegisterProduct(this, name);
    }

    // 创建具体产品对象指针
    virtual ProductType_t *createProduct() override
    {
       return new ProductImpl_t;
    }
};

#endif // PRODUCTREGISTER_H
