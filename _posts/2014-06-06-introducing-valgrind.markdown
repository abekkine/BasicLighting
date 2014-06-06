---
layout: post
title: Introducing Valgrind
date:   2014-06-06 05:01
---
# Memory Leaks

If in your code, whenever you use *heap*, rather than *stack* for your variables/objects, you have to manually allocate & deallocate the memory used by them.

In other words, there should be a **delete** for each **new**, or a **free** for each **malloc**... For static allocations, it should not be a big deal, but when you need to create and destroy your objects dynamically, there the real pain begins.

That's where *valgrind* runs to our help.

# Valgrind

Valgrind is some kind of magical tool for linux developers. Basically it tells you,

* If there are any memory leaks in your code,
* Exactly where these leaks are, if there are any.

All you need to do is run your program with valgrind:

{% highlight bash %}
$ valgrind ./lights.bin
{% endhighlight %}

So our output will be;

{% highlight bash %}
{% include vg.log %}
{% endhighlight %}

And that's just a start. We use script named *grind.sh* to take a shortcut on running valgrind.

{% highlight bash %}
grind.sh:

#!/bin/bash

valgrind --log-file=vg.log ./lights.bin

{% endhighlight %}

You may find valgrind log for [this](https://github.com/abekkine/BasicLighting/tree/e227b3c65cd3a86a1c1238786555c1e5cf8a038b) revision of BasicLighting sources in [here]({{ site.baseurl }}/data/vg2.log). From this point, you may track the changesets to see how to eliminate detected leaks.

One thing to remember, though: No matter how magical the valgrind is, it would be still painful to treat *accumulated* leaks. Believe me, you don't want to wander through a long, long valgrind log file. When leaks were accumulated, it would cause some sort of *chain reactions* and it becomes harder to point out where the *real* mistakes are. So it's better to run valgrind frequently with your program, and eliminate leaks whenever they appear.

Also remember external library issue in [this]({{ site.baseurl }}/{% post_url 2014-06-05-polish-and-verify %}) post; sometimes external libraries may have their own leaks packed with them, and it's easy to link with others when you have less to doubt about your code. We come back to this when we integrate with GLUT.

# Alleyoop

For those who can't live without a gui, there's a tool named *alleyoop* who provides a nice gui for valgrind. I mostly prefer terminal, so it's up to you to decide to use it or not.
