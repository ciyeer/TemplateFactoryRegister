#ifndef IPRODUCTREGISTER_H
#define IPRODUCTREGISTER_H

// 基类，产品注册模板接口类
// 模板参数 ProductType_t 表示的类是产品抽象类

template <class ProductType_t>class IProductRegister
{
public:
    // 获取产品对象抽象接口
    virtual ProductType_t *createProduct() = 0;
protected:
    // 禁止外部构造和析构, 子类"内部"其他函数可以调用
    IProductRegister(){}
    virtual ~IProductRegister(){}
private:
    // 禁止外部拷贝和赋值操作
    IProductRegister(const IProductRegister&);
    const IProductRegister &operator=(const IProductRegister&);
};

#endif // IPRODUCTREGISTER_H
