
namespace RTB
{
	class DelegateBase;
}


class RTB::DelegateBase
{
public:
	DelegateBase();
	~DelegateBase();

	void Broadcast();
	void AddCallback();
};