<span id="826"></span>

## 面向对象

-   案例

-   对于操作类里面写了有参数构造器后需不需要添加无参数构造器，一般是可以不用，因为都是在 
               `main` 方法里 `new`
    的时候直接在小括号里传数据，然后通过有参数构造器里面对`this.`
    赋值，不会只写个()，但是如果出现这种情况，就会提示报错，就需要加上无参数构造器。

-   而实体就一定要有无参数构造器了，这是他的格式要求。

-   实体中有参数构造器有没有都行，无参数构造器默认自带，但是**只写了有参数构造器后，就要另外加上无参数构造器**。全部都可以右键生成，要无参数的就全不选。

<img src="JavaStudyWeek-2.3_files/Image.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.3_files/Image%20%5B1%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

  

-   **成员变量和局部变量区别**

-   局部变量无初始化，动态数组的对象有初始化的。就是`int[] a = new int[3];`
    里面是全赋0。

-   成员变量，是在`main`
    方法里，栈内存，就是单独一个地址或是个值，没有开辟堆内存，所以是符合先进后出的的栈内存。

-   关于生存周期，其实本质都是作用域的问题，在大括号里生存，成员变量也是在对象消失后死亡，对象其实就是一个类，一个封装了变量和方法的类。

<img src="JavaStudyWeek-2.3_files/Image%20%5B2%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

  

## 方法和面向对象的总结

### 方法

<img src="JavaStudyWeek-2.3_files/Image%20%5B3%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.3_files/Image%20%5B4%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.3_files/Image%20%5B5%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.3_files/Image%20%5B6%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   前面落了一块方法重载和`return;` 关键字，这里补上

-   方法重载，就是同一个类里面可以有同样名字的方法，但是传进去的参数不一样（形参列表不同），会自动按照参数匹配的，其他的修饰符还有别的返回值什么的都不管，形参也只考虑个数、类型、顺序，不管叫什么名称。

-   修饰符 `public`  就是公共，`static` 就是全局。

<img src="JavaStudyWeek-2.3_files/Image%20%5B7%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.3_files/Image%20%5B8%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   重载就是易读，而且方便调用，会有提示。

<img src="JavaStudyWeek-2.3_files/Image%20%5B9%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   也是可以设定默认值

<img src="JavaStudyWeek-2.3_files/Image%20%5B10%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   小总结（专业、方便）

<img src="JavaStudyWeek-2.3_files/Image%20%5B11%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   `return` 关键字，和C语言一样，没啥特别的

<img src="JavaStudyWeek-2.3_files/Image%20%5B12%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

### 面向对象编程（oop）

<img src="JavaStudyWeek-2.3_files/Image%20%5B13%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.3_files/Image%20%5B14%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   不建议给初始化值，是因为引用的时候还要传值，除非是结构体那个变量都要求同一个特殊初始值。

<img src="JavaStudyWeek-2.3_files/Image%20%5B15%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.3_files/Image%20%5B16%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   `new` 的是构造器，构造器实际上是返回地址给栈内存的对象名保存。

<img src="JavaStudyWeek-2.3_files/Image%20%5B17%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   重点（弹幕的话其实就是包括两种，只要你定义了构造器，系统就不会自动创建了，但是你（在定义了有参数构造器后）又是还想要无参数构造器，那就得自己搞）

<!-- -->

-   `this` 关键字也很常用，在赋值或者是重名的时候用。

<img src="JavaStudyWeek-2.3_files/Image%20%5B18%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   -   在操作类里的构造器，来给操作类里面声明的实体类变量赋值，在`main`
        方法里面给操作类传实体类名（在此之前`new`
        了实体变量，赋了值后传给操作类，然后可以调用操作类里面的方法）

<img src="JavaStudyWeek-2.3_files/Image%20%5B19%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   -   在重名的时候，这里传给方法的是及格线，然后这个方法是在`Student`
        类里面的，在`main` 方法里面 `new`
        了类，赋值操作填入数据后，然后`类名.方法`
        调用这个方法，给出及格线后，           `this.score`
        就是调用目前对象，也就是新建的类里面的的`score`
        数据，与传入方法的及格线进行比较。

<img src="JavaStudyWeek-2.3_files/Image%20%5B20%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   封装思想

<img src="JavaStudyWeek-2.3_files/Image%20%5B21%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   实体类（标准JavaBean）& 局部变量和成员变量的区别

<img src="JavaStudyWeek-2.3_files/Image%20%5B22%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

## 常用API

-   API中文文档`https://cunzaima.cn/`

<!-- -->

-   别人写好的程序，就不要自己再写了，要直接拿过来用。

<img src="JavaStudyWeek-2.3_files/Image%20%5B23%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   需要学习的：IO包，lang包，NIO包，NET包，text包，time包，util包

-   **包**

<img src="JavaStudyWeek-2.3_files/Image%20%5B24%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   导包的注意事项

<img src="JavaStudyWeek-2.3_files/Image%20%5B25%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   `java.lang` 包不用另外导

<img src="JavaStudyWeek-2.3_files/Image%20%5B26%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   不同包里面有重名的类，默认只能导一个，其余的带全包名使用。

<img src="JavaStudyWeek-2.3_files/Image%20%5B27%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.3_files/Image%20%5B28%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

### String

<img src="JavaStudyWeek-2.3_files/Image%20%5B29%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   常见构造器

<img src="JavaStudyWeek-2.3_files/Image%20%5B30%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   `name`
    里面确实是字符串对象的地址，但是打印的时候会自动找到地址对应的内容打印。

-   `String` 类里面的 `toString` 方法给重写了。

<img src="JavaStudyWeek-2.3_files/Image%20%5B31%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.3_files/Image%20%5B32%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   不推荐用第二种方法（不建议类比以前的声明数组的操作就是`new String("abc")`
    ）

-   **直接双引号包住**就完事了，和C一样方便。

<img src="JavaStudyWeek-2.3_files/Image%20%5B33%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   常见的四种构造器（字符数组和字节数组都可以给构造器数组名然后构建字符串）

-   `byte` 数组是根据`ASCLL` 码表来转换的。

<img src="JavaStudyWeek-2.3_files/Image%20%5B34%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   常用的`String` 类方法

-   运用这些方法去解决案例，才能快速熟悉，不然记不住。

<img src="JavaStudyWeek-2.3_files/Image%20%5B35%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   `.length`
    按宽字节编码来统计字符数量，**一个中文字符**两个字节，**是一个字符**。

-   可以用`.charAt(i)`
    来获取对应索引位置的字符，然后实现字符串里面逐个字符的输出

-   可以用`.toCharArray()`  比如 `char[] chars = s.toCharArray();`
    把字符串转为字符数组，然后可以再遍历，输出

<img src="JavaStudyWeek-2.3_files/Image%20%5B36%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   不能直接用`s1==s2` 来判断字符串相等，这比较的是地址，会输出`false`
    前提是用`new String` 来赋值了，实际上构造器把地址给了`s1` 和`s2`
    。（如果直接双引号引起来，那就是输出`true` 了）

<img src="JavaStudyWeek-2.3_files/Image%20%5B37%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   输出`false` 因为地址不一样。

<img src="JavaStudyWeek-2.3_files/Image%20%5B38%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   输出`true` 因为重写了`toString` 方法

<img src="JavaStudyWeek-2.3_files/Image%20%5B39%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   正确的应该是调用 `.equals()` 方法来比较，输出`true`

<img src="JavaStudyWeek-2.3_files/Image%20%5B40%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   注意字符串不能与其它类型转换后的字符串相比较

-   `.equalsIgnoreCase()` 忽略大小写，经常用于比较验证码。

<img src="JavaStudyWeek-2.3_files/Image%20%5B41%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   `.subString()`
    索引包前不包后，前面的索引就是包括的，选中看是多少个字符然后减一，后面的索引看下方是几个字符就填几。

<img src="JavaStudyWeek-2.3_files/Image%20%5B42%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   只填前面的索引就会一直输出到末尾

<img src="JavaStudyWeek-2.3_files/Image%20%5B43%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   例子，输出`World`

<img src="JavaStudyWeek-2.3_files/Image%20%5B44%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

  

-   切片 (python)

<img src="JavaStudyWeek-2.3_files/Image%20%5B45%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.3_files/Image%20%5B46%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   `.replace()`
    方法，第一个参数是字符串中要替换的字符，第二个是要替换成什么字符

<img src="JavaStudyWeek-2.3_files/Image%20%5B47%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   `.contains()`
    方法，判断字符串有没有给到方法的关键字，然后返回布尔值，精准匹配，大小写也要对应。

<img src="JavaStudyWeek-2.3_files/Image%20%5B48%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   `.startsWith()`
    方法，判断字符串是不是以某个字符串开头，一般用于判断姓氏。

<img src="JavaStudyWeek-2.3_files/Image%20%5B49%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   `.split()`
    方法，把字符串按照某个指定内容分割为多个字符串，放到一个字符串数组里面返回。

-   例子中原字符串姓名按照都好分隔，想提取单独的姓名字符串，存到一个字符串数组里面，就这样写。

<img src="JavaStudyWeek-2.3_files/Image%20%5B50%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   注意事项

<img src="JavaStudyWeek-2.3_files/Image%20%5B51%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   `+=`
    实际上是产生了新的字符串对象，然后把那个对象的地址转给栈内存的变量储存，原本的字符串对象是不变的，只是改变了栈内存变量存的地址，而地址是指向新对象的，原来的（刚开始声明的对象的内容存在字符串常量池）里面，并不会改变。只要不是双引号给的（比如`+=`
    `-=`
    ），就是新创建一个对象，原来的对象也不变，只是没有变量存它的地址，变成垃圾给自动回收了。

-   此处在后面也有提到，利用了`StringBuilder`
    ，本质是一个可变的字符数组来完成拼接，之后创建新的字符串对象提供新地址给原有变量储存。

<img src="JavaStudyWeek-2.3_files/Image%20%5B52%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   第二点就是前面不同声明方式会有差别的原理

<img src="JavaStudyWeek-2.3_files/Image%20%5B53%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

  

-   弹幕说会有优化，说`s1==s2` 是比较`s1` ,`s2`
    的内容而不是地址，可以说是乱讲，还是比较的地址，只是同一个常量是共用一个地址，此处
    `s1` `s2` 存的地址是一样的，都是常量池里面的`abc` ，所以输出`true`

<img src="JavaStudyWeek-2.3_files/Image%20%5B54%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.3_files/Image%20%5B55%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   如图所示

<img src="JavaStudyWeek-2.3_files/Image%20%5B56%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />
