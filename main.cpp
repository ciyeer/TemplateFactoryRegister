#include <iostream>
#include "productregister.h"
#include "shoes.h"
#include "nikeshoes.h"
using namespace std;

int main()
{
   // ========================== 生产耐克球鞋过程 ===========================//
   // 注册产品种类为Shoes（基类），产品为NiKe（子类）到工厂，产品名为nike
   ProductRegister<Shoes, NikeShoes> NikeShoes("nike");
   // 从工厂获取产品种类为Shoes，名称为nike的产品对象
   Shoes *pNikeShoes =IFactory<Shoes>::getInstance().getProduct("nike");
   // 显示产品的广告语
   pNikeShoes->show();
   // 释放资源
   if (pNikeShoes)  
      delete pNikeShoes;

   return 0;
}
