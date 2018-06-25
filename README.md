# Design Pattern in c++ programming
<br>
1.singleton:
<br>feature:一个类仅有一个实例，并提供一个访问它的全局访问点。在内存里只有一个实例，减少了内存的开销，尤其是频繁的创建和销毁实例
<br>usage:thread pool,connection pool,memory allo cator
<br>reflact:<p><li>when we need to make sure that some classes can only have one instance.<li>when a class have only one instance but frequently destroy and rebuild it,make it singleton to save time.</p>
<br>
-----------------------------------------
2.factory:
<br>feature:在工厂模式中，我们在创建对象时不会对客户端暴露创建逻辑，并且是通过使用一个共同的接口来指向新创建的对象。
<br>usage:1、日志记录器：记录可能记录到本地硬盘、系统事件、远程服务器等，用户可以选择记录日志到什么地方。 2、数据库访问，当用户不知道最后系统采用哪一类数据库，以及数据库可能有变化时。 3、设计一个连接服务器的框架，需要三个协议，"POP3"、"IMAP"、"HTTP"，可以把这三个作为产品类，共同实现一个接口。 
<br>reflact:Generally speaking,we build a instance genetator to simplify the (new) operation
<br>
-----------------------------------------
3.abstract factory
<br>feature:提供一个创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类。
<br>usage:
<br>reflact:make all the factories abstract to simplify when creating a set of instance in one factory
<br>
-----------------------------------------
4.builder:
<br>feature:使用多个简单的对象一步一步构建成一个复杂的对象,将变与不变分离开
<br>usage:
<br>reflact:it's different from (abstract)factory,because there is logic in the procdure of building
<br>
-----------------------------------------
5.prototype:
<br>feature:这种模式是实现了一个原型接口，该接口用于创建当前对象的克隆。当直接创建对象的代价比较大时，则采用这种模式
<br>usage:一个对象需要在一个高代价的数据库操作之后被创建。我们可以缓存该对象，在下一个请求时返回它的克隆，在需要的时候更新数据库，以此来减少数据库调用。
<br>reflact:the keywords are deepcopy and fast-clone
<br>
-----------------------------------------
6.adapter:
<br>feature:将一个类的接口转换成客户希望的另外一个接口。适配器模式使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。
<br>usage:有动机地修改一个正常运行的系统的接口，这时应该考虑使用适配器模式。
<br>reflact:when we about to upgrade the old code add more similiar functions,we can add an adapter to compact,thus we don't have to do much work to rewrite old code
<br>
-----------------------------------------
7.bridge:
<br>feature:将抽象部分与实现部分分离，使它们都可以独立的变化
<br>usage:对于两个独立变化的维度，使用桥接模式再适合不过了
<br>reflact:the are abstract classes and operations on them,we just seperate the clasee and operations,and then connect them ,namely ,instant the operation inside class
<br>
-----------------------------------------
8.filter:
<br>feature:使用不同的标准来过滤一组对象，通过逻辑运算以解耦的方式把它们连接起来。
<br>usage:
<br>reflact: the only usage i can image is to filer duriance data form DAO.  
<br>
-----------------------------------------
9.composite:
<br>feature:将对象组合成树形结构以表示"部分-整体"的层次结构。组合模式使得用户对单个对象和组合对象的使用具有一致性。
<br>usage:
<br>reflact:the pattern just means using trees to manage a set of class.
<br>
-----------------------------------------
10.decorator:
<br>feature:动态地给一个对象添加一些额外的职责。就增加功能来说，装饰器模式相比生成子类更为灵活。
<br>usage: 1、扩展一个类的功能。 2、动态增加功能，动态撤销。 
<br>reflact:Exremely convenient for extension operations.
<br>
-----------------------------------------
11.facade:
<br>feature:隐藏系统的复杂性，并向客户端提供了一个客户端可以访问系统的接口。
<br>usage:
<br>reflact:just like proxy in some ways,it wraps a set of fixed operations in a order,thus a simple function call can execute all these functions in the right way
<br>
-----------------------------------------
12.flyweight:
<br>feature:享元模式尝试重用现有的同类对象，如果未找到匹配的对象，则创建新对象。
<br>usage:
<br>reflact:like factory pattern,it use a class to control the generation of instances,what's more it use map to store all instances,so you can reuse them.sacrifice memory to save time.
<br>
-----------------------------------------
13.proxy:
<br>feature:
<br>usage:
<br>reflact:
<br>
-----------------------------------------
14.responsibility chain:
<br>feature:
<br>usage:
<br>reflact:
<br>
-----------------------------------------
15.order:
<br>feature:
<br>usage:
<br>reflact:
<br>
-----------------------------------------
16.interpreter:
<br>feature:
<br>usage:
<br>reflact:
<br>
-----------------------------------------
17.iterator:
<br>feature:
<br>usage:
<br>reflact:
<br>
-----------------------------------------
18.mediator:
<br>feature:
<br>usage:
<br>reflact:give all those instances, i will help you call complicate functions 
<br>
-----------------------------------------
19.Memonto:
<br>feature:
<br>usage:
<br>reflact:auto save,porcedure
<br>
-----------------------------------------
20.Observer:
<br>feature:当对象间存在一对多关系时，则使用观察者模式。比如，当一个对象被修改时，则会自动通知它的依赖对象。
<br>usage:一个对象（目标对象）的状态发生改变，所有的依赖对象（观察者对象）都将得到通知，进行广播通知。
<br>reflact: in java language,Observer has been implemented.Considering the IOC pattern in SpringMVC frame,when a user changes a instance,then all related instances will response to the change automatically.Generally,it simplifies and restricts the logicl,thus brings convience and reduces errors.
<br>
-----------------------------------------
21.state:
<br>feature:
<br>usage:
<br>reflact:make the states of a class abstract
<br>
-----------------------------------------
22.NULL Object:
<br>feature:
<br>usage:
<br>reflact:to avoid some cases that caused by null object
<br>
-----------------------------------------
23.strategy:
<br>feature:
<br>usage:
<br>reflact:like state pattern,but state pattern use a state instance to set target,while strategy pattern use target to include a strategy.
<br>
