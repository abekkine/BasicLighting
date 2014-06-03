---
layout: post
title:  "Good Place to Start"
date:   2014-06-02 23:40
---

It's best (IMHO) to start with logic first, putting glut, shaders & stuff aside.
We aim to obtain a compiling C/C++ code first, before adding visualization.
We will be working on linux platform (i'm specifically working on ubuntu 12.04.4 LTS, 
desktop edition); so our tools will be GNU-C/C++ compiler and Make for builds. 

In order to keep things simple, our starting code will not use any external dependencies.
We will have a couple of source & header files, and a Makefile.

As a beginning, we will need files for

 * Main -- body of our application,
 * Light -- for light objects,
 * Block -- for blocks,
 * Application -- to contain application logic,

In addition we have,

 * A simple namespace for configuration parameters,
 * Edge and EdgeShadow objects to improve readability,
 * A better functional breakdown (i hope),
 * Comment lines for visualization.

You may find the rest in github [repository](https://github.com/abekkine/BasicLighting/tree/a810233affe78bf2a78eab9175423acdeec2535d) page.