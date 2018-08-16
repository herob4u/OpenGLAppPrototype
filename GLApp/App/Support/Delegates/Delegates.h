#include "DelegateBase.h"
#include <vector>

namespace RTB
{
	class GlobalDelegateVoid;
	class DelegateVoid;
	class DelegateTyped;
}

/* Recall class member function pointer
*	typedef RetType (T::*fnPtrName)(ArgType arg);
*	fnPtrName ptr = &ClassName::FuncName;
*   ....
*   ClassName obj = new ClassName();
*   (obj->*ptr)(ArgType param); // Invokes the member function via instance "obj" using "param" as argument
*   
*   // If using a reference instead of pointer, use (obj.*ptr) instead.
*/

/*  ----------------------------------------------------------------------------------------------------------------------------------------
%	Unicast Delegates
	-------------------------------------------------------------------------------------------------------------------------------------*/

/*	Represents a class member function with  void return type
*	and arbitrary arguments.
*
*/
/*
template<typename...Args>
class RTB::DelegateVoid : public RTB::DelegateBase
{
public:
	DelegateVoid();
	~DelegateVoid();

	virtual void Unbind() override;

	void AddRaw(Function<void, Args...> func);
	void AddMember(MemberFunction<void, Args...> func);

private:

};
*/

/**/
template<typename Arg1 = void>
class RTB::DelegateVoid : public RTB::DelegateBase
{
	GENERATE_DELEGATE_BODY(void, Arg1);
};

template<typename Arg1, typename Arg2>
class RTB::DelegateVoid : public RTB::DelegateBase
{
	GENERATE_DELEGATE_BODY(void, Arg1, Arg2);
};


template<typename Arg1, typename Arg2, typename Arg3>
class RTB::DelegateVoid : public RTB::DelegateBase
{
	GENERATE_DELEGATE_BODY(void, Arg1, Arg2, Arg3);
};

template<typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class RTB::DelegateVoid : public RTB::DelegateBase
{
	GENERATE_DELEGATE_BODY(void, Arg1, Arg2, Arg3, Arg4);
};




template<typename RetType, typename Arg1 = void>
class RTB::DelegateTyped : public RTB::DelegateBase
{
	GENERATE_DELEGATE_BODY(RetType, Arg1);
};

template<typename RetType, typename Arg1, typename Arg2>
class RTB::DelegateTyped : public RTB::DelegateBase
{
	GENERATE_DELEGATE_BODY(RetType, Arg1, Arg2);
};

template<typename RetType, typename Arg1, typename Arg2, typename Arg3>
class RTB::DelegateTyped : public RTB::DelegateBase
{
	GENERATE_DELEGATE_BODY(RetType, Arg1, Arg2, Arg3);
};

template<typename RetType, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class RTB::DelegateTyped : public RTB::DelegateBase
{
	GENERATE_DELEGATE_BODY(RetType, Arg1, Arg2, Arg3, Arg4);
};



// Takes in the template arguments and generates the internal class code for the delegate
#define GENERATE_DELEGATE_BODY(RetType, ...) \
	public: \
	typedef RetType(*FuncPtr)(__VA_ARGS__);\
	inline void AddRaw(FuncPtr func);\
	template<typename InClass>\
	inline void AddMember(InClass* InObject, RetType(InClass::*)(__VA_ARGS__));\


/*	Creates a delegate with name Name and void 
*	return type and no arguments.
*/
//#define DECLARE_DELEGATE(Name, InClass)


/*  ----------------------------------------------------------------------------------------------------------------------------------------
%	Multicast Delegates
-------------------------------------------------------------------------------------------------------------------------------------*/