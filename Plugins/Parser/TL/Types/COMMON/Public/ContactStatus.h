#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/UserStatus.h"

//begin namespace block
namespace COMMON
{
class ContactStatus : public TLBaseObject
{
public:
	ContactStatus();
	ContactStatus(int32 user_id, PRIVATE::UserStatus* status);

	~ContactStatus();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 user_id;
	 PRIVATE::UserStatus* status;
};
} //end namespace block
