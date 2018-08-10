#include <map>
#include <vector>

namespace RTB
{
	class DelegateHandler;
	class DelegateBase;
	class Function;

	typedef std::vector<Function> Functions;
}

class RTB::DelegateHandler
{
public:
	DelegateHandler();
	~DelegateHandler();

	void RegisterDelegate();
	void OnDelegateBroadcast(const DelegateBase&);

private:
	/*	The delegate handler manages a list of delegate objects.
	*	Delegates have an associated list of functions bound to them
	*	which are invoked when the delegate is broadcast.
	*/
	std::map<DelegateBase, Functions> delegateMap;

};