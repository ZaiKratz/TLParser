#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class MessageEditData : public TLBaseObject
{
public:
	MessageEditData();
	MessageEditData(bool caption);

	~MessageEditData();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool caption;
};
} //end namespace block
