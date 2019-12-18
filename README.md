# miyuki.serialize
lightweight serialization for C++

## example

```C++
using miyuki::serialize::OutputArchive;
using miyuki::serialize::Context;
struct Foo{
  int a = 2, b = 3, c = 4;
  MYK_SER(a,b,c)
};
int main(){
    Foo foo;
    Context ctx;
    
    // outputs {'a':2,'b':3,'c':4}
    std::cout << toJson(ctx).dump() << std::endl;
}
```

