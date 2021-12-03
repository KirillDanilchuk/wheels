
![Wheels](https://media.giphy.com/media/Gjnpx6nps0yS4/giphy.gif)
# wheels
Core C++ components

- [Components](#components)
- [Integration](#integration)

## Components
### [IO](wheels/io) (input/output)

Input/output component to simplify the work with the console

#### [Samples](samples/io)

[Python style input and output](samples/io/input.cpp)
```cpp
#include <wheels/io/io.hpp>

int main() {
  using namespace wheels;
  auto value = Input<int>("Enter value:");
  PrintLine("Value:", value);
  return 0;
}
```
Output:
```
Enter value:42
Value:42
```

[Print with delimiter](samples/io/output.cpp)
```cpp
#include <wheels/io/io.hpp>

int main() {
  wheels::PrintLine('a', 'b', 1, "number");
  wheels::PrintLineWithDelimiter(", ", 1, 2, 3);
  return 0;
}
```
Output:
```
ab1number
1, 2, 3
```
[Printer with delimiter](samples/io/printer.cpp)
```cpp
#include <wheels/io/io.hpp>

int main() {
  std::vector ints{1, 2, 3, 4, 5};
  wheels::PrinterWithDelimiter printer(/*left_border=*/"[ ",
      /*delimiter=*/" | ",
      /*right_border=*/" ]");
  for (auto&& value : ints) {
    printer.Print(value);
  }
  printer.End(); // print right_border

  wheels::FlushAndNewLine();

  wheels::PrinterWithDelimiter simple_printer(/*delimiter=*/", ");
  simple_printer.PrintLineAll("Begin", 42, "End");
  return 0;
}
```
Output:
```
[ 1 | 2 | 3 | 4 | 5 ]
Begin, 42, End
```

### [support](wheels/support)
Support component to simplify the work

#### [Samples](samples/support)
[panic](samples/support/panic.cpp)

Abort with message builder

```cpp
//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 20/11/2021.
//

#include <wheels/support/panic.hpp>

int main(int argc, char** argv) {
WHEELS_PANIC("Error message 1 " << "Error message 2 " << 3);
return 0;
}
```
Output:
```
Panicked at /Users/kirilldanilchuk/Projects/CLionProjects/wheels/samples/support/panic.cpp:int main(int, char **)[Line 8]: Error message 1 Error message 2 3

Process finished with exit code 134 (interrupted by signal 6: SIGABRT)

```
[assert](samples/support/assert.cpp)
```cpp
//
// Created by Kirill Danilchuk <kirill.danilchuk01@gmail.com> on 20/11/2021.
//

#include <wheels/support/assert.hpp>
#include <wheels/io/io.hpp>

int main() {
  constexpr int SUPER_VALUE = 42;
  const auto value = wheels::Input<int>("Enter value:");
  WHEELS_ASSERT(value < SUPER_VALUE, "Too large value");
  return 0;
}
```
Output:
```
Enter value:43
Panicked at /Users/kirilldanilchuk/Projects/CLionProjects/wheels/samples/support/assert.cpp:int main()[Line 11]: Assertion 'value < SUPER_VALUE' failed: Too large value

Process finished with exit code 134 (interrupted by signal 6: SIGABRT)
```

[Pimpl](tests/pimpl)

["Pointer to implementation" or "pImpl" is a C++ programming technique that removes implementation details of a class from its object representation by placing them in a separate class, accessed through an opaque pointer.](https://en.cppreference.com/w/cpp/language/pimpl)

This is the fast pimpl implementation.
```cpp
// PublicClass.hpp
#include <wheels/support/Pimpl.hpp>

class PrivateClass;

class PublicClass {
  PublicClass(int value);
  ~PublicClass(); //implement to cpp file
  Data GetData();
  
  private:
  Pimpl<PrivateClass, 32, 32> private_class_;
};
```
```cpp
// PublicClass.cpp

#include "PublicClass.hpp"
#include <PrivateClass.hpp>

PublicClass::PublicClass(int value) : private_class_{value} {
  // pass
}

PublicClass::~PublicClass() = default;

auto PublicClass::GetData() -> Data {
  return ToData(private_class->GetValue());
}
```

## Integration
### CMake
#### Embedded (FetchContent)
Since CMake v3.11, [FetchContent](https://cmake.org/cmake/help/v3.11/module/FetchContent.html) can be used to automatically downloaded the repository as a dependency at configure time.
Example
```cmake
include(FetchContent)

FetchContent_Declare(
        wheels
        GIT_REPOSITORY https://github.com/KirillDanilchuk/wheels.git
        GIT_TAG origin/main
)

FetchContent_MakeAvailable(wheels)

target_link_libraries(${PROJECT_NAME} PRIVATE wheels)
```
Example project how to use library https://github.com/KirillDanilchuk/wheels-cmake-test