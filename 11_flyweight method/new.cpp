#include <iostream>
using namespace std;

class Font {
private:
    // unique object key
    string key;

    // object state
    // ...

public:
    Font(const string &key) {
        // 使用key构建对象
    }
};

class FontFactory {
private:
    // 字体池，保证每一个key只有一个对象
    map<string, Font*> fontPool;
public:
    // 创建出来是只读的
    Font *GetFont(const strint &key) {
        map<string, Font*>::iterator item = fontPool.find(key);

        if (item != fontPool.end()) {
            return fontPool[key];
        }
        else {
            Font *font = new Font(key);
            fontPool[key] = font;
            return font;
        }
    }

    void clear() {
        // ...
    }
};