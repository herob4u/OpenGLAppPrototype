
namespace RTB
{
	class DelegateBase;
	class FunctionBase;
	class Function;
	class MemberFunction;
}


class RTB::DelegateBase
{
public:
	DelegateBase();
	virtual ~DelegateBase();

	void Broadcast();
	void AddCallback();

	// Removes all bound functions from this delegate
	virtual void Unbind();
};


/* Base Definition of a function that will bind to a delegate
*/
class RTB::FunctionBase
{

};

/* Declaration for global or static function pointers
*/

template<typename RetType, typename ArgType1>
class RTB::Function : public RTB::FunctionBase
{
public:
	typedef RetType(*FuncPtr)(ArgType1);
};


template<typename RetType, typename ArgType1, typename ArgType2>
class RTB::Function : public RTB::FunctionBase
{
public:
	typedef RetType(*FuncPtr)(ArgType1, ArgType2);
};


template<typename RetType, typename ArgType1, typename ArgType2, typename ArgType3>
class RTB::Function : public RTB::FunctionBase
{
public:
	typedef RetType(*FuncPtr)(ArgType1, ArgType2, ArgType3);
};


template<typename RetType, typename ArgType1, typename ArgType2, typename ArgType3, typename ArgType4>
class RTB::Function : public RTB::FunctionBase
{
public:
	typedef RetType(*FuncPtr)(ArgType1, ArgType2, ArgType3, ArgType4);
};




/*	Declaration for class member function pointers
*/
template<typename InClass, typename RetType, typename ArgType1>
class RTB::MemberFunction : public RTB::FunctionBase
{
public:
	typedef RetType(InClass::*FuncPtr)(ArgType1);
};


template<typename InClass, typename RetType, typename ArgType1, typename ArgType2>
class RTB::MemberFunction : public RTB::FunctionBase
{
public:
	typedef RetType(InClass::*FuncPtr)(ArgType1, ArgType2);
};


template<typename InClass, typename RetType, typename ArgType1, typename ArgType2, typename ArgType3>
class RTB::MemberFunction : public RTB::FunctionBase
{
public:
	typedef RetType(InClass::*FuncPtr)(ArgType1, ArgType2, ArgType3);
};


template<typename InClass, typename RetType, typename ArgType1, typename ArgType2, typename ArgType3, typename ArgType4>
class RTB::MemberFunction : public RTB::FunctionBase
{
public:
	typedef RetType(InClass::*FuncPtr)(ArgType1, ArgType2, ArgType3, ArgType4);
};

