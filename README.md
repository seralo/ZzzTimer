# ZzzTimer
Simple Arduino / C++ library to manage a timer


The library consist of a single header file (ZzzTimer.h).


### Constructor

```cpp
ZzzTimer timer(intervalMs); //milliseconds interval

```

### Functions

```cpp
void update();        // To call in Arduino loop

void setCallback(myCallback);  // Set the callback to call on each new value.
```

### Included examples

- `TimerBasic/TimerBasic.ino` - Show basic usage


### Simple code example

```cpp
#include <ZzzTimer.h>

ZzzTimer timer(5000);



void setup()
{
    ...
    timer.setCallback(myCallback)
}

void loop()
{
    ...
    timer.update();
    ...
}
```

