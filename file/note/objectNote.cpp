1.在c/c++中，为了避免同一个文件被include多次，有两种方式：一种是#ifndef方式，一种是#pragma once方式(在头文件的最开始加入)。 #pragma once方式产
生于#ifndef之后。#ifndef方式受c/c++语言标准的支持，不受编译器的任何限制；而#pragma once方式有些编译器不支持(较老编译器不支持，如gcc 3.4版本之前
  不支持#pragmaonce)，兼容性不够好。#ifndef可以针对一个文件中的部分代码，而#pragma once只能针对整个文件。

2.如果变量都是正数，那就用unsigned int，如果有正数或负数,那就用int

4.::可为全局作用域符号：当全局变量在局部函数中与其中某个变量重名，那么就可以用::来区分如：
例：
char    zhou;    //全局变量   如果全局变量在包含的文件中，也可以这么用
void    sleep（）
｛
      char    zhou;    //局部变量
     ::char(全局变量) =::char(全局变量) / char(局部变量);
｝

5.hpp，在boost、xerces等开源库中频繁出现，hpp，其实质就是将.cpp的实现代码混入.h头文件当中，定义与实现都包含在同一文件，则该类的调用者只需要include
该hpp文件即可，无需再将cpp加入到project中进行编译。而实现代码将直接编译到调用者的obj文件中，不再生成单独的obj，采用hpp将大幅度减少调用project中的
cpp文件数与编译次数，也不用再发布烦人的lib与dll，因此非常适合用来编写公用的开源库。因为头文件包含，所以hpp的代码会复制到调用都的cpp文件中，
编译时会一起编译
即相当于是包含文件中的函数

6.#define后面的\是续行符，表示下面一行是紧接着当前行的，一般用于将十分长的代码语句分几段写（注意\后面除了换行回车不能有任何字符，空格也不行：
  带参宏定义的一般形式为： 　#define 宏名(形参表) 字符串
　　宏名后的第一个括号就是参数，实际实用时，参数传入字符串中即可

9.typedef为c语言的关键字，作用是为一种数据类型定义一个新名字。这里的数据类型包括内部数据类型（int,char等）和自定义的数据类型（struct等）,
用typedef只是对已经存在的类型增加一个类型名，而没有创造一个新的类型。只是增加了一个新名字，可以用该名字定义变量，   ;号结尾
例：
1.typedef int status;  数据类型是int,新名字是status
2.typedef int num[100];//可看成 typedef int[100] num, int[100]是数据类型， num是新名字
  num n;
3.typedef struct  
{
    int month;
    int day;
    int year;  
} time;     time前的是数据类型，time是新名字
4.所以函数指针类型也是可以理解了

11.#pragma  pack (push,1)     作用：是指把原来对齐方式设置压栈，并设新的对齐方式设置为一个字节对齐
相当于：
#pragma pack(push) //保存对齐状态
#pragma pack(4)//设定为4字节对齐
在代码结尾还有一个#pragma pack(pop) 表示恢复压入栈中的对齐状态

14.为了在多线程使用全局变量或者静态变量时,线程间互不影响。  tls线程本地存储。tls的作用是能将数据和执行的特定的线程联系起来。 

18.多线程内存池
　　直白的翻译：支持多线程安全操作的内存池。能够通过加锁的方式来获得安全；否则只会做的更糟（会比系统的慢....可能）。

19.tls（线程本地存储），如果代码支持多线程；那么，内存释放的时候，其绝对不会在原来分配时的线程.
所以，我们需要一个合理且有效的模型：线程间内存池交换内存的模型——使用一个全局的共享内存池，然后各个线程内部的内存池，
向其发起分配和释放的请求。这样，我们也就不在担心上面的问题了；我们可以通过这个全局池，来完成跨线程间的内存操作。当然，
全局池需要加锁，这点毋庸置疑。为了减少加锁的消耗，我们可以缩短线程内部池的访问频率，比如：内部池的分配/释放频率与全局池的访问频率，比
例在：10000:1，或更高。这样，通过均摊，最后加锁的消耗，几乎完全没有了（即使消耗1ms，现在均摊后也只有0.1us）。
需要内存池的目地是提高性能，        影响内存池性能：控制住线程内部池向全局池的访问频率。

20.size_t:它是一种“整型”类型，里面保存的是一个整数，就像int, long那样。用来记录一个大小(size)。size_t的全称应该是size type，
就是说“一种来记录大小的数据类型”。用sizeof(xxx)操作的结果就是size_t类型。可以做加减乘除，也可以转化为int并赋值给int类型的变量。
在32位架构中被普遍定义为：
typedef   unsigned int size_t;
而在64位架构中被定义为：
typedef  unsigned long size_t;   所以，不能size(int) -1;-1会转成unsigned类型
则尽量避免有符号数与无符号数的比较运算和避免减法运算，在很多时候，在unsigned的世界里，x-y>0与x>y都是不等价的。

如果遇到无符号数与有符号数之间的操作，编译器会自动转化为无符号数来进行处理
浮点数（float，double）实际上都是有符号数，unsigned 和signed前缀不能加在float和double之上，不存在有符号数根无符号数之间转化的问题了。

22.一个最小的包是  : unsigned short packagelen;  包的总长
          short protocolid;           消息类型 x2
          int   netid;                process_id 命名空间中的，service_config
          int   playerid;             玩家id
93.netid是表示是哪个服发的，是群发或http等;可看成是大范围的protocolid，

25.a("one"):这样的对象是临时对象，不能取地址，不能被引用，不过可以给同类型的其他对象赋值，该临时对象定以后可以进行一次操作，然后立即销毁。
当我们定义一个对象以后并不想立即给它赋初值，而是以后给它赋初值，在稍后赋初值的时候，该类临时对象就可以发挥作用了。
例：有一个类a;
a a;
a = a("one");

26.shared_ptr
在定义的时候可以指定删除器（deleter）。无法直接传入析构函数。方法:在单例函数内部再定义一个destory函数，该函数也要为static的，即通过类名可直接调用。

27.
weak_ptr被设计为与shared_ptr共同工作，可以从一个shared_ptr或者另一个weak_ptr对象构造，获得资源的观测权。但weak_ptr没有共享资源，它的构造/析构不
会引起指针引用计数的增加/减少。它只是一个观察者。使用weak_ptr的成员函数use_count()可以观测资源的引用计数，另一个成员函数expired()的功能等价于use_count() == 0，
也就是shared_ptr管理的资源已经不复存在了。weak_ptr没有重载operator和->，它不共享指针，不能操作资源，这是它弱的原因。在需要的时候就调用lock()从被观测
的shared_ptr获得一个可用的shared_ptr对象供外界使用，从而操作资源。当expired() == true的时候，lock()函数将返回一个存储空指针的shared_ptr。
例：
shared_ptr<int> sp(new int(10));
  cout<<sp.use_count()<<endl;     1
  boost::weak_ptr<int> wp(sp);   观测sp 
  cout<<wp.use_count()<<endl;      1
  boost::shared_ptr<int> sp2 = wp.lock();  使用sp产生新的share_ptr sp2
  sp2 = 100;                        使用
  cout<<wp.use_count()<<endl;   2  引用计数加1

  weak_ptr不控制指针的析构，若引用的share_ptr析构了，weak_ptr就不再能取的shared_ptr指针

当两个对象需要互相引用的时候(各类中都有指针指向对方)，我们总希望其中一个对象拥有另外一个对象的强引用，而另外一个对象拥有自己的弱引用
可以使用lock获得一个可用的shared_ptr对象。weak_ptr的一个重要用途是通过lock获得this指针的shared_ptr,使对象自己能够生产shared_ptr来管理自己，

28.enable_shared_from_this是一个模板类
当类a被share_ptr管理，且在类a的成员函数里需要把当前类对象作为参数传给其他函数时，就需要传递一个指向自身的share_ptr。
1.为何不直接传递this指针
       使用智能指针的初衷就是为了方便资源管理，如果在某些地方使用智能指针，某些地方使用原始指针，很容易破坏智能指针的语义，从而产生各种错误。

2.可以直接传递share_ptr<this>么？
       不能，因为这样会造成2个非共享的share_ptr指向同一个对象，未增加引用计数导致对象被析构两次。

若一个类 t 继承 std::enable_shared_from_this<t> ，则会为该类 t 提供成员函数： shared_from_this 。 当 t 类型对象 t 被一个名为 pt 的 std::shared_ptr<t> 
类对象管理时，调用 t::shared_from_this 成员函数，将会返回一个新的 std::shared_ptr<t> 对象，它与 pt 共享 t 的所有权。

为何会出现这种使用场合
       因为在异步调用中，存在一个保活机制，异步函数执行的时间点我们是无法确定的，然而异步函数可能会使用到异步调用之前就存在的变量。为了保证该变量在异步
函数执期间一直有效，我们可以传递一个指向自身的share_ptr给异步函数，这样在异步函数执行期间share_ptr所管理的对象就不会析构，所使用的变量也会一直有效了（保活）。
内部其实是weak_ptr管理，shared_from_this就是用weak_ptr构造一个share_ptr最终目地都是为避免重析构。



30.使用extern和包含头文件来引用函数区别
extern的引用方式比包含头文件要简洁得多！想引用哪个函数就用extern声明哪个函数。一个明显的好处是，会加速程序的编译
（确切的说是预处理）的过程间。在大型c程序编译过程中，这种差异是非常明显的。 在连接时，会在编译后的文件找extern函数
的实现。函数就不用加了,函数声明和函数定义很好区分,链接在本编译单元找不到该符号的定义的话,会在其它编译单
元中寻找.类成员函数也是，头文件的实现函数不一样要写在同名的源文件中。
对于全局变量就不一样了
  extern int a;
加extern 是声明,不加extern 就是定义了. 如果不加的话,编译器无法区分这到底是声明还是定义呀, 所以加个extern方便区分.

31.lexical_cast 位于boost命名空间，为了使用 lexical_cast，需要包含头文件 <boost/lexical_cast.hpp>
1.lexical_cast在转换字符串时，字符串中只能包含数字和小数点，不能出现除e/e以外的英文字符或者其他非数字字符。
可将字符串转成int,long等：例: int a = lexical_cast<int>("123");      string 到 int
2.可将数字将成string 例： string str = lexical_cast<string>(123)     int 到  string

35.申请空间后要用memset初始化，包括结构体

36.memcopy与memmove区别：当内存发生局部重叠的时候，memmove保证拷贝的结果是正确的，memcpy不保证拷贝的结果的正确

42.用malloc原因:失败返回null,提前知道内存有没有足够空间,将碎片空间进行整理成一个大块

45.pair是将2个数据组合成一个数据，如stl中的map就是将key和value放在一起来保存。当一个函数需要返回2个数据的时候，可以选择pair。 pair的实现是一个结构体，
主要的两个成员变量是first second 因为是使用struct不是class，所以可以直接使用pair的成员变量。
存的数据可以是同一类型或者不同类型。

49.其实在mongodb里面，find()和findone()的用法是一样的，举个例子：findone({name:”mongo”})
和find({name:”mongo”}).limit(1)其实是等效的。它们的参数也是一样的，只不过find()和findone()返回的不同而已。
第一个区别就是，findone()会返回符合条件的第一个文档对象，而find()会返回所有符合条件的对象数组。
第二个区别是，findone()返回的是一个对象，而find()返回的是一个数组，数组里面装着对象。
findone()返回的值前端只需要用data.name就能获取到，但find()返回的值前端要用data[i].name来获取。

64.1.struct中全是publie，且没有构造函数，则可用｛｝进行构造，例：struct a = {}
  2.若struct中有private或protected，或有构造函数，则需使用构造函数进行初始化
例：
struct s {
    private:
        int x;
    public:
        double y;
        s(void){}
        s(int idemo,double ddemo) {x=idemo;y=ddemo;}
};
s os1;//将调用默认构造函数(无参构造函数)
s os2(1000,2.345);
s os3=s(2000,4.567);等价于：s os3(2000,4.567)  因是声明并初始化os3对象，所以将调用s(int,double)构造函数对os3进行初始化。
s os[4]={s(10,1.234),s(20,2.234)};//未初始化的将调用默认构造函数。如此时没有默认构造函数会出错。

但如果os3已经存在了，s os3(100,1.234);os3=s(2000,4.567)，则表示用一个临时对象赋值给os3，将调用operator=，
然后系统再释放这个临时产生的对象。系统默认的=运算是将源对象的数据成员的值复制到目标对象中的数据成员中。
3.接受一个参数的构造函数允许使用赋值句法初始化对象。
例：class c {
    private:
        int x;
    public:
        c(int idemo) {x=idemo;}
};
c oc=1000;//不能加花括号

76.std::array中的data()，表示返回指向array中第一个元素的指针。
1. 读写锁机制
写者：写者使用写锁，如果当前没有读者，也没有其他写者，写者立即获得写锁；否则写者将等待，直到没有读者和写者。
读者：读者使用读锁，如果当前没有写者，读者立即获得读锁；否则读者等待，直到没有写者。

2. 读写锁特性：
同一时刻只有一个线程可以获得写锁，同一时刻可以有多个线程获得读锁。读写锁处于写锁状态时，所有试图对读写锁加锁的线程，不管是读者试图
加读锁，还是写者试图加写锁，都会被阻塞。
读写锁处于读锁状态时，有写者试图加写锁时，之后的其他线程的读锁请求会被阻塞，以避免写者长时间的不写锁。

78.0x7fffffff 的二进制表示就是除了首位是 0，其余都是1  0111=7
是最大的整型数 int（因为第一位是符号位，0 表示他是正数）

81.静态成员变量不随对象的建立而分配空间的,也不是随对象的撤销而释放.静态成员变量是在程序编译时分配空间,而在程序结束时释放空间.

100.insert(pair<...>) 版本返回值是一个pair结构，其中第一个元素是一个迭代器，第二个元素是一个bool类型，如果原来的map中不含有插入的
元素，则bool为true，迭代器指向插入的元素；如果map中已经含有插入的元素了，则bool为false，返回的迭代器指向对应的map中已经存在的元素

1、 mongo::bsonobj，这个是bson对象的表示
2、mongo::bsonelement，这个是bson对象中元素的表示方法
例： std::vector<mongo::bsonelement> elems = obj["time"].array();  要取出对象obj中的元素，可用bsonelement类型接

bsonarraybuilder和bsonobjbuilder是一个级别的，继承同一个类

  bsonarraybuilder msgs_builder;
    for (size_t i = 0; i < size; ++i) {
    msgs_builder.append(i);  只放一个元素
  }   结果是[0,1,2....]   存入bsonobj的时候要加.arr()

  bsonobjbuilder rec;
      rec.append("address", m->receivers[i]->address);
      rec.append("status", m->receivers[i]->status);  放两个元素
结果：      {"address": xxxx, "status": xxxxx} 组合好后要加.obj()

    obj.appendarray("attack", attack_report.arr());  一个键对应的是arr()，则用appendarray() ,  得:｛ "attack": [。。。。]  ｝

