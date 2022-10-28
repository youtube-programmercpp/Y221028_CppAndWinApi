struct A {
	int a;
	int b;
};
struct B : A {
	short c;
};
void f(A* p)
{
	p->a = 10;
	p->b = 20;
	//((B*)p)->c = 30; //C言語の書き方
	static_cast<B*>(p)->c = 30;//C++の書き方
}
int main()
{
	B x;
	x.a = 1;
	x.b = 2;
	x.c = 3;
	f(&x);
}
