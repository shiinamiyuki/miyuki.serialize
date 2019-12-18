// MIT License
//
// Copyright (c) 2019 椎名深雪
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <miyuki.serialize/serialize.hpp>
#include <iostream>

using namespace miyuki::serialize;

struct Bar : public Serializable {
    int a{}, b{}, c = 4;

    MYK_SER(a, b, c)

    MYK_TYPE(Bar, "Bar")

};

struct Foo {
    int a, b, c;
    std::shared_ptr<Bar> bar;
    std::shared_ptr<Bar> bar2;
    MYK_SER(a, b, c, bar, bar2)
};

int main() {
    Context context;
    context.registerType<Bar>();
    Foo foo{};
    foo.a = 2;
    foo.b = 3;
    foo.c = 4;
    foo.bar = std::make_shared<Bar>();
    foo.bar2 = foo.bar;
    auto j = toJson(context, foo);
    std::cout << j.dump() << std::endl;
    foo = fromJson<Foo>(context, j);
    j = toJson(context, foo);
    std::cout << j.dump() << std::endl;
}
