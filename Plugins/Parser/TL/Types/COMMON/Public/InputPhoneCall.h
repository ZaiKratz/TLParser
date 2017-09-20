#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputPhoneCall : public TLBaseObject
{
public:
	InputPhoneCall();
	InputPhoneCall(unsigned long long id, unsigned long long access_hash);

	~InputPhoneCall();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long id;
	 unsigned long long access_hash;
};
} //end namespace block
