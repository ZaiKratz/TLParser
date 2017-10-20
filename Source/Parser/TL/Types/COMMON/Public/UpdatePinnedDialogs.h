#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdatePinnedDialogs : public TLBaseObject
{
public:
	UpdatePinnedDialogs();
	UpdatePinnedDialogs(TArray<TLBaseObject*> order);

	~UpdatePinnedDialogs();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<TLBaseObject*>  Getorder() const
	{
		 return this->order;
	}

private:
	TArray<TLBaseObject*> order;
};
} //end namespace block
