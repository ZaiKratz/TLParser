#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class ReorderPinnedDialogs : public TLBaseObject
{
public:
	ReorderPinnedDialogs();
	ReorderPinnedDialogs(bool force, TArray<TLBaseObject*> order);

	~ReorderPinnedDialogs();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getforce() const
	{
		 return this->force;
	}

	TArray<TLBaseObject*>  Getorder() const
	{
		 return this->order;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	bool force;
	 TArray<TLBaseObject*> order;
	bool result;
};
} //end namespace block
