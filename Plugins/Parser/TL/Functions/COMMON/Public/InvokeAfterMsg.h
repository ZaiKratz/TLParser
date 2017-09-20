#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InvokeAfterMsg : public TLBaseObject
{
public:
	InvokeAfterMsg();
	InvokeAfterMsg(unsigned long long msg_id, TLBaseObject* query);

	~InvokeAfterMsg();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long msg_id;
	 TLBaseObject* query;
	TLBaseObject* result;
};
} //end namespace block
