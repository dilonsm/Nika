## Nika
Inspired by TheCherno, from the Hazel Engine series.
[Youtube Playlist](https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT)

### About
'Nika' is a work in progress Game Engine which is being written in C++.

To try it out, u need an IDE of your choice that supports .sln files.

**1) Clone it via terminal.**

```
git clone --recursive https://github.com/dilonsm/Nika.git
```

**2) Download latest premake binary and put it in Nika/vendor/premake.**

**Download Page --->[Premake](https://premake.github.io/download/)**

There is a 'RAYpremake5.lua' file in the premake folder. \
Rename it to 'premake5.lua' and move it to Nika/Nika/vendor/raylib.

**3) Run the .bat script to generate the project.**

**4) Open the solution file and build the project**

***It may take two or three tries to build!***

**When building the solution, raylib is compiled first, followed by Nika and then Sandbox.** \
**My assumption is that the Nika.dll is created before the Sandbox bin folder exists, so copying it there may fail but i'm on it.**

