import java.io.*;
package p1;
package p2;
class A implements p1
{
	private int a;
	protected int b;
	int c,d;
}

class B extends A, implements p1
{
	public void change()
	{
		a = 0;
		b = 0;
		c = 0;
		d = 0;
	}
}
class C extends A, implements p2
{
	public void change()
	{
		a = 0;
		b = 0;
		c = 0;
		d = 0;
	}
}

class execute
{
	public static void main(String args[])
	{
		B ob2 = new B();
		C ob3 = new C();
		ob2.change();
		ob3.change();
	}
}
	}
}