#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class SetTyping : public TLBaseObject
{
public:
	SetTyping();
	SetTyping(TLBaseObject* peer, TLBaseObject* action);

	~SetTyping();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getpeer() const
	{
		 return this->peer;
	}

	TLBaseObject*  Getaction() const
	{
		 return this->action;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	TLBaseObject* peer;
	 TLBaseObject* action;
	bool result;
};
} //end namespace block
