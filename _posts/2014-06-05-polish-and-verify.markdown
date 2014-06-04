---
layout: post
title: Polish and Verify
date:   2014-06-05 01:15
---
At this point, algorithmic functionality, including vector calculations required to cast shadows, added to code. Now we will finish remaining debug logs, marked with **PRINT** definitions. But most importantly, before adding visulation with the help of external libraries (GLUT, SDL, etc.) we should check & verify our code against possible memory leaks.

Usually external libraries may bring their own leaks into your program and those are usually much more difficult to resolve. So, before we start to link with something complicated, we better be sure that there left no memory leaks on our code.

Valgrind is our main tool in this quest, and i will add some scripts to repository for ease of use.

Then, we will profile our code to see if there are any perfomance issues.

When all these steps will be completed, we start implementing **Display** class for visualization.
