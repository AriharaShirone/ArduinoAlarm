# ArduinoAlarm
基于Arduino的简单报警器

很早以前做的一个项目，低成本的防盗报警器。装在你家门口，有人开门就会报警然后给你发短信。

需要使用SIM900模块。当然，要运行这个项目，除该模块之外，你还需要：

Arduino（UNO就行，不需要太高级的板子，当然我没用Nano试过，如果Nano够用的话体积会更小）；

红外线距离传感模块（用来判断门有没有开）。

当时似乎因为线不够长（懒得买），用10/11做了软串口

代码重新做过注释，应该比较好懂，很容易就能复刻一个。端口什么的可以自己调。
