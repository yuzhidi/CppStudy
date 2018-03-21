#include <unordered_map>
#include <iostream>
enum UuidTaskState {
    INIT,
    TO_GENERATE_TMP_UUID,
    TO_GET_TMP_UUID,
    TO_GET_UUID,
    NEW_UUID,
    GOT_UUID
};

static std::string getUuidTaskStateName(UuidTaskState state) {
    switch(state) {
        case INIT:
            return "init";
        case TO_GENERATE_TMP_UUID:
            return "TO_GENERATE_TMP_UUID";
        case TO_GET_TMP_UUID:
            return "TO_GET_TMP_UUID";
        case TO_GET_UUID:
            return "TO_GET_UUID";
        case NEW_UUID:
            return "NEW_UUID";
        case GOT_UUID:
            return "GOT_UUID";
            default:
            return  "nuknl";
    }

}
struct LeoStruct {
    int i;
    std::string s;
    LeoStruct(int i, std::string s):i(i),s(s){}
};
int main()
{
    std::unordered_map<int, std::string> c = {{1, "one"}, {2, "two"}, {3, "three"},
                                    {4, "four"}, {5, "five"}, {6, "six"}};

    LeoStruct leoStruct = LeoStruct(7, "seven");
    std::unordered_map<int, LeoStruct&> cLeo = {{7, leoStruct}};


    // erase all odd numbers from c
    auto it = c.find(6);
    if (it == c.end()) {
        std::cout<< "null" <<std::endl;
    } else {
        std::cout<< it->second <<std::endl;
        c.erase(it);
        for(auto& p : c)
        std::cout << p.second << std::endl;
    }
    std::cout<< getUuidTaskStateName(TO_GET_TMP_UUID) << std::endl;


    for(auto& p : cLeo) {
        std::cout << "init:" << p.second.s << std::endl;
    }
     cLeo.erase(7);
     for(auto& p : cLeo) {
      std::cout << "erase 7:" << p.second.s << std::endl;
    }
    cLeo.emplace(7,leoStruct);
    for(auto& p : cLeo) {
        std::cout << "init2:" << p.second.s << std::endl;
    }

    leoStruct.s= "not seven";
    for(auto& p : cLeo) {
        std::cout << "check not seven?:" << p.second.s << std::endl;
    }
}
