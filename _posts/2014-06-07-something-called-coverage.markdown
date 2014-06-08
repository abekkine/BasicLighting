---
layout: post
title: "Something called Coverage"
date:   2014-06-07 14:01
---
# Leaks are gone... or not?

When we run our last [build](https://github.com/abekkine/BasicLighting/tree/333659d6c2fb4d5d9320f8fea75fa23cb55f25b0) with valgrind, everything looks fine. Check our valgrind log below:

{% highlight bash %}
{% include vg.clean.log %}
{% endhighlight %}

However, remember that we don't call *Application::render()* yet. And valgrind can only detect leaks from executed code. When requested, *Display::quitRequest()* function always returns true, so render function cannot be executed. So, let's tweak *Display::quitRequest()* function a bit; so it returns *false* for a number of times before it finally returns *true*.

{% highlight cpp %}
bool Display::quitRequest() { 
     // TODO return quit request.

    static int count=1000;
    bool quit = false;

    count--;
    if (count < 0) {
        quit = true;
    }

    return quit;
}
{% endhighlight %}

When you compile with this changes, and run with *grind.sh*, we get following log file:

{% highlight text %}
{% include vg.loop.log %}
{% endhighlight %}

New leaks appear. Valgrind can only detect memory leaks in executed program sections. Naturally, if we have code sections that is not executed, all possible errors & leaks in them will stay dormant.

# Coverage and Testing

So, how can be assure that all code sections in our program will be executed? Here comes *Coverage Analysis* and *Testing* topics.

We can use coverage analysis tools to detect non-executed code lines. Then we can force them to execute by testing techniques. 

# lcov

We finish this post by explaining how to use *lcov*, a coverage analysis tool for linux platforms. We will use lcov to understand what causes our existing memory leaks.

First thing we do is to install lcov:

{% highlight bash %}
$ sudo apt-get install lcov
{% endhighlight %}

Then we update our makefile to generate data needed by lcov tool:

{% highlight makefile %}
...
FLAGS=-g -Wall -Wextra -Werror -Wfatal-errors 
FLAGS+=-O0 -coverage
...
{% endhighlight %}

We just added to switches to compiler & linker flags. When we build with these options, additional files with extension *.gcno* is generated. Now we should run our application to collect data.

{% highlight bash %}
$ ./lights.bin
{% endhighlight %}

After this step you see more additional files (with *.gcda* extension) appears in our project folder. We can now proceed with report generation. For this, we run following command in our project folder:

{% highlight bash %}
$ lcov -o report.info -c -d .
{% endhighlight %}

Generated *report.info* file is in text format, however it is hard to read and interpret. Therefore, we generate a much more readable html format for coverage information. For this purpose, we run following command:

{% highlight bash %}
$ genhtml -o report --no-branch-coverage report.info
{% endhighlight %}

At the end of this last step, we have a folder named *report* which contains coverage analysis for our application. Run following:

{% highlight bash %}
$ cd report
$ google-chrome ./index.html
{% endhighlight %}

You can find link to generated report [here]({{site.baseurl}}/data/report/index.html).




