#include "auto_base.h"

void p(std::map<int, std::vector<int>>& map) {
    for(auto & itr : map) {
        cout << itr.first <<"hhhh" <<endl;
    }
}
//序列容器
void vec(std::vector<int>& vec) {
    unsigned i = 0;
    for(const auto& it : vec)
        cout << "elem" << "[" << i++ << "]" << ":" << " " << it <<endl;

    cout << "total size: " << vec.size() <<endl;
}

//关系容器
void m(boost::unordered_map<int, int> &map) {
    unsigned i = 0;
    for(const auto& itr : map)
        cout << "elem" << "[" << i++ << "]" << ":" << " " << itr.first << " " << itr.second << endl;

    cout << "total size: " << map.size() <<endl;
}

//关系型容器-->序列容器
void mv(std::map<int, std::vector<int>>& map) {
    unsigned i = 0;
    for(const auto& itr : map) {
        cout << "elem" << "[" << i++ << "]" << ":" << " " << itr.first <<endl;;
        cout << "   ";
        for(const auto& it : itr.second)
            cout << it << " "; 
        cout << endl;
    }
    cout << "total size: " << map.size() <<endl;
}

//关系型容器-->关系型容器-->序列容器
void mmv(std::map<int, std::map<int, std::vector<int>>>& map) {
    unsigned i = 0;
    for(const auto& itr0 : map) {
        cout << "elem0" << "[" << i++ << "]" << ":" << " " << itr0.first <<endl;;
        unsigned j = 0;
        for(const auto& itr1 : itr0.second) {
            cout << "   " << "elem1" << "[" << j++ << "]" << ":" << " " << itr1.first <<endl;;
            cout << "      ";
            for(const auto& it : itr1.second)
                cout << it << " "; 
            cout << endl;
        }
        cout << "   " << "total size: " << itr0.second.size() <<endl;
    }
    cout << "total size: " << map.size() <<endl;
}


#if 0
void mmmv(std::map<int, std::map<int, std::vector<int>>>& map) {
    unsigned i = 0;
    for(const auto& itr0 : map) {
        cout << "elem" << "[" << i++ << "]" << ":" << " " << itr0.first <<endl;;
        cout << "   ";
        unsigned j = 0;
        for(const auto& itr1 : itr0.second) {
            cout << "elem" << "[" << j++ << "]" << ":" << " " << itr1.first <<endl;;
            cout << "      ";
            for(const auto& it : itr1.second)
                cout << it << " "; 
            cout << endl;
        }
        cout << "total size: " << itr0.second.size() <<endl;
    }
    cout << "total size: " << map.size() <<endl;
}
//关系型容器-->关系型容器-->序列容器
void mv(std::map<int, std::map<int, >>& map) {
    unsigned i = 0;
    for(const auto& itr : map) {
        cout << "elem" << "[" << i++ << "]" << ":" << " ";
        for(const auto& it : itr.second)
            cout << it << " "; 
        cout << endl;
    }
    cout << "total size: " << map.size() <<endl;
}
#endif
