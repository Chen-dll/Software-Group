<span id="658"></span>

继续看黑马程序员的课程

## 数组

-   多个变量指向同一个数组 因为数组名存的是地址 赋值后也是地址
    类似于C语言的指针

-   原理图

<img src="JavaStudyWeek-2.1_files/Image.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   空指针

<img src="JavaStudyWeek-2.1_files/Image%20%5B1%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   注意 **`空指针异常`**

<img src="JavaStudyWeek-2.1_files/Image%20%5B2%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   小总结

<img src="JavaStudyWeek-2.1_files/Image%20%5B3%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   简单应用案例

-   找最大值

<img src="JavaStudyWeek-2.1_files/Image%20%5B4%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   数组反转 (弹幕里的写法也OK）

<img src="JavaStudyWeek-2.1_files/Image%20%5B5%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   随机交换数组元素

<img src="JavaStudyWeek-2.1_files/Image%20%5B6%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

## 方法（函数）

-   和C没什么不同 多了前面的修饰符 `public static` 是公用静态的意思

<img src="JavaStudyWeek-2.1_files/Image%20%5B7%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   断点 `Debug`

<img src="JavaStudyWeek-2.1_files/Image%20%5B8%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   例子

<img src="JavaStudyWeek-2.1_files/Image%20%5B9%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   void类型方法不用写 `return;`

<img src="JavaStudyWeek-2.1_files/Image%20%5B10%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   常见注意事项

<img src="JavaStudyWeek-2.1_files/Image%20%5B11%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   调用方法

<img src="JavaStudyWeek-2.1_files/Image%20%5B12%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   方法的执行原理 （栈内存）

<img src="JavaStudyWeek-2.1_files/Image%20%5B13%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.1_files/Image%20%5B14%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.1_files/Image%20%5B15%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   小总结

<img src="JavaStudyWeek-2.1_files/Image%20%5B16%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   参数传递机制（值传递）

<img src="JavaStudyWeek-2.1_files/Image%20%5B17%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   基本类型传递就是复制数据过去（传数据）

<img src="JavaStudyWeek-2.1_files/Image%20%5B18%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.1_files/Image%20%5B19%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   引用类型传递传地址可以改变数据（传地址）本质都是传值，Java里面数组名存的是地址

<img src="JavaStudyWeek-2.1_files/Image%20%5B20%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   小总结

<img src="JavaStudyWeek-2.1_files/Image%20%5B21%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   方法重载和 `return;` 关键字，去2.3看

<!-- -->

-   `println` 去掉`ln` 就不换行

-   一些小技巧

<img src="JavaStudyWeek-2.1_files/Image%20%5B22%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   三目运算符 `? :`

<img src="JavaStudyWeek-2.1_files/Image%20%5B23%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   一些必要的边缘检查

<img src="JavaStudyWeek-2.1_files/Image%20%5B24%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   两种空数组对比（一个在堆内存创造了数组空间也就是new了一个空间，一个就只有个地址，没new空间）

<img src="JavaStudyWeek-2.1_files/Image%20%5B25%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.1_files/Image%20%5B26%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   函数传入数组首先判空，再判长度，最后判内容

<img src="JavaStudyWeek-2.1_files/Image%20%5B27%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.1_files/Image%20%5B28%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   直接`arr1.fori` 回车

-   几个简单案例

-   买机票（简单判断语句`if` 和`swtich` 和`case` 的使用）

<img src="JavaStudyWeek-2.1_files/Image%20%5B29%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.1_files/Image%20%5B30%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   随机验证码（ASCLL表和随机数生成函数结合的应用）

<img src="JavaStudyWeek-2.1_files/Image%20%5B31%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.1_files/Image%20%5B32%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   去掉最高最低求平均（1.0\*整形自动转换为浮点）

<img src="JavaStudyWeek-2.1_files/Image%20%5B33%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   加密（没什么特别的 就是整数拆分而已）

<img src="JavaStudyWeek-2.1_files/Image%20%5B34%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   复制数组

<img src="JavaStudyWeek-2.1_files/Image%20%5B35%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   抢红包（抢到赋0）

<img src="JavaStudyWeek-2.1_files/Image%20%5B36%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-2.1_files/Image%20%5B37%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   最慢的筛素数

<img src="JavaStudyWeek-2.1_files/Image%20%5B38%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

-   类似于`goto` 的语法，不推荐，不用`break`
    是因为跳出了内部循环，外部循环会打印是素数

<img src="JavaStudyWeek-2.1_files/Image%20%5B39%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

  

-   九九乘法表（`\t` )

<img src="JavaStudyWeek-2.1_files/Image%20%5B40%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />
