#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/PhoneCallProtocol.h"
#include "../../../Types/Common/Public/PhoneCall.h"

//begin namespace block
namespace COMMON
{
class PhoneCallWaiting : public TLBaseObject
{
public:
	PhoneCallWaiting();
	PhoneCallWaiting(unsigned long long id, unsigned long long access_hash, FDateTime date, int32 admin_id, int32 participant_id, COMMON::PhoneCallProtocol* protocol, FDateTime receive_date);

	~PhoneCallWaiting();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long id;
	 unsigned long long access_hash;
	 FDateTime date;
	 int32 admin_id;
	 int32 participant_id;
	 COMMON::PhoneCallProtocol* protocol;
	 FDateTime receive_date;
};
} //end namespace block
