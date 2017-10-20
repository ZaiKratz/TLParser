#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdateDialogPinned : public TLBaseObject
{
public:
	UpdateDialogPinned();
	UpdateDialogPinned(bool pinned, TLBaseObject* peer);

	~UpdateDialogPinned();
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

private:
	bool pinned;
	 TLBaseObject* peer;
};
} //end namespace block