一般来说，bsonobj的创建都是通过bsonobjbuilder来做的，除非你已经得到了其字节流，那可以直接生成bsonobj
即bsonobj生成的对象在=号左边，或即将被字节流赋值，例： mongo::bsonobj key = bson("key" << 3);
 bsonobjbuilder类生成的对象，可以之后使用，最后要用obj（）转成bsonobj类型 mongo::bsonobjbuilder objb;

105.  static filejsonseq loadfilejsonfromdir(const std::string& files_path)
先读取文件夹的所有文件名到一个vector中，再一个个取出，用ifstream去一行一行的读，读出是string类型，再将string类型解析成json
取出的json，不是按文件在文件夹中的位置，会乱序

107. 0x0表示十六进制数0，等于十进制的数0。

109:(net::msg& m, json::value& r)   msg就是gac发送的数据，包括playerid， netid等信息。

110:gate_rcf.cpp
      gate_svr.async_send_game_svr(player_id,
            http_req["net_id"].asint(),
            req_type,
            scontent);
gate在发给gg的数据中，就已将数据从包中解析出来，分成playerid,net_id,protocolid，scontent四部分，gg再将数据整合成struc中，再发给对应的处理函数

114. set是关联容器。其键值就是实值，实值就是键值，不可以有重复，
所以我们不能通过set的迭代器来改变,比较函数不是<号，是（）

115.区域锁(scoped locking)不是一种锁的类型，而是一种锁的使用模式(pattern)。
区域锁实际上是raii模式在锁上面的具体应用。raii(resource acquisition is initialization)叫“资源获取即初始化”，
最早是由c++的发明者 bjarne stroustrup为解决c++中资源分配与销毁问题而提出的。raii的基本含义就是：c++中的资源
（例如内存，文件句柄等等）应该由对象来管理，资源在对象的构造函数中初始化，并在对象的析构函数中被释放。stl中的智能指针就是raii的一个具体应用。
解决：函数内部突然抛出了异常，程序会自动退出，导致锁不会释放。
解决：区域锁就是把锁封装到一个对象里面。锁的初始化放到构造函数，锁的释放放到析构函数。即使运行时抛出异常，析构函数仍然
会自动运行.如果觉得锁的力度太大，可以用中括号来限定锁的作用区域.

119. logs << "battlevip.json size=" << mapbattlevip.size() << logend;  在读取配置到容积中时，一般都打印这句话

120.   vector<int> vi = {10 ,30 ,50, 10};  数字表示下标的权重
      discrete_distribution<int> dist(vi.begin(), vi.end());  将vi中的值转化为离散分布，即概率是｛0.1，0.3，0.5，0.1｝
       mt19937 engin(time(null));   设置种子，生成随机数
      int i = dist(engin);    返回0到3，分别表示数组中的下标


121.
在网络中,使用ip地址（在网络层，一台机器当然也可以由多个网络接口，即网卡，每个结构对应一个ip地址）。
标示一个主机上的特定进程.使用ip:port，即ip地址和端口号，一般地说，每个进行网络通信的应用程序都要占用主机上的一个端口。举个例子，
使用tcp进行通信，需要建立连接，比如主机a上的进程a和主机b上的进程b进行通信，a、b之间的连接如何标示？使用四元组<a的ip，a所占用的端口，
b的ip，b所占用的端口,ip:port就确定了一个socket，在一个tcp连接中，她就像一个插口，注意，叫做插口，套接字也就是类似的意思。你把应用程
序插入到这个插座，就可以和连接的另外一方对话了。


123.用一个qvalue存战报信息，转化成string类型后，压缩到一段内存中上，再将内存中的数据写到某个地址中，

124.io_service，相当于一个线程分配中心，post函数是接收某个任务，调用线程去处理

126.private:  数据成员和函数成员，只能在  类成员和友元 中访问。不能被继承类访问（无论何种继承）.
声明为protect的函数，变量，仅父类和子类内部（即定义父类和子类的代码中）可以调用,无法通过对象进行调用

127.在一个类中，对于函数名相同的const函数和非const函数能够构成重载，被调用的时机：如果定义的对象是常对象，则调用
的是const成员函数，如果定义的对象是非常对象，则调用重载的非const成员函数。

128.const_cast的目的并不是为了让你去修改一个本身被定义为const的值，因为这样做的后果是无法预期的。const_cast的
目的是修改一些指针/引用的权限，如果我们原本无法通过这些指针/引用修改某块内存的值，现在你可以了。
例：
const int a = 12;
const int *ap = &a;
int* tmp = const_cast<int*>(ap);
*tmp = 11;

129.一个字节占8位，16进制一个符号占4位，所以一个字节可以用两个16进制符号表示，比如35h。

129.位移需看机器位数，32位时，0x1<<31时，是在二进位的位上进行移动，结果是1在第32位上，再移一位，则1会到第1位上
0x01这个16进制不能简单的看成8位，左移8位后再多移1位又到1
0x01左移5位得  0010 0000 ， 减1得：0001 1111

131.boost/array的功能相当有限，只能应用在已知数组大小。或者对运行速度要求很高的场合。需要可动态变动容量的数组，使用std::vector或boost::scoped_array.

132.锁递归和非递归区别：同一个线程可以多次获取同一个递归锁，不会产生死锁。而如果一个线程多次获取同一个非递归锁，则会产生死锁。
例：
mutexlock mutex;
void foo()
{
  mutex.lock();
  // do something
  mutex.unlock();
}
void bar()
{
  mutex.lock();
  // do something
  foo();     如果是非递归锁，会永远阻塞在这里，产生死锁。
  mutex.unlock(); 
}
递归锁存在的问题：调用函数和被调用函数以为自己拿到了锁，都在修改同一个对象，这时就很容易出现问题。
读写锁比互斥锁开销大。读写锁的优势在读操作很频繁，而写操作较少的情况下。如果写操作的次数多于读操作，并且写操作的时间都很短，
则程序很大部分的开销都花在了读写锁上，这时反而用互斥锁效率会更高些。

133.成员变量是类对象时，如果该对象只有有参构造器，声明成员对象时可以不传，构造函数中在对该对象传参初始化。c++11，可以声明的同时初始化。

134.取玩家离线时间：playedataptr->offline().offtime()

135.敏感字、词组，一个个取出，mcb类保存map[长度，cb类],cb类map存[字符指针，ss类]，ss类将字或词存在unorder_set容器中。
即，找同一长度的cb管理类，通过字符指针找到词组，查看是否完全匹配，再设为*.   先过滤长度，再通过指针在多个词组中找到一个，再看这一个是否与被查的相同

136.函数指针的调用：    function<void()> tick_add_handler;  tick_add_handler被赋值后，   tick_add_handler();即为调用（无参时）

139.delete 对象时，会调用这个对象的析构函数，如果在this类的析构函数中delete this，当析构函数执行时，就会死循环的调用析构函数.且delete根new配合使用

140.boost::bind(&memberfunction, obj, _1, _2......成员函数绑定，第一个参数可以是value、pointer和reference，
即传值、传地址和传引用都是可以的，下面三种使用bind的形式都是成立的。
绑定后返回的函数与绑定的函数有相同的实体，在调用时，才用到this指针，所以this指向的类，不能析构。
a a;
a& r = a;

boost::bind(&a::func, a);
boost::bind(&a::func, &a);   根据&a::func找到函数体，&a指向调用这个函数的对象，所以bind成员函数需传this
boost::bind(&a::func, r);

传递值或引用,所有的参数都会被拷贝一遍，然后析构一遍,所以首先必须保证参数能够被拷贝而不影响逻辑和数据一致性，
其次，参数能够被析构而不影响逻辑和数据一致性。单例就不行，所以最好传地址。

144.vector托管对象指针时，删第一个元素，会把二赋值到一，三赋值到二，再析构第三个位置，所以vector托管对象时，如果erase，对象会析构，内存不会泄漏。

145.  if(lm_list.insert(m).second) lm_list是unordered_set类型，insert会返回pair<iterator,bool>,这里是判断是否insert成功

146.
mutex:lock()   线程阻塞直到获得互斥量所有权
try_mutex:     try_lock()，尝试取互斥量，没取到马上返回false，非阻塞
timed_mutex:   timed_lock(),在一定的时间内尝试取互斥量

148.
用0x0，表示十六进制，也是占一个字节

149.  singleton    创单例的时候就用这个，在栈空间生成（就一个对象，不会占太大的空间）;

151. 模板的使用
定义模板
template<class address_type = void>
static address_type* create_some_memory(size_t sz)
{
  return (address_type*)::nedalloc::nedmalloc(sz);
}
使用，<类型>（参数）
static char* rbuffer = create_some_memory<char>(1024 * 1024 * 100);

152. 区别
template<class create_type>
static void* create_type_memory()
{
  return ::nedalloc::nedmalloc(sizeof(create_type));       开辟某种数据类型大小的内存空间   creator用到
}


template<class create_type, class ...argls>
static create_type* create_some_type(argls ...argl)
{
  return new(::nedalloc::nedmalloc(sizeof(create_type))) create_type(argl...);   开辟某种数据类型大小的内存空间，并在该空间上构造该类型的对象 
}

153. nedmalloc是一个跨平台的高性能多线程内存分配库，线程请求内存时，首先从线程自己的维护的空闲内存查找，然后再从线程内存池中查找。

154.
#define playerdatainitial(typename, nickname) \
protected:\
  std::string _str_##typename()\
  {\
    const static std::string classname = #typename;\
    return classname;\
  }\
  boost::shared_ptr<typename> _##nickname;\
  boost::shared_ptr<typename> ptr_##nickname(){\
    _##nickname->tofull();\   主要是tofull(会调用toload和tocomplete()，complete又调用classfinal（）)
    return _##nickname;\
  }\
  boost::shared_ptr<typename> ptr_##nickname##_raw(){\
    _##nickname->toload();\   调用classload()
    return _##nickname;\
  }\
