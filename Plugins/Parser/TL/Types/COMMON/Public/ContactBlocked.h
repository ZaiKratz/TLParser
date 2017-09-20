#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class ContactBlocked : public TLBaseObject
{
public:
	ContactBlocked();
	ContactBlocked(int32 user_id, FDateTime date);

	~ContactBlocked();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 user_id;
	 FDateTime date;
};
} //end namespace block
