#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/DraftMessage.h"

//begin namespace block
namespace COMMON
{
class UpdateDraftMessage : public TLBaseObject
{
public:
	UpdateDraftMessage();
	UpdateDraftMessage(TLBaseObject* peer, COMMON::DraftMessage* draft);

	~UpdateDraftMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getpeer() const
	{
		 return this->peer;
	}

	COMMON::DraftMessage*  Getdraft() const
	{
		 return this->draft;
	}

private:
	TLBaseObject* peer;
	 COMMON::DraftMessage* draft;
};
} //end namespace block
