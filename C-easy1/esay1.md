# C-EASY-1 
## part1_C
1.——GCC是编译器。用于将源代码转换成计算机读得懂的文件；MinGW是一个让windows用户也能编程的软件

2.——c_cpp_properties.json可以检测用户所编写的代码是否出错；tasks.json起到编译作用，生成exe文件；launch.json可以一行一行执行代码，观察其是否出错

3.因为vs code只是一个文本编辑器，需要安装c语言插件才能在上面运行相关程序,插件的作用就是让其能读懂c语言的程序

![1](..\glimmer_program\picture\1.png)

![2](..\glimmer_program\picture\2.png)

 将"externalConsole"的 false 改为 true

![3](..\glimmer_program\picture\3.png)

---
## part2_C
1.变量类型表示变量是什么种类的数据 如整数、浮点数、字符字符串。它规定了变量的各种性质（占用大小、存放数据的类型等）。存放年龄应该用整数。不能用char，char只能用于存放单个字符。应使用一个数组来储存'apple' 
`char apple[] = "apple";`

2.从0开始。容易读取到其他变量的值甚至直接崩溃。因为很容易忽略数组的大小所以常见，问题出现的很隐蔽所以危险。

3.for循环：先为变量设置一个初始值，随后规定范围，每执行一次for循环里的操作就自增；while循环：若满足一定的条件就一直执行，只有不满足条件时才结束循环。
for的初始化为循环计数提供了一个初始值；条件判断确定了循环的范围，迭代用于计次，记录循环的进行。while 和 do whlie 区别：while第一次就开始判断是否满足表达式才进行循环；而do while 是先做一次再判断

```
#include <stdio.h>

int main(void)
{
    int sum = 0,i = 1;
    while (i<=10){
        sum += i;
        i++;
    }
    printf("%d",sum);
    return 0;
}
```
```
#include <stdio.h>

int main(void)
{
    int sum = 0,i = 1;
    do{
        sum += i;
        i++;
    }while (i<=10);
    printf("%d",sum);
    return 0;
}
```
两者输出均为55

4.逻辑表达式判断条件真假，而算术表达式是对变量或者常数进行运算；因此逻辑表达式的运算结果是true或者false，而算术表达式的运算结果是数。&&是和；||是或；!是不。

(框架已省略)
`printf("%d",2>5 || 2!=3);`
输出1

`printf("%d",2*10>5 && 3+2==3);`
输出0

最终程序：
```
#include <stdio.h>

int main()
 {
    char name[10],sig = 'Y';
    int age,count = 0;
    do{
        printf("请分别输入名字与年龄：");
        scanf("%s %d",name,&age);
        count ++; //计次
        printf("你叫%s,今年%d岁了,还要继续打印吗?(Y/N)",name,age); //询问用户是否继续，并用变量sig记录回答
        scanf("%s",&sig);
    }while (sig == 'Y'); //输入"Y"则循环执行


    if(sig == 'N'){
        printf("本次程序共操作%d次!",count); //输入"N"结束
    }
    else{
        printf("你的输入有误！"); //防止用户乱搞
    }

    return 0;
}
```
---

## part3_C

1.精简后的代码：
```
#include <stdio.h>

//定义乘方
int f(int a){
    return a*a;
}

//定义平均数
int p(int a,int b,int c){
    return (a+b+c)/3;
}

//定义分数计算
int score(int a,int b,int c){
    int ave = p(a,b,c); //计算平均数
    int fc = f(a-ave)+f(b-ave)+f(c-ave); //计算方差
    return 3 * ave - fc / 3;
}

//定义排序打印
void type(int zh1,int zh2,int zh3){
    if (zh1 >= zh2 && zh2 >= zh3) {
      printf("小明 > 小强 > 小林");
  } else if (zh1 >= zh3 && zh3 >= zh2) {
      printf("小明 > 小林 > 小强");
  } else if (zh2 >= zh1 && zh1 >= zh3) {
      printf("小强 > 小明 > 小林");
  } else if (zh2 >= zh3 && zh3 >= zh1) {
      printf("小强 > 小林 > 小明");
  } else if (zh3 >= zh1 && zh1 >= zh2) {
      printf("小林 > 小明 > 小强");
  } else { // zh3 >= zh2 && zh2 >= zh1
      printf("小林 > 小强 > 小明");
  }
  
}
int main(){

    int x1, x2, x3;
    int y1, y2, y3;
    int z1, z2, z3;

    printf("请输入小明的三项成绩（顺序为A B C,以一个空格为间隔）：");
    scanf("%d %d %d", &x1, &x2, &x3);
    printf("请输入小强的三项成绩（顺序为A B C,以一个空格为间隔）：");
    scanf("%d %d %d", &y1, &y2, &y3);
    printf("请输入小林的三项成绩（顺序为A B C,以一个空格为间隔）：");
    scanf("%d %d %d", &z1, &z2, &z3);

    int zh1 = score(x1,x2,x3);
    int zh2 = score(y1,y2,y3);
    int zh3 = score(z1,z2,z3);

    type(zh1,zh2,zh3);

    return 0;
}
```

2.~~（最初想法）预测：swap函数可以交换输入两数a、b的值。~~
~~原因：先将a的值放进一个”空の箱“，在将b赋值给a，最后再将箱子里的值给b~~

（查阅资料后）——> 无事发生
实参的值给到形参后执行了swap的操作，完成了交换，但是对main函数中的a，b未造成影响.
若要修改，则应将main里的a，b的地址传入swap函数中，再进行系列操作

修改如下：
```
#include <stdio.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(){
  int a = 10;
  int b = 20;
  swap(&a, &b);
  printf("%d %d",a,b);
}
```
代码漂亮地完成了交换的操作！