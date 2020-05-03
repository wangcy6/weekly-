/*
 *常量总结：
 *在实际的编程项目中，我们往往是不会使用某个数值，比如说1, 10, 1024, 
 *我们会给这些具体数值附上具体的含义，这种没有具体含义的数值被称作
 *幻数。也是说，当别人来查看你的代码的时候，或者一段时间后，你自己来
 *查看自己的代码的时候，你有时候必须通过查看代码上下文才能明白这个数值
 *的作用，这会给编程带来不必要的困扰，所以在实际中，我们往往会使用具名
 *常量来表示我们所需要的数值，在C语言中使用的是宏定义来实现的。比如我们
 *需要简历一个长度为10的数组，经常会采用下面这种做法:
 */
#define ARRAYLENGTH 10
int array[ARRAYLENGTH];
/*
 *这样在别人查看你代码的时候能清晰的明白这个是数组的长度，而不会被10这个
 *数值所困扰，而且往往宏定义我们是放在头文件里面的，在以后我们需要修改
 *数组长度的时候，我们只需要修改头文件里面的一处即可，而不会去在整个项目
 *中查找数值为10的数组，而去依次修改；后面这种做法你不能保证的是你所遇到
 *的数值10都是同一个含义，也有可能会忘记修改某个数值，这些都会给项目带来
 *麻烦，所以应该努力避免使用幻数，而使用具名常量来表示一个具体数值。
 *
 *接下要总结的是具名常量的表示方式，以及其在c语言和c++中的不同。
 *
 *在c语言中，具名常量是往往通过宏定义来实现的。也就是我们的上个例子。
 *在时间编译过程中，预处理器会把我们定义的宏依次替换到相应位置，所以
 *这个值又叫做编译期间常量。编译期间常量与运行时常量的差别在于，后者
 *需要在程序运行时通过取地址操作才能查看里面的具体数值，而编译期间常量
 *是在编译时确定了的，可以直接查看这个数值，不用去读取具体地址上的内容，
 *效率也更快。（这里说得不是很专业，因为笔者现在对预处理汇编了解不够
 *深，所以大致是认为编译期间由预处理器直接写入的，而无须取地址操作，可
 *能有错误）;
 *
 *c语言中的const的关键字与c++的关键字是有差别的，差别就在于c++中的const会
 *根据具体情况来决定是否分配内存空间。
 *c++中，一般说来，如果const仅仅用来把一个名字用一个值进行代替的话（就如
 *如同使用#define一样），那么该存储空间就不必要创建。要是存储空间没有创
 *建的话（这依赖于数据类型的复杂性以及编译器的性能）。在进行完数据类型检
 *查之后，为了代码更加有效，值也许会折叠到代码中，这和以前使用#define不同。
 *不过如果要一个const的地址，甚至不知不觉把他传递给一个带引用参数的函数或
 *者把他定义成extern, 则会为该const创建空间.
 *c++中的const默认为内部连接, 要使其能够被其他文件访问必须在初始化的时候
 *使用 extern进行定义；
 *而c中的const为外部连接，这是需要注意的地方。
 *
 *然后要讨论的是c++编译期间类里的常量。
 *要使用一个类有编译期间的常量成员，则需要使用static，在这种情形下，static
 *关键字意味着"不管类的对象被创建多少次，都只有一个实例".类中的一个常量成员，
 *在该类的所有对象中它都一样。一个内建类型的static const可以看做一个编译期间
 *常量.还有一个需要注意的地方，必须在static const 定义的对他进行初始化。
 *还有一种创建一个编译期间类里常量的方法就是使用枚举，2个例子如下
 *
 */
class compilerConst {
	static const int size = 100;
	int array[size];
};

class compilerConstByEnum {
	enum {
		size = 100
	};
	int array[size];
};

/*
 *
 *C++还需要注意的是const对象和const成员函数，
 *const成员函数能够被一个const对象所调用，这样才嫩保证const对象不会被自己的
 *成员函数所修改，任何一个不会修改成员变量的函数都应该定位为一个const成员函数；
 *定义方式如下
 *
 */
class ConstMemberFucn {
	int i;
	public:
	int get() const;
};
/*
 *需要注意的是，为了强调这是个const成员函数需要在定义的时候也进行声明，所以这个
 *const成员函数定义如下:
 */
int
ConstMemberFucn::get() const
{
	return i;
}
/*如果确实需要在某个const对象中修改某个数据成员，可以将这个数据成员声明为mutable.*/

class MultableClass {
	mutable int i;
	public:
	void set() const;
};
void
MultableClass::set() const {
	i++;
}

/*
 *另外与const相对应的一个关键字是volatile.
 *语法是一样的, 但是意思"在编译器认识的范围内，这个数据可以被改变".就是告诉编译不要
 *擅自做出有关该数据的任何架定，优化期间尤其如此。一般很少使用这个关键字，具体的代码
 *例子可参考　<<c++编程思想>>第八章8.5节。接下来就是编程思想相应的习题了，仅供参考，
 *如与问题可与笔者联系，或参考原书给出的代码.
 */

//c0801
const int i = 100;
const int j = 100;
const int k = 100;:
// g++ -x c -S c0801.cpp -o c0801_c.s
//  4:5: error: variably modified ‘array’ at file scope
// int array[i + j + k];
int array[i + j + k];