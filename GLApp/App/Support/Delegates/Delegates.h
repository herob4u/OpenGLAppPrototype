#include "DelegateBase.h"
#include <vector>

namespace RTB
{
	class GlobalDelegateVoid;
	class DelegateVoid;
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


/*	Creates a delegate with name Name and void 
*	return type and no arguments.
*/
//#define DECLARE_DELEGATE(Name, InClass)


/*  ----------------------------------------------------------------------------------------------------------------------------------------
%	Multicast Delegates
-------------------------------------------------------------------------------------------------------------------------------------*/