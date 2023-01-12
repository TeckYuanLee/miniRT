Honestly, while I was trying to implement diffusing, I was stuck at it for the whole day. Having all the pixels rendered in [0, 0, 0], which is just black. At first, I suspect that my random function maybe wrong. Tested and done more search online to implement a correct RNG function. But that did not fix the problem, so I just kept checking each part of my code, making all the maths are correct.

(Side note, debugger helped me a lot in this process, as there were many variables that I want to check. But at one point of the day, the debugger was not working, it shows that "breakpoint could not be found because of module not loaded", turns out i left out the `-g3` flag in compiling.)

After a really long day, I decided to sit down and actually really think about what could be the cause. Then I though maybe it's because the "scattered" ray was in a wrong direction. After reading more, the math is actually correct. So, I went back to my code, running the flow line by line, realized that its always "hitting" something even when some ray shouldn't be. Turns out, I did not initialize the `hit record`, which in turn has garbage value that tricked the program thinking it "hitted" something.

So, there's the lesson, initializing is very important.

I had the same bug for a short time while implementing anti aliasing, which is taking multiple sampling for surrounding pixel of the origin pixel, the initial value started with garbage value, and rendered a weired rainbowy screen.
