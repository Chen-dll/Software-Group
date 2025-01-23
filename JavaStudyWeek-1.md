<span id="540"></span>

<div>

<div>

配置了 IntelliJ IDEA 和 Java 21.0环境，运行了经典“Hello
World“，复习了一遍

</div>

### 安装 IntelliJ IDEA

<div>

**下载 IntelliJ IDEA**：

</div>

<div>

   - 从 JetBrains 的官方网站下载最新版本的 IntelliJ IDEA 专业版。

</div>

<div>

**安装**：

</div>

<div>

   - 傻瓜式安装，最后激活一手。

</div>

### 安装 Java Development Kit (JDK)

1.  <div>

    **下载 JDK**：

    </div>

<div>

   - 从 Oracle 官网下载长期支持的JDK 版本。

</div>

1.  <div>

    **安装 JDK**：

    </div>

<div>

   - 运行下载的安装包并按照指示完成安装。

</div>

1.  <div>

    **配置环境变量：**新版自动配好了，老版或者说有多个要切换的版本就改`JAVA_HOME`
    路径。

    </div>

<div>

   -
**Windows**：在系统属性的“高级”选项卡中，点击“环境变量”按钮，然后添加或编辑
`JAVA_HOME`  变量，设置其值为 JDK 的安装路径。同时，确保 `PATH` 
变量中包含 `%JAVA_HOME%\bin` 。

</div>

<img src="JavaStudyWeek-1_files/Image.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

### 配置 IntelliJ IDEA 使用 JDK

1.  <div>

    **启动 IntelliJ IDEA**：

    </div>

<div>

   - 打开 IntelliJ IDEA。

</div>

1.  <div>

    **创建或导入项目**：

    </div>

<div>

   - 如果是新项目，选择“Create New
Project”。如果是现有项目，选择“Open”。

</div>

1.  <div>

    **配置 JDK**：

    </div>

- <div>

  在创建新项目时，IDEA 会要求你选择一个 JDK。选择已有的 JDK
  版本或直接下载。

  </div>

<!-- -->

- <div>

  对于现有项目，可以在项目结构中配置 JDK。通过
  `File > Project Structure > Project`  来访问项目设置，然后选择正确的
  Project SDK。

  </div>

<!-- -->

- <div>

  装插件。

  </div>

- <div>

  `project->module->package->class`

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B1%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

- <div>

    

  </div>

### 开始编码

1.  <div>

    **创建一个 Java 类**：

    </div>

<div>

   - 在项目视图中，右键点击 `src`  文件夹，选择 `New > Java Class`
，然后输入类名。

</div>

1.  <div>

    \*\*编写代码\*\*：

    </div>

<div>

   - “Hello, World!” 程序：

</div>

<div>

     \`\`\`java

</div>

<div>

     public class HelloWorld {

</div>

<div>

         public static void main(String\[\] args) {

</div>

<div>

             System.out.println("Hello, World!");

</div>

<div>

         }

</div>

<div>

     }

</div>

<div>

     \`\`\`

</div>

1.  <div>

    **运行程序** ：

    </div>

<div>

   - 右键点击包含 `main`  方法的 `Java`  类，选择
`Run 'HelloWorld.main()'` （这里的 `HelloWorld`  是类名）。

</div>

<img src="JavaStudyWeek-1_files/Image%20%5B2%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

### 提示

- <div>

  psvm、sout快速输入很方便，注释也是ctrl+/，双斜杠//，/*\*       ,*
  /*\*\**

  </div>

  <div>

                                                                       
                        \*/,       \*/

  </div>

- <div>

  快捷键，ctrl+D没用，Alt+↑/↓就可以移动了，Alt+Shift+↑/↓是复制一段代码，Ctrl+F搜索

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B3%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

## 数据类型

- <div>

  跟C++差不多，没什么特别的，速过当复习

  </div>

- <div>

  标识符要求和进制转换，还有数据内存中表示，二进制0b 八进制0 十六进制0x

  </div>

- <div>

  逻辑运算符一样自增自减什么的都一样。

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B4%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-1_files/Image%20%5B5%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-1_files/Image%20%5B6%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-1_files/Image%20%5B7%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-1_files/Image%20%5B8%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

<div>

  

</div>

- <div>

  自动类型转换，小的自动转为大的，表达式里面`byte` ，`char` ，`short`
  自动转为`int`

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B9%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-1_files/Image%20%5B10%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-1_files/Image%20%5B11%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

- <div>

  强制类型转换，可能会数据丢失 按`Alt+Enter`

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B12%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

<div>

  

</div>

## 输出 API:Scanner

- <div>

  Java API 中文文档 `https://cunzaima.cn/`

  </div>

- <div>

  步骤如图 第一步自动导了不用管

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B13%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

- <div>

  使用如图

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B14%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

<div>

  

</div>

- <div>

  不完全总结

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B15%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

- <div>

    

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B16%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-1_files/Image%20%5B17%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-1_files/Image%20%5B18%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

## 流程控制

- <div>

  典，速过

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B19%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-1_files/Image%20%5B20%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-1_files/Image%20%5B21%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

- <div>

  `switch` 注意事项

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B22%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

- <div>

  记得写`break`

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B23%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

- <div>

  穿透性用法简化代码，用`if` 也不错

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B24%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

- <div>

  `for` 循环 （知道循环次数）

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B25%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

- <div>

  `while` 循环（条件）

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B26%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

- <div>

  `do-while` 循环（先do一次再判断条件）

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B27%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

- <div>

  三种区别

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B28%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

- <div>

  死循环

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B29%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

- <div>

  关键字 `break` 和 `continue`

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B30%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-1_files/Image%20%5B31%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

- <div>

  `Random()` , 生成1~10，0~9 + 1，生成3~17，0~14 + 3

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B32%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-1_files/Image%20%5B33%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

- <div>

  `Ctrl+Alt+t` 可以快速选择语句

  </div>

## 数组

- <div>

  声明语法

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B34%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-1_files/Image%20%5B35%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-1_files/Image%20%5B36%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

- <div>

  可以像C一样写 但up推荐不要

  </div>

- <div>

  但动态的不能照搬C语言 `int a[100]` , 要写`int[] a = new int[3]`

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B37%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

- <div>

  遍历数组 直接数组名.fori + 数组名.sout 秒了

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B38%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

- <div>

  默认初始值

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B39%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-1_files/Image%20%5B40%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

- <div>

  数组声明总结

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B41%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

- <div>

  数组内存执行原理

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B42%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-1_files/Image%20%5B43%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

- <div>

  只需要注意 System.out.println(arr) 存的不是首位44 而是数组对象的地址

  </div>

<img src="JavaStudyWeek-1_files/Image%20%5B44%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" /><img src="JavaStudyWeek-1_files/Image%20%5B45%5D.png"
style="--en-uploadstate:uploaded;" type="image/png"
data-filename="Image.png" />

<div>

  

</div>

</div>

 
