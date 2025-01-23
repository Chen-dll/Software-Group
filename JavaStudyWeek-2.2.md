<span id="744"></span>

## 方法应用案例

-   双色球

<img src="JavaStudyWeek-2.2_files/Image.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.2_files/Image%20%5B1%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.2_files/Image%20%5B2%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   一些边界判断

<img src="JavaStudyWeek-2.2_files/Image%20%5B3%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

  

<img src="JavaStudyWeek-2.2_files/Image%20%5B4%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

## ※面向对象编程

其实就是强调分开成很多个对象的思想，每个对象写一个模板完成特定的功能，万物皆对象

-   第一步新建个类，就类似`C++` 里面的类，类的变量，类里面可以封装函数

<img src="JavaStudyWeek-2.2_files/Image%20%5B5%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   第二步`main` 方法里面调用 跟结构体的调用方式一样，要
    `Student s1=new Student();`

<img src="JavaStudyWeek-2.2_files/Image%20%5B6%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.2_files/Image%20%5B7%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   就是结构体或者说C++里面的类 没啥特别的

<img src="JavaStudyWeek-2.2_files/Image%20%5B8%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.2_files/Image%20%5B9%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.2_files/Image%20%5B10%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   `Student s1= new Student();` 首先把`Student.class`
    加载到方法区，然后在栈内存开一个`s1` 变量，然后 `new Student()`
    在堆内存开一个空间，最后把类的地址存给栈内存`s1` 这个变量，

<img src="JavaStudyWeek-2.2_files/Image%20%5B11%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   地址是包名+类名的形式 @是在哪里的意思，十六进制存地址

<img src="JavaStudyWeek-2.2_files/Image%20%5B12%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.2_files/Image%20%5B13%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   引用类型的变量就是存地址的变量

<img src="JavaStudyWeek-2.2_files/Image%20%5B14%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   注意事项

<img src="JavaStudyWeek-2.2_files/Image%20%5B15%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   一个文件可以有多个类，但是只能有一个`public`
    修饰的类，而且这个类的名字只能是文件名，不然会报错

<img src="JavaStudyWeek-2.2_files/Image%20%5B16%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

  

-   地址赋`NULL`
    会导致栈内存储存的地址没了，堆内存开辟的空间没有被引用了，找不到就会报错  
    （空指针异常）

<img src="JavaStudyWeek-2.2_files/Image%20%5B17%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   `Java` 垃圾内存会自动删，C里面`malloc` 之后要`free`

<img src="JavaStudyWeek-2.2_files/Image%20%5B18%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   C++里面 `new` 完要 `delete`

<img src="JavaStudyWeek-2.2_files/Image%20%5B19%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   Java不用管

<img src="JavaStudyWeek-2.2_files/Image%20%5B20%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   `this` 的执行原理

<img src="JavaStudyWeek-2.2_files/Image%20%5B21%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.2_files/Image%20%5B22%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   `this` 的用法，类似于一个指针变量，拿到当前对象的地址，`this.score`
    就好比 `Student.score`

<img src="JavaStudyWeek-2.2_files/Image%20%5B23%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   用处就是访问当前对象的成员变量

<img src="JavaStudyWeek-2.2_files/Image%20%5B24%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.2_files/Image%20%5B25%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

## 构造器

-   创建对象的时候，对象会根据右边小括号里面的参数情况，来选择对应的构造器执行。

<img src="JavaStudyWeek-2.2_files/Image%20%5B26%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   用于初始化对象成员变量 （和手动赋值相比就是能在`new`
    的时候在小括号给好数据，赋好值了。

<img src="JavaStudyWeek-2.2_files/Image%20%5B27%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.2_files/Image%20%5B28%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   构造器注意事项

<img src="JavaStudyWeek-2.2_files/Image%20%5B29%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.2_files/Image%20%5B30%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   面向对象的三大特征之一 封装（好习惯）

-   设计规范：合理隐藏、合理暴露

-   对于变量，在对象里面把成员变量都`private` ，写一些`public`
    的方法提供给调用者使用  `get` `set`

-   对于方法，就是看需不需要提供给外界，不需要就 `private`

-   对于构造器，都`public`

-   公开对应修饰符 `public` 隐藏对应修饰符`private`

<img src="JavaStudyWeek-2.2_files/Image%20%5B31%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   不直接把成员变量提供直接访问权限，给出可调用的函数来进行访问，函数中加入一些必要的判断

<img src="JavaStudyWeek-2.2_files/Image%20%5B32%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   小总结

<img src="JavaStudyWeek-2.2_files/Image%20%5B33%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

## 实体类

-   特征

<img src="JavaStudyWeek-2.2_files/Image%20%5B34%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   IDE自动可以为成员变量生成 `get` `set` 方法，直接右键，然后选中全部

<img src="JavaStudyWeek-2.2_files/Image%20%5B35%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.2_files/Image%20%5B36%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   实体中有参数构造器有没有都行，无参数构造器默认自带，但是只写了有参数构造器后，就要另外加上无参数构造器。全部都可以右键生成，要无参数的就全不选。

-   实体类啥也没有 就是能创建对象储存和输出数据，就是单纯的结构体。

-   对于实体中的`get` 和 `set`
    方法，再定义有参数构造器（比较贴心和人性化）的话，就会是在`new`
    的时候，完成了赋值的操作，就是 `set`
    了值，以后要更改或者提取数据也是要调用那两个方法的（毕竟全是`private`
    ，也算是合理隐藏吧）,如果没有有参数构造器，默认就是无参数构造器，也是相当的`private`
    。

-   对数据的处理交给其他类完成，先写个有参数构造器接受结构体，相当于给方法类新声明的结构体赋值，然后再去调用别的方法。

<img src="JavaStudyWeek-2.2_files/Image%20%5B37%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.2_files/Image%20%5B38%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   结构体数组的遍历也是类似的，不过他令m等于 `movie[i]`
    没什么必要，弹幕说可能名字比较复杂，那也无所谓

<img src="JavaStudyWeek-2.2_files/Image%20%5B39%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />
