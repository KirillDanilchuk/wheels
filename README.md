
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
  using namespace wheels::io;
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
  wheels::io::PrintLine('a', 'b', 1, "number");
  wheels::io::PrintLineWithDelimiter(", ", 1, 2, 3);
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
#include <vector>

int main() {
  std::vector ints{1, 2, 3, 4, 5};
  wheels::io::PrinterWithDelimiter printer(/*left_border=*/"[ ",
      /*delimiter=*/" | ",
      /*right_border=*/" ]");
  for (auto&& value : ints) {
    printer.Print(value);
  }
  printer.End(); // print right_border
  return 0;
}
```
Output:
```
[ 1 | 2 | 3 | 4 | 5 ]
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