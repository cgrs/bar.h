# bar.h

(Yet another) progress bar C library

## Description

This C library helps on printing progress bars in programs with long running
tasks.

![Demonstration](demo.gif?raw=true)

## Usage

```c
#include "bar.h"
/* ... */
bar_1(20); // prints a preset bar at 20%
/* ... */
```

This project has inline documentation. To find out how a function works, just peek at the code.

Please note that it counts from 0 to 100 inclusive (that's 101 possible values to the progress bar).

## Motivation

I started developing this library under a friend request. I thought it could be useful for
other people, so I decided to upload it here.

I also did this to practise my C coding skills, so you may find some bad coding practices or
designs. In that case, don't hesitate to send me a pull request.