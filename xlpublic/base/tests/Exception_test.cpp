#include <xlpublic/base/Exception.h>
#include <stdio.h>

class Bar
{
public:
    void test()
    {
        throw XL::Exception("oops");
    }
};

void foo()
{
    Bar b;
    b.test();
}

int main()
{
    try
    {
        foo();
    }
    catch (const XL::Exception &ex)
    {
        printf("reason: %s\n", ex.what());
        printf("stack trace: %s\n", ex.stackTrace());
    }
}
