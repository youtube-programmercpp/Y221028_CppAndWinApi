struct A {
	int a;
	int b;
	virtual void f()
	{
	}
};
struct B : A {
	short a;
	short b;
};
#include <iostream>
void f(A* p)
{
	if (const auto pb = dynamic_cast<B*>(p)) {
		std::cout << "キャスト成功\n";
	}
}
#include <stdlib.h>
int main()
{
	A x;
	f(&x);
	B y;
	f(&y);

	//通常の C++ の new では出来ない状況の場合を想定
	const auto pa = static_cast<A*>(malloc(sizeof(A)));
	//memcpy(pa, &x, sizeof x);
	new(pa) A;//A のコンストラクタを呼ぶ
	pa->a = 1234;
	pa->b = 5678;
	pa->f();
}
