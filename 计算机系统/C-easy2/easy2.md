# C-EASY-2

## step1
***指针***
1 可以通过“__变量类型 * 变量名__”来创建一个指针，如：
    `int *p;`
2 先看前半：x初始值为10，最后输出x的值为20。这是因为我们先创建了一个指针变量p，并用` &`（__取地址__）指向x的地址，随后p通过 `*`（__解引用__）将20赋值给位于p所指向地址的变量也就是x，x的值便变成了20。

后半：定义了一个数组arr[]，然后定义一个指针q，用*（__解引用__）取得了数组首个元素的地址（整个数组不需取地址，故无需&）里的值，即3。随后对y进行计算："++*arr"表示对数组arr取其首元素的地址所对应的值3，随后进行自增，其结果为4；右边 " *++q"，表示先将指针所指向的元素向后移一位，即此时指向arr[1]，第二位元素，并取出他地址里所存放的值，也就是6，最后将两者相加4+6即为10，得到y的值。


3 野指针即为没有指向对象的指针。其可能指向一些不能进行操作的地址，一旦在程序中被使用，有可能会导致程序崩溃。在平时编写程序的过程中应记得为指针初始化。

4 定义swap时应使用指针，修改如下:
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

***结构体***
1 如下：
```
typedef struct Perinfo{
        char name[10];
        char gender;
        int age;
        double height;
    }PI; //重命名为PI
```
这里通过 `typeof` 为我们的结构体新建了一个名字"PI"

2 指针结构体表示一个**指针变量**指向结构体。以上述代码为例：
```
typedef struct Perinfo{
        char name[10];
        char gender;
        int age;
        double height;
    }PI;

//定义一个打印信息的函数
void TypeInfo(PI *stu){
    printf("姓名:%s 性别:%c 年龄:%d 身高(cm):%.2f",stu->name,stu->gender,stu->age,stu->height);
}
    
int main(){
    PI stu={"Mashiro",'W',18,148};
    PI *p = &stu; //创建一个指针，使其指向一个结构体(stu)
    TypeInfo(p);
    return 0;
}
```
注意：访问指针结构体中的信息应使用 `-> `
像这样，我们便利用指针结构体打印出了真白同学的信息

3  结构体的内存对齐规则指 结构体中各成员的起始值必须为自身编译器对齐值的整数倍，若起始值不为对齐值的整数倍，则会自动填充至整数倍；且结构体总大小必须为最大成员大小的整数倍。

运行以下程序
```
struct P1{
    char name[10];
    char gender;
    int age;
    double height;
};

struct P2{
    char name[10];
    char gender;
    double height;
    int age;
};

printf("%ld %ld",sizeof(struct P1),sizeof(struct P2));
```
运行后可以发现终端输出了 **24**与**32**
我们可以了解到各类型对齐值分别为：
>char 1
>int 4
>double 8

其中最大的为`double` 占了8个字节，故最终结构体总长度应为8的倍数

先看P1：从0开始，name+10，gender+1,此时为偏移值为11；
11不为4的倍数，所以需要补齐至12再增加；加上age的4个字节变为16，16为8的倍数，故无需补齐，直接加上height的8个字节即可，最终大小为24个字节，恰好为8的倍数。

再看P2：前半同P1，偏移值为11；11不为8的倍数，需补齐至16再增加，加上height8个字节得到24，24为4的倍数，故可以直接加上age的4个字节，得到28.但28不为8的倍数，故还需补齐至32，所以最终大小为32，比P1多。

<u>总结：合理安排结构体中成员的定义顺序可以节省一定的空间</u>

***

## ste2
***什么是链表***
1 数组的长度一般是比较固定的，增删改查比较难，而链表的长度可以是动态的，进行增删改查等操作也更为容易。

2 单向链表节点既存数据也存下个节点的地址，且只能从头到尾走。每个节点均由两部分组成：数据域与指针域，分别完成上述两项任务。现在创建一个链表：

```
#include <stdio.h>
#include <stdlib.h> //为了调用malloc函数而导入的库

typedef struct Node{        //定义结构体
    int data; //数据域，存放数据
    struct Node *next; //指针域，存放下个节点的地址

}Node;

int main(){
    int a = 1;
    Node *p = malloc(sizeof(Node));//申请一个节点
    p->data = a; //存入变量a的值
    p->next = NULL; //设置为"空指针"，代表链表已结束
    
    return 0;
}
```

***各种链操作***
代码位于==LinkList.c==文件中