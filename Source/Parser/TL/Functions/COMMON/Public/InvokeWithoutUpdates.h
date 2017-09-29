#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InvokeWithoutUpdates : public TLBaseObject
{
public:
	InvokeWithoutUpdates();
	InvokeWithoutUpdates(TLBaseObject* query);

	~InvokeWithoutUpdates();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getquery() const
	{
		 return this->query;
	}

	TLBaseObject* GetResult() const
	{
		 return this->result;
	}

private:
	TLBaseObject* query;
	TLBaseObject* result;
};
} //end namespace block