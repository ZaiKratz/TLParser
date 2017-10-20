#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class ToggleDialogPin : public TLBaseObject
{
public:
	ToggleDialogPin();
	ToggleDialogPin(bool pinned, TLBaseObject* peer);

	~ToggleDialogPin();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getpinned() const
	{
		 return this->pinned;
	}

	TLBaseObject*  Getpeer() const
	{
		 return this->peer;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	bool pinned;
	 TLBaseObject* peer;
	bool result;
};
} //end namespace block
