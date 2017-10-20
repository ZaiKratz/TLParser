#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/PhoneCall.h"

//begin namespace block
namespace COMMON
{
class PhoneCallDiscarded : public TLBaseObject
{
public:
	PhoneCallDiscarded();
	PhoneCallDiscarded(bool need_rating, bool need_debug, unsigned long long id, TLBaseObject* reason, int32 duration);

	~PhoneCallDiscarded();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetNeedRating() const
	{
		 return this->need_rating;
	}

	bool GetNeedDebug() const
	{
		 return this->need_debug;
	}

	unsigned long long Getid() const
	{
		 return this->id;
	}

	TLBaseObject*  Getreason() const
	{
		 return this->reason;
	}

	int32 Getduration() const
	{
		 return this->duration;
	}

private:
	bool need_rating;
	 bool need_debug;
	 unsigned long long id;
	 TLBaseObject* reason;
	 int32 duration;
};
} //end namespace block
