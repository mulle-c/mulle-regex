# mulle-regex

#### 📣 Unicode regex library

A simple regular expression library fit for most purposes.

> This is a version of Henry Spencers well-known regular-expression package,
> regexp(3) adapted for unicode.

It gives C programs the ability to use egrep-style regular expressions.
It is not, alas, fully POSIX.2-compliant; that is hard.

This version is the one which is examined and explained in one chapter of
"Software Solutions in C" (Dale Schumacher, ed.; AP Professional 1994;
ISBN 0-12-632360-7), plus a couple of insignificant updates, plus one
significant bug fix (done 10 Nov 1995).

This implementation uses nondeterministic automata rather than the
deterministic ones found in some other implementations, which makes it
simpler, smaller, and faster at compiling regular expressions, but slower
at executing them.  Many users have found the speed perfectly adequate,
although replacing the insides of egrep with this code would be a mistake.

The code is in general less forgiving than the original Henry Spencers code.
For substitution you have to give the length of the destination buffer,
to protect against overflows. There are a few added convenience methods.



| Release Version                                       | Release Notes  | AI Documentation
|-------------------------------------------------------|----------------|---------------
| ![Mulle kybernetiK tag](https://img.shields.io/github/tag/mulle-c/mulle-regex.svg) [![Build Status](https://github.com/mulle-c/mulle-regex/workflows/CI/badge.svg)](//github.com/mulle-c/mulle-regex/actions) | [RELEASENOTES](RELEASENOTES.md) | [DeepWiki for mulle-regex](https://deepwiki.com/mulle-c/mulle-regex)




## Documentation & Guides

* [API Summary](asset/dox/api/toc)




### You are here

![Overview](overview.dot.svg)





## Add

### Add mulle-regex via mulle-core

mulle-regex is a component of the
[mulle-core](//github.com/mulle-core/mulle-core) library.
In your code include its umbrella header:

``` c
#include <mulle-core/mulle-core.h>
```

In your project add mulle-core as a git submodule and link against it:

``` bash
git submodule add -f "https://github.com/mulle-core/mulle-core.git" \
                     "stash/mulle-core"
git submodule update --init --recursive
```

then add these comands to your `CMakeLists.txt`:

``` cmake
include_directories( SYSTEM "stash/mulle-core/src")
add_subdirectory( stash/mulle-core)
target_link_libraries( ${PROJECT_NAME} PUBLIC mulle-core)
```

Or let [mulle-sde](//github.com/mulle-sde) do it:

``` sh
mulle-sde add mulle-core/mulle-core
```




### Add mulle-regex as a cmake subproject

In your code include its header:

``` c
#include <mulle-regex/mulle-regex.h>
```

Add mulle-regex and dependencies as git submodules and link against
them:

``` bash
git submodule add -f --name "mulle-utf" \
                            "https://github.com/mulle-c/mulle-utf.git" \
                            "stash/mulle-utf"
git submodule add -f --name "mulle-regex" \
                        "https://github.com/mulle-c/mulle-regex" \
                        "stash/mulle-regex"
git submodule update --init --recursive
```

``` cmake
include_directories( SYSTEM "${CMAKE_BINARY_DIR}/include")

add_subdirectory( stash/mulle-utf)
add_subdirectory( stash/mulle-regex)

target_link_libraries( ${PROJECT_NAME} PUBLIC mulle-utf)
target_link_libraries( ${PROJECT_NAME} PUBLIC mulle-regex)
```

Or let [mulle-sde](//github.com/mulle-sde) do it:

``` sh
mulle-sde add github:mulle-c/mulle-regex
```

## Individual Install

Install all the prerequisites.

``` bash
PREFIX=/tmp/usr/local
BUILD_DIR="mulle-regex/build"

cmake -S "mulle-regex" -B "${BUILD_DIR}"    \
  -DCMAKE_BUILD_TYPE="Release"                  \
  -DCMAKE_INSTALL_PREFIX="${PREFIX}"            \
  -DCMAKE_PREFIX_PATH="${PREFIX}"               \
  -DCMAKE_C_FLAGS="-I"${PREFIX}"/include"       \
&& cmake --build "${BUILD_DIR}" &&              \
&& cmake --install "${BUILD_DIR}"
```

## Acknowledgments

```
Copyright (c) 1986, 1993, 1995 by University of Toronto.
Written by Henry Spencer.  Not derived from licensed software.
Permission is granted to anyone to use this software for any
purpose on any computer system, and to redistribute it in any way,
subject to the following restrictions:

1. The author is not responsible for the consequences of use of
this software, no matter how awful, even if they arise
from defects in it.

2. The origin of this software must not be misrepresented, either
by explicit claim or by omission.

3. Altered versions must be plainly marked as such, and must not
be misrepresented (by explicit claim or omission) as being
the original software.

4. This notice must not be removed or altered.
```

The original distribution might still live at ftp://ftp.zoo.toronto.edu/pub/bookregexp.{tar|shar}.

## Author

[Nat!](https://mulle-kybernetik.com/weblog) for Mulle kybernetiK  
[Henry Spencer!]() for University of Toronto  



