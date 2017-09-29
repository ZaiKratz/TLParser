#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InvokeWithLayer : public TLBaseObject
{
public:
	InvokeWithLayer();
	InvokeWithLayer(int32 layer, TLBaseObject* query);

	~InvokeWithLayer();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getlayer() const
	{
		 return this->layer;
	}

	TLBaseObject*  Getquery() const
	{
		 return this->query;
	}

	TLBaseObject* GetResult() const
	{
		 return this->result;
	}

private:
	int32 layer;
	 TLBaseObject* query;
	TLBaseObject* result;
};
} //end namespace block