public:\
  inline typename& nickname(){return *ptr_##nickname();}\ 所以调用ptr->items()取个性化数据时，会调用ptr_##nickname()函数，会同步db
  ，因此，每次取到的数据都是最新的。
  inline typename& nickname##_raw(){return *ptr_##nickname##_raw();}\   调用ptr->items_raw,则只用调用toload()，根据需求决定怎么调用

155. 随机奖励和选择奖励的容器不同，打开奖励的方法也不同
actionboxlist  可选奖励vector容器                      runbox
actionrandomlist  随机奖励vector容器，有权重            runrandom
奖励中没有封装任何限制，如等级、武将等

标签---------------------------------------------------------
158. enum可以不指定对象名,  匿名枚举的作用等价于宏变量
凡是无名的struct、union、enum，里面的名称都可以直接使用，无需.操作符。

159.
类型不占空间，生成变量才占空间。
当struct内部的union类型没有名字也没有对象的话, union内部的元素会直接成为struct的元素. 
例：
struct s2{
        union{
                int i;
        };
        struct{
                int i;
        };  
｝union和struct中的i都是struct s2的成员，所以是重复定义，一个改成int j；则struct s2 ss;  ss的大小是8.


struct s1{
        union u{
                int i;
        };
        struct ss1{
                int i;
        };
｝只是声明了类型，没有生成变量，所以 struct s1 xxx;  xxx的大小是0;


struct s6{//the same to s1
        union{
                int;
        };
        struct{
                int;
        };
}生成的对象也是0，

161.  
void _auto_player::toload()
void _auto_player::tocomplete()   这两个函数都是在玩家登录后去处理数据，之后不能再调用该函数处理数据

162.tofull()是toload()和tocomplete().

163.playerdata创建对象时，
_info = creator<playerbase>::create(this, pid);
initial();是去创建所有个性化玩法模块(没有下载db)，和下载collection集合的数据，

164.struct armynpc
    {
      armynpc()
      {
        memset(this, 0x0, 
          sizeof(armynpc) 
          - sizeof(passive_ids) 
          - sizeof(npcinfo)
          - sizeof(harted)
        );
        npcinfo = json::objectvalue;
      }

用0或0x0是一样，虽然写0是int类型，但这里只会取0的8位，这8位和0x0的8位是一样的。
初始化结构体时，大小减去stl容积的大小，有json的，给json类型赋初始类型。

createplayerclass(playerclientprocess, clientprocess, datastate);
#define createplayerclass(classtype, varname, statevalue) \
{\
_##varname = creator<classtype>::create(this);\
_##varname->setclassstate(statevalue);\这个函数是auto_player的，所以个性化模块都
要继承auto_player.

只有各玩法模块调用tofull时，才会去classload下载数据，即 inline typename& nickname(){return *ptr_##nickname();}\， 所以是玩家第一次调用nickname()时，
才会去数据库下载数据。

164.能用const的就都用，比如查询配置信息时。

172.当要描述一个物体有多冲描述方法，但又想都保存在一个结构体时，可用union。例：
    struct base
    {
      bool rare;
    };

    struct res : public base
    {
      long long val;
    };

    struct man : public base
    {
      long long manid;
      long long num;
      bool transfer;
    };

    struct item : public base
    {
      long long itemid;
      long long num;
    };

    union declare
    {
      base _base;  //基本属性
      res _res;    //资源
      man _man;    //武将
      item _item;  //道具
    };

    struct box
    {
      box(){
        actionid = null;
        memset(&boxdata, 0, sizeof(boxdata));
        rare_compose.clear();//奖励组成
      }
      int actionid;
      declare boxdata;
      boost::unordered_map<long long, int> rare_compose;
    };

173.创建数据结构，放入容器中，如果数据大，可用creator开辟堆空间，存指针到容积中。如果结构体很小，可生成栈对象，将对象放入容积中.

177.在程序中所有的数据都是以流的方式进行传输或保存的，程序需要数据的时候要使用输入流读取数据，而当程序需要将一些数据保存起来的时候，就要使用输出流完成。
unicode万国码、它为每种语言中的每个字符设定了统一并且唯一的二进制编码，以满足跨语言、跨平台进行文本转换、处理的要求。
字符流处理的单元为2个字节的unicode字符，分别操作字符、字符数组或字符串，而字节流处理单元为1个字节，操作字节和字节数组。
所有文件的储存是都是字节（byte）的储存，在磁盘上保留的并不是文件的字符而是先把字符编码成字节，再储存这些字节到磁盘。在读取文件（特别是文本文件）时，
也是一个字节一个字节地读取以形成字节序列 字节流可用于任何类型的对象，包括二进制对象，而字符流只能处理字符或者字符串；
在所有的硬盘上保存文件或进行传输的时候都是以字节的方法进行的，包括图片也是按字节完成，而字符是只有在内存中才会形成的，所以使用字节的操作是最多的。

183.枚举中某个枚举变量的值默认为前一个变量的值+1，而如果第一个不赋值，默认值为0

186.从无到有叫初始化，初始化（调用拷贝构造函数）创建了新对象；赋值（调用赋值操作符）没有创建新对象，而是对已有的对象赋值。

187.数组名不可以被赋值，做函数实参时，实际上是复制了一份首地址的数值

构造函数的函数体内只能做赋值而不是初始化。
引用是：声明关系，一经声明，不可变更。
例：int a,b;
int &ra = a;
// int &ra = b; //错误，不可更改原有的引用关系
所以成员变量是引用或const类型时，必须在初始化列表进行初始化

性能原因：
// 不使用初始化列表
class myclass
{
  type variable;
public:
  myclass(type a) //假设type是一个定义了拷贝构造与赋值操作符的类
  {
    variable = a;
  }
};
int main()
{
  type type;
  myclass mc(type);
  return 0;
}
1. 调用type的拷贝构造函数来创建’a’.
2. 调用type的构造函数来创建成员对象variable.
3. 调用type的赋值操作符，修改成员对象variable。
        variable = a; 
4. 调用type的析构函数，因为a的生命周期结束了.

// 使用初始化列表
class myclass {
    type variable;
public:
    myclass(type a):variable(a) {   // 假设type是一个定义了拷贝构造与赋值操作符的类
    }
};
1. 调用type的拷贝构造函数来初始化‘a’ .
2. 调用type的拷贝构造函数，在初始化列表中的使用参数’a’来对成员对象”variable”进行初始化.   variable(a)
3. 调用type的析构函数，因为a的声明周期结束了.

少了一个调用赋值运算符的过程。
结构体也可用初始化列表。
声明时赋值:其实是在调用构造函数的时候生效的，本质是编译器将赋值语句内联到类型的每一个实例构造器的代码前面(即在执行构造函数的函数体前)。

187.在c语言中，memset一个结构体是个明智的做法，但是在c++中不是。一个c++类中除了需要空间来存放数据成员之外，还可能保存着虚函数表指针s，偏移量等信息，
一但你memset之后全都没有了。所以这是错误的行为。而且memset完全可以用构造函数的初始化列表来代替。

string不能使用memset或者memcpy这些低级函数。
你new完后string的构造函数已经调用完毕，你再memset就破坏了他的内部数据不变式。
因为memset这种低级函数绕过了封装，可能会触发意想不到的行为。可用构造函数来实现！！！
用memset之前要考虑有没有c++的东西。

189.struct approvet 
{
  approvet() 
  : type(approvetype::unset), exval(0), is_auto(false) {}
  ~approvet() = default;

  unsigned type;    //申请类型
  unsigned exval;   //限制值
  bool is_auto;     //是否自动批准
};

    struct legionbriefinfo {
      legionbriefinfo(const legionptr legionp) 
      : approve(legionp->_approve),
      ~legionbriefinfo() = default;

      approvet approve;
    };

    结构体是一种类型。在初始化列表中approve(legionp->_approve)，不能理解为调用approvet的有参构造器，况且也没有实现有参构造器，
    理解为定义时初始化：approvet approve = legionp->_approve;

193.   如果有多个if判断然后return 的需求，用下列的写法，统一了出口和入口，如果以后要求在函数结束前加某些操作也方便
do {
    if (player->legion().isjoinlegion()) {
      break;
    }
    if (player->legion().iscool()) {
      break;
    }
    if (!legionp) {
      break;
    }
    }
  } while (0);
  return ret;

197.switch case要加花括号的原因：swithc 是一个块，不是case是一个块。
在一段代码中的case 1 后面还有一个case2的话，且case 2中使用了case 1定义的变量的话，那么如果运行时，n = 2，swich 直接条转到case 2 内部，这样就出现
了 i 还没有初始化的事情了，（变量的声明是在编译阶段，而变量的赋值则在运行时），如果能运行的话，则在case 2中，i是一个未知的值，所以编译期因直接避免
这种事情发生，就让其编译无法通过。   所以，有局部变量要加｛｝

199.
deque的一块块的连续空间组合而成的，所以你不用担心它会像vector那样空间不足时重新开辟一块比原有空间更大的内存，然后全部复制过去，再释放掉旧的内存。
deque只需增加一小块内存就可以。

200.deque不是满了自己删除，将它的大小限定在一定范围内，需要手动维护。

202.map可以下标插入和下标访问，下标访问不存在的键值返回0

enummap[1] = "one";
enummap[2] = "two";
插入2时,先在enummap中查找主键为2的项，没发现，然后将一个新的对象插入enummap，键是2，值是一个空字符串，插入完成后，将字符串赋为"two";
 该方法会将每个值都赋为缺省值，然后再赋为显示的值，如果元素是类对象，则开销比较大

map用下标访问注意：if k does not match the key of any element in the container, the function inserts a new element with that key and 
 returns a reference to its mapped value. 

206.action_mgr.invisiblesettingonce(action::exp); 设置获得的道具在actiomn_mgr.result（）的json中写入记录或不写入设置

209.一开始vector为空时，不能对其进行下标赋值。而要用push_back().

 212.memset(_manidlist, -1, playerformatnum * sizeof(int));  -1的一个字节是1111 1111，则一个int是-1, 只能0，或-1


216 .  执行gac请求的线程和执行定时器的线程是不一样的。
例:当系统时间到5点时，要执行5点事件前，会trylock，已加锁，所以在执行事件时可以不加锁
player->trylock();
player->tick().tick5event();
但在执行系统的5点事件时，要加锁，比如清空通天的排名.

217.
boost::exception_detail::clone_impl<boost::exception_detail::error_info_injector<boost::bad_weak_ptr> >
出现boost::bad_weak_ptr最可能的原因是enable_shared_from_this<>类构造函数中调用shared_from_this(), 
因为构造尚未完成，实例还没有被shared_ptr管理，自然没有weak_ptr.
还有可能就是enable_shared_from_this<>类没有创建成shared_ptr, 例如错误用成了scoped_ptr.
所以，构造器的情况，是不是在对象没创建完成，就访问了对象的数据
构造函数不能直接或间接调用getowndataptr（）,

  _sgt = new playermanager();
      _sgt->initdata();可以先创建对象后，对象再调函数进行二段式初始化

218.pthread_cond_timedwait是线程sleep时的状态

219:
线程中使用，主线程中无效
boost::this_thread::sleep(boost::posix_time::seconds(2));    // 这种更好用
boost::this_thread::sleep(boost::get_system_time() + boost::posix_time::seconds(2));
主线程中使用：
boost::thread::sleep(boost::get_system_time() + boost::posix_time::seconds(5));

220.头文件的作用，隐藏实现，对外提供接口(h和cpp写在一起，外部将不能通过包含头文件的方式使用函数)。   且其它文件在调用时，编译时只需函数声明，
连接时会去自动找到实现代码。只在头文件中做声明，如果有定义，会出现：如果多次包含头文件，会出现重复定义的错误.

225.地图配置中，mapname是代表这场战役的名字，或是守关武将的名字，不能写在army字段中。mapdata的类中会用到该字段。

226.linux pathname find -name 文件名，  -name是关键字，要加, pathname是要找的路径,不加就从当前路径开启找

227.为什么需要std::ref和std::cref
bind()是一个函数模板，它的原理是根据已有的模板，生成一个函数，但是由于bind()不知道生成的函数执行的时候，传递进来的参数是否还有效。所以它选择参数
值传递而不是引用传递。如果想引用传递，std::ref和std::cref就派上用场了。

230.共用体就是共用一个内存首地址，并且各种变量名都可以同时使用，操作也是共同生效

231.
一个类模板(类生成类)允许用户为类定义一种模式，使得类中的某些数据成员、默认成员函数的参数，某些成员函数的返回值，能够取任意类型(包括系统预定义的和用户自定义的)。
　　如果一个类中的数据成员的数据类型不能确定，或者是某个成员函数的参数或返回值的类型不能确定，就必须将此类声明为模板，它的存在不是代表一个具体的、实际的类，
而是代表一类类。

234.一个类中用成meta_save/update，但不是玩家自己的类，可不用继承auto_player,可用_auto_meta

235.unique和manid是一样的

236.battlehelp::resetmasterskill(own().getowndataptr(), army_side, fm_datap->horseskillid());  重置上阵部队的坐骑技能

237.training_field::reportmanage _report_mng  是类的成员变量，这只昰声明，还没有直接的创建对象，只有这个类的构造函数执行后，创建成员变量，
所以虽然reportmange只有有参构造器，但这里可以不用传，这个类的构造函数中再传.
例：
playertrainingfield::playertrainingfield(playerdata *const own) 
  _report_mng(limit::report_num),

239.武将管理类有一个所有武将都同的属性，当增加某一属性是所有武将共有时，在这个接口下加  void playermanmgr::recal_comon_attri()
而这一共有属性是一变量保存的，所以当属性变化时，要调用  own().man().recalcomonman();  接口修改这个变量

240.玩家的基本数据，如名，脸，战力，军团名等，都是常用到的，但都不不同的模块中，取时不方便，所以创建了一个中间变量shared_player,所有的这些数据都可通过这个类取到
用时playerptr->data().name()

241.own().reset1():这个类的数据，是每日5点重置，玩家登录就会同步

242.own().info().alterexp(add_exp),加经验失败时，只有玩家满级这一种情况

243.
指定群发玩家:static void batchsign(const _type_list& vec, _type_message& message, const short protocol);

群发：static void batchall(_type_message& message, const short protocol);

 244. chat_sys.despatchlegiondinner( chat::server_legion_dinner_ques, _legion_id, pl,  chatpos::dinner_chat_windows);
                                    发起者id，私聊时是玩家id，广播时是广播类型,广播类型时，决定了以什么样的格式显示

gas想广播一条数据：调用广播类进行广播，


245.gac通过聊天窗发的数据通过  void chat_system::chatreq(net::msg& m, json::value& r)   接收，解析数据找到频道对应的数据处理函数,不同窗口对应不同的处理函数
也就是，gac只要是窗口发送的数据，都绑定一个协议，协议再绑定这个函数

246: value_type == typedef pair<const key, type> value_type;

248.trylock()是想在执行某个动作前想加锁就加锁，而在构造函数中singletonmutexptrcreate,是在调用这个对象时，就已加锁

249. 下载db时，判断某字段是否存在
#define checknoteoo(bs)\
  if(! bs.eoo())

250.var_type.h  各种常见类型

254. bsonelement.h  573 ,下载db转换类型时的错误提示
ss << "field not found, expected type " << t;
ss << "wrong type for field (" << fieldname() << ") " << type() << " != " << t;
例： type:3003, pid:3145728022, wrong type for field (rpi) 18 != 16
bsontypes.h  bson类型编号

255.gac与gas交互时，如果有错误，会以下列格式抛出 
loge << "type:" << m.protocolid << ", pid:" << m.playerid << ", " << e.what() << logend;

256.json的类型转换抛出的错误：
 type:3007, pid:3145728022, double out of int rang/e, 表示要转换的值是double类型,大于想转成的int类型，所以要将json的double类型转成int
 类型也是可行的，需这个double类型的大小不超过int

257.静态成员函数和静态成员变量是所有对象都共享的，静态成员函数只能访问静态成员变量

258.function，声明出一种类型，类似int，       bind是改变函数的参数数量，返回新的函数类型

259.vector类型的成员变量声明时初始化， vector<int> a(10), 编译器会认为是一个函数，提示10不是一种类型，可以用初始化列表的方式初始化，
vector<int> a{1,2,3};

260.静态成员变量要在类外初始化
例：
class aa
{
public:
  typedef boost::function<int(playerdataptr, const reqarg&)> actrechargedealfunc;
private:
  static std::map<int, actrechargedealfunc> kactdealmap;  
};
此时的kactdealmap只是声明，需要在类外初始化才会分配空间
std::map<int, actrechargedealfunc> aa::kactdealmap;  这么写还是不对，因为是在类外初始化，actrechargedealfunc是在类内的类型，所以也要加命名空间
std::map<int, kactdealmap::actrechargedealfunc> aa::kactdealmap;

静态成员变量在多线程中会出现同时读写的情况，所以静态的数据，不需修改时，要都加上const 

261.static_cast<type>(expression) 类似c的强转，使用这个，就表明这里需要转换，会明显些，static_cast在编译时会进行类型检查，而强制转换不会

262.dynamic_cast 用于类间的转换，如果不对，会返回null
例： pf是父类的指针，ps是子类指针，当子类指针转成父类，即上转，一般不会有问题。下转，父类的指针转成子类时，这个父类的指针需是被子类赋值过的，
单纯的父类指针转成子类不会成功ps = dynamic_cast<ps *>(pf);  https://blog.csdn.net/macuilxochitl/article/details/19615311

264.const指针可以接收非const和const指针，而非const指针只能接收非const指针

265.函数后const，不能修改数据成员，不能调用非const成员函数,非成员的非const函数可以调用，因为非成员的函数不会修改成员 数据。
函数前const，函数返回的对象不能做为左值，即不能修改。主要用于修饰返回的指针或引用，
保护指针指向的内容或引用的内容不被修改
左值例：
class a {  
private:  
    int i;  
public:  
    a(){i=0;}  
    int & get(){  
        return i;  
    }  
};  
void main(){  
    a a;  
    cout<<a.get()<<endl; //数据成员值为0  
    a.get()=1; //尝试修改a对象的数据成员为1，而且是用函数调用表达式作为左值。  
    cout<<a.get()<<endl; //数据成员真的被改为1了，返回指针的情况也可以修改成员i的值，所以为了安全起见最好在返回值加上const，使得函数调用表达式不能作为左值  
}  

267.json["xx"].asint(); xx这个字段如果不存在，[]重载函数返回nullref, asint()得0

273.resoure  和 box 区别，   box中有man

275.actionboxlist 的配置，[[],[]],注意在只有一份奖励时，最外层还有一个[]

278. 例：传入等级对应的经验容器，传入经验值key，返回对应的等级
unsigned experiences_index_search(const std::vector<key_type>& arr, const key_type& key) 就是一个二分查找

279.中间没有空的，不写即可，有默认值
log(dblog::strlogbusiness, player, 4, shunyiid, 1);

280.passing ‘const gg::playerlegion’ as ‘this’ argument discards qualifiers,  通过这个对象调用的函数破坏了限定，也就是const
const auto& legion = player->legion(); 
加上这个const之后，这个legion只能调用const的成员函数

283.
side_json["arr"] = array_config.array_id; 此时side_json是object类型，不能再用side_json.appen(xx)
会报错
in json::value::operator[](arrayindex): requires arrayvalue

284.广播 weight字段：广播优先级， roll字段：播放次数

287.局部锁中调用全局锁会死锁：一个线程先取了局部锁，要取全局锁，但被另一个线程使用了，所以会wait,另一个线程先取得的全局锁，想取局部锁，但局部锁被第一个线程使用了，
此时发生死锁

288.null在c++中是0，做为函数参数使用时，会出现二义性

289.自定义类型要分号结尾，例类、结构体，enum都是自定义类型

290,定义变量时，要考虑初始化时是否要设成-1，设成-1则不能是unsigned类型

291.容器调用resize()后，所有的空间都已经初始化了，所以可以直接访问。
reserve是容器预留空间，但并不真正创建元素对象，在创建对象之前，不能引用容器内的元素，因此当加入新的元素时，需要用push_back()/insert()函数。
reserve可以用[],但是size还是0,用auto不能遍历里面的元素
vector<vecor<int> > ;  说是>>之间要有空格，但有时却不报错，vec在插入数据时，必须初始内部有多少vector，内部的vector没有初始大小，则只能push_back插入数据 

292.累加的权重，好比是有一条线，在这条线上，随机到某个点的概率是相同的，占的点越多，则随机到的概率越大，
例：20，30，40,则线的总长是90，随机到0-20，就是20，随机到20-50，就是30，50-90就是40，可使用map存，插入没成功，抽到的位置就是返回的位置，
若插入失败，下一个元素就是抽到的位置，当抽到时，要把抽到的那份去掉,避免了无效的抽取。
90 70
30 70
50 90

294.singletonsafe  :加了全局锁的单例

295.定位new，先申请了一块内存，在这个内存上创建对象，对象中可能有指针指向了新开辟的空间，不能直接delete bufptr，因为会释放对象内的指针占用的空间，
而指针指向的空间没有释放，因为bufptr也指向buf这块空间，所以buf也会释放。所以需通过bufptr调用对象的析构函数，再delete这块空间
https://blog.csdn.net/qianqin_2014/article/details/51320775

296.meta_begin_update()  跟meta_sign_update()区别：在线才同步gac
例： int buf = 512
char * bufptr = new char[buf];
class a;

aptr = new (bufptr(传内存的地址)) a;

296. history_task_def.h中的
class a
{
union {
    basearg base_arg;
    battlebasearg battle_base_arg;
    ...
  };

}
因为是无名的union中，所以相当于是类的成员对象，又因为是在union中，所以这些对象共用一个首地址。只会在多种类中创建一种对象，所以可在union中将所有类进行构造，
决定了要创建哪个类，就传入哪个对象的地址。


297.当使用一条delete表达式删除一个动态分配的对象时
例：delete sp;
delete [] arr;
实际执行两步。1.对sp所指的对象或arr所指的数组中的元素执行对应的析构函数。2.编译器调用名为operator delete
的标准库函数释放内存空间。所以实际上析构函数只是销毁对象。而不会释放掉内存

298.player中有多个类，玩法数据，战报，布阵，头文件写在一个文件，实现写在不同文件

299.  return(r, player->peakdata().get_daily_box(r[strmsg][1u] = json::arrayvalue));函数直接写在里面

300.  ptr_data->_player_info = shared::playermgr::shared().get(g1->id()); //取玩家的多种数据

301.还是要考虑fatherid的问题，通过fatherid可找到武将的原始配置数据,当要找武将原始数据时，要配fatherid，例：peak_system.cpp:778

302.取配置错误时，使用loge

303.传入lv返回配置，可不用设一个函数，直接取配置过来，再传入lv，如果是传入某个值，经过计算后再返回结果的，可设成函数

304.peak_system.cpp:1239   实现定时器时，最好一个定时器执行后，执行函数再启动另一个定时器，则不管是改时间，还是一段时间后再重启，都是走一样的流程

305.保持 “一致性” 使得接口容易被正确使用。例如 stl 容器的接口就十分一致，都有一个名为 size 的成员函数返回目前容器的大小。

306.内置类型，以及stl的迭代器和函数对象。对它们而言，pass-by-value往往比较合适。   姑且认为是非自定义类型就传值 
内置类型在按值传参时，只是将变量的值传递到栈上。 然后被调用函数将值取出后，使用即可。 
在按引用传参时，需要将被引用的变量的地址压栈， 然后被调用函数首先取出地址，然后再次根据地址寻址获取值。

307.class中，成员变量被越少的成员函数访问，封装性越好，非成员函数能实现的功能尽量用非成员函数。
例：class
{
  void cleara();
  void clearb();
  void clearall(){//--clearall有资格访问私有成员，降低了封装性
    cleara();
    clearb();
  }
}
上例的clearall()成员函数，写成类外的非成员函数   clearall(class c){c.cleara(); c.clearb()}

例：
class a
{
  a(int x, int y = 0)
};
a a;
a = 1;可以这么写，会隐试的将1传入类a的构造函数。

309.使用non-member函数的另一种好处
当你需要为某个函数的所有参数（包括被this指针所指的那个隐喻函数）进行类型转换(下例是对构造函数的所以参数进行类型转换)，那么这个函数必须是个non-member。
class rational {
public:
    rational(int numerator = 0, int denominator = 1) 
        : mnumerator(numerator), mdenominator(denominator) {}
    int numerator() const { return mnumerator; }
    int denominator() const { return mdenominator; }
private:
    int mnumerator; // 分子
    int mdenominator; // 分母
};

const rational operator*(const rational& lhs, const rational& rhs) {
    return rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}
 
int main() {
    rational onefourth(1, 4);
    rational result;
    result = onefourth * 2;
    result = 2 * onefourth; // 如果不是 non-member 的形式将不支持这种写法
}

310.省是现代词，是一个专有名词，指的是默认。shěng

311.dynamic_cast 少用。  一般是要使用派生类中的独有的函数，所以将基类指针转成派生类，最好是将该函数实现成virtual

312.mutalbe的中文意思是“可变的，易变的”，mutable是为了突破const的限制而设置的。被mutable修饰的变量(mutable只能由于修饰类的非静态数据成员)，将永远处于可变的状态，
即使在一个const函数中。
假如类的成员函数不会改变对象的状态，那么这个成员函数一般会声明为const。但是，有些时候，我们需要在const的函数里面修改一些跟类状态无关的数据成员，
那么这个数据成员就应该被mutalbe来修饰

314.~按位取反,将某个数x的二进制的每一个bit取反

315.纯虚函数（pure virtual）目的是让子类只继承函数接口，而不关心子类怎么去实现它。
非纯虚函数（impure vitual）目的是让子类可选择的实现这个接口，或是使用父类的默认实现。
成员函数（non-virtual）目的是让子类继承这个函数以及它的实现，而不去改变它（即所有子类都使用这个相同的实现）。

316.map的key是多个变量组成时，可看成是组合索引，且重载<号函数后，key可实现排序

317.体会，取成军团指针后加全局锁，取到讨伐的军队后，加全局锁

319.int占32位的时候，最大可以赋值为：2147483647。也就是0x7fffffff。  20多亿

320.玩家登录后，会先在本地找玩家的数据，本地数据是超过1万，才会去删除不在线玩家，找不到玩家数据才会下载db，重启后，本地数据就清空,玩家再次登录会下载db

321.extern 可修饰本头文件的函数，实现在本cpp文件中

324.本线程要跟另一个进程进行rcp通信时，本线程会创建一个client的rcp，通过这个rc

325.tar -zcvf game.tar.gz ./game --exclude=./game/obj

326. 无符号的做减法，再减之前要判断两数大小

327.迭代器失效分序列容器和关联容器，不能简单的理解为，当前的迭代器失效，使迭代器往下移一位即可.
https://blog.csdn.net/qq_37964547/article/details/81160505
是否可理解为，不能对失效的迭代器进行操作，需要在失效之前进行操作或操作后对迭代器赋于新的值才能操作。

328.左值引用，用于传参，扩展对象的作用域。右值引用，延长了临时变量的生命周期.
临时变量不能作为非const引用参数，不是因为他是常量，而是因为c++编译器的一个关于语义的限制。如果一个参数是以非const引用传入，c++编译器就有理由认为程
序员会在函数中修改这个值，并且这个被修改的引用在函数返回后要发挥作用。但如果你把一个临时变量当作非const引用参数传进来，由于临时变量的特殊性，程序员
并不能操作临时变量，而且临时变量随时可能被释放掉，所以，一般说来，修改一个临时变量是毫无意义的，据此，c++编译器加入了临时变量不能作为非const引用的
这个语义限制，意在限制这个非常规用法的潜在错误。
但const 的引用不用修改值，所以有了&&（右值引用)

329.totm,得到的周和月，都从0开始

330.顶层const（top-level const）表示指针（或引用等）本身是个常量。底层const（low-level const）表示指针指的对象是一个常量。
一般当说到顶层或底层const的时候都是指针或者引用类型的，因为普通类型的const只能是底层的。

331. 多个零散的#define xx yy可放到一个enum中 
enum   
    {
      closed = 0,
      opened,
      reset,

      resettime = 5 * hour,
      opentime = 20 * hour + 30 * minute,
      closetime = 21 * hour,
    };

332.模板偏特化，即给默认类型，模块优先调用特化模板,比如一个想减类模板函数，int可以直接想减，unsigned需判断减数和被减数的大小，
所以，可以特化一个unsigned的模板，实现别一种的比较方法

335.标识符，可理解为代表某东西的符号，例变量名，标识符不能以数字开头

336.[error] timer call err :in json::value::operator[](arrayindex): requires arrayvalue
定时器调用的回调函数中 json使用有错误

337.shared_player中，ptr会不会不个在读，一个在写
塔防模式
->_bposf  history_task.cpp:393

338.long long int 是什么鬼

339.一个通用奖励可以配权重。和随机奖励的区别是，少了一个权重，随机奖励是一个json中配了很多有权重的奖励，用boxid来标记这个json文件

340. 下图中throw 出的是字段字符串类型，所以 catch 的参数是 const chat* msg
try {
  throw"division by zero condition!" 
}catch(const chat* msg) {

}

341.as ‘this’ argument discards qualifiers [-fpermissive]
注意： c++中，const 修饰的参数引用的对象，只能访问该对象的const函数，因为调用其他函数有可能会修改该对象的成员，
编译器为了避免该类事情发生，会认为调用非const函数是错误的。

342.unordered_map是计算key的哈希值，以找回value存放的对应格子，修改value不需重新插入,
map需重新插入

342.函数形参是引用时，不能传临时变量，是const的引用时，可以传临时变量

343.move
0.对指针进行操作时，是所有权的转移 1.以极低的性能消耗实现复制（将内容取过来），2.被取的变量不能再使用，

344.explicit  只能修饰构造函数，将抑制隐式转换
按照默认规定，只有一个参数的构造函数也定义了一个隐式转换，将该构造函数对应数据类型的数据转换为该类对象
class string {
string ( const char* p );
};
string s1 = “hello”; //ok 隐式转换，等价于string s1 = string（“hello”）;

345.用内存池的原因：
c/c++的内存分配（通过malloc或new）可能需要花费很多时。更糟糕的是，随着时间的流逝，内存将形成碎片，
所以一个应用程序的运行会越来越慢。当它运行了很长时间或执行了很多的内存分配（释放）操作的时候。特别是，
你经常申请很小的一块内存，堆（heap）会变成碎片的。

346. 在构造函数中调用另一个构造函数
class msg {
    msg() {
      _len = minpackage;
      _operate = -1;
      _nid = -1;
      _pid = -1;
      _str = null;
    }
    //调用下列的构造函数，有些成员变量没有初始化，可能类型的构造函数很多，
    //不想一一写，可用定位new，在自身的空间上先调用另一构造器进行构造，以
    //初始化成员变量
    msg(const variable::i32 pto, std::string& json_str_utf8) {
      new(this) msg();
      _operate = pto;
      _len = (unsigned short)json_str_utf8.size() + minpackage;
      _str = json_str_utf8.data();
    }

};

346.make_shared函数的主要功能是在动态内存中分配一个对象并初始化它，返回指向此对象
的shared_ptr;由于是通过shared_ptr管理内存，因此一种安全分配和使用动态内存的方法。

347,./可执行文件名 参数1 ...
int main(int argc, char* argv[])
argv[0] 是函数名，其后是参数
一个程序的执行必须有main函数入口，且不能被其它函数调用，所以当需要参数时，不能在函数
内部取的，只能从外传入，因此main函数有参数
exec不能看成一个简单的函数，它是可执行可执行文件的

348. 当map是大于的排序时，lower_uppper返回小于等于k的值，  小于时，则返回大于等于k的值

349. 简单的话，堆和栈都是内存，堆是程序员进行管理，栈是系统进行管理，堆比栈大的多的多。
https://blog.csdn.net/k346k346/article/details/80849966

350
epoll事件有两种模型：
edge triggered (et) 边缘触发只有数据到来,才触发,不管缓存区中是否还有数据。
level triggered (lt) 水平触发只要有数据都会触发。

首先介绍一下lt工作模式：
lt(level triggered)是缺省的工作方式，并且同时支持block和no-block socket.在这种做法中，内核告诉你一个文件描述符是否就绪了，然后你
可以对这个就绪的fd进行io操作。如果你不作任何操作，内核还是会继续通知你的，所以，这种模式编程出错误可能性要小一点。
传统的select/poll都是这种模型的代表．
优点：当进行socket通信的时候，保证了数据的完整输出，进行io操作的时候，如果还有数据，就会一直的通知你。
缺点：由于只要还有数据，内核就会不停的从内核空间转到用户空间，所有占用了大量内核资源，试想一下当有大量数据到来的时候，每次读取一个字节，
这样就会不停的进行切换。内核资源的浪费严重。效率来讲也是很低的。

et:
et(edge-triggered)是高速工作方式，只支持no-block socket。在这种模式下，当描述符从未就绪变为就绪时，内核通过epoll告诉你。然后它会假设
你知道文件描述符已经就绪，并且不会再为那个文件描述符发送更多的就绪通知。请注意，如果一直不对这个fd作io操作(从而导致它再次变成未就绪)，
内核不会发送更多的通知(only once).
优点：每次内核只会通知一次，大大减少了内核资源的浪费，提高效率。
缺点：不能保证数据的完整。不能及时的取出所有的数据。

351.emplace_back() 将传入的值直接放到构造函数中构造, 传入临时变量时可使用
注意容器扩容，地址重新分配，迭代器失效问题。

352.可定大小，只能用｛｝初始化，或用fill

353.
总结：公钥和私钥是成对的，它们互相解密。
公钥加密，私钥解密。

354.
meta_begin_update , meta_auto_update
  void _auto_player::meta_begin_update() {
    if (own().isonline()) {
      meta_auto_update();
    }
  }
  只继承 auto_meta，在用sign_update时，如果覆写meta_auto_update,则不会update,需覆写meta_begin_update
  save不受影响

  356. ssh免密登录，   生成密钥，给对方公钥，对方写入autokey...,则双方都删除公钥
  1.sudo chmod 600 config
  2. confg 中的host写什么，就得  ssh什么，不用config，可 ssh xx@xx登录，且密钥需是原始名。

355.迭代器是不用引用是复制一份

jiluend
1.详解array  看书签
2.网络问题  书签
3.legion_manage.cpp: 971   删除后，军团指针还能锁娄吗？
4.看积分商店实现
5.zsh 补全慢
6.qvalue  不能   tme << (qvalue(qjson::arr) << x )?
7.shop_mgr.cpp:97  概率是否不对

79.player_classic_battle.h:12     extern void initial_config();  在源文件中有实现，这里不加extern行吗？???

thread常用到超时处理，所以引入data_time库
线程就是在进程的另一个空间里运行一个函数,因此，创建线程里，要传递给线程一个可调用物（函数或函数对象），必须有operator()，以供线程执行

常用的boost::shared_ptr函数有： 
get() 获取裸指针 
reset() 计数器减一 

main.cpp开始，先配置log，再打印log的设置，游戏服再开始start,start中先创建线程池，再建立通信.
initialgame: 都是初始化设置，在接收gac请求前，还没看到下载数据  
玩家登录验证：通过pid或name先在playermap中找，找不到就先创建一个playerdata类，会先构造父类playerbase,构造好后，设置base还没下载数据的标记，然后通过
playerid或name去load  base的数据对playerbase进行初始化,再创建各性化数据类，各性化数据都是先全部创建，再去下载load，如果错过了这次load，只能在调用的时候load，
最后加入playermap中，这一过程是不在线状态,load时，调用__object->setdata()，设置下载的db数据，在每次调用__object()时，会先tofull()，所以会去调用classload()
和~final() ,   所以是先setdata,再tofull(可看成是使用前)

playerdata的initial（）是创建个性化数据，和setdata数据，都是发生在playerdata的构造函数中，所以不能在此期间调用share_ptr

登录时，先确定能取到playerdataptr,再设置为在线状态，在做登录处理



1.gas调用聊天系统主动发军团相关广播
   1.传入广播类型和军团id和内容
  2.从数据进行组包，发送时，聊天系统发的是同一种组包方式
  3.调用方法通过军团id找到要发送的成员

2.gac聊天窗中输入数据时，需进行gas检查，然后返回的数据格式是一样的，但是发送频道不同，接收数据的玩家也不同，所以要自实现方法，又因为需要缓存数据，
取各频道数据的方法都不同，所以也要自实现 


类 对象，   不能 类 对象（）

下载，上传，obj,array,大写


2.void exclusivemutex(singletonmutexptr m)
  {
    auto& lm_list = localtssdata()._localmutex; //不是获取一个share_special_ptr？为什么_localmutex可以共用??
    if (lm_list.insert(m).second)
    {
      //保证数据独享
      if (false == (*m)().timed_lock(trylocktime)) {



rcf:
1.定义接口
rcf_begin(cm_protocol, "cm_protocol")//--cm_protocol可看成所有接口的总称
//接口中只有一个函数, 返回值是void，函数名是transfer，接受4个参数, 可以写多个函数
rcf_method_v4(void, transfer, const variable::i64&, const variable::i32&, const variable::i32&, const std::string&)
rcf_end(cm_protocol)

2.在服务端实现接口中的函数，接口的实现客户端不可见 
class dealdata
  {
  public:
    void transfer(const variable::i64& player_id, const variable::i32& net_id, const variable::i32& protocol_id, const std::string& data_str)
    {
      thread_shared::initframe();
      thread_shared::eventandstep(protocol_id);
      while (!game_svr->isok())
                common::sleep(100000);
            print("recv: " << player_id << ", " << protocol_id << ", " << data_str);
            game_svr->recv_msg(player_id, net_id, protocol_id, data_str);
      thread_shared::cleanframe();
    }
  }
生成一个rcf的服务端，绑定ip、port,接口
  _game_service = new ::rcf::rcfserver();
      _game_service->addendpoint(rcf::tcpendpoint("127.0.0.1", game_data._game_service_port));//游戏服端口
      _game_service->bind< ::cm_protocol >(*(new dealdata()));  //传入的参数是气喘接口中函数的对象

3.rcf客户端,传入接口
      _game_rcf = ::rcfclient< ::game_svr >(rcf::tcpendpoint("127.0.0.1", _gdata._game_service_port));


线程池：
线程本地储存：boost::thread_specific_ptr;
class tss_data
{
};
本地储存的数据多，可封装成一个对象传入，
boost::thread_specific_ptr<tss_data> type_tss_data_ptr;//每个线程都可调用type_tss_data_ptr,但都是不一样的tss_data对象，每个线程第一次使用前都会new一个，可
看成每个线程使用前，都会生成一个本地的储存空间。这个type_tss_data_ptr是全局的

gdb-----------------------------------------------------------------------------------------------------------

1.-g为了调试用的,加个-g 是为了gdb 用，不然gdb用不到,-o必须写在后面（-g,主编译器将符号表（对应程序的变量和代码行的内存地址
列表）保存在生成的可执行文件中，这样才能在调会话过程中引用源代码中的变量名和行号

gdb实际上是使用机器语言指针工作。不能简单的理解为是一行一行的执行代码。例：声明i确实会生成机器码，但是gdb发现这种代码对调用目的来
说没有用处，所以在这行设置断点不会停。被优化后的代码也会出来断点的位置不是我们想要的的结果

3.c用gcc, c++用g++


 3.step没有进函数的原因是gdb不会在不具有调用信息的代码内停止，例：printf()

 3.finish:恢复gdb运行，直到恰好在函数返回之后为止。用此查看函数返回值

 3.until:执行完循环直到跳出循环的第一行代码处暂停。实际是执行程序，直到到达的内存地址比当前内存地址更高的机器指令，而
 不是直到源代码中的一个更大的行号。
 如果执行until导致回跳到循环顶部，再执行until就可离开当前循环。
 执行到某行或某函数入口：例：until 12, until bed.c:12, until swap, until bed.c:swap


4.程序运行参数。
  set args=x 可指定运行时参数。
  show args 命令可以查看设置好的运行参数。


 7.c x a 进入tui模式

8.断点
 tbreak 临时断点

 监视点：即是断点，也可打印变量值，用于监视某个变量什么时候发生变化，在哪变化。watch z , watch (z > 28). 对全局变量和函数之间连续传递
 的局部变量来说特别有用。
 watch (i | j > 12) && i > 24 && stlen(name) > 6   加了三个条件

 即，在使用watch时步骤如下：
1. 使用break在要观察的变量所在处设置断电；
2. 使用run执行，直到断点；
3. 使用watch设置观察点；
4. 使用continue观察设置的观察点是否有变化。

 条件断点：加的表达，需要能返回bool，可用逻辑、运行符、位运行，可看成是c语言if对条件中的
 1.break 30
 condition 1 num_y==2  (假设打的断点是编号1,注意不要加if)  cond=condition,   已存在的断点
 删除条件：condition 1,即设空
 2. break 20 if num_y==2  新创建的断点
 3.用自己的函数：break test.c:myfunc if !check_sanity(i)

 4.断点命令列表：使用com mands命令设置
 例：break main
  commands 1  给断点1设命令列表
  silent  加这个是为了打印简洁
  printf "main was pass %d.\n", n    printf 就相当于平时用的，只是去掉了括号
  continut   加这个相当于按了c键
  end   每个命令需以end的结束
 例：2
  commands 1     if的使用同c，printf只是去掉括号，可用gdb的print
  p tmp->val
  if(tmp->left != 0)
  p tmp->ledf->val
  else
  printf "%s\n" "none"
  end
  if(tmp->right != 0)
  p tmp->right->val
  else
  printf "%s\n", "none"
  end
 end
 例 3 commands和call（调用自己的函数)结合使用
 commands
 printf "xxxxx"
 call printftree(root) 
 end

 取消commands   置空  commends1 ..... end

delete 2 3 4(删除2，3，4位置的断点)
delete：删除断点、监视点和捕获点
禁用断点：disable 数字列表 ， 不加参数禁用所有列表   dis=disable
启用断点：enable 数字列表

若有函数 void main();  在函数入口处设置断点 break main
重载函数或同名静态函数：break 文件名：函数名 例：break bed.c:main


 9.栈帧：在函数调用期间，与调用关联的运行时信息存储在栈帧中，包括局部变量的值，形参，调用该函数的位置，当函数退出时，
 这个帧被弹出栈，且被释放
 frame 当前栈帧，up, down切换，backtrace显示当前存在的所有帧集合  bt=backtrace
 info locals:当前栈帧中的所有局部变量的值列表
 info args:显示当前函数的传入参数

 10.c c不会中断程序，只是挂起，按c可继续运行

 11.段错误：通常由于数组索引超出了边界，或者或者采用了错误的指针值。
 系统分给程序的有权限的内存的单位和程序访问内存的单位不同，可能会出现多分，当程序访问超出自己申请的内存大小时，就没有段错误，
 所以，不能根据是没有段错误来判断程序对内存的操作正确

 访问不存的物理地址是总线程错误，是因为提供给处理器的是无效地址，与发生段错误的原因不同

 12.next等命令时，gdb显示的是将要执行的代码行

 14.continue 3, 忽略接下来的3个断点

 15.很多调用动作需先执行到断点位置才能设置，因为在进行这个位置的函数之前，函数内的变量还不存在

 16.print
 打印结构体内容: p *tmp  tmp指向一个结构体
 display:使gdb在执行中每次暂停时就输出指定变量值 禁用disable display 1,启用enable display 1 ,删除undisable 1, disp = display
 打印数组：int a[25],   p *a@25   改变访问地址的类型  p (int[25])*a  若访问的变量需加作用域：p *node::root 和.cpp函数的实现一样，类型开头，作用域+：：

 ptype:查看结构或类的代码，例：ptype node

 print、displayer可指定格式输出：p/x y（以16进制显示y变量）， c表示字符，s表示字符串，f表示浮点型

 17.设置变量的值
  set x = 12,  若有int arr[6], 则可set arr={1,1,2,2}
  设置新变量接收值：set $q = p  （必须加$,$q称为方便变量）
  不执行源代码的情况下遍历数组：set $i=0, p w[$i++]

 18.如果机器上有多个cpu，则会有多个程序真正的同步运行

 19.new thread xxx (lwp xxx) ：gdb提示有线程创建

 20.调试时，栈帧一般会看新写的代码处的函数，因为老的代码已用这么久，一般不会错，调用的库也不会错，只能是新写的代码访问了什么，而调用老代码或动态库去执行访问，然后就错了   剩下重置次数

 21.ni 和si 是执行机器语句，一个函数可能解析成多个机器语句。

 22. disas看反汇编， i r 看寄存器

 23 mov  1,2   2 复制到 1

 24 内存映射 i proc m （info proc mappings 的简写）核查零是不是有效地址：

25.例 ：g++ -std=gnu++14  x.cpp -g -og -gdwarf-3 -o x
-gdwarf- 2:产生dwarf version2 的格式的调试信息,常用于irixx6上的dbx调试器.gcc会使用dwarf version3的一些特性.
可 以指定调试信息的等级:在指定的调试格式后面加上等级:
如: -ggdb2 等,0代表不产生调试信息.在使用-gdwarf-2时因为最早的格式为-gdwarf2会造成混乱,所以要额外使用一个-glevel来指定调试信息的 等级,其他格式选项也可以另外
指定等级.

26.g++ -e xx.cpp -o xx.i   预处理

27.死锁
先用pstack 进程号 查看各个线程的堆栈信息,看哪个的堆栈可能有问题，就用gdb attack 线程号， 查看这个线程的堆栈信息

28.打印所有线程堆栈
thread apply all bt

29.log
(gdb) set logging on    -> 打开记录功能。
(gdb) set logging off -> 关闭记录功能。   没有指明文件，会自动生成gdb.txt

set logging file <filename> //设定logging output 的文件
set logging on //开始logging, 所有输出到终端的信息都会写到之前设定的文件中（filename）
set logging off //停止logging

30. gdb attach pid 后，可直接打断点，不用点run,退出gdb不会使线程退出，detach 取消挂接的进程

31.(gdb) set print element 0   不限制打印字符串的长度 

32.gdb打印不了内嵌容器，例如打印内嵌的map，first对，second不对

33.call function()  如果该函数返回值为void，则调用后不会有内容。该函数内可打断点


mongodb————————————————————————————————————————————
1.mongodb 将数据存储为一个文档，数据结构由键值(key=>value)对组成。mongodb 文档类似于 json 对象。字段值可以包含其他文档，数组及文档数组。
2.mongodb 是一个面向文档存储的数据库.
3.查询指令使用json形式的标记，可轻易查询文档中内嵌的对象及数组。
4.需要注意的是：（文档相当于行，列叫字段，表叫集合,是 mongodb 文档组）
文档中的键/值对是有序的。
文档中的值不仅可以是在双引号里面的字符串，还可以是其他几种数据类型（甚至可以是整个嵌入的文档)。
mongodb区分类型和大小写。
mongodb的文档不能有重复的键。
文档的键是字符串。除了少数例外情况，键可以使用任意utf-8字符。
5.集合存在于数据库中，集合没有固定的结构，这意味着你在对集合可以插入不同格式和类型的数据，但通常情况下我们插入集合的数据都会有一定的关联性。当第一个文档插入时，集合就会被创建。
6. capped collection，一种固定大小的集合，当集合的大小达到指定大小时，新数据覆盖老数据,
capped collections是高性能自动的维护对象的插入顺序。它非常适合类似记录日志的功能 和标准的collection不同，你必须要显式的创建一个capped collection， 指定一个collection的大小，单位是字节。collection的数据存储空间值提前分配的。
要注意的是指定的存储大小包含了数据库的头信息。例：db.createcollection("mycoll", {capped:true, size:100000})
7.创建集合(创建表)：db.createcollection(name, options),options: 可选参数, 指定有关内存大小及索引的选项
capped  布尔  （可选）如果为true，则创建固定集合。固定集合是指有着固定大小
的集合，当达到最大值时，它会自动覆盖最早的文档。当该值为 true 时，必须指定 size 参数。
8.查看已有集合，可以使用 show collections 命令
例：创建固定集合 mycol，整个集合空间大小 6142800 kb, 文档最大个数为 10000 个。
> db.createcollection("mycol", { capped : true, autoindexid : true, size : 6142800, max : 10000 } )
{ "ok" : 1 }
9.也可以不用提前创建集合：当你插入一些文档时，mongodb 会自动创建集合。例：
> db.mycol2.insert({"name" : "菜鸟教程"})         自动创建mycol2集合
> show collections           
mycol2
10.删除集合：db.collection.drop()，没有参数    collection是要删除的集合名
11.插入文档：db.collection_name.insert(document)
方法1：
>db.col.insert({title: 'mongodb 教程', 
    description: 'mongodb 是一个 nosql 数据库',
    by: '菜鸟教程',
    url: 'http://www.runoob.com',
    tags: ['mongodb', 'database', 'nosql'],
    likes: 100
})
方法2：也可以将数据定义为一个变量
> document=({title: 'mongodb 教程', 
    description: 'mongodb 是一个 nosql 数据库',
    by: '菜鸟教程',
    url: 'http://www.runoob.com',
    tags: ['mongodb', 'database', 'nosql'],
    likes: 100
});
执行插入操作：
> db.col.insert(document)
writeresult({ "ninserted" : 1 })
> 

12.更新文件：
方法1:  update() 方法用于更新已存在的文档。语法格式如下：
db.collection.update(
   <query>,    update的查询条件，类似sql where后面的。
   <update>,   update的对象和更新的操作符（如$,$inc...）等，也可以理解为sql set后面的
   {（下列都是可选参数）
     upsert: <boolean>,  如果不存在update的记录，是否插入objnew,true为插入，默认是false，不插入。
     multi: <boolean>,   默认是false,只更新找到的第一条记录，true时,将按条件查出来多条记录全部更新。
     writeconcern: <document>  抛出异常的级别
   }
)
例：更新标题(title)，修改多条相同的文档    $set操作符替换掉指定字段的值
>db.col.update({'title':'mongodb 教程'},{$set:{'title':'mongodb'}},{multi:true})    $inc是对某个字体的值进行加减，所以值只能填正负数据
                    <query>                <update>                  可选参数

方法2：
save() 方法通过传入的文档来替换已有文档。
db.collection.save(
   <document>,  文档数据(更新的文档id和数据写在一起)
   {
     writeconcern: <document>  可选，抛出异常的级别。
   }
)

例：替换了 id 为 56064f89ade2f21f36b03136 的文档数据
>db.col.save({
    "_id" : objectid("56064f89ade2f21f36b03136"),   可看出，这行是每个文档的唯一标识符
    "title" : "mongodb",
    "description" : "mongodb 是一个 nosql 数据库",
    "by" : "runoob",
    "url" : "http://www.runoob.com",
    "tags" : [
            "mongodb",
            "nosql"
    ],
    "likes" : 110
})

删除指定字段：  $unset操作符删除一个指定的字段
> db.tk.player_collection.update({},{$unset:{"babelfm":""}},{multi:true})
删除表collection中的所有babelfm字段，muliti为true，表示删除所有找到的，

13.删除文件：
在执行remove()函数前先执行find()命令来判断执行的条件是否正确，这是一个比较好的习惯。
remove() 方法的基本语法格式如下所示：
db.collection.remove(
   <query>,
   <justone>
)
2.6版本以后    两者的区别是：options项需不需要｛｝括起。
db.collection.remove(
   <query>,
   {
     justone: <boolean>,   如果不填，默认是删除所有符合条件的文档
     writeconcern: <document>
   }
)
例1：
>db.col.remove({'title':'mongodb 教程'})
writeresult({ "nremoved" : 2 })    # 删除了两条数据
>db.col.find()
……                                 # 没有数据

例2：删除所有文档
>db.col.remove({})
 db.tk.legion_fuben_system_acti.drop()

14.查询文档：
db.collection.find(query, projection)
query ：可选，使用查询操作符指定查询条件
projection ：可选，使用投影操作符指定返回的键。默认省略

projection 参数的使用方法
db.collection.find(query, projection)
若不指定 projection，则默认返回所有键，指定 projection 格式如下，有两种模式
例有三字段，第一个显示，第二个不显示，则第三个系统就不知道是显示还是不显示
db.collection.find(query, {title: 1, by: 1}) // inclusion模式 指定返回的键，不返回其他键
db.collection.find(query, {title: 0, by: 0}) // exclusion模式 指定不返回的键,返回其他键
id 键默认返回，需要主动指定 id:0 才会隐藏
例：> db.tk.player_collection.find({pi:57671697},{"babelfm":1}).pretty()

若不想指定查询条件参数 query 可以 用 {} 代替，但是需要指定 projection 参数：
querydb.collection.find({}, {title: 1})

以易读的方式来读取数据（格式化的方式来显示所有文档），可以使用 pretty() 方法，语法格式如下：
>db.col.find().pretty()

1.大、小、等
操作              格式                          范例                               rdbms中的类似语句
等于             {<key>:<value>}        db.col.find({"by":"菜鸟教程"}).pretty()   where by = '菜鸟教程'
小于           {<key>:{$lt:<value>}}    db.col.find({"likes":{$lt:50}}).pretty()  where likes < 50
小于或等于   {<key>:{$lte:<value>}}    db.col.find({"likes":{$lte:50}}).pretty() where likes <= 50
大于           {<key>:{$gt:<value>}}    db.col.find({"likes":{$gt:50}}).pretty()  where likes > 50
大于或等于     {<key>:{$gte:<value>}}  db.col.find({"likes":{$gte:50}}).pretty() where likes >= 50
不等于      {<key>:{$ne:<value>}}      db.col.find({"likes":{$ne:50}}).pretty()  where likes != 50

2.and(对象中的,号相当于and)
mongodb 的 find() 方法可以传入多个键(key)，每个键(key)以逗号隔开，即常规 sql 的 and 条件。
>db.col.find({key1:value1, key2:value2}).pretty()    即只有符合两个键值条件的文档才会显示
例：
> db.col.find({"by":"菜鸟教程", "title":"mongodb 教程"}).pretty()
{
        "_id" : objectid("56063f17ade2f21f36b03133"),
        "title" : "mongodb 教程",
        "description" : "mongodb 是一个 nosql 数据库",
        "by" : "菜鸟教程",
        "url" : "http://www.runoob.com",
        "tags" : [
                "mongodb",
                "database",
                "nosql"
        ],
        "likes" : 100
}
类似于 where 语句：where by='菜鸟教程' and title='mongodb 教程'

3.or   or一个范围，范围用[]括起
>db.col.find(
   {
      $or: [
         {key1: value1}, {key2:value2}
      ]
   }
).pretty()
例：
>db.col.find({$or:[{"by":"菜鸟教程"},{"title": "mongodb 教程"}]}).pretty()
{
        "_id" : objectid("56063f17ade2f21f36b03133"),
        "title" : "mongodb 教程",
        "description" : "mongodb 是一个 nosql 数据库",
        "by" : "菜鸟教程",
        "url" : "http://www.runoob.com",
        "tags" : [
                "mongodb",
                "database",
                "nosql"
        ],
        "likes" : 100
}

4.and 和 or 联合使用
sql 语句为： 'where likes>50 and (by = '菜鸟教程' or title = 'mongodb 教程')'
例：
>db.col.find({"likes": {$gt:50}, $or: [{"by": "菜鸟教程"},{"title": "mongodb 教程"}]}).pretty()
{
        "_id" : objectid("56063f17ade2f21f36b03133"),
        "title" : "mongodb 教程",
        "description" : "mongodb 是一个 nosql 数据库",
        "by" : "菜鸟教程",
        "url" : "http://www.runoob.com",
        "tags" : [
                "mongodb",
                "database",
                "nosql"
        ],
        "likes" : 100
}

5.使用 (<) 和 (>) 查询 - $lt 和 $gt
类似：select * from col where likes>100 and  likes<200;
例：获取"col"集合中 "likes" 大于100，小于 200 的数据
db.col.find({likes : {$lt :200, $gt : 100}})

6.模糊查询   /模糊，    ^开关，     $结尾
例：
查询 title 包含"教"字的文档：
db.col.find({title:/教/})
查询 title 字段以"教"字开头的文档：
db.col.find({title:/^教/})
查询 titl e字段以"教"字结尾的文档：
db.col.find({title:/教$/})

7.操作符 - $type (查询某个字段的某种类型)
如果想获取 "col" 集合中 title 为 string 的数据，你可以使用以下命令：
db.col.find({"title" : {$type : 2}})
或
db.col.find({"title" : {$type : 'string'}})

8.limit与skip方法
>db.collection_name.find().limit(number)    只显示前number条记录
>db.collection_name.find().limit(number).skip(number)   先skip(跳过)num条记录，再（limit）显示前num条记录

9.sort() 
通过参数指定排序的字段，1 为升序排列，-1 是用于降序排列。
>db.collection_name.find().sort({key:1})
例：col集合中的数据按字段likes的降序排列：
>db.col.find({},{"title":1,—id:0}).sort({"likes":-1})
                只显示title项，隐藏文档id
{ "title" : "php 教程" }
{ "title" : "java 教程" }
{ "title" : "mongodb 教程" }

skip(), limilt(), sort()三个放在一起执行的时候，执行的顺序是先 sort(), 然后是 skip()，最后是显示的 limit()。

问题：
1.在往集合中插入文档时，不用先确定字段类型吗？



update:  改数字时要加类型限制
1.可更新已存在的数据或不存在就插入新数据，可更新第一条或全部
例：
db.col.update( { "count" : { $gt : 1 } } , { $set : { "test2" : "ok"} } );
找到集合col中，存在count字段的值 大于 1 的， 将字段 test2的值改为ok。   找不到不改，只更新第一条

如果不加$set:则是找到count字段的值大于1的文档，将文档设成只有 test2:0k字段，所以加$set时，是替换set的字段
不加set，则是替换掉key这个文档的所有数据，包括key，所以不加set时，要保存的数据中要有key值
例：
    mongo::bsonobj key = bson("key" << ptr->keyid());
    mongo::bsonobj obj = bson("key" << ptr->keyid() << "value" << ptr->tobson());
    thread_shared::getlocalmongo().savemongo(_db_name, key, obj);

db.col.update( { "count" : { $gt : 15 } } , { $inc : { "count" : 1} },false,true ); 
使用$inc操作符将一个字段的值增加或者减少的格式是
将全部符合条件的,将count的值加1

> db.tk.player_collection.update({"pi":2097507},{$set:{"babelbt.curlevel":30}})//将curlevel改成30，注意babel.curlevel要有“”
//如果之前不存在babelbt.curlevel，会插入数据，所以修改要加存在条件判断
> db.tk.player_collection.update({"reset1.mct":{$exists:true}},{$set:{"reset1.mct":numberint(0)}},{multi:true})

insert:
mongodb 使用 insert()方法向集合中插入文档，集合不存在会自动创建
db.collection_name.insert(document)
例：  做成json数据，一堆键值对
>db.col.insert({title: 'mongodb 教程', 
    description: 'mongodb 是一个 nosql 数据库',
    by: '菜鸟教程',
    url: 'http://www.runoob.com',
    tags: ['mongodb', 'database', 'nosql'],
    likes: 100
})


drop:
删除一个集合，collection是集合的名字
db.collection.drop()

remove:
用来移除集合中的数据
db.collection.remove(
   <query>,   
   {
     justone: <boolean>,  默认是false，删所有符合条件的数据
     writeconcern: <document>
   }
)
例：db.col.remove({'title':'mongodb 教程'})
> db.tk.player_army.find({"pi":57673776,"uid":33}).pretty()

query:
objcollection db_manager::query(const std::string& db_name_str, const mongo::query custom /* = mongo::query() */, 
const int limit_num /* = 0 */, const mongo::bsonobj* fields /* = null */)
.  query 是请求的条件，    fields是要load的字段，空是所有字段
例1：  索引是"key" << type，    排序条件：vl降序， ct升序， strplayrid升序
mongo::query key(bson("key" << type));
      key.sort(bson("vl" << -1 << "ct" << 1 << strplayerid << 1));
      objcollection objs = thread_shared::getlocalmongo().query(dbn::dbactivityrankdata, key, maxsize);

例2：索引是biz.sm字段 > 0， 排序， biz.sm 降序， biz.smct 升序 strplayerid 升序   ,  只load strplayerid字段
mongo::query find_query(bson("biz.sm" << bson("$gt" << 0)));
    find_query.sort(bson("biz.sm" << -1 << "biz.smct" << 1 << strplayerid << 1));
    mongo::bsonobj find_val = bson(strplayerid << 1);
    objcollection objs = thread_shared::getlocalmongo().query(
      dbn::dbplayercollection, 
      find_query, 
      100,
      &find_val
      );

例3：  请求索引， campwarbase 字段存在, 只load  strplayerid字段     这个集合中，campwarbase本身并不是一个索引
auto key = bson("campwarbase" << bson("$exists" << true));
        auto skip_field = bson(strplayerid << 1);
        auto objs = thread_shared::getlocalmongo().query(dbn::dbplayercollection, key, 0, &skip_field);


findone:
和query很像，只返回符合条件的第一个文档，且返回的是对象，query返回的是数组.    custom可填键值或判大小、存在，   fields是要显示的字段
mongo::bsonobj db_manager::findone(const std::string& db_name_str, const mongo::query custom /* = mongo::query() */, const mongo::bsonobj* fields /* = null */)


ensureindex：  
创建索引： 
void db_manager::ensureindex(const std::string &collection, const mongo::bsonobj& key)
例：1  以玩家id为升序， id字段为升序创建索引
thread_shared::getlocalmongo().ensureindex(dbn::dbplayerhorse, bson(strplayerid << 1 << "id" << 1));

例：2  以key字段 为升序创建索引，    所以，可有多个key，从某个数开启递增
    thread_shared::getlocalmongo().ensureindex(dbn::dblegionmanor, bson("key" << 1));


$unset:  
删除某字段
update({"userid":9},{"$unset":{"allyreq":true}})
注意unset这个东东只认key    value可以是任意的.true.1或者其他都没关系.只要看到 allyreq就会干掉它


注意military.lv的用法
  bool playermilitary::meta_auto_save()
  {
    mongo::bsonobj key = bson(strplayerid << own().id());
    mongo::bsonobjbuilder obj; 
    obj << "lv" << _level;
    mongo::bsonobj set_obj = bson("$set" << bson("military" << obj.obj()));
    return thread_shared::getlocalmongo().savemongo(dbn::dbplayercollection, key, set_obj);
  }

  mongo::query query(bson("military.lv" << bson("$gt" << 0)));
  mongo::bsonobj field = bson(strplayerid << 1);
  objcollection objs = thread_shared::getlocalmongo().query(dbn::dbplayercollection, query, 0, &field);

嫌取配置麻烦可以这么做：#define legion_option_cfg (gg::legion::legioncfg::shared().option_cfg)


连接另一个物理机的mongodb
1.mongo 10.17.172.221:37057
2. use admin
3.db.auth("rwuser","cmgoq8ym3ctl")

绑号：
1.备份需要的db
# mongodump -h 10.17.172.222:37017 -d sid3000 -o ./
2.上传备份数据到db
mongorestore -h 10.17.172.222:37017 -d sid55 ./mongb/sid3000/
3.让mysql中的player_xx表中的某个玩家id为要绑定的id
update player_55 set player_id = 3145728004 where player_id = 57673775;

fight————————————————————————————————————————————————————————————————————

1.每个属性值 * 每个属性加的比例 得最终的属性值，  单个最终属性值 * 每个单位的属性值 = 单个属性的战力， 所以战力之和就是武将战力

map_data.h
auto map_config = war_map.get_map(1002);
设置战位信息
群英会战斗是默认两个玩家间的战争


mapid/mapdata
通过mapid取得地图数据，
ptr_war_map_data route = war_map.get_map(1002);//最底层的方法取地图数据
fightreport f;
f.setpathfunction(route)  设置寻路路径

map_war.h的war_system类管理所有的地图信息（mapconfig(除了地图的所有配置，例：守兵)和war_map(真正的战斗图，战位、走位等信息)）


创建攻守双方
ptrarmyside atk, def;  可看成开战前的排兵布阵，包括一些大范围的信息和单个npc实例
 player->warfm().currentfm(); 返回 std::vector<playermanptr> currentfm(); 实现上就是返回装有武将指针的容器

    static ptrarmyside warplayer(playerdataptr player, const std::vector<wstar::fpos>& pos_list = std::vector<wstar::fpos>(), const int ai_setting = battle::usual_player_mode)
    {   //谁？哪些武将？地图站位
      return warplayer(player, player->warfm().currentfm()(武将指针容器), player->warfm().currentbv(布局的总战力), pos_list(点位), ai_setting(ai:攻击模式"自动打、寻找目标等"));g
    }

设置攻击者的武将的站位，和攻击模式
auto atk = battlehelp::warplayer(player, config->mapdata->attacker_pos_list());static 的 warplayer,
warplayer中，会创建armyside对象，再取武将信息创建army实例，再将实例放入armyside对象中

    auto def = war_sys.npcside(config);
    trarmyside war_system::npcside(ptrmapconfig npcptr)
  {
    ptrarmyside sb = npcptr->npcside(npcptr->mapdata->defender_pos_list()); 最终调用的是mapconfig父类mapdata的npcside()
    return sb;   npcside实现是一个函数封装了创建armyside的方法 
  }   mapdata中才有npcside，如果是armynpc类，直接调用toarmyinstance生成军队,armynpc可看成是存单个军队的数据，调用toarmyinstance才生成真正的单个军队
  mapdata是一个统帅，麾下有多个军队，存在armynpc中，要战斗时才用toarmyinstance生成军队实例army对象,那如果统帅是我，我的友军可用armynpc存，用时再生成army.mapdata是不包括 ptr_war_map_data的，需要存时，要构建一个新的结构，其中有ptr_map_data_ptr的成员变量，再继承mapdata

addnotice:加战报反馈的推送人。
战报反馈
无请求
report_notice_resp = 11305
返回
msg:[结果码, 战报类型, 战报地址, 自定义格式参数]


dofight最终也是调用dofightsim,反回的结果好像也就用来判断谁胜败
  auto& reportdata = f.reportdata();  这个返回的reportdata，所有战斗数据都在上面

noticeclient, 压入一些数据到战报中，再创建地址，将战报复制过来，再将地址发给gac

void fightreport::donefight(const int type, const json::value& extra /* = json::objectvalue */)
  {
    reportdata().addmember("type", type);  //加战报类型
    const std::string str_report = reportdata().toindentstring();
    reportpost(boostbind(noticeclient, type, str_report, extra, _notice_list, _path_list));  //发送战报给gac
    _path_list.clear();
    _notice_list.clear();
  }


preparechallenge：
判断玩家是否可以打这个图：各种限制，用dofight判断配地图数据和npc地图是否正解，给gac一个battleid,加入找到这个图的标识，mapid，或关卡id等。

challenge:
to_custom_command(）攻击方指令
判断gac传过来的battleid, mapid是否正确
各种限制也要判断
这里的atk和def是prepare设置好的，保存在各性化模块中
处理：胜/败  
发消息给gac

战斗线束后，要清理各性化模块中的准备战斗相关数据
void playerwarmgr::resetbattle()
  {
    battleid = 0;
    battleseed = 0;
    atk = ptrarmyside();
    def = ptrarmyside();
    config = mapwar::ptrmapconfig();
  }

战位：
在创建atk中，会通过playerptr找到当前的布陈，warfm（）的布阵可以直接传playptr，但其它玩法的布陈需要传vector<playermanptr>
battlehelp中已保存了布陈信息，会自己取来加武将经验


1."outcometype":1,   某个地图中，某个自己保护的npc死后判败，即在friend:字段设置npc信息，在cutcometype字段设成1，即这个目标死亡之后敌方获得胜利

2.nametype:0未知 1武将 2小兵 3建筑   当要配置一个自己的城门，被攻破算败时，城门也在friend字段进行配置，nametype设置3即可，还需设置outcometype

3.兵营也是设置 nametype字段 3

4.ptrarmyside armys创建了ptrarmyside后，可改主公名： armys->_side_name = gamer.randomname();

5.友军信息要自己取出创建armynpc进行保存，继承mapdata的结构体，只会保存敌军，army字段的数据
for (const auto &itr : data["friend"]) {
    mapwar::armynpc npc(itr);
    friend_list.push_back(npc);
  }

6.army中的soldierid是武将的小兵,小兵创建后也会放入自己的部队中，atk->_army_data.push_back(m)

7.236.battlehelp::resetmasterskill(own().getowndataptr(), army_side, fm_datap->horseskillid());  重置上阵部队的坐骑技能

8.战报："me"字段信息   :[[武将id, 武将前等级,武将前经验, 武将后等级, 武将后经验, 增加的经验, 是否满级, 星级, 进阶等级]]


static int addmanexp(playerdataptr player, std::vector<playermanptr> battleman, const int per_man, json::value& json)
    {
      json = json::arrayvalue;
      unsigned total_me = 0;
      for (unsigned i = 0; i < battleman.size(); ++i)
      {
        playermanptr man = battleman[i];
        if (!man)continue;
        json::value sgme(json::arrayvalue);
        sgme.append(man->armyid());
        sgme.append(man->lv());
        sgme.append(man->exp());
        const int real_add = man->numalterexp(per_man);
        total_me += (per_man - real_add);
        sgme.append(man->lv());
        sgme.append(man->exp());
        sgme.append(per_man);
        sgme.append(man->ismaxlevel());
        sgme.append(man->starlevel());
        sgme.append(man->steplevel());
        json.append(sgme);
      }
      return total_me;//×üê£óà总剩余
    }

塔防模式
army字段外的   "tower_defence":true 是对玩家而言的，真表示是塔防模式，去掉某些ai，即站在某个位置不能动，敌军过来才会攻击
no_carry_soldier 也是对于玩家而言，一般tower_defence为true时，这个也是true，不携带小兵

在不是简单的对战模式中，要考虑是否是塔防模式，塔防模式一般还要去掉小兵，重设置ai，set_idx_array_type，地图是否有友军，友军是否携带小兵。

9.创建上阵部队时，如果暂不设位置，可用battlehelp::emptyposlist
battlehelp::warplayer(
      player, 
      player->teamfm().currentfm(config->tmidx), 
      player->teamfm().currentbv(config->tmidx),
      battlehelp::emptyposlist)

10.讨伐玩法中，地图的attack_pos，大于等级上阵武将数

11.duelresult fight::dofight(std::vector<battle::ptrarmyside> attack, std::vector<battle::ptrarmyside> defend)
可放多个上阵部队

static ptrarmyside copyfrom(ptrarmyside other, const bool copy_army = false)//_army_data中存的是武将数据的指针，false时是用原来武将的数据
std::vector<ptrarmy> _army_data;//部队数据                                  //true时，是创建一份新的数据，再存新数据的指针

linux——————————————————————————————————————————————————

1.make 的报错信息
g++: internal compiler error: killed (program cc1plus)
please submit a full bug report,
内存不足

2.以make 这个程式，并以makefile 这个参数设定档，依据 install 这个标的(target) 的指定来安装到正确的路径！

3. grep 后接正则表示式， ls |grep *.sh  会查不到内容，因为*表示匹配0个


svn————————————————————————————————————————————————————————————————————
svn co 2323/   ./ 这么写才不会下2323目录

执行svn up和svn merge等命令出现在首位置的各字母含义如下：
“ ” 无修改
“a” 新增
“c” 冲突
“d” 删除
“g” 合并
“i”   忽略
“m” 改变
“r” 替换
“x” 未纳入版本控制，但被外部定义所用
“?” 未纳入版本控制
“!” 该项目已遗失 (被非 svn 命令所删除) 或是不完整

“~” 版本控制下的项目与其它类型的项目重名
“l” 锁定
“s” 已切换
“k” 存在锁定标记
..
冲突：update最新版本下来修改，别人也下最新版本下来，当别人先commit时，你再update，版本已跟你的不一样，若同一个地方不一样，系统不知选哪个版本，
所以每次修改之前要update再修改(如果修改后commit之前没有人update，则可认为上下一个版本，所以你修改本地版本，相当于修改上面的版本，所以commit没有问题)，
上传之前也要update，有冲突在本地解决再上传.
.
foo.c
foo.c.mine
foo.c.r30
foo.c.r31
svn resolved   将*mine和*r30,r31删除   fsvn resolve --accept working 1.json
冲突例：
工程师a修改了a.txt的第一行，提交了。
工程师b也修改了a.txt的第一行，然后执行svn up，这时svn提示了：（以下，你开始扮演工程师b的角色了）
$ svn up
在 “a.txt” 中发现冲突。
选择: (p) 推迟，(df) 显示全部差异，(e) 编辑,
(mc) 我的版本, (tc) 他人的版本,
(s) 显示全部选项:
我一般选择p（推迟），即引入冲突到本地，不过不会影响到svn服务器端，可以放心。
ok，开始解决冲突了。
这时，会生成几个文件：
a.txt  a.txt.mine  a.txt.r6328  a.txt.r6336
一般，查看a.txt就可以看到冲突的详情了：
[yicheng@chengyi svntest]$ cat a.txt
<<<<<<< .mine
i also modify ,agndagnagasdg;
=======
i modify this line;
>>>>>>> .r6336
以上，<<<<<<< .mine和=======之间是工程师b（当前的“你”）修改的内容，=======与>>>>>>> .r6336之间是工程师a修改的内容。这时，最好的办法是，叫上工程师a，你们一起确定这些修改是否都需要，是否相互兼容，然后留下需要的部分，删 除<<<<<<< .mine、=======和>>>>>>> .r6336。
然后，测试，测试！确定没问题之后，就可以告诉svn，你解决冲突了：
svn resolve --accept working a.txt (该命令会删除a.txt.mine  a.txt.r6328  a.txt.r6336）
svn ci -m ’some comment’ a.txt
这里需要注意的是，a.txt.mine  a.txt.r6328  a.txt.r6336这几个文件的存在代表着有冲突产生。如果不解决冲突，就手工删除它们，svn服务器也会很傻的认为你解决了冲突，允许你继续之后 的工作。但是，冲突依旧存在，你的a.txt中不但有别人的修改，还有那些讨厌的<=>符号。
在冲突未解决前，试图提交代码是肯定会失败的：
$ svn ci -m ”
svn: 提交失败(细节如下):
svn: 提交终止: “/path/to/svntest/a.txt” 处于冲突状态
在使用svn update 的时候，会出现如下一些信息：
$ svn update
u  install
g  readme
c  bar.c
updated to revision 46.
那么，u 开头的信息提示你，这个文件在你本地没有修改过，文件已经根据版本库的新版本更新了。g 开头的信息提示你，这个文件在你本地已经修改过，但是和版本库中对应的版本并没有冲突的地方，svn已经合并更新了。而c 开头的信息提示你，这个文件有点麻烦，你在本地的修改和版本库中的版本修改的地方重叠了，也就是说，你修改了某一行，你的同事也修改了同一行。这个就需要你自己手工去解决了。当冲突发生时，要注意到有三件事情可以帮助你解决问题。
.
update 是从svn服务器上把最新版本下载到本地来；
svn update -r 200 test.php
将本地副本中的文件test.php还原到版本200.   
.
.commit;
commit 是将本地做过的改动（修改、新增、删除、改名、移动等）上传更新到svn服务器；
svn commit -m '注释内容' [-n] [--no-unlock] path   ,不加指定文件就是上传所有修改，新增等等的
//简写 
svn ci
//提交文件夹及目录   
svn ci -m '注释内容' test.php
svn ci -m '注释内容' user
.新文件，先用  svn add 文件，加到svn控制，再用svn ci -m 文件上传
.
.
svn　diff　-r　修正版本号m:修正版本号n　文件名
svn diff -r 200:201 test.php＜－ 对修正版本号200 和 修正版本号201 比较差异
.
linux下svn回滚
方法1： 用svn merges
1) 先 svn up，保证更新到最新的版本，如20；
2) 然后用 svn log ，查看历史修改，找出要恢复的版本，如10 。如果想要更详细的了解情况，可以使用svn diff -r 10:20 [文件或目录];
3) 回滚到版本号10：svn merge -r 20:10 [文件或目录]，注意版本号之间的顺序，这个叫反向合并；
4) 查看当前工作版本中的文件，如test.cpp和版本号10中文件的差别：svn diff -r 10 test.cpp， 有差别则手动改之；
5) 若无差别，则提交：svn ci -m“back to r 10，xxxxx” [文件或目录]。这时svn库中会生成新的版本，如21。
方法2: 用svn up
前2步如方法1，然后直接 svn up -r 10。当前的工作版本就是版本10了。但是注意，这时svn库中会并不会生成新的版本，下次在本地svn up之后，还是会回到之前的版本。
.
svn log | head -n 10
.
.
window是merge, from和to的文件夹要一样，去到要被更新处点文件夹右键


#tt5601_1_0_1


io服务：
异步操作会投递给系统，之后的处理由系统完成，操作完成后会触发回调，boost.asio封装了异步操作及回调，当系统完成异步操作后，调用了boost.asio封装的回调，
boost.asio将完成事件保存到队列中，并在io服务运行时进行查询，一旦有完成事件，会调用相应的回调函数，从而实现异步操作。也就是说，异步操作是由io服务投递，
回调也是由io服务执行，如果要执行异步操作，必须运行io服务。

运行io服务:
分为两种方式run和poll：
run:方法会启动事件循环直到异步操作队列全部执行完成，调用完回调后即可退出
poll:方法会启动事件循环直接执行所有已完成的异步操作回调后退出
两者区别在于poll不包含等待动作，即run为阻塞式的，poll为非阻塞式的。
run_one会运行事件处理循环，直到至少执行完成一个异步操作回调；poll_one会执行完成0～1个已就绪的异步操作回调。

停止io服务:
stop接口用来停止io服务的运行，当调用之后，run/poll操作都会立即返回，但是需要了解的是该接口只是向io服务发送了终止信号导致运行接口全部立即返回，
如果尝试再次启动，则需要调用reset接口使io服务恢复到可运行状态。检查io服务是否处理可运行状态是通过stopped接口判断的。

执行操作(注意区分执行io服务和执行操作的区别)
io服务提供了两种接口来执行操作，dispatch和post：
post
将操作投递到异步操作队列中去；
dispatch
如果该方法和io服务运行在同一线程，则操作会直接执行，否则行为与post一致。

为什么以及如何保证io服务一直运行:
即使调用了run执行io服务，在没有异步操作及其回调需要处理的情况下，run方法就会返回，io服务就停止运行了，所以如果需要的话，必须再采用一些措施来
保证io服务一直运行，方法有两种：

1.在异步操作完成回调中一直发起异步操作
这种方式保证了一直有异步操作需要处理，run方法就不会返回，可以一直运行
2.使用io_service::work
在io_service::work不被析构的情况下，io服务会一直运行下去

io_service::work如何实现:
io_service::work只是将io服务要处理的异步操作个数加1，这样一直有异步操作需要执行，析构的时候异步个数被减1，如果这时已经没有要执行的异步操作，
则会调用io服务的stop接口。

如何退出io服务执行
通常情况下调用io服务的stop接口即可，但是如果需要完成所有异步操作，应该还是需要等待其run接口正常退出。

开辟线程来执行run函数，可理解为，线程一起在循环执行队列中的事件。

iomanager::iomanager() {
    for (size_t i = 0; i < _ioconfig.size(); ++i) {
      ioptr tmpio = creator<boost::asio::io_service>::create(); //--创建io server
      workptr tmpwork = workptr( //--shared_ptr托管一个io 的work，使刚创建的io_server一直执行
        new(create_type_memory<boost::asio::io_service::work>()) boost::asio::io_service::work(*tmpio),
        delete_some<boost::asio::io_service::work>
      );
      services.push_back(tmpio);
      works.push_back(tmpwork);
      servicethreads.push_back(_ioconfig[i]);
    }
    _netio = creator<boost::asio::io_service>::create();
    _network = workptr(
      new(create_type_memory<boost::asio::io_service::work>()) boost::asio::io_service::work(*_netio),
      delete_some<boost::asio::io_service::work>
    );
  }

  workptr是sharedptr, workptr(要托管的内存，析构时调用的函数)
workptr tmpwork = workptr(
        new(create_type_memory<boost::asio::io_service::work>()) boost::asio::io_service::work(*tmpio),
        delete_some<boost::asio::io_service::work>

  void iomanager::start(const size_t net_thread /* = 4 */) {
    for (size_t i = 0; i < services.size(); ++i) {
      services[i]->reset(); //--启动io_server  ->时是调用io_server的reset，.才是调用shared_ptr的reset
      for (unsigned n = 0; n < servicethreads[i]; ++n) {
        threads.push_back(    //--创建一个线程执行操作run
          creator<boost::thread>::create(boostbind(boost::asio::io_service::run, &(*services[i])))
        );
      }
    }

    for (size_t i = 0; i < net_thread; ++i) {
      threads.push_back(//创建4个线程去执行run
        creator<boost::thread>::create(boostbind(boost::asio::io_service::run, &(*_netio)))
      );
    }
  }

  lock 锁
  1.读写锁：锁的时间很长才用，读写锁用一个字节的内存存储读的次数。因为这个数字必须被原子的更新，获取读锁的时
  候与获取mutex有着同样的总线事务，而且竞争造成的开销几乎一样。
  获取锁的时间比较长，这个时候用读写所就可以让多个线程并发的去读
  要满足另外一个特点“读的次数远多于写”


正则表达试

1.非打印字符指在计算机中有一些字符是确确实实存在,但是它们不能够显示或者打印出来。
2.定位符：
^ 要匹配的字符串出现在行开始的位置, $ 要匹配的字符串出现在结束的位置
\b 匹配的字符串出现在单词的边界。例：/\bcha/ cha字符出现在一个单词的开头，/cha\b\ cha字符出现在单词的末尾。
\b 非边界匹配。 要匹配的字符不出现在单词的开头或末尾
        

vimium
1.在visual mode中，按c转成caret mode






设计模式：
观察者模式：csubject中有-个容器存多个cobserver,当csubject中有一个变化发生，需要通知容器中的所有cobserver,
          但每个cobserver有不同的行为，所以用cobserver中用多态，容器中存的是被赋值后的cobserver的基类指针，
          csubject中会有加入、移除、调用 观察三个方法。又因为可能有多个csubject，每个csubject中有不同的cobserver,
          所以cobserver可抽象出一个基类，加入移除可以是同一个函数名的函数，但函数实现的加入的容积可不同，可
          用同一个函数名中实现遍历调用容器，只要使容器中的对象调用不同的函数即可。





boost:
1.array:
性能与原始数组相差无几，在对性能要求很高，或者不需要动态数组的情况下可用。
在声明时加类型和大小，构造函数的初始化列表可用{}进行初始化

2.debug和release区别
 debug模式跑程序速度很慢。release模式跑程序速度很快。亲测差别可达一个数量级左右。所以如果你要测试很大很
 复杂的程序的运行结果，最好用release模式。当然release跑起来加的断点啥的就不管用了，找bug还得用debug模式。

 3.ref
 bind传参时是浅拷贝，不能修改原来的参数，所以用ref(函数式编程)
 内部是用一个指针存传入参数的引用的指针

 4.operator 除操作符重载外，还是自定义对象类型的隐匿转换
 class a
 {
 public:
  operator string() {//返回值类型string放在operator的前面，以此区分重载
    return "abcd";
  }
};
a a;
则直接调用a时，会返回"abcd" 

io:
详解   https://segmentfault.com/a/1190000003063859



申请的时候，不能有军团，不能是国王，赛期不能申请非本国军团

开赛，删除玩家申请中的非本国军团



tmux:
#启动新会话：
tmux [new -s 会话名 -n 窗口名]

#恢复会话：
tmux at [-t 会话名]

#列出所有会话：
tmux ls

#关闭会话：
tmux kill-session -t 会话名

#会话
:new<回车>  启动新会话
s           列出所有会话
$           重命名当前会话

#窗口
c  创建新窗口
w  列出所有窗口
n  后一个窗口
p  前一个窗口
f  查找窗口
,  重命名当前窗口
&  关闭当前窗口

#窗格（分割窗口）
%  垂直分割
"  水平分割
"
o  交换窗格
x  关闭窗格
⍽  左边这个符号代表空格键 - 切换布局
q 显示每个窗格是第几个，当数字出现的时候按数字几就选中第几个窗格
{ 与上一个窗格交换位置
} 与下一个窗格交换位置
z 切换窗格最大化/最小化

#调整窗口排序
swap-window -s 3 -t 1  交换 3 号和 1 号窗口
swap-window -t 1       交换当前和 1 号窗口
move-window -t 1       移动当前窗口到 1 号

#同步窗格 
#这么做可以切换到想要的窗口，输入 tmux 前缀和一个冒号呼出命令提示行，然后输入：
:setw synchronize-panes

#调整窗格尺寸
#如果你不喜欢默认布局，可以重调窗格的尺寸。虽然这很容易实现，但一般不需要这么干。这几个命令用来调整窗格：
prefix : resize-pane -d          当前窗格向下扩大 1 格
prefix : resize-pane -u          当前窗格向上扩大 1 格
prefix : resize-pane -l          当前窗格向左扩大 1 格
prefix : resize-pane -r          当前窗格向右扩大 1 格
prefix : resize-pane -d 20       当前窗格向下扩大 20 格
prefix : resize-pane -t 2 -l 20  编号为 2 的窗格向左扩大 20 格

#tt6151_51_-1_-1_-1_-1_-1_0

vim:
ctrl+o/i  光标间的跳 转




[0, {"pr":[[名次，玩家名，军团名，伤害, 国家id(占位)],[]...]--玩家排行, "lr":[[名次，玩家名，军团名，伤害, 国家id],[]...]--军团排行}]


gdb p017
不是root，切换成root, 不是gg目录，进入gg目录
gdb attach no ./startup ./gg 

进入相关目录
go p017
go gpo17

查看screen
lk p017   hp 

shell
1.info=($(ps aux|grep p017 |awk '{print $2 "\t" $11}')) 
print $2 表示只输出第2列，第一列是$1   以空格分格，再输出第11列
返回到info中是数组，数组中的元素是awk返回的结果从左到右，上到下保存，用info[idx]访问

2.在shell中输入一个命令后，想等待结果返回再输入第二个命令 
用：expect
send:xx  相当于从键盘输入 xx

3.变量
1.${变量} :输出变量  $(变量) :变量执行的结果返回
2.定义变量时，=号左右不能有空格
3.定义变量时不用加$,使用时需要加。加不加{}都可，加是为了限制这个变量的范围
4.local 变量 时，该变量才是局部变量
5.全局变量是在该进程中一直有效，用source 执行多次sh脚本，则该全局变量就是同一个
6.if [ ! $gpid ]  变量空的判断，！与变量之间要有空格

4. if 和 elif　后要加  if[ 表达式 ] :表达式左右要有空格

5.字符串
1.双引号内能有变量，能有转义字符。 单引号则不可
2.比较相等用=
3.string='abcdef'
4.echo ${string:1:4} 输出bcde,表示从第1个字符开始，输出4个,数组从0开始
5.echo ${#string} #输出字符串大小只能这么写


7. ${} 和 $() 区别
${}是变量替换，可根据变量的状态，例被定义，被删除等  来返某个值  ${变量}  是输出变量本身的值
$()命令替换，即将命令返回的结果暂时保存，在需要的地方重新输出，看起来像是新命令输出的值   与反引号相同

8.传入的参数
字符串可不加引号 if [ $1 = a ] 
参数提取： $1 或 ${1}

9.shell 中连接mongo，在输入框中可有双引号，在脚本中要将其去掉，也许在shell命令输入框中和脚本中对双引号的处理不一样
mongo "mongodb://rwuser:cmgoq8ym3ctl@10.20.202.217:27317/admin?authmechanism=mongodb-cr"

10. for循环
类似c的for： for(( i = 1; i <= 100; i = i + 2 ))

11.关系运算符
1.关系运算符只支持数字，不支持字符比较，后报错：integer expression expected,但用在[[ ]] 中不会报错

12.逻辑运算行和布尔运算符的区别好像就是中括号多与少的问题
if [[ $a -lt 100 || $b -gt 100 ]]  //这种与c相拟，可用这种
if [ $a -lt 100 -a $b -gt 15 ]

13.expr 
1. `expr xxx`, 注意前后的符号, 在脚本中可不写
2. 'expr 1 + $x' :如果$不是数字或整数字符，会返回错误，可用此判断一个字符是否是数字, 返回非0都是错误

14.输入输出重定向
1. 0 通常是标准输入（STDIN），1 是标准输出（STDOUT），2 是标准错误输出
2. 2>&1   标准错误输出到标准输出


python
1.不用 {}来控制模块，用缩进来控制模块，每个语句块的缩进要相同
2.以新行来作为语句的结束，
3.引号
可以使用引号''、双引号、三引号 来表示字符串，引号的开始与结束必须的相同类型的。
其中三引号可以由多行组成，常用做注释。

4.变量
1.a = b = c = 20 : 则三个变量都会分配到同一块内存空间
2.全局变量和局部变量同名时，局部会覆盖全局。
3.Python假定在函数内被赋值的变量都是局部变量，使用全局变量要用 gloabl 注明
例：
Money = 2000
def AddMoney():
   # global Money
   Money = Money + 1,这么写会报错，需将上行取消注释
print Money

5.数据类型
Numbers（数字）:
1.long 类型只存在于 Python2.X 版本中，在 2.2 以后的版本中，int 类型数据溢出后会自动转为long类型。在 Python3.X 版本中 long 类型被移除，使用 int 替代。
2.改变值，新值所占的空间是新的内存

3.类型属于对象，变量是没有类型的：
例:
a=[1,2,3]
a="Runoob"
以上代码中，[1,2,3]和"Runoob" 是对象，[1,2,3] 是 List 类型，"Runoob" 是 String 类型，而变量 a 是没有类型，她仅仅是一个对象的引用（一个指针，
可以是 List 类型对象，也可以指向 String 类型对象。

4.可变、不可变
1.分可变和不可变，本质是变之后是否开辟新的内存空间
2.strings, tuples（元组）, 和 numbers 是不可更改的对象，而 list,dict 等则是可以修改的对象。
3.在传参时，不可变类型是传值，可变类型是传引用 

String（字符串）
索引:
B   O  O  K
0   1  2  3 
-4 -3 -2 -1

print str           # 输出完整字符串
print str[0]        # 输出字符串中的第一个字符
print str[2:5]      # 输出字符串中第三个至第六个之间的字符串, 是从0开始的下标，不包括尾下标
print str[2:]       # 输出从第三个字符开始的字符串
print str * 2       # 输出字符串两次
print str + "TEST"  # 输出连接的字符串

str[2:5:2] 在一定范围内以步长2进行截取
str='abcbefg'
str[2:5:2] 为：ce

List（列表） 标识 []
类似vector,可以嵌套,可以存放不同的数据类型

print list               # 输出完整列表
print list[0]            # 输出列表的第一个元素
print list[1:3]          # 输出下标1到2的元素
print list[2:]           # 输出从第三个开始至列表末尾的所有元素
print tinylist * 2       # 输出列表两次
print list + tinylist    # 打印组合的列表

Tuple（元组）标识 ()
const 类型的List,只读
print tuple               # 输出完整元组
print tuple[0]            # 输出元组的第一个元素
print tuple[1:3]          # 输出下标1到2的元素
print tuple[2:]           # 输出从第三个开始至列表末尾的所有元素
print tinytuple * 2       # 输出元组两次
print tuple + tinytuple   # 打印组合的元组
如果只有一个元素， 需在元素后面加,号
任意无符号的对象，以逗号隔开，默认为元组，所以:tup3 = "a", "b", "c", "d" 是声明一个元组


Dictionary（字典）标识 {}
类型map, key和value都可是不同的类型
print dict['one']          # 输出键为'one' 的值
print dict[2]              # 输出键为 2 的值
print tinydict             # 输出完整的字典
print tinydict.keys()      # 输出所有键
print tinydict.values()    # 输出所有值

del dict['Name']  # 删除键是'Name'的条目
dict.clear()      # 清空字典所有条目
del dict          # 删除字典

键必须不可变，所以可以用数字，字符串或元组充当，所以用列表就不行，

6.算数运算符
Python2.x 里，整数除整数，只能得出整数。如果要得到小数部分，把其中一个数改成浮点数即可 

7.成员运算符
in  如果在指定的序列中找到值返回 True，否则返回 False。
not in  如果在指定的序列中没有找到值返回 True，否则返回 False
例：
a = 10
b = 20
list = [1, 2, 3, 4, 5 ];
 
if ( a in list ):
   print "1 - 变量 a 在给定的列表中 list 中"
else:
   print "1 - 变量 a 不在给定的列表中 list 中"

8.身份运算符 is , is not
判断对象是否是引用同一块内存空间
例：
a = 10
b = 10  则相当于 a = b = 10,所以 if (a is b) 返回true

9. if
Python程序语言指定任何非0和非空（null）值为true，0 或者 null为false。
if 判断条件：
    执行语句……
else：
    执行语句……
//===============
  if 判断条件1:
    执行语句1……
elif 判断条件2:
    执行语句2……
else:
    执行语句4……
//判断对件可加括号
if (num >= 0 and num <= 5) or (num >= 10 and num <= 15):    

没有swithc语句

10. for循环
可以遍历任何序列的项目，如一个列表或者一个字符串

for x in 'string': x可取字符串中的每个字符 
for x in List: x可取字符串中的每个元素

11. for...else  和  while...else 会在循环正常结束后执行，中断循环不执行。

12.pass 是空语句，是为了保持程序结构的完整性。如果定义一个空函数程序会报错，当你没有想好函数的内容是可以用 pass 填充

13.函数
1.不写返回值类型,实现以:号开始且缩进
例：def functionname( parameters ):
   "函数_文档字符串"
   function_suite
   return [expression]

2.可不按参数声明顺序传递,在传参时指定参数的值
例：def printinfo( name, age ):
    pass
   return;
#调用printinfo函数
printinfo( age=50, name="miki" );

3.不定长参数, *参数
例：def functionname([formal_args], *var_args_tuple ):
    pass
   return [expression]

   *var_args_tuple可传入多个参数,var_args_tuple相当于多个参数的句柄

4.lambda
1.函数实现是一个表达试，不是语句块,   lambda arg1, arg2, ...：expression
例：
sum = lambda arg1, arg2: arg1 + arg2;
# 调用sum函数
print "相加后的值为 : ", sum( 10, 20 )

14.模块
1.import:相当于包含头文件，使用时需 模块名.函数名
2.from...import:只引用别一个文件的部分内容
例：from fib import fibonacci  ,只引用 fib 模块的 fibonacci 函数

15.类
1.Python不允许实例化的类访问私有数据，但你可以使用 对象名._类名__私有属性名 来访问
class Runoob:
    __site = "www.runoob.com"

runoob = Runoob() 创建对象
print runoob._Runoob__site  访问私有成员

2.单下划线、双下划线、头尾双下划线说明：
头尾双下划线：__foo__: 定义的是特殊方法，一般是系统定义名字 ，类似 __init__() 之类的。
单下划线：_foo: 以单下划线开头的表示的是 protected 类型的变量，即保护类型只能允许其本身与子类进行访问
双下划线：__foo: 双下划线的表示的是私有类型(private)的变量, 只能是允许这个类本身进行访问了。


