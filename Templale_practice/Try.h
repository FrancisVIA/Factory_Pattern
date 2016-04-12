/********Design Pattern: Factory Pattern*********/
#include <boost/function.hpp>

typedef  boost::function<int(int ,int)> Func;

template<typename T>
class Try
{
	public:
		Try(T p1, T p2): t1(p1), t2(p2), \
			val_1(-1), val_2(-2)
		{
		
		};

		~Try()
		{

		};

		virtual T Add() = 0;

	    void SetFunc(Func func_input, int input_1, int input_2)
		{
				func = func_input;
				val_1 = input_1;
				val_2 = input_2;
		};


		T ExecuteFunc()
		{
				return (T)func(val_1, val_2);
		};

	protected:
		T t1;
		T t2;

	private:
		Func  func;
		int val_1;
		int val_2;

};

template <typename T>
class Try_Derive1:public Try<T>
{
		public:
			Try_Derive1(T p1, T p2):Try<T>(p1, p2)
			{
			
			};

			~Try_Derive1()
			{

			};

			T Add()
			{
				return t1+t2;
			
			};
};

template<typename T>
class Try_Derive2:public Try<T>
{
	public:
		Try_Derive2(T p1, T p2):Try<T>(p1, p2)
		{

		};

		~Try_Derive2()
		{
		
		};

		T Add()
		{
				return t1-t2;
		};

};

template<typename T>
class TryFactory
{
	public:
		TryFactory(T p1, T p2):t1(p1), t2(p2)
		{

		};
		~TryFactory()
		{
		
		};
		virtual Try<T>* CreateTry() = 0; 

	protected:
		T t1;
		T t2;

};

template<typename T>
class Try_Derive1Factory:public TryFactory<T>
{
	public:
		Try_Derive1Factory(T p1, T p2):TryFactory<T>(p1, p2)
		{

		};

		~Try_Derive1Factory()
		{

		};

		Try<T>* CreateTry()
		{
			return new Try_Derive1<T>(t1 ,t2);
		};
};

template<typename T>
class Try_Derive2Factory:public TryFactory<T>
{
	public:
		Try_Derive2Factory(T p1, T p2):TryFactory<T>(p1, p2)
		{

		};

		~Try_Derive2Factory()
		{

		};

		Try<T>* CreateTry()
		{
				return new Try_Derive2<T>(t1, t2);
		};

};

