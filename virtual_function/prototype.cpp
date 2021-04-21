/*prototype.cpp --虚拟函数列表的C语言实现*/
#include <cstdio>
#include <cstdint>
#include <cstdlib>

extern "C" {
    // 基类ISpeaker虚拟函数表 原型
    struct SpeakerTable {
        void(* speak) (void* _ptr);
    };

    // 派生类中speak()方法的实现
    void _dog_speak(void* _ptr) {
        uint8_t* p = (uint8_t*)_ptr;
        p+=sizeof(SpeakerTable*);
        size_t b = *((size_t*)p);
        printf("woof! %llu\n",b);
    }

    void _human_speak(void* _ptr) {
        uint8_t* p = (uint8_t*)_ptr;
        p+=sizeof(SpeakerTable*);
        size_t b = *((size_t*)p);
        printf("hello! %llu\n",b);// 有点问题???
    }
    // 派生类Dog的虚函数表
    const static SpeakerTable _dogSpeakTable = {
            _dog_speak
    };
    // 派生类Human的虚函数表
    const static SpeakerTable _humanSpeakTable = {
            _human_speak
    };

    // 数据结构
    struct _ispeaker {
        const SpeakerTable* vt;
        size_t b;
    };
    // Dog的内存模型--存储结构
    struct _dog {
        const SpeakerTable* vt;
        size_t b;
    };
    // Human的内存模型--存储结构
    struct _human {
        const SpeakerTable* vt;
        size_t b;
        size_t c;
    };
    // 模拟类中的构造器
    _dog * createDog() {
        _dog* ptr = (_dog*)malloc(sizeof(_dog));
        ptr->vt = &_dogSpeakTable;
        ptr->b = 0;

        return ptr;
    }
    _human * createHuman() {
        _human* ptr = (_human*)malloc(sizeof(_human));
        ptr->vt = &_humanSpeakTable;
        ptr->b = 1;
        ptr->c = 2;

        return ptr;
    }

};

int main(int _argc,char** _argv) {
    _dog* dog = createDog();
    _human* human = createHuman();

    _ispeaker* speaker1 = (_ispeaker*)dog;// 强制类型转换
    _ispeaker* speaker2 = (_ispeaker*)human;

    speaker1->vt->speak(speaker1);
    speaker2->vt->speak(speaker2);

    return 0;
}