#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/WebPage.h"

//begin namespace block
namespace COMMON
{
class WebPagePending : public TLBaseObject
{
public:
	WebPagePending();
	WebPagePending(unsigned long long id, FDateTime date);

	~WebPagePending();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long Getid() const
	{
		 return this->id;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

private:
	unsigned long long id;
	 FDateTime date;
};
} //end namespace block
