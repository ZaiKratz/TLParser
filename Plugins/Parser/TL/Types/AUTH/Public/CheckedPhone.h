#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace AUTH
{
class CheckedPhone : public TLBaseObject
{
public:
	CheckedPhone();
	CheckedPhone(bool phone_registered);

	~CheckedPhone();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool phone_registered;
};
} //end namespace block
