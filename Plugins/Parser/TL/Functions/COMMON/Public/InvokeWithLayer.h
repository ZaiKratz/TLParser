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
private:
	int32 layer;
	 TLBaseObject* query;
	TLBaseObject* result;
};
} //end namespace block
