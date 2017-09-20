#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/PhoneCallDiscardReason.h"
#include "../../../Types/Common/Public/PhoneCall.h"

//begin namespace block
namespace COMMON
{
class PhoneCallDiscarded : public TLBaseObject
{
public:
	PhoneCallDiscarded();
	PhoneCallDiscarded(bool need_rating, bool need_debug, unsigned long long id, PRIVATE::PhoneCallDiscardReason* reason, int32 duration);

	~PhoneCallDiscarded();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool need_rating;
	 bool need_debug;
	 unsigned long long id;
	 PRIVATE::PhoneCallDiscardReason* reason;
	 int32 duration;
};
} //end namespace block
