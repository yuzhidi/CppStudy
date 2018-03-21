#include <iostream>
#include <vector>
 struct LeoStruct {
    int i;
    std::string s;
    LeoStruct(int i, std::string s):i(i),s(s){}
};
int main()
{
    // 创建含有整数的 vector
    std::vector<int> v = {7, 5, 16, 8};
    LeoStruct ls0 = LeoStruct(1, "one");

    std::vector<LeoStruct*> lv;

    lv.push_back(&ls0);
    // 添加二个整数到 vector
    v.push_back(25);
    v.push_back(13);

    // 迭代并打印 vector 的值
    for(int n : v) {
        std::cout << n << '\n';
    }

    for(const auto& ls : lv) {
        std::cout << ls->s << '\n';
    }
    ls0.s = "not one";
    for(const auto& ls : lv) {
        std::cout << "check is not one? : " << ls->s << '\n';
    }
}
