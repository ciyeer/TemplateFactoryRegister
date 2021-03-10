#ifndef IFACTORY_H
#define IFACTORY_H
#include <iostream>
#include <map>
#include "iproductregister.h"
/*
* 工厂模板类，用于获取和注册产品对象
* 模板参数 ProductType_t 表示的类是产品抽象类
*/

template <class ProductType_t> class IFactory
{
public:
    // 获取工厂单例,工厂的实例是唯一的
    static IFactory<ProductType_t> &getInstance()
    {
        static IFactory<ProductType_t> instance;
        return instance;
    }

    // 产品注册
    void RegisterProduct(IProductRegister<ProductType_t> *pRegister, std::string strName)
    {
        m_ProductRegistry[strName] = pRegister;
    }
    // 根据产品名字,获取具体产品对象
    ProductType_t *getProduct(std::string name)
    {
        // 从map中找到已经注册过的产品,并返回产品对象
        if(m_ProductRegistry.find(name) != m_ProductRegistry.end())
            return m_ProductRegistry[name]->createProduct();        // important
        // 未注册的产品,则提示找不到
        std::cout << "this product isn't exist   " << name << std::endl;
        return nullptr;
    }

private:
    IFactory(){}
    ~IFactory(){}
    // 禁止外部拷贝跟赋值操作
    IFactory(const IFactory &);
    const IFactory &operator=(const IFactory&);

    // 保存注册过的产品: key: 产品名字   value: 产品类型
    std::map<std::string, IProductRegister<ProductType_t>*> m_ProductRegistry;
};

#endif // IFACTORY_H
